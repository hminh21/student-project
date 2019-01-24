#include "DonThuc.h"

DonThuc::DonThuc()
{
	_HeSo = 0;
	_BienMu = new Node_Bien_Mu;
	_BienMu->_Bien = 0;
	_BienMu->_SoMu = 0;
	_Next = NULL;
}

DonThuc::~DonThuc()
{
}

Node_Bien_Mu* DonThuc::creatNode(char ch)
{
	Node_Bien_Mu* p  = new Node_Bien_Mu;
	p->_Bien = ch;
	p->next = NULL;
	p->_SoMu = 1;
	
	return p;
}

void DonThuc::addTail(char ch, Node_Bien_Mu*& pTail)
{
	Node_Bien_Mu* p = creatNode(ch);

	if (pTail == NULL) {
		pTail =_BienMu= p;
	}
	else {
		pTail->next = p;
		pTail = p;
	}
}

void DonThuc::Read(string str0)
{
	Node_Bien_Mu *pTail= NULL;
	char ch[1];

	for (int i = 0; i < str0.length(); i++) {
		if (str0[i] > 47 && str0[i] < 58) {

			while (str0[i] > 47 && str0[i] < 58) {
				ch[0] = str0[i];
				_HeSo = _HeSo * 10 + atoi(ch);
				i++;
			}
			if (str0[i] == '.') {
				i++;
				int dem = 1;
				while (str0[i] > 47 && str0[i] < 58) {
					ch[0] = str0[i];
					_HeSo = _HeSo + atoi(ch) / (pow(10, dem));
					dem++;
					i++;
				}i--;
			}
		}

		else if (str0[i] >= 97 && str0[i] <= 122) {
			addTail(str0[i], pTail);
		}

		else if (str0[i] == '^') {

			pTail->_SoMu = 0;
			ch[0] = str0[i];
			i++;
            
			bool dauMu = 0;
			if (str0[i] == '~') {
				dauMu = 1;
				i++;
			}

			while (str0[i] > 47 && str0[i] < 58) {
				ch[0] = str0[i];
				pTail->_SoMu = pTail->_SoMu * 10 + atoi(ch);
				i++;
			}
			if (dauMu == 1)
				pTail->_SoMu *= (-1);
		}
	}

	if (str0[0] == '-') {
		_HeSo*=(-1);
	}

	_Next = NULL;

}

ostream & operator<<(ostream &outDev, DonThuc &_Donthuc)
{
	Node_Bien_Mu *p=_Donthuc._BienMu;

	if(_Donthuc._HeSo>=0)
	    outDev << "+"<<_Donthuc._HeSo;
	else
		outDev << _Donthuc._HeSo;

	while (p != NULL) {
		outDev << p->_Bien;
		if (p->_SoMu != 1) {
			outDev << "^";
			outDev << p->_SoMu << " ";
		}
		p = p->next;
	}
	return outDev;
}


bool CheckBienMu(Node_Bien_Mu* r, Node_Bien_Mu* t)
{
	while (r != NULL && t != NULL)
	{
		if (r->_Bien != t->_Bien || r->_SoMu != t->_SoMu)
			return false;
		r = r->next;
		t = t->next;
		if ((r == NULL && t != NULL) || (r != NULL && t == NULL))
			return false;
	}
	return true;
}

DonThuc* DonThuc::findTail()
{
	for (DonThuc *p = this; p != NULL; p = p->_Next)
	{
		if (p->_Next == NULL)
			return p;
	}

	return NULL;
}

DonThuc DonThuc::operator*(const DonThuc& dT) {
	DonThuc _temp;
	DonThuc *p;
	_temp._HeSo = _HeSo*dT._HeSo;
	if (_BienMu->_Bien == dT._BienMu->_Bien) {
		_temp._BienMu = creatNode(_BienMu->_Bien);
		_temp._BienMu->_Bien = _BienMu->_Bien;
		_temp._BienMu->_SoMu = _BienMu->_SoMu+dT._BienMu->_SoMu;
	}
	else 
	{
		_temp._BienMu = _BienMu;
		_temp._BienMu->next = dT._BienMu;
	}
	return _temp;
}
