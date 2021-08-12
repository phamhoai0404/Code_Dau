#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class SANPHAM
{
    protected:
        char masp[20];
        char tensp[20];
        int ngaysx;
        char maus[20];
    public:
        void nhap();
        void xuat();
};
class MAYGIAT: private SANPHAM
{
    private:
        int kg_quan_ao_max;
    public:
        void nhap();
        void xuat();
};
class TULANH: private SANPHAM
{
    private:
        int dungtich;
    public:
        void nhap();
        void xuat();
};
void SANPHAM::nhap()
{
    cout<<"\nma san pham: ";fflush(stdin);gets(masp);
    cout<<"ten san pham: ";fflush(stdin);gets(tensp);
    cout<<"ngay san xuat: ";cin>>ngaysx;
    cout<<"mau sac: "; fflush(stdin);gets(maus);
}
void SANPHAM::xuat()
{
    cout<<setw(10)<<masp;
    cout<<setw(10)<<tensp;
    cout<<setw(10)<<ngaysx;
    cout<<setw(10)<<maus;
}
void MAYGIAT::nhap()
{
    SANPHAM::nhap();
    cout<<"kg quan ao max : ";cin>>kg_quan_ao_max;
}
void TULANH::nhap()
{
    SANPHAM::nhap();
    cout<<"dung tich : ";cin>>dungtich;
}
void MAYGIAT:: xuat()
{
    SANPHAM::xuat();
    cout<<setw(10)<<kg_quan_ao_max<<endl;
}
void TULANH:: xuat()
{
    SANPHAM::xuat();
    cout<<setw(10)<<dungtich<<endl;
}
void hienthi_maygiat()
{
    cout<<setw(10)<<"masp";
    cout<<setw(10)<<"tensp";
    cout<<setw(10)<<"ngaysx";
    cout<<setw(10)<<"maus";
    cout<<setw(10)<<"kgmax"<<endl;
}
void hienthi_tulanh()
{
    cout<<setw(10)<<"masp";
    cout<<setw(10)<<"tensp";
    cout<<setw(10)<<"ngaysx";
    cout<<setw(10)<<"maus";
    cout<<setw(10)<<"dungtich"<<endl;
}
int main()
{
    TULANH b;
    MAYGIAT a;
    cout<<"\n nhap TT MAY GIAT: ";
    a.nhap();hienthi_maygiat();a.xuat();
    cout<<"\n nhap TT TU LANH: ";
    b.nhap();hienthi_tulanh();b.xuat();
    return 0;
}



