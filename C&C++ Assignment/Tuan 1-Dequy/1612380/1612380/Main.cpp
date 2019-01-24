#include "Header.h"

void main()
{
	int n, N, arrA[MAX];
	float x, arrB[MAX];
	nhapN(n);
	nhapX(x);

	printf("------------Cau 1-------------\n");
	printf("%i\n",GiaiThua(n));
	printf("------------Cau 2-------------\n");
	printf("%f\n", TongPhanSo1(n));
	printf("------------Cau 3-------------\n");
	printf("%f\n", TongPhanSo2(n));
	printf("------------Cau 4-------------\n");
	printf("%f\n", TongS1(n, x));
	printf("------------Cau 5-------------\n");
	printf("%f\n", TongS2(n, x));

	nhapMang1D(N, arrA);

	printf("------------Cau 6-------------\n");
	printf("%i\n", DemSNT(N, arrA));
	printf("------------Cau 7-------------\n");
	printf("%i\n", DemSHT(N, arrA));
	printf("------------Cau 8-------------\n");
	printf("%i\n", TongChan(N, arrA));
	printf("------------Cau 9-------------\n");
	ViTriNguyenTo(N, arrA);
	printf("------------Cau 10-------------\n");

	ViTriChan(N, arrA);

	printf("--------------------------------\n");

	nhapMangThuc(N, arrB);

	printf("------------Cau 11-------------\n");
	printf("%f\n", TongGiaTri(N, arrB));
	printf("------------Cau 12-------------\n");
	printf("%i\n", DemGiaTriPhanBiet(N, arrB));
	_getch();
}