using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.ViewModel;
using System.Collections.ObjectModel;

namespace ManagementSystem.Model
{
    public class ReportData2 : BaseViewModel
    {

        //Tab 2 giao dịch doanh thu
        private ObservableCollection<Revenue> dealDay;
        public ObservableCollection<Revenue> DealDay { get { return dealDay; } set { dealDay = value; OnPropertyChanged(); } }

        private ObservableCollection<Revenue> dealWeek;
        public ObservableCollection<Revenue> DealWeek { get { return dealWeek; } set { dealWeek = value; OnPropertyChanged(); } }

        private ObservableCollection<Revenue> dealMonth;
        public ObservableCollection<Revenue> DealMonth { get { return dealMonth; } set { dealMonth = value; OnPropertyChanged(); } }

        private ObservableCollection<Revenue> dealQuarter;
        public ObservableCollection<Revenue> DealQuarter { get { return dealQuarter; } set { dealQuarter = value; OnPropertyChanged(); } }

        private ObservableCollection<Revenue> dealYear;
        public ObservableCollection<Revenue> DealYear { get { return dealYear; } set { dealYear = value; OnPropertyChanged(); } }

        private ObservableCollection<Revenue> dealPeriod;
        public ObservableCollection<Revenue> DealPeriod { get { return dealPeriod; } set { dealPeriod = value; OnPropertyChanged(); } }
    }
}
