using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.ViewModel;

namespace ManagementSystem.Model
{
    public class TransactionData : BaseViewModel
    {
        private DEAL deal;
        public DEAL Deal { get { return deal; } set { { deal = value; };  OnPropertyChanged();} }

        private int numercialOrder;
        public int NumercialOrder { get { return numercialOrder; } set { numercialOrder = value; OnPropertyChanged(); } } //Số thứ tự khi hiển thị ra 1 list

        private string productName;
        public string ProductName { get { return productName; } set { productName = value; OnPropertyChanged(); } }

        private bool isSale;
        public bool IsSale { get { return isSale; } set { isSale = value; OnPropertyChanged(); } } 
    }
}
