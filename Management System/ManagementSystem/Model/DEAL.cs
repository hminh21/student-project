//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated from a template.
//
//     Manual changes to this file may cause unexpected behavior in your application.
//     Manual changes to this file will be overwritten if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace ManagementSystem.Model
{
    using System;
    using System.Collections.Generic;
    
    public partial class DEAL
    {
        public int ID { get; set; }
        public string CustomerName { get; set; }
        public string PhoneNumber { get; set; }
        public string CustomerAddress { get; set; }
        public Nullable<System.DateTime> PayDate { get; set; }
        public int ProductID { get; set; }
        public int Quantity { get; set; }
        public Nullable<double> SalePercent { get; set; }
        public string SaleEvent { get; set; }
        public int DisplayPrice { get; set; }
        public bool IsDeleted { get; set; }
    
        public virtual PRODUCT PRODUCT { get; set; }
    }
}
