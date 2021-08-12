#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class TIVI;
class HANG;
class date
{
    private:
        int d;
        int m;
        int y;
    public:
        void nhap();
        void xuat();
    friend class TIVI;
};
class NSX
{
    private:
        char tennsx[20];
        char diachi[30];
    public:
        void nhap();
        void xuat();
    friend class HANG;
};
class HANG
{
    protected:
        char tenhang[20];
        NSX x;
        float dongia;
    public:
        void nhap();
        void xuat();
};
class TIVI: private HANG
{
     private:
        float kichthuoc;
        date ngaynhap;
    public:
        void nhap();
        void xuat();
};
void date::nhap()
{
      cout<<"ngay nhap: ";cin>>d;
      cout<<"thang nhap : ";cin>>m;
      cout<<"nam nhap: ";cin>>y;
}
void date:: xuat()
{
    cout<<setw(8)<<d<<"/"<<m<<"/"<<y;
}
void NSX::nhap()
{
     cout<<"ten nsx:  ";fflush(stdin);gets(tennsx);
     cout<<"diachi: ";fflush(stdin);gets(diachi);
}
void NSX:: xuat()
{
    cout<<setw(10)<<tennsx;
    cout<<setw(10)<<diachi;

}
void HANG :: nhap()
{
    cout<<"ten hang: ";fflush(stdin);gets(tenhang);
    x.nhap();
    cout<<"don gia: ";cin>>dongia;
}
void HANG::xuat()
{
    cout<<setw(10)<<tenhang;
    x.xuat();
    cout<<setw(10)<<dongia;
}
void TIVI::nhap()
{
    HANG::nhap();
    cout<<"kich thuoc: ";cin>>kichthuoc;
    ngaynhap.nhap();
}
void TIVI :: xuat()
{
    HANG::xuat();
    cout<<setw(10)<<kichthuoc;
    ngaynhap.xuat();
}
void cot_mau()
{
    cout<<setw(10)<<"tenhang";
    cout<<setw(10)<<"tenNSX";
    cout<<setw(10)<<"diachi";
    cout<<setw(10)<<"dongia";
    cout<<setw(10)<<"kicthuoc";
    cout<<setw(15)<<"ngaynhap"<<endl;
}
int main()
{
    TIVI a;
    a.nhap();
    cout<<"\n\n thong tin vua nhap la: "<<endl<<endl;
    cot_mau();
    a.xuat();
    return 0;
}
