#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
class VEHICLE
{
    protected:
        char nhanhieu[20];
        int namsx;
        char hang[20];
    public:
        void nhap();
        void xuat();
};
class OTO: private VEHICLE
{
    private:
        int sochongoi;
        int dungtich;
    public:
        void nhap();
        void xuat();
};
class MOTO: private VEHICLE
{
    private:
        int phankhoi;
    public:
        void nhap();
        void xuat();
};
void VEHICLE::nhap()
{
    cout<<"\n nhan hieu: ";fflush(stdin);gets(nhanhieu);
    cout<<"\n nam san xuat: ";cin>>namsx;
    cout<<"\n hang: ";fflush(stdin);gets(hang);
}
void VEHICLE::xuat()
{
    cout<<setw(10)<<nhanhieu;
    cout<<setw(10)<<namsx;
    cout<<setw(10)<<hang;
}
void OTO::nhap()
{
    VEHICLE::nhap();
    cout<<"\n so cho ngoi: ";cin>>sochongoi;
    cout<<"\n dung tich: ";cin>>dungtich;
}
void OTO::xuat()
{
    VEHICLE :: xuat();
    cout<<setw(10)<<sochongoi<<setw(10)<<dungtich<<endl;
}
void MOTO::nhap()
{
    VEHICLE::nhap();
    cout<<"\n phan khoi: ";cin>>phankhoi;
}
void MOTO::xuat()
{
    VEHICLE::xuat();
    cout<<setw(10)<<phankhoi<<endl;
}
void hienthioto()
{
    cout<<setw(10)<<"nhanhieu";
    cout<<setw(10)<<"namsx";
    cout<<setw(10)<<"hang";
    cout<<setw(15)<<"sochongoi";
    cout<<setw(10)<<"dungtich"<<endl;
}
void hienthimoto()
{
    cout<<setw(10)<<"nhanhieu";
    cout<<setw(10)<<"namsx";
    cout<<setw(10)<<"hang";
    cout<<setw(10)<<"phankhoi"<<endl;
}
int main()
{
    OTO a;
    cout<<"\n nhap thong tin xe oto: ";a.nhap();
    cout<<"\ hien thi thong tin oto: \n";hienthioto();a.xuat();
    MOTO b;
    cout<<"\n nhap thong tin xe moto: ";b.nhap();
    cout<<"\n hien thi thong tin moto:\n";hienthimoto();b.xuat();
}
