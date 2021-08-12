#include<iostream>
#include<string>
#include<stdio.h>
#include<iomanip>
using namespace std;
class quan_ly
{
    private:
        char maql[20];
        char ten[30];
    public:
        void nhap();
        void xuat();
    friend class phong_may;
};
class  may
{
    private:
        char mamay[20];
        char kieum[20];
        char tinhtrang[30];
    public:
        void nhap();
        void xuat();
    friend class phong_may;
};
class phong_may
{
    private:
        char maphong[20];
        char tenphong[30];
        float dientich;
        quan_ly x;
        may y[30];
        int n;
    public:
        void nhap();
        void xuat();
};
void quan_ly::nhap()
{
    cout<<"\n ma quan ly: "; fflush(stdin);gets(maql);
    cout<<"\n ho va ten: "; fflush(stdin);gets(ten);
}
void quan_ly::xuat()
{
    cout<<maql<<"\t" <<ten;
}
void may::nhap()
{
    cout<<"\n ma may: "; fflush(stdin);gets(mamay);
    cout<<"\n kieu may: "; fflush(stdin);gets(kieum);
    cout<<"\n tinh trang : "; fflush(stdin);gets(tinhtrang);
}
void may::xuat()
{
    cout<<setw(10)<<mamay<<setw(10)<<kieum<<setw(10)<<tinhtrang<<endl;
}
void phong_may::nhap()
{
    cout<<"\n ma phong : "; fflush(stdin);gets(maphong);
    cout<<"\n ten phong :" ; fflush(stdin);gets(tenphong);
    cout<<"\n dien tich: "; cin>>dientich;
    cout<<"\n thong tin nguoi quan ly , "; x.nhap();
    do{
        cout<<"\n nhap so luong may: ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai so luong may: ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n may "<< i+1<<" :" ;y[i].nhap();
    }
}
void phong_may:: xuat()
{
    cout<<"\n ma phong : "<<maphong;
    cout<<"\n ten phong :" <<tenphong;
    cout<<"\n dien tich: "<<dientich;
    cout<<"\n nguoi quan ly: ";x.xuat();cout<<"\n";
    cout<<"\n thong tin cua cac may la : \n ";
    cout<<setw(10)<<"mamay";
    cout<<setw(10)<<"kieumay";
    cout<<setw(10)<<"tinhtrang"<<endl;
    for( int i=0;i<n;i++)
    {
        y[i].xuat();
    }
}
main()
{
    phong_may a;
    a.nhap();
    a.xuat();
}














