#include<iostream>
#include<string>
#include<iomanip>
#include<stdio.h>
using namespace std;
class phieu;
class hang
{
    private:
        char tenhang[30];
        float dongia;
        int soluong;
    public:
        void nhap()
        {
            cout<<"\nten hang: "; fflush(stdin); gets(tenhang);
            cout<<"\ndon gia: "; cin>>dongia;
            cout<<"\nso luong: "; cin>>soluong;
        }
        float tien()
        {
        	float k=0;
            k= dongia*soluong;
            return k;
        }
        void xuat()
        {
            cout<<setw(15)<<tenhang;
            cout<<setw(15)<<dongia;
            cout<<setw(15)<<soluong;
            cout<<setw(15)<<tien()<<endl;
        }
        friend class phieu;
};
class date
{
    private:
        int d, m ,y;
    public:
        void nhap()
        {
            cout<<"\nngay: "; cin>>d;
            cout<<"\nthang: "; cin>>m;
            cout<<"\nnam: "; cin>>y;
        }
        void xuat()
        {
            cout<<d<<"/"<<m<<"/"<<y<<endl;
        }
        friend class phieu;

};
class phieu
{
    private:
        char maphieu[10];
        date ngaylap;
        hang a[100];
        int n;
    public:
        void nhap();
        void xuat();
        float tong()
        {
            float t = 0;
            for( int i = 1; i <= n; i++)
                t += (float)a[i].dongia * a[i].soluong;
            return t;
        }

};
void phieu::nhap()
{
    cout<<"\nma phieu: "; fflush(stdin); gets(maphieu);
    cout<<"\n nhap ngay nhap:";	ngaylap.nhap();
    cout<<"\nnhap so luong hang: "; cin>>n;
    for( int i = 1; i <= n; i++)
    {
        cout<<"\nstt: "<<i<<endl;
        a[i].nhap();
    }
}
void phieu::xuat()
{
    cout<<"\n\t\t======== PHIEU MUA HANG========="<<endl;
    cout<<"\n\tMa phieu: "<<maphieu<<"\t\t\t Thanh lap:";ngaylap.xuat();cout<<endl;
    cout<<setw(15)<<"Ten hang";
    cout<<setw(15)<<"Don gia";
    cout<<setw(15)<<"So luong";
    cout<<setw(15)<<"Thanh tien"<<endl;
    for( int i = 1; i <= n; i++)
        a[i].xuat();
    cout<<endl;
    cout<<setw(50)<<"Cong thanh tien: "<<tong()<<endl;
}
int main ()
{
    phieu x;
    x.nhap();
    x.xuat();
}
