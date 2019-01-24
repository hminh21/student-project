#include "Dathuc.h"

DaThuc::DaThuc()
{
	_DonThuc = new DonThuc;

}


DaThuc::~DaThuc()
{

}

void DaThuc::AddTail(DonThuc* p, DonThuc* &pTail)
{
	if (pTail == NULL)
		pTail = _DonThuc = p;
	else {
		pTail->set_Next(p);
		pTail = p;
	}
}

void DaThuc::Cut(int temp, int pos, string& str0, string str, DonThuc*&pTail)
{
	str0 = str.substr(temp, pos - temp);
	DonThuc* p = new DonThuc;
	p->Read(str0);
	AddTail(p, pTail);
}

void DaThuc::cutstring(int& temp, int& pos, char ch, string& str0, string str, DonThuc*&pTail)
{
	Cut(temp, pos, str0, str, pTail);
	temp = pos;
	pos = str.find(ch, pos + 1);
}

string DaThuc::ReadFile(ifstream & File)
{
	int pos = 0;
	string str;

	getline(File, str);

	pos = str.find("^-", 0);
	while (pos != -1) {
		str[pos + 1] = '~';
		pos = str.find("^-", pos);
	}
	return str;

}

void DaThuc::ReadString(string str)
{
	DonThuc* pTail = NULL;
	string str0;
	int temp = 0;

	int posplus = 0;
	int posminus = 0;

	posplus = str.find('+', 0);
	posminus = str.find('-', 0);

	while (1) {
		if (posminus > posplus) {

			if (posplus == -1) {
				while (posminus != -1) {
					cutstring(temp, posminus, '-', str0, str, pTail);
				}break;
			}
			cutstring(temp, posplus, '+', str0, str, pTail);
		}

		if (posminus < posplus) {
			if (posminus == -1) {
				while (posplus != -1) {
					cutstring(temp, posplus, '+', str0, str, pTail);
				}break;
			}

			cutstring(temp, posminus, '-', str0, str, pTail);
		}
	}

	Cut(temp, str.length(), str0, str, pTail);
}

ostream & operator<<(ostream &outDev, DaThuc &_Dathuc)
{
	DonThuc* p = _Dathuc._DonThuc;

	while (p != NULL) {
		outDev << *p;
		p = p->get_Next();
	}

	return outDev;
}



void DaThuc::XoaDonThuc(DonThuc*& q)
{
	DonThuc* r = q->get_Next();
	if (r == NULL) //Neu don thuc can xoa nam o cuoi danh sach
	{
		DonThuc* p;
		for (p = _DonThuc; p->get_Next()->get_Next() != NULL; p = p->get_Next());
		p->set_Next(NULL);
		delete r;
		return;
	}
	*q = *r;
	delete r;
}

DaThuc& DaThuc::operator~()
{
	DonThuc* p, *q, *pprev = _DonThuc, *qprev = _DonThuc;
	for (p = _DonThuc; p->get_Next() != NULL; p = p->get_Next())
	{
		for (q = p->get_Next(); q != NULL; pprev = p, qprev = q, q = q->get_Next())
		{
			Node_Bien_Mu* r, *t;
			r = p->get_BienMu();
			t = q->get_BienMu();

			if (CheckBienMu(r, t) == true) //Kiem tra 2 don thuc 
			{
				p->set_HeSo(p->get_HeSo() + q->get_HeSo()); //Thuc hien phep tinh va thay doi p

				XoaDonThuc(q);//Xoa q
				q = qprev;
			}

			if (p->get_HeSo() == 0) //Neu p = 0 thi xoa luon p
			{
				XoaDonThuc(p);

				if (p->get_Next() == NULL) //Neu xoa chi con lai 1 don thuc 
					return *this;

				p = pprev;
				break;
			}

			if (q->get_Next() == NULL)// Neu q = 0 o cuoi danh sach
			{
				if (q->get_HeSo() == 0)
					XoaDonThuc(q);
			}
		}
	}
	return *this;
}


void DaThuc::ChenDonThuc(float heso, char bien, int somu)
{
	DonThuc* q = new DonThuc;
	if (q == NULL)
		cout << "khong du bo nho" << endl;
	q->set_HeSo(heso);
	q->set_Bien(bien);
	q->set_SoMu(somu);
	q->set_Next(NULL);
	q->get_BienMu()->next = NULL;
	if (_DonThuc->get_Next() == NULL && _DonThuc->get_HeSo() == 0 && _DonThuc->get_BienMu()->_SoMu==0)
	{
		_DonThuc = q;
	}
	else
	{
		DonThuc* p = _DonThuc;
		for (; p->get_Next() != NULL; p = p->get_Next());
		p->set_Next(q);
	}

}



void DaThuc::ChenDonThuc( DonThuc& donthuc)
{
	Node_Bien_Mu *p = donthuc.get_BienMu();

	DonThuc* q = new DonThuc;
	if (q == NULL)
		cout << "khong du bo nho" << endl;
	q->set_HeSo(donthuc.get_HeSo());

	
	q->set_Bien(p->_Bien);
	q->set_SoMu(p->_SoMu);
	Node_Bien_Mu* r = q->get_BienMu();
	p = p->next;
	while (p != NULL)
	{	
		Node_Bien_Mu* x = new Node_Bien_Mu;
		if (x == NULL)
			cout << "Khong du bo nho" << endl;
		r->next = x;
		r = r->next;
		r->_Bien = p->_Bien;
		r->_SoMu = p->_SoMu;

		p = p->next;
	}
	r->next = NULL;
	
	if (_DonThuc->get_Next() == NULL && _DonThuc->get_HeSo() == 0 && _DonThuc->get_BienMu()->_SoMu == 0 && _DonThuc->get_BienMu()->_Bien==0)
	{
		_DonThuc = q;
	}
	else
	{
		DonThuc* r = _DonThuc;
		for (; r->get_Next() != NULL; r = r->get_Next());
		r->set_Next(q);
	}

}

DaThuc DaThuc::operator+(const DaThuc &dathuc)
{

	DaThuc *temp = new DaThuc;
	
	DonThuc* p, *q;

	//duyet da thuc thu nhat 
	for (p = _DonThuc; p != NULL; p = p->get_Next())
		temp->ChenDonThuc(p->get_HeSo(),p->get_BienMu()->_Bien,p->get_BienMu()->_SoMu);

	for (q = dathuc._DonThuc; q != NULL; q = q->get_Next())
		temp->ChenDonThuc(q->get_HeSo(), q->get_BienMu()->_Bien, q->get_BienMu()->_SoMu);
	
	~*temp;
	!*temp;
	return *temp;
}

DaThuc DaThuc::operator-(const DaThuc &dathuc)
{

	DaThuc *temp = new DaThuc;

	DonThuc* p, *q;

	//duyet da thuc thu nhat 
	for (p = _DonThuc; p != NULL; p = p->get_Next())
		temp->ChenDonThuc(p->get_HeSo(), p->get_BienMu()->_Bien, p->get_BienMu()->_SoMu);


	for (q = dathuc._DonThuc; q != NULL; q = q->get_Next())
		temp->ChenDonThuc(-(q->get_HeSo()), q->get_BienMu()->_Bien, q->get_BienMu()->_SoMu);

	~*temp;
	!*temp;
	return *temp;
}


DaThuc DaThuc::operator*(const DaThuc& dathuc) {
	DonThuc *p, *q;
	DaThuc * temp = new DaThuc;
	DonThuc h;
	for (p = _DonThuc; p != NULL; p = p->get_Next()) {
		//duyet da thuc thu 2 
		for (q = dathuc._DonThuc; q != NULL; q = q->get_Next()) 
		{
			
			h = (*p) * (*q);
			temp->ChenDonThuc(h);
	
		}
	}
	~*temp;
	!*temp;
	return *temp;
}
void DaThuc::AddDonThuc(DonThuc& dT) {
	CreateDonThuc(dT);
	dT.set_Next(_DonThuc);
}

void DaThuc::CreateDonThuc(DonThuc dT) {
	dT.set_HeSo(0);
	_DonThuc->set_Next(NULL);
}

DaThuc& DaThuc::operator!() {
	mergeSort(_DonThuc);
	return *this;

}
DonThuc* findMid(DonThuc *head)
{
	if (head->get_Next() == NULL)
		return head;
	DonThuc *p, *q;
	p = q = head;
	while (q->get_Next() && q->get_Next()->get_Next())
	{
		p = p->get_Next();
		q = q->get_Next()->get_Next();
	}
	return p;
}
// dividing list into 2 parts
bool divideList(DonThuc *head, DonThuc *&head1, DonThuc *&head2)
{
	if (head == NULL)
		return false;
	DonThuc *mid = findMid(head);
	head1 = head;
	head2 = mid->get_Next();
	mid->set_Next(NULL);
	return true;
}
// merge 2 list which each one has already been sorted (using recursion)
DonThuc *mergeList(DonThuc *head1, DonThuc *head2)
{
	DonThuc *head = NULL;		// List after merge

	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;

	if (ktBeHon(head1->get_BienMu(),head2->get_BienMu()))
	{
		head = head1;
		head->set_Next(mergeList(head1->get_Next(), head2));

	}

	else
	{
		head = head2;
		head->set_Next(mergeList(head1, head2->get_Next()));

	}
	return head;
}
bool ktBeHon(Node_Bien_Mu* node1, Node_Bien_Mu* node2){
	int a= 0, b= 0;
	Node_Bien_Mu *p = new Node_Bien_Mu;
	p = node1;
	while (p != NULL){
		a += p->_SoMu;
		p = p->next;
	}
	p = node2;
	while (p != NULL){
		b += p->_SoMu;
		p = p->next;
	}
	return (a < b);

}
bool mergeSort(DonThuc *&head)
{
	if (head == NULL || head->get_Next() == NULL)
		return false;

	DonThuc *head1, *head2;
	head1 = NULL;
	head2 = NULL;
	divideList(head, head1, head2);
	mergeSort(head1);
	mergeSort(head2);
	head = mergeList(head1, head2);
	return true;
}
