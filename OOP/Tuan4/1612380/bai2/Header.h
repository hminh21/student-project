#include "SinhVien.h"


void ReadFile(ifstream &fs, vector<SinhVien> &A);
void strtoken(char str[], const SinhVien& sv);
void SortAphalbet(vector <SinhVien> &sv);
ostream& operator<<(ostream& outDev, const NGAY& Ngay);