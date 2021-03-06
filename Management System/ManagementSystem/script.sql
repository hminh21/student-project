USE [master]
GO
/****** Object:  Database [ManagementSystem]    Script Date: 1/5/2019 11:50:47 PM ******/
CREATE DATABASE [ManagementSystem]
GO
USE [ManagementSystem]
GO
/****** Object:  Table [dbo].[CATEGORY]    Script Date: 1/5/2019 11:50:47 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[CATEGORY](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[DisplayName] [nvarchar](max) NULL,
	[Quantity] [int] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[DEAL]    Script Date: 1/5/2019 11:50:47 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[DEAL](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[CustomerName] [nvarchar](max) NULL,
	[PhoneNumber] [nvarchar](15) NULL,
	[CustomerAddress] [nvarchar](max) NULL,
	[PayDate] [date] NULL,
	[ProductID] [int] NOT NULL,
	[Quantity] [int] NOT NULL,
	[SalePercent] [float] NULL,
	[SaleEvent] [nvarchar](max) NULL,
	[DisplayPrice] [int] NOT NULL,
	[IsDeleted] [bit] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
/****** Object:  Table [dbo].[PRODUCT]    Script Date: 1/5/2019 11:50:47 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[PRODUCT](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[DisplayName] [nvarchar](max) NULL,
	[Quantity] [int] NOT NULL,
	[RetailPrice] [int] NOT NULL,
	[CatID] [int] NOT NULL,
	[IsDeleted] [bit] NOT NULL,
PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO
SET IDENTITY_INSERT [dbo].[CATEGORY] ON 

INSERT [dbo].[CATEGORY] ([ID], [DisplayName], [Quantity]) VALUES (1, N'Áo', 0)
INSERT [dbo].[CATEGORY] ([ID], [DisplayName], [Quantity]) VALUES (2, N'Quần', 0)
INSERT [dbo].[CATEGORY] ([ID], [DisplayName], [Quantity]) VALUES (3, N'Giày', 0)
SET IDENTITY_INSERT [dbo].[CATEGORY] OFF
ALTER TABLE [dbo].[DEAL]  WITH CHECK ADD  CONSTRAINT [FK_DEAL_PRODUCT] FOREIGN KEY([ProductID])
REFERENCES [dbo].[PRODUCT] ([ID])
GO
ALTER TABLE [dbo].[DEAL] CHECK CONSTRAINT [FK_DEAL_PRODUCT]
GO
ALTER TABLE [dbo].[PRODUCT]  WITH CHECK ADD  CONSTRAINT [FK_PRODUCT_CATEGORY] FOREIGN KEY([CatID])
REFERENCES [dbo].[CATEGORY] ([ID])
GO
ALTER TABLE [dbo].[PRODUCT] CHECK CONSTRAINT [FK_PRODUCT_CATEGORY]
GO
USE [master]
GO
ALTER DATABASE [ManagementSystem] SET  READ_WRITE 
GO
