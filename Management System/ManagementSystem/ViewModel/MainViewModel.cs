using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Collections.ObjectModel;
namespace ManagementSystem.ViewModel
{
    public class MainViewModel : BaseViewModel
    {
        public bool isLoaded = false;
        public ICommand LoadedWindowCommand { get; set; }
        public ICommand MasterCommand { get; set; }
        public ICommand TransactionCommand { get; set; }
        public ICommand ReportCommand { get; set; }
        //public ICommand ReportCommand { get; set; }

        //xử lí
       public MainViewModel()
        {
            LoadedWindowCommand = new RelayCommand<Window>((p) => { return true; }, (p) =>
            {
                isLoaded = true;
                p.Hide(); //Ẩn màn hình menu
                //Đăng nhập 
                LoginWindow loginWindow = new LoginWindow(); 
                loginWindow.ShowDialog();

                var loginVM = loginWindow.DataContext as LoginViewModel; //Lấy data context từ static resource LoginVM ngoài LoginWindow.xaml

                //loginWindow là màn hình login, còn loginVM là dữ liệu của màn hình đó
                if (loginVM.isLogin) //Login được mới hiện menu
                {
                    p.Show();
                }
                else
                {
                    p.Close();
                }
            }
                );
          

                MasterCommand = new RelayCommand<object>((p) => { return true; }, (p) => { MasterWindow wd = new MasterWindow(); wd.ShowDialog(); });
                TransactionCommand = new RelayCommand<object>((p) => { return true; }, (p) => { TransactionWindow wd = new TransactionWindow(); wd.ShowDialog(); });
                ReportCommand = new RelayCommand<object>((p) => { return true; }, (p) => { ReportWindow wd = new ReportWindow(); wd.ShowDialog(); }); 
        }
    }
}
