#include "DHA.h"

CDHA::CDHA()
{

}

CDHA::CDHA(CSINHVIEN* sv)
{
	_sv.push_back(sv);
}

CDHA::CDHA(const CDHA& d)
{
	CSINHVIEN* sv;
	for (int i = 0; d.get_SV().size(); i++)
	{
		//Khoi tao vung nho
		sv = createSV(d.get_SV()[i]->get_Class());

		//copy du lieu sinh vien
		sv->set_Name(d.get_SV()[i]->get_Name());
		sv->set_MSSV(d.get_SV()[i]->get_MSSV());
		sv->set_Date(d.get_SV()[i]->get_Date());
		sv->set_Score(d.get_SV()[i]->get_Score());

		//Neu sinh vien do thuoc he Tien tien thi co diem iBT
		if (d.get_SV()[i]->get_Class() == "CTT")
			sv->set_iBT(d.get_SV()[i]->get_iBT());

		//Truyen vao danh sach
		this->get_SV().push_back(sv);
	}
}


CDHA::~CDHA()
{
	_sv.clear();
}


void CDHA::Input(istream& is)
{
	int n;
	cout << "Nhap so luong sinh vien:";
	is >> n;
	string str;
	CSINHVIEN* sv;
	for (int i = 0; i < n; i++)
	{
		cout << "----------Sinh vien thu " << i + 1 << " ----------" << endl;

		is.ignore(); //Xoa bo nho dem
		cout << "He(CQ hoac TT):";
		getline(is, str);
		while (str != "CQ" && str != "TT")
		{
			cout << "Khong hop le, nhap lai" << endl;
			getline(is, str);
		}
		str = "C" + str;
		sv = createSV(str); //Khoi tao vung nho
		if (sv == NULL) return;

		//Nhap thong tin sinh vien
		sv->Input(is);

		//Truyen vao mang vector
		_sv.push_back(sv);
	}
}

void CDHA::Output(ostream& os)
{
	for (int i = 0; i < _sv.size(); i++)
	{
		os << "----------Sinh vien thu " << i + 1 << " ----------" << endl;
		_sv[i]->Output(os);
		os << endl;
	}
}

int CDHA::TotalGraduation()
{
	int temp = 0;
	for (int i = 0; i < _sv.size(); i++)
	{
		if (_sv[i]->Result() == "Dau TN")
			temp++;
	}
	return temp;
}

CSINHVIEN* CDHA::createSV(string type) //Cap vung nho cho sinh vien
{
	CSINHVIEN* sv = NULL;
	//Phan chia
	if (type == "CCQ")
		sv = new CCQ;
	else if (type == "CTT")
		sv = new CTT;

	return sv;
}