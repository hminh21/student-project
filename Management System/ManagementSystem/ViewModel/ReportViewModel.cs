using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.Model;
using System.Collections.ObjectModel;
using System.Windows.Input;
using DevExpress.Xpf.Core;
using System.Globalization;
using System.Windows.Forms;

namespace ManagementSystem.ViewModel
{
    class sumArray
    {
        public DateTime detailDate { get; set; }
        public int date {get; set;}
        public int sumPrice { get; set; }

        public string productName { get; set; }
        public int sumQuantity { get; set; }
    }

    public class ReportViewModel : BaseViewModel
    {
        private ReportData reportDataList;
        public ReportData ReportDataList { get { return reportDataList; } set { reportDataList = value; OnPropertyChanged(); } }

        private int time;
        public int Time { get { return time; } set { time = value; OnPropertyChanged(); } }

        private ReportData2 reportDataList2;
        public ReportData2 ReportDataList2 { get { return reportDataList2; } set { reportDataList2 = value; OnPropertyChanged(); } }


        //  Tab khoảng thời gian
        private ObservableCollection<int> yearTime;
        public ObservableCollection<int> YearTime { get { return yearTime; } set { yearTime = value; OnPropertyChanged(); } }

        private DateTime beginTime = DateTime.Now;
        public DateTime BeginTime { get { return beginTime; } set { beginTime = value; OnPropertyChanged(); } }

        private DateTime endTime = DateTime.Now;
        public DateTime EndTime { get { return endTime; } set { endTime = value; OnPropertyChanged(); } }

        public ICommand AnalyzeCommand { get; set; }

        public ReportViewModel()
        {
            //Load tab Tồn kho
            LoadReportDataList();

           AnalyzeCommand = new RelayCommand<DXTabItem>((p) => { return true; }, 
               (p) => 
               {
                   if (p.Name == "Day")
                   {
                       LoadDealDay(Time);
                   }
                   else if (p.Name == "Week")
                   {               
                       //Tìm ngày đầu và ngày cuối của tuần hiện tại
                       int weekNow = GetWeekOfYear(DateTime.Now);
                       DateTime firstDayOfWeekNow = FirstDateOfWeek(DateTime.Now.Year, weekNow, CultureInfo.CurrentCulture); 
                       DateTime lastDayOfWeekNow = firstDayOfWeekNow.AddDays(6);

                       //Từ đó suy ra ngày đầu và ngày cuối của tuần người dùng nhập
                       DateTime firstDayOfWeekChoose;
                       if (firstDayOfWeekNow.Month >= DateTime.Now.Month)
                       {
                           firstDayOfWeekChoose = firstDayOfWeekNow.AddDays((time - GetWeekNumberOfMonth(firstDayOfWeekNow)) * 7);
                       }
                       else
                       {
                           firstDayOfWeekChoose = lastDayOfWeekNow.AddDays((time - GetWeekNumberOfMonth(lastDayOfWeekNow)) * 7 + 1);
                       }

                       if (time == 5 && firstDayOfWeekChoose.Month > DateTime.Now.Month)
                       {
                           MessageBox.Show("Tháng này không có tuần thứ 5", "Lỗi");
                           return;
                       }

                       DateTime lastDayOfWeekChoose = firstDayOfWeekChoose.AddDays(6);

                       LoadDealWeek(firstDayOfWeekChoose, lastDayOfWeekChoose);
                   
                       
                   }
                   else if (p.Name == "Month")
                   {
                       LoadDealMonth(time);
                   }
                   else if (p.Name == "Quarter")
                   {
                       LoadDealQuarter(time);
                   }
                   else if (p.Name == "Year")
                   {
                       LoadDealYear(time);
                   }
                   else
                   {
                       LoadDealPeriodTime(BeginTime, EndTime);
                   }
               });
        }


        void LoadReportDataList()
        {

            ReportDataList = new ReportData();
            ReportDataList2 = new ReportData2();
           
            LoadCategoryList();
            LoadProductList();

            //Load 5 năm từ nay trở về trước vào combobox
            YearTime = new ObservableCollection<int>();
            int year = DateTime.Now.Year;
            for (int i = 0; i < 5; i++)
            {
                YearTime.Add(year);
                year--;
            }
        }

        void LoadCategoryList()
        {
            ReportDataList.CategoryList = new ObservableCollection<CATEGORY>();

            var CategoryList = DataProvider.Ins.DB.CATEGORies.Where(x => true);

            foreach (var category in CategoryList)
            {
                ReportDataList.CategoryList.Add(category);
            }
        }

        void LoadProductList()
        {
            ReportDataList.ShirtList = new ObservableCollection<PRODUCT>();
            ReportDataList.PantsList = new ObservableCollection<PRODUCT>();
            ReportDataList.ShoesList = new ObservableCollection<PRODUCT>();

            var ProductList = DataProvider.Ins.DB.PRODUCTs.Where(x => x.IsDeleted == false);

            foreach (var product in ProductList)
            {
                if (product.CatID == 1)
                {
                    ReportDataList.ShirtList.Add(product);
                }
                else if (product.CatID == 2)
                {
                    ReportDataList.PantsList.Add(product);
                }
                else
                {
                    ReportDataList.ShoesList.Add(product);
                }
            }
        }

        private int GetWeekNumberOfMonth(DateTime date) //Nguồn tự liệu tham khảo: https://stackoverflow.com/questions/2136487/calculate-week-of-month-in-net/2136549#2136549
        {
            DateTime tempdate = date.AddDays(-date.Day + 1);
            CultureInfo ciCurr = CultureInfo.CurrentCulture;
            int weekNumStart = ciCurr.Calendar.GetWeekOfYear(tempdate, CalendarWeekRule.FirstFourDayWeek, ciCurr.DateTimeFormat.FirstDayOfWeek);
            int weekNum = ciCurr.Calendar.GetWeekOfYear(date, CalendarWeekRule.FirstFourDayWeek, ciCurr.DateTimeFormat.FirstDayOfWeek);
            return weekNum - weekNumStart + 1;
        }

        static int GetWeekOfYear(DateTime time) //Nguồn tư liệu tham khảo: https://stackoverflow.com/questions/19901666/get-date-of-first-and-last-day-of-week-knowing-week-number
        {
            DayOfWeek day = CultureInfo.CurrentCulture.Calendar.GetDayOfWeek(time);
            if (day >= DayOfWeek.Monday && day <= DayOfWeek.Wednesday)
            {
                time = time.AddDays(3);
            }

            return CultureInfo.CurrentCulture.Calendar.GetWeekOfYear(time, CalendarWeekRule.FirstFourDayWeek, DayOfWeek.Monday);
        }

        public static DateTime FirstDateOfWeek(int year, int weekOfYear, System.Globalization.CultureInfo ci) //Nguồn tư liệu tham khảo: https://stackoverflow.com/questions/19901666/get-date-of-first-and-last-day-of-week-knowing-week-number
        {
            DateTime jan1 = new DateTime(year, 1, 1);
            int daysOffset = (int)ci.DateTimeFormat.FirstDayOfWeek - (int)jan1.DayOfWeek;
            DateTime firstWeekDay = jan1.AddDays(daysOffset);
            int firstWeek = ci.Calendar.GetWeekOfYear(jan1, ci.DateTimeFormat.CalendarWeekRule, ci.DateTimeFormat.FirstDayOfWeek);
            if ((firstWeek <= 1 || firstWeek >= 52) && daysOffset >= -3)
            {
                weekOfYear -= 1;
            }
            return firstWeekDay.AddDays(weekOfYear * 7);
        }

        void LoadDealDay(int day)
        {
            ReportDataList.DealDay = new ObservableCollection<Revenue>();
            ReportDataList2.DealDay = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate.Value.Day == day && x.PayDate.Value.Month == DateTime.Now.Month && x.PayDate.Value.Year == DateTime.Now.Year);

            foreach (var deal in DealList)
            {
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Day, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.date = deal.PayDate.Value.Day;
                    element.sumPrice = deal.DisplayPrice;

                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }

            foreach (var element in SumArrayQuantity)
            {
                var revenue = new Revenue();
                revenue.ProductName = element.productName;
                revenue.SumQuantity = element.sumQuantity;

                ReportDataList.DealDay.Add(revenue); //Load vào biểu đố số lượng
            }


            foreach (var element in SumArrayPrice)
            {
                var revenue = new Revenue();
                revenue.Time = element.date;
                revenue.SumPrice = element.sumPrice;

                ReportDataList2.DealDay.Add(revenue); //Load vào biểu đố doanh thu
            }
        }

        void LoadDealWeek(DateTime beginDay, DateTime endDay)
        {
            ReportDataList.DealWeek = new ObservableCollection<Revenue>();
            ReportDataList2.DealWeek = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate >= beginDay && x.PayDate <= endDay);

           foreach (var deal in DealList)
            {            
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Day, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.date = deal.PayDate.Value.Day;
                    element.sumPrice = deal.DisplayPrice;
                    
                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }

            foreach (var element in SumArrayQuantity)
            {
                var revenue = new Revenue();
                revenue.ProductName = element.productName;
                revenue.SumQuantity = element.sumQuantity;

                ReportDataList.DealWeek.Add(revenue); //Load vào biểu đố số lượng
            }


            foreach (var element in SumArrayPrice)
            {
                var revenue = new Revenue();
                revenue.Time = element.date;
                revenue.SumPrice = element.sumPrice;

                ReportDataList2.DealWeek.Add(revenue); //Load vào biểu đố doanh thu
            }

        }

        void LoadDealMonth(int month)
        {
            ReportDataList.DealMonth = new ObservableCollection<Revenue>();
            ReportDataList2.DealMonth = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate.Value.Month == month && x.PayDate.Value.Year == DateTime.Now.Year);

            foreach (var deal in DealList)
            {
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Day, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.date = deal.PayDate.Value.Day;
                    element.sumPrice = deal.DisplayPrice;

                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }
                foreach (var element in SumArrayQuantity)
                {
                    var revenue = new Revenue();
                    revenue.ProductName = element.productName;
                    revenue.SumQuantity = element.sumQuantity;

                    ReportDataList.DealMonth.Add(revenue); //Load vào biểu đố số lượng
                }


                foreach (var element in SumArrayPrice)
                {
                    var revenue = new Revenue();
                    revenue.Time = element.date;
                    revenue.SumPrice = element.sumPrice;

                    ReportDataList2.DealMonth.Add(revenue); //Load vào biểu đố doanh thu
                }
        }

        void LoadDealQuarter(int quarter)
        {
            //quarter = 1 => Quý 1: Tháng 1 -> 3
            //quarter = 2 => Quý 1: Tháng 4 -> 6
            //quarter = 3 => Quý 1: Tháng 7 -> 9
            //quarter = 4 => Quý 1: Tháng 10 -> 12

            ReportDataList.DealQuarter = new ObservableCollection<Revenue>();
            ReportDataList2.DealQuarter = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate.Value.Year == DateTime.Now.Year && (x.PayDate.Value.Month + 2) / 3 == quarter);

            foreach (var deal in DealList)
            {            
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Month, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.date = deal.PayDate.Value.Month;
                    element.sumPrice = deal.DisplayPrice;
                    
                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }

            foreach (var element in SumArrayQuantity)
            {
                var revenue = new Revenue();
                revenue.ProductName = element.productName;
                revenue.SumQuantity = element.sumQuantity;

                ReportDataList.DealQuarter.Add(revenue); //Load vào biểu đố số lượng
            }


            foreach (var element in SumArrayPrice)
            {
                var revenue = new Revenue();
                revenue.Time = element.date;
                revenue.SumPrice = element.sumPrice;

                ReportDataList2.DealQuarter.Add(revenue); //Load vào biểu đố doanh thu
            }
        }

        void LoadDealYear(int year)
        {

            ReportDataList.DealYear = new ObservableCollection<Revenue>();
            ReportDataList2.DealYear = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate.Value.Year == year);

            foreach (var deal in DealList)
            {
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Month, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.date = deal.PayDate.Value.Month;
                    element.sumPrice = deal.DisplayPrice;

                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }

            foreach (var element in SumArrayQuantity)
            {
                var revenue = new Revenue();
                revenue.ProductName = element.productName;
                revenue.SumQuantity = element.sumQuantity;

                ReportDataList.DealYear.Add(revenue); //Load vào biểu đố số lượng
            }


            foreach (var element in SumArrayPrice)
            {
                var revenue = new Revenue();
                revenue.Time = element.date;
                revenue.SumPrice = element.sumPrice;

                ReportDataList2.DealYear.Add(revenue); //Load vào biểu đố doanh thu
            }
        }

        void LoadDealPeriodTime(DateTime beginTime, DateTime endTime)
        {
            ReportDataList.DealPeriod = new ObservableCollection<Revenue>();
            ReportDataList2.DealPeriod = new ObservableCollection<Revenue>();

            List<sumArray> SumArrayQuantity = new List<sumArray>();
            List<sumArray> SumArrayPrice = new List<sumArray>();

            var DealList = DataProvider.Ins.DB.DEALs.Where(x => x.IsDeleted == false && x.PayDate >= beginTime && x.PayDate <= endTime);

            foreach (var deal in DealList)
            {
                if (IsExistsDate(SumArrayPrice, deal.PayDate.Value.Day, deal.DisplayPrice) == false)
                {
                    var element = new sumArray();
                    element.detailDate = (DateTime)deal.PayDate;
                    element.sumPrice = deal.DisplayPrice;

                    SumArrayPrice.Add(element);
                }

                if (IsExistsProduct(SumArrayQuantity, deal.PRODUCT.DisplayName, deal.Quantity) == false)
                {
                    var element = new sumArray();
                    element.productName = deal.PRODUCT.DisplayName;
                    element.sumQuantity = deal.Quantity;

                    SumArrayQuantity.Add(element);
                }
            }

            foreach (var element in SumArrayQuantity)
            {
                var revenue = new Revenue();
                revenue.ProductName = element.productName;
                revenue.SumQuantity = element.sumQuantity;

                ReportDataList.DealPeriod.Add(revenue); //Load vào biểu đố số lượng
            }


            foreach (var element in SumArrayPrice)
            {
                var revenue = new Revenue();
                revenue.PayDate = element.detailDate;
                revenue.SumPrice = element.sumPrice;

                ReportDataList2.DealPeriod.Add(revenue); //Load vào biểu đố doanh thu
            }
        }


        bool IsExistsDate(List<sumArray> SumArray, int date, int price)
        {
            for (int i = 0; i < SumArray.Count; i++)
            {
                if (date == SumArray[i].date)
                {
                    SumArray[i].sumPrice += price;
                    return true;
                }
            }
            return false;
        }

        bool IsExistsProduct(List<sumArray> SumArray, string productName, int quantity)
        {
            for (int i = 0; i < SumArray.Count; i++)
            {
                if (productName == SumArray[i].productName)
                {
                    SumArray[i].sumQuantity += quantity;
                    return true;
                }
            }
            return false;
        }
    }
}
