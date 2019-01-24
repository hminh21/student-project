#define _DonThuc_h
#include <iostream>
#include<math.h>
#include<string>

using namespace std;


struct Node_Bien_Mu
{
	int _SoMu;
	char _Bien;
	Node_Bien_Mu* next;
};

class DonThuc
{
	float _HeSo = 0;
	Node_Bien_Mu* _BienMu;
	DonThuc* _Next;
public:

	float get_HeSo() {
		return this->_HeSo;
	};

	DonThuc();
	~DonThuc();

	Node_Bien_Mu* get_BienMu() { return this->_BienMu; };
	DonThuc* get_Next() { return this->_Next; };

	void set_HeSo(float HeSo) { _HeSo = HeSo; };
	void set_Next(DonThuc* Next) { _Next = Next; };
	void set_Bien(char bien) { _BienMu->_Bien = bien; };
	void set_SoMu(int somu) { _BienMu->_SoMu = somu; };
	void set_BienMu(Node_Bien_Mu* bienmu) { _BienMu = bienmu; }

	Node_Bien_Mu* creatNode(char);
	void addTail(char, Node_Bien_Mu*&);
	void Read(string);
	DonThuc* findTail();
	friend bool CheckBienMu(Node_Bien_Mu* r, Node_Bien_Mu* t);


	DonThuc operator*(const DonThuc&);
	friend ostream& operator<<(ostream&, DonThuc&);
	friend class Dathuc;
};



