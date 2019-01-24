#include "Header.h"

void main()
{
	//PHAN SO
	cout << "PHAN SO" << endl;
	Fraction ps[] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
	int n1 = sizeof(ps) / sizeof(ps[0]);
	Ref head1 = NULL, tail1 = NULL, p1;
	int iSize1 = sizeof(Fraction);
	for (int i = 0; i < n1; i++)
		AddFirst(head1, tail1, &ps[i], iSize1);
	PrintList(head1, &PrintFrac);
	Fraction fr1 = { 1, 2 }, fr2 = { 3, 4 }, fr3 = { 5, 6 }, fr4 = { 2, 3 };
	cout << "Tim kiem phan tu 1/2 trong danh sach" << endl;
	p1 = findList(head1, &fr1, fracCmp);
	cout << p1 << endl;
	cout << "Chen phan tu 5/6 vao sau phan tu 3/4 trong danh sach" << endl;
	InsertAfter(head1, &fr2, &fr3, iSize1, fracCmp);
	PrintList(head1, PrintFrac);
	cout << "Chen phan tu 5/6 vao truoc phan tu 3/4 trong danh sach" << endl;
	InsertBefore(head1, tail1, &fr2, &fr3, iSize1, fracCmp);
	PrintList(head1, PrintFrac);
	cout << "Xoa phan tu dau tien trong danh sach" << endl;
	DeleteBeg(head1, tail1);
	PrintList(head1, PrintFrac);
	cout << "Xoa phan tu cuoi cung trong danh sach" << endl;
	DeleteEnd(head1, tail1);
	PrintList(head1, PrintFrac);
	cout << "Xoa phan tu 5/6 dau tien trong danh sach" << endl;
	DeleteAt(head1, tail1, &fr3, iSize1, fracCmp);
	PrintList(head1, PrintFrac);
	cout << "Chen phan tu 2/3 vao truoc phan tu 3/4 trong danh sach" << endl;
	InsertAt(head1, tail1, &fr2, &fr4, iSize1, fracCmp);
	PrintList(head1, PrintFrac);
	cout << "Chen phan tu 1/2 vao cuoi danh sach" << endl;
	AddLast(head1, tail1, &fr1, iSize1);
	PrintList(head1, PrintFrac);
	DestroyList(head1, tail1);
	cout << "-----------------------------------------" << endl;
	//SO NGUYEN
	cout << "SO NGUYEN" << endl;
	int iArr[] = { 1, 2, 3, 4};
	int n2 = sizeof(iArr) / sizeof(iArr[0]);
	int iSize2 = sizeof(int);
	Ref head2 = NULL, tail2 = NULL, p2;
	for (int i = 0; i < n2; i++)
		AddFirst(head2, tail2, &iArr[i], iSize2);
	PrintList(head2, &PrintInt);
	int i1 = 1, i2 = 2, i3 = 3, i4 = 4;
	cout << "Tim kiem phan tu 1 trong danh sach" << endl;
	p2 = findList(head2, &i1, intCmp);
	cout << p2 << endl;
	cout << "Chen phan tu 3 vao sau phan tu 2 trong danh sach" << endl;
	InsertAfter(head2, &i2, &i3, iSize2, intCmp);
	PrintList(head2, PrintInt);
	cout << "Chen phan tu 3 vao truoc phan tu 2 trong danh sach" << endl;
	InsertBefore(head2, tail2, &i2, &i3, iSize2, intCmp);
	PrintList(head2, PrintInt);
	cout << "Xoa phan tu dau tien trong danh sach" << endl;
	DeleteBeg(head2, tail2);
	PrintList(head2, PrintInt);
	cout << "Xoa phan tu cuoi cung trong danh sach" << endl;
	DeleteEnd(head2, tail2);
	PrintList(head2, PrintInt);
	cout << "Xoa phan tu 3 dau tien trong danh sach" << endl;
	DeleteAt(head2, tail2, &i3, iSize2, intCmp);
	PrintList(head2, PrintInt);
	cout << "Chen phan tu 2 vao truoc phan tu 3 trong danh sach" << endl;
	InsertAt(head2, tail2, &i3, &i2, iSize2, intCmp);
	PrintList(head2, PrintInt);
	cout << "Chen phan tu 1 vao cuoi danh sach" << endl;
	AddLast(head2, tail2, &i1, iSize2);
	PrintList(head2, PrintInt);
	DestroyList(head2, tail2);
	cout << "--------------------------------" << endl;

	//SO THUC
	cout << "SO THUC" << endl;
	double fArr[] = { 1.1, 2.0, 3.0, 4.0 };
	int n3 = sizeof(fArr) / sizeof(fArr[0]);
	int iSize3 = sizeof(double);
	Ref head3 = NULL, tail3 = NULL, p3;
	for (int i = 0; i < n3; i++)
		AddFirst(head3, tail3, &fArr[i], iSize3);
	PrintList(head3, &PrintDou);
	double f1 = 1.1, f2 = 2.0, f3 = 3.3, f4 = 4.4;
	cout << "Tim kiem phan tu 1.1 trong danh sach" << endl;
	p3 = findList(head3, &f1, douCmp);
	cout << p3 << endl;
	cout << "Chen phan tu 3.3 vao sau phan tu 2 trong danh sach" << endl;
	InsertAfter(head3, &f2, &f3, iSize3, douCmp);
	PrintList(head3, PrintDou);
	cout << "Chen phan tu 3.3 vao truoc phan tu 2 trong danh sach" << endl;
	InsertBefore(head3, tail3, &f2, &f3, iSize3, douCmp);
	PrintList(head3, PrintDou);
	cout << "Xoa phan tu dau tien trong danh sach" << endl;
	DeleteBeg(head3, tail3);
	PrintList(head3, PrintDou);
	cout << "Xoa phan tu cuoi cung trong danh sach" << endl;
	DeleteEnd(head3, tail3);
	PrintList(head3, PrintDou);
	cout << "Xoa phan tu 3.3 dau tien trong danh sach" << endl;
	DeleteAt(head3, tail3, &f3, iSize3, douCmp);
	PrintList(head3, PrintDou);
	cout << "Chen phan tu 2 vao truoc phan tu 3.3 trong danh sach" << endl;
	InsertAt(head3, tail3, &f3, &f2, iSize3, douCmp);
	PrintList(head3, PrintDou);
	cout << "Chen phan tu 1.1 vao cuoi danh sach" << endl;
	AddLast(head3, tail3, &f1, iSize3);
	PrintList(head3, PrintDou);
	DestroyList(head3, tail3);
	cout << "------------------------------------------------------------" << endl;

	//SO PHUC
	cout << "SO PHUC" << endl;
	Complex sp[] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
	int n4 = sizeof(sp) / sizeof(sp[0]);
	Ref head4 = NULL, tail4 = NULL, p4;
	int iSize4 = sizeof(Complex);
	for (int i = 0; i < n4; i++)
		AddFirst(head4, tail4, &sp[i], iSize4);
	PrintList(head4, &PrintPlex);
	Complex sp1 = { 1, 2 }, sp2 = { 3, 4 }, sp3 = { 5, 6 }, sp4 = { 2, 3 };
	cout << "Tim kiem phan tu 1 + 2i trong danh sach" << endl;
	p4 = findList(head4, &sp4, plexCmp);
	cout << p4 << endl;
	cout << "Chen phan tu 5 + 6i vao sau phan tu 3 + 4i trong danh sach" << endl;
	InsertAfter(head4, &sp2, &sp3, iSize4, plexCmp);
	PrintList(head4, PrintPlex);
	cout << "Chen phan tu 5 + 6i vao truoc phan tu 3 + 4i trong danh sach" << endl;
	InsertBefore(head4, tail4, &sp2, &sp3, iSize4, plexCmp);
	PrintList(head4, PrintPlex);
	cout << "Xoa phan tu dau tien trong danh sach" << endl;
	DeleteBeg(head4, tail4);
	PrintList(head4, PrintPlex);
	cout << "Xoa phan tu cuoi cung trong danh sach" << endl;
	DeleteEnd(head4, tail4);
	PrintList(head4, PrintPlex);
	cout << "Xoa phan tu 5 + 6i dau tien trong danh sach" << endl;
	DeleteAt(head4, tail4, &sp3, iSize4, plexCmp);
	PrintList(head4, PrintPlex);
	cout << "Chen phan tu 2 + 3i vao truoc phan tu 3 + 4i trong danh sach" << endl;
	InsertAt(head4, tail4, &sp2, &sp4, iSize4, plexCmp);
	PrintList(head4, PrintPlex);
	cout << "Chen phan tu 1 + 2i vao cuoi danh sach" << endl;
	AddLast(head4, tail4, &sp1, iSize4);
	PrintList(head4, PrintPlex);
	DestroyList(head4, tail4);
	_getch();
}