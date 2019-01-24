using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows;
using System.Windows.Controls;

namespace ManagementSystem.ViewModel
{
    public class LoginViewModel : BaseViewModel
    {
        public bool isLogin { get; set; }

        private string username;
        public string Username { get { return username; } set { username = value; OnPropertyChanged(); } } //txtUsername binding vào username này

        private string password;

        public string Password { get { return password; } set { password = value; OnPropertyChanged(); } } //txtPassword binding vào password này
       
        public ICommand LoginCommand { get; set; }
        public ICommand PasswordChangedCommand { get; set; }

        public ICommand CloseCommand { get; set; }

        //xử lí
        public LoginViewModel()
        {
            isLogin = false;
            LoginCommand = new RelayCommand<Window>((p) => { return true; }, (p) => { Login(p); });
            CloseCommand = new RelayCommand<Window>((p) => { return true; }, (p) => { p.Close(); });
            PasswordChangedCommand = new RelayCommand<PasswordBox>((p) => { return true; }, (p) => { Password = p.Password; });

        }

        void Login(Window p)
        {
            if (p == null)
                return;

            if (Username == "admin" && Password == "123")
            {
                isLogin = true;
                p.Close(); //Command sẽ được gọi khi button gán command đó được click và command đó chỉ được thực thi khi window login đóng
            }
            else
            {
                isLogin = false;
                MessageBox.Show("Sai tài khoản hoặc mật khẩu", "Đăng nhập thất bại");
            }
        }
    }
}
