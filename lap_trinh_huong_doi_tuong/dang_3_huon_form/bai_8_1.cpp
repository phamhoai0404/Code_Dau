#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class PHIEUNHAPHANG;
class DATEt
{
    private:
        int day;
        int month;
        int year;
    public:
        void nhap();
        void xuat();
    friend class PHIEUNHAPHANG;
};
class HANGHOA
{
    private:
        char ten[20];
        float gia;
        int soluong;
    public:
        void nhap();
        void xuat();
        float thanhtien(){
            return gia*soluong;
        }
    friend class PHIEUNHAPHANG;
};
class NHACUNGCAP
{
    protected:
        char mancc[20];
        char tenncc[20];

    public:
        void nhap();
        void xuat();
};
class PHIEUNHAPHANG: private NHACUNGCAP
{
    private:
        char maphieu[20];
        DATEt ngaylap;
        char diachi[20];
        HANGHOA x[30];
        int xn;
    public:
        void nhap();
        void xuat();
        float tong();
};
float PHIEUNHAPHANG::tong()
{
    float k=0;
    for( int i=0;i<xn;i++)
        k+=x[i].thanhtien();
    return k;
}
void DATEt::nhap()
{
    cout<<"Ngay lap: ";cin>>day>>month>>year;
}
void DATEt:: xuat()
{
    cout<<day<<"/" <<month << "/" <<year;
}
void NHACUNGCAP::nhap()
{
    cout<<"Ten nha cung cap: ";fflush(stdin);gets(tenncc);
    cout<<"Ma nha cung cap: ";fflush(stdin);gets(mancc);
}
void HANGHOA::nhap()
{
    cout<<"\n\tTen hang: ";fflush(stdin);gets(ten);
    cout<<"\tDon gia: ";cin>>gia;
    cout<<"\tSo luong: ";cin>>soluong;
}
void HANGHOA:: xuat()
{
   cout<<setw(15)<<ten;
   cout<<setw(15)<<gia;
   cout<<setw(15)<<soluong;
   cout<<setw(15)<<thanhtien()<<endl<<endl;
}
void PHIEUNHAPHANG::nhap()
{
    cout<<"\nMa phieu: ";fflush(stdin);gets(maphieu);
    ngaylap.nhap();
    cout<<"Dia chi: ";fflush(stdin);gets(diachi);
    NHACUNGCAP::nhap();
    cout<<"====nhap so luong hang hoa: ";cin>>xn;
    for( int i=0;i<xn;i++)
    {
        cout<<" + hang "<<i+1;
        x[i].nhap();
    }
}
void cot_mau_hang()
{
    cout<<setw(15)<<"Tenhang";
    cout<<setw(15)<<"Dongia";
    cout<<setw(15)<<"Soluong";
    cout<<setw(15)<<"Thanhtien"<<endl;
}
void PHIEUNHAPHANG::xuat()
{
    cout<<"\n\n\t\t==============PHIEU NHAP HANG================\n\n";
    cout<<setw(20)<<"Ma phieu: "<<maphieu;
    cout<<setw(20)<<"Ngay lap: ";ngaylap.xuat();cout<<endl;
    cout<<setw(18)<<"Ma NCC: "<<mancc;
    cout<<setw(21)<<"Ten NCC: "<<tenncc<<endl;
    cout<<setw(19)<<"Dia Chi: "<<diachi<<endl<<endl;
    cot_mau_hang();
    for( int i=0;i<xn;i++)
        x[i].xuat();
    cout<<setw(45)<<"cong thanh tien:";
    cout<<setw(15)<<tong()<<endl;
}
int main()
{
    PHIEUNHAPHANG x;
    x.nhap();
    system("cls");
    x.xuat();
}

