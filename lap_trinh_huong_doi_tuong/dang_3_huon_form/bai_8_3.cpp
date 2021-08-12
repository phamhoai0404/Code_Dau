#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class PHIEU;
class date
{
    private:
        int d;
        int m;
        int y;
    public:
        void nhap();
        void xuat();
   friend class PHIEU;
};
class PERSON
{
    private:
        char tennv[20];
        char chucvu[30];
    public:
        void nhap();
    friend class PHIEU;
};
class PHONG
{
    private:
        char maphong[20];
        char tenphong[20];
        char truongphong[20];
    public:
        void nhap();
    friend class PHIEU;
};
class TAISAN
{
     private:
        char ten[20];
        int soluong;
        char tinhtrang[20];
    public:
        void nhap();
        void xuat();
    friend class PHIEU;
};
class PHIEU
{
    public:
        char maphieu[20];
        date ngaykiemke;
        PERSON nhanvienkiemke;
        PHONG taiphong;
        TAISAN x[30];
        int xn;
    public:
        void nhap();
        void xuat();
        int tong_so_luong()
        {
            int k=0;
            for( int i=0;i<xn;i++)
                k+=x[i].soluong;
            return k;
        }

};
void date::nhap()
{
      cout<<"\tngay nhap: ";cin>>d;
      cout<<"\tthang nhap : ";cin>>m;
      cout<<"\tnam nhap: ";cin>>y;
}
void date:: xuat()
{
      cout<<setw(8)<<d<<"/"<<m<<"/"<<y;
}
void PERSON::nhap()
{
    cout<<"ten nhan vien kiem ke:  ";fflush(stdin);gets(tennv);
    cout<<"chuc vu:  ";fflush(stdin);gets(chucvu);
}
void PHONG::nhap()
{
    cout<<"kiem ke tai phong:  ";fflush(stdin);gets(tenphong);
    cout<<"ma phong:  ";fflush(stdin);gets(maphong);
    cout<<"truong phong:  ";fflush(stdin);gets(truongphong);
}
void TAISAN:: nhap()
{
    cout<<"\n\t+ ten tai san :  ";fflush(stdin);gets(ten);
    cout<<"\t+ so luong: ";cin>>soluong;
    cout<<"\t+ tinh trang:  ";fflush(stdin);gets(tinhtrang);
}
void TAISAN :: xuat()
{
    cout<<setw(25)<<ten;
    cout<<setw(20)<<soluong;
    cout<<setw(20)<<tinhtrang<<endl<<endl;
}
void cot_mau()
{
    cout<<setw(30)<<"ten tai san";
    cout<<setw(20)<<"so luong";
    cout<<setw(20)<<" tinh trang"<<endl<<endl;
}
void PHIEU::nhap()
{
      cout<<"\nma phieu:  ";fflush(stdin);gets(maphieu);
      cout<<"ngay kiem ke: \n";ngaykiemke.nhap();
      nhanvienkiemke.nhap();
      taiphong.nhap();
      cout<<"\n so luong tai san: ";cin>>xn;
      for( int i=0;i<xn;i++)
      {
          cout<<"\n =====tai san thu: "<<i+1;
          x[i].nhap();
      }
}
void PHIEU::xuat()
{
    cout<<"\n\n\t\t=========PHIEU KIEM KE TAI SAN==========="<<endl<<endl;
    cout<<"\tMa phieu: "<<maphieu<<setw(20)<<"Ngay kiem ke:"<<right;ngaykiemke.xuat();
    cout<<"\n\tNhan vien kiem ke: "<<nhanvienkiemke.tennv<<setw(20)<<"Chuc vu:"<<nhanvienkiemke.chucvu;
    cout<<"\n\tKiem ke tai phong: "<<taiphong.tenphong<<setw(20)<<"Ma phong: "<<taiphong.maphong;
    cout<<"\n\tTruong phong: "<<taiphong.truongphong<<endl;
    cot_mau();
    for( int i=0;i<xn;i++)
        x[i].xuat();
    cout<<"\n\n\t So tai khoan kiem ke: "<<xn;
    cout<<"\t\t Tong so luong: "<<tong_so_luong()<<endl;
}
int main()
{
    PHIEU x;
    x.nhap();
    system("cls");
    x.xuat();
    return 0;
}
