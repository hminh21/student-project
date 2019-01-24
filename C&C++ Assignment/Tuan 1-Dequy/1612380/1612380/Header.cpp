#include "Header.h"

//Nhap n
void nhapN(int &n)
{
	printf("Nhap n: ");
	scanf("%i", &n);
}

//Tinh giai thua
int GiaiThua(int n)
{
	if (n <= 1)
		return 1;
	return GiaiThua(n - 1)*n;
}

//Tinh tong cac phan so co mau so = 2k + 1
float TongPhanSo1(int n)
{
	if (n <= 0)
		return 1;
	return TongPhanSo1(n - 1) + 1.0 / (2*n + 1);
}

//Tinh tong cac phan so co dang (2k+1)/(2k+2)
float TongPhanSo2(int n)
{
	if (n <= 0)
		return 1 / 2;
	return TongPhanSo2(n - 1) + float(2 * n + 1) / (2 * n + 2);
}

//Nhap x
void nhapX(float &x)
{
	printf("Nhap x: ");
	scanf("%f", &x);
}

//Tinh tong cac so x^n
float TongS1(int n, float x)
{
	if (n <= 1)
		return x;
	return TongS1(n - 1,x) + pow(x, n);
}

//Tinh tong cac so nguyen duong
int S(int n)
{
	if (n <= 1)
		return 1;
	return S(n - 1) + n;
}

//Tinh tong cac so mu co dang x^n/(1+2+..+n)
float TongS2(int n, float x)
{
	if (n <= 1)
		return x;
	return TongS2(n - 1, x) + pow(x, n) / S(n);
}

//Nhap mang
void nhapMang1D(int &N, int arrA[])
{
	printf("Nhap so phan tu: ");
	scanf("%i", &N);
	for (int i = 0; i <= N - 1; i++)
	{
		printf("A[%i]= ",i);
		scanf("%i", &arrA[i]);
	}
}

//Kiem tra so nguyen to
bool ktSNT(int A,int i)
{
	if (A == 1)  // dieu kien dung khi A = 1 la so nguyen to
		return false;
	if (i == 1) // dieu kien dung khi i giam con 1 ma A khong chia het cho so nao thoa 1 < i < A
		return true;
	else
	{
		if (A % i != 0) // kiem tra so nguyen to
			return ktSNT(A, i - 1);
	}
	return false;
}

//Dem so nguyen to trong mang1D
int DemSNT(int N, int arrA[])
{
	int i = arrA[N - 1] - 1;
	if (N == 0) // dieu kien dung khi xet toi phan tu cuoi cung
		return 0;

	if (ktSNT(arrA[N - 1],i) == true) //dem so nguyen to 
		return DemSNT(N - 1, arrA) + 1;

	return DemSNT(N - 1, arrA);
}

//Tinh tong uoc so
int TongUocSo(int A, int i) //i la bien so chay tu 1 -> A[n-1] - 1 de tim uoc so
{
	if (i == 0) //dieu kien dung
		return 0;

	if (A % i == 0) //kiem tra uoc so
		return TongUocSo(A, i - 1) + i; //tinh tong

	return TongUocSo(A, i - 1);
}

//Kiem tra so hoan thien
bool ktSHT(int A)
{
	int i = A - 1;
	if (TongUocSo(A, i) == A) //kiem tra so hoan thien
		return true;
	return false;
}

//Dem so hoan thien
int DemSHT(int N, int A[])
{
	if (N == 0) //dieu kien dung
		return 0;

	if (ktSHT(A[N - 1]) == true)
		return DemSHT(N - 1, A) + 1; //dem so hoan thien
	return DemSHT(N - 1, A);
}

//Tinh tong cac so chan trong mang
int TongChan(int N, int arrA[])
{
	if (N == 0) //dieu kien dung
		return 0;

	if (arrA[N - 1] % 2 == 0) // kiem tra xem phan tu do co chan hay khong
		return TongChan(N - 1, arrA) + arrA[N-1];
	return TongChan(N - 1, arrA);
}

// Liet ke vi tri cac phan tu la nguyen to trong mang
int ViTriNguyenTo(int N, int arrA[])
{
	int i = arrA[N - 1] - 1; // i la bien chay tu A[N-1] - 1 -> 1 de xet A co chia het cho i trong khoang do hay khong
	if (N == 0)
		return 0;
		
	if (ktSNT(arrA[N - 1], i) == true) // kiem tra so nguyen to
	{
		printf("arrA[%i]\n",N-1);
		return ViTriNguyenTo(N - 1, arrA);
	}
			return ViTriNguyenTo(N - 1, arrA);
}
// Liet ke vi tri cac phan tu la chan trong mang
int ViTriChan(int N, int arrA[])
{
	if (N == 0) // dieu kien dung
		return 0;
	if (arrA[N - 1] % 2 == 0)
	{
		printf("arrA[%i]\n", N - 1);
		return ViTriChan(N - 1, arrA);
	}
	return ViTriChan(N - 1, arrA);
}

//Nhap mang so thuc
void nhapMangThuc(int N, float arrB[])
{
	for (int i = 0; i <= N - 1; i++)
	{
		printf("arrB[%i]= ", i);
		scanf("%f", &arrB[i]);
	}
}

//Tinh tong cac gia tri lon hon gia tri dung lien truoc no trong mang
float TongGiaTri(int N, float arrB[])
{
	if (N < 2) //dieu kien dung
		return 0;
	if (arrB[N - 1] > arrB[N - 2]) // xet vi tri cua B[N-1] so voi so dung truoc no la B[N-2]
		return TongGiaTri(N - 1, arrB) + arrB[N - 1];
	return TongGiaTri(N - 1, arrB);
}


//Tim gia tri phan biet
bool TimGiaTriPhanBiet(int N, float arrB[])
{
	for (int i = 0; i < N - 1; i++)
	{
		if (arrB[N - 1] == arrB[i]) //So sanh phan tu thu N voi cac phan tu con lai
			return false;
	}
	return true;
}

//Dem phan biet cac gia tri trong mang
int DemGiaTriPhanBiet(int N, float arrB[])
{
	if (N == 0)
		return 0;

	if (TimGiaTriPhanBiet(N,arrB) == true)
		return DemGiaTriPhanBiet(N - 1, arrB) + 1;

	return DemGiaTriPhanBiet(N - 1, arrB);
}