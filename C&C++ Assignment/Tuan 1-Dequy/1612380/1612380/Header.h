#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX 50

//Nhap n
void nhapN(int &n);

//Tinh n giai thua
int GiaiThua(int n);

//Tinh tong cac phan so co mau so le
float TongPhanSo1(int n);

//Tinh tong cac phan so co dang (2k+1)/(2k+2)
float TongPhanSo2(int n);

//Nhap x
void nhapX(float &x);

//Tinh tong cac so x^n
float TongS1(int n, float x);

//Tinh tong cac so nguyen duong
int S(int n);

//Tinh tong cac so mu co dang x^n/(1+2+..+n)
float TongS2(int n, float x);

//Nhap mang
void nhapMang1D(int &N, int arrA[]);

//Kiem tra so nguyen to
bool ktSNT(int arrA, int i);

//Dem so nguyen to trong mang
int DemSNT(int N, int arrA[]);

//Tinh tong uoc so
int TongUocSo(int A, int i);

//Kiem tra so hoan thien
bool ktSHT(int A);

//Dem so hoan thien
int DemSHT(int N, int arrA[]);

//Tinh tong cac so chan trong mang
int TongChan(int N, int arrA[]);

// Liet ke vi tri cac phan tu la nguyen to trong mang
int ViTriNguyenTo(int N, int arrA[]);

// Liet ke vi tri cac phan tu la chan trong mang
int ViTriChan(int N, int arrA[]);

//Nhap mang so thuc
void nhapMangThuc(int N, float arrB[]);

//Tinh tong cac gia tri lon hon gia tri dung lien truoc no trong mang
float TongGiaTri(int N, float arrB[]);

//Tim gia tri phan biet
bool TimGiaTriPhanBiet(int N, float arrB[]);

//Dem phan biet cac gia tri trong mang
int DemGiaTriPhanBiet(int N, float arrB[]);