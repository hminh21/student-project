using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.Model;
using System.Windows.Input;
using System.Windows;


namespace ManagementSystem.ViewModel
{
    public class TransactionViewModel : BaseViewModel
    {
        //Dùng lớp ObservableCollection vì nó kế thừa INotifyPropertyChanged nên ta có thể binding
        private ObservableCollection<TransactionData> transactionDataList;
        public ObservableCollection<TransactionData> TransactionDataList { get { return transactionDataList; } set { transactionDataList = value; OnPropertyChanged(); } }

        //COMMAND
        public ICommand AddCommand { get; set; }
        public ICommand UpdateCommand { get; set; }
        public ICommand WatchCommand { get; set; }
        public ICommand DeleteCommand { get; set; }

        //Binding cho SelectedItem
        private TransactionData selectedItem;
        public TransactionData SelectedItem
        {
            get
            {
                return selectedItem;
            }
            set
            {
                selectedItem = value;
                OnPropertyChanged();
                if (selectedItem != null)
                {
                    CustomerName = SelectedItem.Deal.CustomerName;
                    PhoneNumber = SelectedItem.Deal.PhoneNumber;
                    CustomerAddress = SelectedItem.Deal.CustomerAddress;
                    PayDate = (DateTime)SelectedItem.Deal.PayDate;
                    ProductName = SelectedItem.ProductName;
                    Quantity = SelectedItem.Deal.Quantity;
                    IsSale = SelectedItem.IsSale;
                    SalePercent = SelectedItem.Deal.SalePercent * 100;
                    SaleEvent = SelectedItem.Deal.SaleEvent;

                }
            }
        }

        //Binding cho CustomerName
        private string customerName;
        public string CustomerName { get { return customerName; } set { customerName = value; OnPropertyChanged(); } }

        //Binding cho PhoneNumber
        private string phoneNumber;
        public string PhoneNumber { get { return phoneNumber; } set { phoneNumber = value; OnPropertyChanged(); } }

        //Binding cho CustomerAddress
        private string customerAddress;
        public string CustomerAddress { get { return customerAddress; } set { customerAddress = value; OnPropertyChanged(); } }

        //Binding cho PayDate
        private DateTime payDate = DateTime.Now;
        public DateTime PayDate { get { return payDate; } set { payDate = value; OnPropertyChanged(); } }


        //Binding cho ProductName
        private string productName;
        public string ProductName { get { return productName; } set { productName = value; OnPropertyChanged(); } }

        //Binding cho Quantity
        private int? quantity = null;
        public int? Quantity { get { return quantity; } set { quantity = value; OnPropertyChanged(); } }

        //Binding cho checkbox IsSale
        private bool isSale;
        public bool IsSale { get { return isSale; } set { isSale = value; OnPropertyChanged(); } } 

        //Binding cho SalePercent
        private double? salePercent = 0;
        public double? SalePercent { get { return salePercent; } set { salePercent = value; OnPropertyChanged(); } }


        //Binding cho SaleEvent
        private string saleEvent;
        public string SaleEvent { get { return saleEvent; } set { saleEvent = value; OnPropertyChanged(); } }

        public TransactionViewModel()
        {
            LoadTransactionData();

            //Khởi tạo AddCommand
            AddCommand = new RelayCommand<object>((p) =>
            {
                //Kiểm tra sự tồn tại trong database
                var displayList = DataProvider.Ins.DB.DEALs.Where(x => x.CustomerName == CustomerName && x.IsDeleted == false);
                if (displayList == null || SalePercent < 0 || Quantity <= 0)
                {
                    return false;
                }

                return true;
            }, (p) =>
            {
                //Add deal vào db
                var deal = new DEAL() { CustomerName = CustomerName, PhoneNumber = PhoneNumber, CustomerAddress = CustomerAddress, PayDate = PayDate, ProductID = getIDProduct(ProductName), Quantity = (int)Quantity, IsDeleted = false };
                
                if (deal.ProductID == -1) //Ktra sản phẩn có tồn tại trong db không
                {
                    MessageBox.Show("Không tồn tại sản phẩm " + ProductName + " trong kho", "Lỗi");
                    return;
                }

                //Tính thành tiền
                if (IsSale == true)
                {
                    deal.SalePercent = SalePercent / 100;
                    deal.SaleEvent = SaleEvent;
                    deal.DisplayPrice = CalcDisplayPrice(DataProvider.Ins.DB.PRODUCTs.Find(deal.ProductID).RetailPrice, Convert.ToDouble(deal.SalePercent)) * deal.Quantity;
                }
                else
                {
                    deal.DisplayPrice = DataProvider.Ins.DB.PRODUCTs.Find(deal.ProductID).RetailPrice * deal.Quantity;
                }

                DataProvider.Ins.DB.DEALs.Add(deal);

                //Update lại số lượng trong product
                var product = DataProvider.Ins.DB.PRODUCTs.Find(deal.ProductID);
                if (deal.Quantity > product.Quantity) //Kiểm tra đầu vào
                {
                    MessageBox.Show("Số lượng sản phẩm vượt quá số lượng tồn kho", "Lỗi");
                    return;
                }

                product.Quantity -= (int)Quantity;
                //Update lại số lượng trong category
                var category = DataProvider.Ins.DB.CATEGORies.Find(deal.PRODUCT.CatID);
                category.Quantity -= (int)Quantity;

                DataProvider.Ins.DB.SaveChanges();

                //Add vào TransactionDataList để update lại danh sách hiển thị lên màn hình
                TransactionData transactionData = new TransactionData();
                transactionData.NumercialOrder = TransactionDataList.Count() + 1;
                transactionData.IsSale = IsSale;
                transactionData.ProductName = deal.PRODUCT.DisplayName;
                transactionData.Deal = deal;

                TransactionDataList.Add(transactionData);
            });

            //Khởi tạo UpdateCommand
            UpdateCommand = new RelayCommand<object>((p) =>
            {
                //Kiểm tra đầu vào
                if (SalePercent < 0 || Quantity <= 0)
                {
                    return false;
                }

                return true;
            }, (p) =>
            {
                var displayList = DataProvider.Ins.DB.PRODUCTs.Where(x => x.DisplayName == ProductName && x.IsDeleted == false);
                if (displayList == null || displayList.Count() == 0)
                {
                    MessageBox.Show("Không tồn tại sản phẩm " + ProductName + " trong kho", "Lỗi");
                    return;
                }
                //Cập nhật lại deal
                var deal = DataProvider.Ins.DB.DEALs.Find(SelectedItem.Deal.ID);

                //Cập nhật lại số lượng trong category
                //Nếu vẫn giữ nguyên loại sản phẩm đó
                var product = DataProvider.Ins.DB.PRODUCTs.Find(getIDProduct(ProductName));
                if (deal.PRODUCT.CatID == product.CatID)
                {
                    var category = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                    category.Quantity = category.Quantity + deal.Quantity - (int)Quantity;

                    if (category.Quantity < 0)
                    {
                        MessageBox.Show("Số lượng giao dịch lớn hơn số lượng tồn kho", "Lỗi");
                        return;
                    }
                }
                else // Nếu đổi sang loại khác thì
                {
                    //Tăng số lượng ở loại cũ
                    var oldCategory = DataProvider.Ins.DB.CATEGORies.Find(deal.PRODUCT.CatID);
                    oldCategory.Quantity += deal.Quantity;

                    //Giảm số lượng ở loại mới
                    //deal.PRODUCT.CatID = product.CatID;
                    var newCategory = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                    newCategory.Quantity -= (int)Quantity;

                    if (newCategory.Quantity < 0)
                    {
                        MessageBox.Show("Số lượng giao dịch lớn hơn số lượng tồn kho", "Lỗi");
                        return;
                    }
                }

                deal.CustomerName = CustomerName;
                deal.PhoneNumber = PhoneNumber;
                deal.CustomerAddress = CustomerAddress;
                deal.PayDate = PayDate;
                if (IsSale == true)
                {
                    deal.SalePercent = SalePercent;
                    deal.SaleEvent = SaleEvent;
                }
                else
                {
                    deal.SalePercent = null;
                    deal.SaleEvent = null;
                }

                //Cập nhật lại số lượng product
                //Nếu vẫn giữ nguyên tên sản phẩm đó
                if (deal.PRODUCT.DisplayName == product.DisplayName)
                {
                    //Cập nhật số lượng sản phẩm đó
                    product.Quantity = product.Quantity + deal.Quantity - (int)Quantity;
       
                }
                else //Nếu đổi sang sản phẩm khác
                {
                    //Tăng số lượng sản phẩm cũ
                    var oldProduct = DataProvider.Ins.DB.PRODUCTs.Find(deal.ProductID);
                    oldProduct.Quantity += deal.Quantity;

                    //Giảm số lượng sản phẩm mới
                    product.Quantity -= (int)Quantity;
                    deal.ProductID = product.ID;
                }

                if (product.Quantity < 0)
                {
                    MessageBox.Show("Số lượng giao dịch lớn hơn số lượng tồn kho", "Lỗi");
                    return;
                }

                //Cập nhật số lượng trong deal
                deal.Quantity = (int)Quantity;

                //Cập nhật thành tiền
                if (IsSale == true)
                {
                    deal.SalePercent = SalePercent / 100;
                    deal.SaleEvent = SaleEvent;
                    deal.DisplayPrice = CalcDisplayPrice(product.RetailPrice, Convert.ToDouble(deal.SalePercent)) * deal.Quantity;
                }
                else
                {
                    deal.DisplayPrice = product.RetailPrice * deal.Quantity;
                }

                DataProvider.Ins.DB.SaveChanges();
                //Cập nhật lại TransactionDataList
                var transactionData = TransactionDataList.ToList().Find(x => x.Deal.ID == deal.ID);
                transactionData.ProductName = deal.PRODUCT.DisplayName;
                transactionData.IsSale = IsSale;
                transactionData.Deal = deal;
            });

            //Khởi tạo WatchCommand
            WatchCommand = new RelayCommand<object>((p) =>
            {
                if (string.IsNullOrEmpty(CustomerName))
                {
                    return false;
                }
                return true;
            }, (p) =>
            {
                var deal = DataProvider.Ins.DB.DEALs.Find(SelectedItem.Deal.ID);

                string retailPrice = getMoney(deal.PRODUCT.RetailPrice) + " VNĐ";
                string displayPrice = getMoney(deal.DisplayPrice) + "VNĐ";

                MessageBox.Show("Tên khách hàng: " + deal.CustomerName + "\n" + "ID: " + deal.ID + "\n" + "Số điện thoại: " + deal.PhoneNumber + "\n" + "Địa chỉ: " + deal.CustomerAddress + "\n" + "Ngày thanh toán: " + Convert.ToDateTime(deal.PayDate).Date.ToShortDateString() + "\n" 
                   + "Tên sản phẩm: " + deal.PRODUCT.DisplayName + "\n" + "Loại sản phẩm: " + deal.PRODUCT.CATEGORY.DisplayName + "\n" + "Giá gốc: " + retailPrice + "\n" + "Số lượng: " + deal.Quantity + "\n"
                   + "Giảm: " + Convert.ToDouble(deal.SalePercent) * 100 + " %" + "\n" + "Nhân dịp: " + deal.SaleEvent + "\n" + "Thành tiền: " + displayPrice, "Thông tin chi tiết");
            });

            //Khởi tạo DeleteCommand
            DeleteCommand = new RelayCommand<object>((p) =>
            {
                if (string.IsNullOrEmpty(CustomerName))
                {
                    return false;
                }
                return true;
            }, (p) =>
            {
                var deal = DataProvider.Ins.DB.DEALs.Find(SelectedItem.Deal.ID);
                var product = DataProvider.Ins.DB.PRODUCTs.Find(deal.ProductID);
                var category = DataProvider.Ins.DB.CATEGORies.Find(deal.PRODUCT.CatID);

                //Đánh dấu là đã bị xóa trong db
                deal.IsDeleted = true;

                //Tăng số lượng trong category
                category.Quantity += deal.Quantity;

                //Tăng số lượng trong product
                product.Quantity +=  deal.Quantity;

                //Xóa trong TransactionDataList
                int index = TransactionDataList.ToList().FindIndex(x => x.Deal.ID == SelectedItem.Deal.ID);

                for (int i = index + 1; i < TransactionDataList.Count; i++)
                {
                    TransactionDataList[i].NumercialOrder -= 1; //Giảm số thứ tự
                }

                TransactionDataList.RemoveAt(index);

                DataProvider.Ins.DB.SaveChanges();
            }
            );

        }

        void LoadTransactionData()
        {
            TransactionDataList = new ObservableCollection<TransactionData>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(p => p.IsDeleted == false);

            int i = 1;
       
            foreach (var deal in DealList)
            {
                TransactionData transactionData = new TransactionData();
                transactionData.NumercialOrder = i;
                transactionData.Deal = deal;
                transactionData.ProductName = deal.PRODUCT.DisplayName;
                if (deal.SalePercent == null)
                    transactionData.IsSale = false;
                else
                    transactionData.IsSale = true;

                TransactionDataList.Add(transactionData);
                i++;
            }
        }

        int getIDProduct(string _productName)
        {
            var product = DataProvider.Ins.DB.PRODUCTs.Where(p => p.DisplayName == _productName && p.IsDeleted == false);
            if (product == null || product.Count() == 0)
            {
                return -1;
            }
            else
                return product.First().ID;
        }

        int CalcDisplayPrice(int _retailPrice, double _salePercent)
        {
            double displayPrice = _retailPrice * (1 - _salePercent);
            return (int)Math.Round(displayPrice);
        }

        int getIDCat(string _catName)
        {
            if (_catName == "Áo")
                return 1;
            else if (_catName == "Quần")
                return 2;
            else
                return 3;
        }

        string getMoney(int money)
        {
            string moneyString = "";

            while (money > 0)
            {
                moneyString = (money % 10).ToString() + moneyString;
                money /= 10;

                if ((moneyString.Count() - moneyString.Count(p => p.ToString() == ",")) % 3 == 0 && money > 0)
                    moneyString = "," + moneyString;
            }
            return moneyString;
        }

    }
}
