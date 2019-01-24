using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagementSystem.ViewModel;

namespace ManagementSystem.Model
{
    public class MasterData : BaseViewModel
    {
        private PRODUCT product;
        public PRODUCT Product { get { return product; } set { product = value; OnPropertyChanged(); } }

        private int numercialOrder;
        public int NumercialOrder { get { return numercialOrder; } set { numercialOrder = value; OnPropertyChanged(); } } //Số thứ tự khi hiển thị ra 1 list

        private string catName;
        public string CatName { get { return catName; } set { catName = value; OnPropertyChanged(); } } 
    }

}
