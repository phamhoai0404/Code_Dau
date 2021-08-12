#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class THUCPHAM
{
    protected:
        char tentp[20];
        int gia;
    public:
        void nhap();
        void xuat();
};
class TPHOP: private THUCPHAM
{
    private:
        int sohop;
    public:
        void nhap();
        void xuat();
};
class TPKHOP: private THUCPHAM
{
    private:
        int khoiluong;
    public:
        void nhap();
        void xuat();
};
void THUCPHAM::nhap()
{
    cout<<"\n\nten thuc pham: ";fflush(stdin);gets(tentp);
    cout<<"gia: ";cin>>gia;
}
void THUCPHAM::xuat()
{
    cout<<setw(10)<<tentp;
    cout<<setw(10)<<gia;
}
void TPHOP::nhap()
{
    THUCPHAM::nhap();
    cout<<"so hop: ";cin>>sohop;
}
void TPKHOP::nhap()
{
    THUCPHAM::nhap();
    cout<<"khoiluong : ";cin>>khoiluong;
}
void TPHOP:: xuat()
{
    THUCPHAM::xuat();
    cout<<setw(10)<<sohop<<endl;
}
void TPKHOP:: xuat()
{
    THUCPHAM::xuat();
    cout<<setw(15)<<khoiluong<<endl;
}
void hienthi_tphop()
{
    cout<<setw(10)<<"tentp";
    cout<<setw(10)<<"gia";
    cout<<setw(10)<<"sohop"<<endl;
}
void hienthi_tpkhop()
{
    cout<<setw(10)<<"tentp";
    cout<<setw(10)<<"gia";
    cout<<setw(15)<<"khoiluong"<<endl;
}
int main()
{
    TPHOP a;
    TPKHOP b;
    cout<<"\n  1.nhap TT TP HOP: ";
    a.nhap();hienthi_tphop();a.xuat();
    cout<<"\n  2.nhap TT TP KHONG HOP: ";
    b.nhap();hienthi_tpkhop();b.xuat();
    return 0;
}




