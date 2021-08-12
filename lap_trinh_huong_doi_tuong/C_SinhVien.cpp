#include <iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class SinhVien
{
	private:
		char hoten[30];
		int toan, ly, hoa;
		char k[30];
	public:
		void nhap();
		void xuat();
		float TB();
		string xloai();

};
void SinhVien::nhap()
{
	cout<<"\n nhap ho ten sinh vien: "; fflush(stdin); gets(hoten);
	cout<<"\n nhap diem Toan: "; cin>>toan;
	cout<<"\n nhap diem Ly: "; cin>>ly;
	cout<<"\n nhap diem Hoa: "; cin>>hoa;
}
float SinhVien::TB()
{
	float tbc=(toan+ly+hoa)*1.0/3;
	return tbc;
}
string SinhVien::xloai()
{
    string k;
    if( TB() < 5 ) k="YEU";
    else if(TB()<7)k="RUNGBINH";
         else if(TB()<8)k="KHA";
               else k="GIOI";
   return k;
}
void SinhVien::xuat()
{
	cout<<setw(10)<<hoten;
	cout<<setw(10)<<toan;
	cout<<setw(10)<<ly;
	cout<<setw(10)<<hoa;
	cout<<setw(10)<<TB();
	cout<<setw(10)<<xloai()<<endl;
}
int main(){
	SinhVien sv[30];
	int n;
	cout<<"\n nhap so sinh vien: "; cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"		sinh vien thu "<<i+1<<endl;
		sv[i].nhap();
	}
	cout<<setw(10)<<"hoten";
	cout<<setw(10)<<"toan";
	cout<<setw(10)<<"ly";
	cout<<setw(10)<<"hoa";
	cout<<setw(10)<<"TBC";
	cout<<setw(10)<<"xeploai";
	cout<<endl;
	for(int i=0;i<n;i++)
	sv[i].xuat();
	return 0;
}

