using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;
using DevExpress.Xpf.Core;
using System.Globalization;
using System.Threading;

namespace ManagementSystem
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("vi-VI");
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("vi-VI");

            base.OnStartup(e);
        }
    }
}
