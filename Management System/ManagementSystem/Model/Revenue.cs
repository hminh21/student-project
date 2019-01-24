using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.ViewModel;
using System.Collections.ObjectModel;
namespace ManagementSystem.Model
{
    public class Revenue : BaseViewModel
    {
        //Cả ngày, tháng, năm
        private DateTime payDate;
        public DateTime PayDate { get { return payDate; } set { payDate = value; OnPropertyChanged(); } }

        //Có thể là ngày hoặc tháng hoặc năm
        private int time;
        public int Time { get { return time; } set { time = value; OnPropertyChanged(); } }

        private int sumPrice;
        public int SumPrice { get { return sumPrice; } set { sumPrice = value; OnPropertyChanged(); } }

        private string productName;
        public string ProductName { get { return productName; } set { productName = value; OnPropertyChanged(); } }

        private int sumQuantity;
        public int SumQuantity { get { return sumQuantity; } set { sumQuantity = value; OnPropertyChanged(); } }
    }
}
