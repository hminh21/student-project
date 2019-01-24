
#include"Donthuc.h"
#include<string>
#include<fstream>

using namespace std;

class DonThuc;

class DaThuc
{
	DonThuc* _DonThuc;
public:
	DaThuc();
	~DaThuc();


	void ReadString(string);
	string ReadFile(ifstream &);
	void cutstring(int& temp, int& pos, char ch, string& str0, string str, DonThuc*&pTail);
	void Cut(int temp, int pos, string& str0, string str, DonThuc*&pTail);
	void AddTail(DonThuc* p, DonThuc* &pTail);
	
	void XoaDonThuc(DonThuc*&);
	void ChenDonThuc(float, char, int);
	void ChenDonThuc(DonThuc& donthuc);

	DonThuc* get_DonThuc(){ return _DonThuc; };
	void AddDonThuc(DonThuc& dT);
	void CreateDonThuc(DonThuc dT);

	DaThuc& operator~();
	DaThuc& operator!();
	DaThuc operator+(const DaThuc &);
	DaThuc operator-(const DaThuc &);
	DaThuc operator*(const DaThuc &);
	friend ostream&operator<<(ostream&, DaThuc&);
};
DonThuc* findMid(DonThuc *head);
bool divideList(DonThuc *head, DonThuc *&head1, DonThuc *&head2);
DonThuc *mergeList(DonThuc *head1, DonThuc *head2);
bool mergeSort(DonThuc *&head);
bool ktBeHon(Node_Bien_Mu* node1, Node_Bien_Mu* node2);