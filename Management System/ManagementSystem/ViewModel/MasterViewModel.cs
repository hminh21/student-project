using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using ManagementSystem.Model;
using System.Windows.Input;
using System.Windows;
using OfficeOpenXml;
using System.IO;


namespace ManagementSystem.ViewModel
{
    public class MasterViewModel : BaseViewModel
    {
         //Dùng lớp ObservableCollection vì nó kế thừa INotifyPropertyChanged nên ta có thể binding
        private ObservableCollection<MasterData> masterDataList;
        public ObservableCollection<MasterData> MasterDataList { get { return masterDataList; } set { masterDataList = value; OnPropertyChanged(); } }

        //COMMAND
        public ICommand AddCommand { get; set; }
        public ICommand UpdateCommand { get; set; }
        public ICommand WatchCommand { get; set; }
        public ICommand DeleteCommand { get; set; }
        public ICommand ImportCommand { get; set; }

        //Binding cho SelectedItem
        private MasterData selectedItem;
        public MasterData SelectedItem { 
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
                    DisplayName = SelectedItem.Product.DisplayName;
                    CatName = SelectedItem.CatName;
                    RetailPrice = SelectedItem.Product.RetailPrice;
                    Quantity = SelectedItem.Product.Quantity;

                }
            } 
        }

        //Binding cho DisplayName
        private string displayName;
        public string DisplayName { get { return displayName; } set { displayName = value; OnPropertyChanged(); } }

        //Binding cho CatName
        private string catName;
        public string CatName { get { return catName; } set { catName = value; OnPropertyChanged(); } }

        //Binding cho RetailPrice
        private int? retailPrice;
        public int? RetailPrice { get { return retailPrice; } set { retailPrice = value; OnPropertyChanged(); } }

        //Binding cho Quantity
        private int? quantity = null;
        public int? Quantity { get { return quantity; } set { quantity = value; OnPropertyChanged(); } }


        public MasterViewModel()
        {
            LoadMasterData();
            
            //Khởi tạo AddCommand
            AddCommand = new RelayCommand<object>((p) =>
            {
                //Kiểm tra sự tồn tại trong database
                var displayList = DataProvider.Ins.DB.PRODUCTs.Where(x => x.DisplayName == DisplayName && x.IsDeleted == false);
                if (displayList == null || displayList.Count() > 0 || RetailPrice <= 0 || Quantity <= 0)
                {
                    return false;
                }

                return true;
            }, (p) => 
            {
                //Add product vào db
                var product = new PRODUCT() { DisplayName = DisplayName, CatID = getIDCat(CatName), RetailPrice = (int)RetailPrice, Quantity = (int)Quantity, IsDeleted = false };
                DataProvider.Ins.DB.PRODUCTs.Add(product);
                //Update lại số lượng trong category
                var category = DataProvider.Ins.DB.CATEGORies.Find(getIDCat(CatName));
                category.Quantity += (int)Quantity;

                DataProvider.Ins.DB.SaveChanges();

                //Add vào MasterDataList để update lại danh sách hiển thị lên màn hình
                MasterData masterData = new MasterData();
                masterData.NumercialOrder = MasterDataList.Count() + 1;
                masterData.CatName = product.CATEGORY.DisplayName;
                masterData.Product = product;

                MasterDataList.Add(masterData);
            });

            //Khởi tạo UpdateCommand
            UpdateCommand = new RelayCommand<object>((p) =>
            {
                //Kiểm tra sự tồn tại trong database
                var displayList = DataProvider.Ins.DB.PRODUCTs.Where(x => x.DisplayName == DisplayName && x.IsDeleted == false);
                if (displayList == null || RetailPrice <= 0 || Quantity <= 0)
                {
                    return false;
                }

                return true;
            }, (p) =>
            {
                //Kiểm tra xem có cập nhật trùng tên product khác đã có trong db
                var conflictProduct = DataProvider.Ins.DB.PRODUCTs.Where(x => x.DisplayName == DisplayName && x.ID != SelectedItem.Product.ID && x.IsDeleted == false);

                 if(conflictProduct.Count() > 0)
                {
                    MessageBox.Show(conflictProduct.First().DisplayName + " đã có trong danh sách","Lỗi không thể cập nhật sản phẩm");
                    return;
                }
                //Cập nhật lại product
                var product = DataProvider.Ins.DB.PRODUCTs.Find(SelectedItem.Product.ID);

                //Cập nhật lại số lượng trong category
                //Nếu vẫn giữ nguyên loại sản phẩm đó
                if (product.CatID == getIDCat(catName))
                {
                    var category = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                    category.Quantity = category.Quantity - product.Quantity + (int)Quantity;
                }
                else // Nếu đổi sang loại khác thì
                {
                    //Giảm số lượng ở loại cũ
                    var oldCategory = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                    oldCategory.Quantity -= (int)Quantity;

                    //Tăng số lượng ở loại mới
                    product.CatID = getIDCat(catName);
                    var newCategory = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                    newCategory.Quantity += (int)Quantity;
                }

                product.DisplayName = DisplayName;
                product.RetailPrice = (int)RetailPrice;
                
             
                //Cập nhật lại số lượng product
                product.Quantity = (int)Quantity;

                //Cập nhật lại MasterDataList
                var masterData = MasterDataList.ToList().Find(x => x.Product.ID == product.ID);
                masterData.CatName = product.CATEGORY.DisplayName;
                masterData.Product = product;

                DataProvider.Ins.DB.SaveChanges();
            });

            //Khởi tạo WatchCommand
            WatchCommand = new RelayCommand<object>((p) => 
            {
              if (string.IsNullOrEmpty(DisplayName))
              {
                  return false;
              }
              return true;
            }, (p) =>
            {
                var product = DataProvider.Ins.DB.PRODUCTs.Find(SelectedItem.Product.ID);

                string moneyString = getMoney(product.RetailPrice) + " VNĐ";

                MessageBox.Show("Tên sản phẩm: " + product.DisplayName + "\n" + "ID: " + product.ID + "\n" + "Loại sản phẩm: " + product.CATEGORY.DisplayName + "\n"
                + "Số lượng tồn kho: " + product.Quantity + "\n" + "Giá sản phẩm: " + moneyString, "Thông tin chi tiết");
            });

            //Khởi tạo DeleteCommand
            DeleteCommand = new RelayCommand<object>((p) => 
            { 
                if (string.IsNullOrEmpty(DisplayName))
                {
                    return false;
                }
                return true; 
            }, (p) =>
            {
                var product = DataProvider.Ins.DB.PRODUCTs.Find(SelectedItem.Product.ID);
                var category = DataProvider.Ins.DB.CATEGORies.Find(SelectedItem.Product.CatID);

                //Đánh dấu là đã bị xóa trong db
                product.IsDeleted = true;

                //Giảm số lượng trong category
                category.Quantity -= product.Quantity;

                //Xóa trong MasterDataList
                int index = MasterDataList.ToList().FindIndex(x => x.Product.ID == SelectedItem.Product.ID);

                for (int i = index + 1; i < MasterDataList.Count; i++ )
                {
                    MasterDataList[i].NumercialOrder -= 1; //Giảm số thứ tự
                }

                MasterDataList.RemoveAt(index);

                DataProvider.Ins.DB.SaveChanges();
            }
            );

            //Khởi tạo ImportCommand
            ImportCommand = new RelayCommand<object>((p) => { return true; }, (p) => 
            {
                var dlg = new Microsoft.Win32.OpenFileDialog();

                dlg.DefaultExt = ".xlsx";
                dlg.Filter = "Excel Files(.xlsx)|*.xlsx|Excel Files(.xls)|*.xls|Excel Files(*.xlsm)|*.xlsm";

                // Hiển thị dialog và trả về kết quả
                Nullable<bool> result = dlg.ShowDialog();

                //Kiểm tra kết quả
                if (result == true)
                {
                    //open
                    var package = new ExcelPackage(new FileInfo(dlg.FileName));

                    //go to sheet
                    ExcelWorksheet workSheet = package.Workbook.Worksheets[1];

                    for (int i = workSheet.Dimension.Start.Row + 1; i <= workSheet.Dimension.End.Row; i++)
                    {
                        try
                        {
                            int j = 1; //columnn trong file
                            

                            //Lấy tên sản phẩm
                            //data.Product.DisplayName = workSheet.Cells[i, j++].Value.ToString();
                            string displayname = workSheet.Cells[i, j++].Value.ToString();

                            //Lấy loại sản phẩm
                            string catname = workSheet.Cells[i, j++].Value.ToString();
                            if (catname != "Áo" && catname != "Quần" && catname != "Giày")
                            {
                                MessageBox.Show("Loại sản phẩm chỉ có thể là Áo, Quần hoặc Giày", "Lỗi đọc file");
                                return;
                            }
                            int catID = getIDCat(catname);

                            //Lấy giá gốc
                            var RetailPriceTemp = workSheet.Cells[i, j++].Value;
                            int retailprice, _quantity;
                            if (RetailPriceTemp != null)
                            {
                               retailprice = Convert.ToInt32(RetailPriceTemp);
                            }
                            else
                            {
                                MessageBox.Show("Dữ liệu giá gốc NULL", "Lỗi đọc file");
                                return;
                            }

                            //Lấy số lượng
                            var QuantityTemp = workSheet.Cells[i, j++].Value;
                            if (QuantityTemp != null)
                            {
                                _quantity = Convert.ToInt32(QuantityTemp);
                            }
                            else 
                            {
                                MessageBox.Show("Dữ liệu số lượng NUL", "Lỗi đọc file");
                                return;
                            }

                            //Kiểm tra xem product đó đã tồn tại trong database không
                            var displayList = DataProvider.Ins.DB.PRODUCTs.Where(x => x.DisplayName == displayname && x.IsDeleted == false);
                            if (displayList == null || displayList.Count() > 0)
                            {
                                MessageBox.Show(displayname + " đã tồn tại trong database", "Lỗi nhập dữ liệu");
                                return;
                            }

                            var product = new PRODUCT() { DisplayName = displayname, CatID = catID, RetailPrice = retailprice, Quantity = _quantity, IsDeleted = false };
                            DataProvider.Ins.DB.PRODUCTs.Add(product);
                            //Update lại số lượng trong category
                            var category = DataProvider.Ins.DB.CATEGORies.Find(product.CatID);
                            category.Quantity += _quantity;

                            var masterData = new MasterData();
                            masterData.NumercialOrder = MasterDataList.Count() + 1;
                            masterData.CatName = product.CATEGORY.DisplayName;
                            masterData.Product = product;
                            //Add vào MasterDataList
                            MasterDataList.Add(masterData);


                            DataProvider.Ins.DB.SaveChanges();
                        }
                        catch
                        {
                            MessageBox.Show("File chưa đóng", "Lỗi");
                            return;
                        }

                    }
                }
            }
            );
        }


        void LoadMasterData()
        {
            MasterDataList = new ObservableCollection<MasterData>();
          
            var ProductList = DataProvider.Ins.DB.PRODUCTs.Where(p=>p.IsDeleted == false);

            int i = 1;

            foreach (var product in ProductList)
            {
                MasterData masterData = new MasterData();
                masterData.NumercialOrder = i;
                masterData.Product = product;
                masterData.CatName = product.CATEGORY.DisplayName;

                MasterDataList.Add(masterData);
                i++;
            }
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
