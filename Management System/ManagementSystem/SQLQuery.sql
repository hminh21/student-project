CREATE DATABASE ManagementSystem
GO

USE ManagementSystem
GO

CREATE TABLE CATEGORY
(
	ID int identity(1,1),
	DisplayName nvarchar(MAX),
	Quantity int NOT NULL,

	PRIMARY KEY(ID)
)
GO

CREATE TABLE PRODUCT
(
	ID int identity(1,1),
	DisplayName nvarchar(MAX),
	Quantity int NOT NULL,
	RetailPrice int NOT NULL,
	CatID int NOT NULL,
	IsDeleted bit NOT NULL

	PRIMARY KEY(ID),
	CONSTRAINT FK_PRODUCT_CATEGORY FOREIGN KEY(CatID) REFERENCES CATEGORY(ID)
)
GO


CREATE TABLE DEAL
(
	ID int identity(1,1),
	CustomerName nvarchar(MAX),
	PhoneNumber nvarchar(15),
	CustomerAddress nvarchar(MAX),
	PayDate date,
	ProductID int NOT NULL,
	Quantity int NOT NULL,
	SalePercent float,
	SaleEvent nvarchar(MAX),
	DisplayPrice int NOT NULL,
	IsDeleted bit NOT NULL,

	PRIMARY KEY(ID),
	CONSTRAINT FK_DEAL_PRODUCT FOREIGN KEY(ProductID) REFERENCES PRODUCT(ID)
)
GO

INSERT INTO CATEGORY VALUES(N'Áo',0)
INSERT INTO CATEGORY VALUES(N'Quần',0)
INSERT INTO CATEGORY VALUES(N'Giày',0)
