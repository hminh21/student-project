#include "KHTN.h"


CKHTN::CKHTN()
{
}

CKHTN::CKHTN(CSINHVIEN* sv)
{
	_sv.push_back(sv);
}

CKHTN::CKHTN(const CKHTN& k)
{
	CSINHVIEN* sv;

	for (int i = 0; i < k.get_SV().size(); i++)
	{
		//Khoi tao vung nho chua du lieu cua 1 sinh vien
		sv = createSV(k.get_SV()[i]->get_class());

		if (sv == NULL)
		{
			cout << "Khong du bo nho" << endl;
			return;
		}
		//Copy du lieu sinh vien
		sv->set_Name(k.get_SV()[i]->get_Name());
		sv->set_Age(k.get_SV()[i]->get_Age());
		sv->set_MSSV(k.get_SV()[i]->get_MSSV());
		sv->set_newSubject(k.get_SV()[i]->get_newSubject());
		sv->set_retestSubject(k.get_SV()[i]->get_retestSubject());
		sv->set_restudySubject(k.get_SV()[i]->get_restudySubject());

		//Truyen vao mang
		_sv.push_back(sv);
	}
}

CKHTN::~CKHTN()
{
	_sv.clear();
}

CSINHVIEN* CKHTN::createSV(string type)
{
	CSINHVIEN* sv = NULL;

	if (type == "CCNTN")
		sv = new CCNTN;
	else if(type == "CCTTT") //Neu la class CCTTT
		sv = new CCTTT;

	if (sv == NULL)
		cout << "Khong du bo nho" << endl;
	return sv;
}

void CKHTN::Input(istream& is)
{
	int n;
	cout << "Nhap so luong sinh vien:";
	is >> n;
	string str;
	CSINHVIEN* sv;
	for (int i = 0; i < n; i++)
	{
		cout << "----------Sinh vien thu " << i + 1 << " ----------" << endl;
		
		is.ignore();
		cout << "He(CNTN hoac CTTT):";
		getline(is, str);
		while (str != "CNTN" && str != "CTTT")
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

void CKHTN::Output(ostream& os)
{
	for (int i = 0; i < _sv.size(); i++)
	{
		os << "----------Sinh vien thu " << i + 1 << " ----------" << endl;
		_sv[i]->Output(os);
		os << endl;
	}
}

int CKHTN::TotalTuitionFee()
{
	int sum = 0;

	for (int i = 0; i < _sv.size(); i++)
		sum += _sv[i]->calcTuitionFee();

	return sum;
}