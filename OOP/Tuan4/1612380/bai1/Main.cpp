#include "PhanSo.h"

int main()
{
	vector<PhanSo> ps;
	int N;
	int tuso, mauso;
	char ch;
	ifstream fs("PhanSoList.txt", ios::in);
	if (!fs)
		return 1;
	fs >> N;
	for (int i = 0; i < N; i++)
	{
		ps.resize(i + 1);
		fs >> tuso;
		fs >> ch;
		fs >> mauso;
		ps[i].SetTuSo(tuso);
		ps[i].SetMauSo(mauso);
		cout << ps[i].ToString() << endl;
	}

	PhanSo max, min;
	max = findMax(ps);
	min = findMin(ps);
	cout << "Max = " << max.ToString() << endl;
	cout << "Min = " << min.ToString() << endl;
	cout <<"Tong cac phan so: " << (~TongPS(ps)).ToString() << endl;
	cout << "Tich cac phan so: " << (~TichPS(ps)).ToString() << endl;

	vector <PhanSo> p;
	cout << "Danh sach chua toi gian:" << endl;
	PhanSo a(12, 36);
	p.push_back(a);
	cout << a.ToString() << endl;
	PhanSo b(240, 120);
	p.push_back(b);
	cout << b.ToString() << endl;
	PhanSo c(8, 24);
	p.push_back(c);
	cout << c.ToString() << endl;
	
	cout << "Sau khi toi gian:" << endl;
	for (int i = 0; i < p.size(); i++)
		cout << (~p[i]).ToString() << endl;
	return 0;
}