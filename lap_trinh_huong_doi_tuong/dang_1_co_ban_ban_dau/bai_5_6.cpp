#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
class HANHOA
{
    int a;
};
class SANPHAM
{
    protected:
        char masp[20];
        char tensp[20];
        int ngaysx;
        float trluong;
        char maus[20];
    public:
        void nhap();
        void xuat();
};
class HANGDIENTU:  private SANPHAM
{
    private:
        int congxuat;
        char dongdien[20];
    public:
        void nhap();
        void xuat();
    friend void nhapmang( HANGDIENTU a[], int &n);
    friend void xuatmang( HANGDIENTU a[], int n);
    friend void trluongmin( HANGDIENTU a[], int n);
};
void SANPHAM::nhap()
{
    cout<<"\nma san pham: ";fflush(stdin);gets(masp);
    cout<<"ten san pham: ";fflush(stdin);gets(tensp);
    cout<<"ngay san xuat: ";cin>>ngaysx;
    cout<<"trong luong : ";cin>>trluong;
    cout<<"mau sac: "; fflush(stdin);gets(maus);
}
void SANPHAM::xuat()
{
    cout<<setw(10)<<masp;
    cout<<setw(10)<<tensp;
    cout<<setw(10)<<ngaysx;
    cout<<setw(10)<<trluong;
    cout<<setw(10)<<maus;
}
void HANGDIENTU::nhap()
{
    SANPHAM::nhap();
    cout<<"cong suat : ";cin>>congxuat;
    cout<<"dong dien: ";fflush(stdin);gets(dongdien);
}
void HANGDIENTU:: xuat()
{
    SANPHAM::xuat();
    cout<<setw(10)<<congxuat;
    cout<<setw(10)<<dongdien<<endl;
}
void hienthi()
{
    cout<<setw(10)<<"masp";
    cout<<setw(10)<<"tensp";
    cout<<setw(10)<<"ngaysx";
    cout<<setw(10)<<"trluong";
    cout<<setw(10)<<"maus";
    cout<<setw(10)<<"congxuat";
    cout<<setw(10)<<"dongdien"<<endl;
}
void nhapmang( HANGDIENTU a[], int &n)
{
    do{
        cout<<"\n nhap vao so hang dien tu : ";cin>>n;
        if(n<0||n>20)cout<<"\n vui long nhap lai !";
    }while(n<0||n>20);
    for( int i=0;i<n;i++)
    {
        cout<<"\n   dien tu thu "<<i+1<<":";
        a[i].nhap();
    }
}
void xuatmang( HANGDIENTU a[], int n)
{
    hienthi();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void trluongmin( HANGDIENTU a[], int n)
{
    float minn=a[0].trluong;
    for( int i=1;i<n;i++)
        if(minn>a[i].trluong)minn=a[i].trluong;
    cout<<"\n nhung mat hang co trong luong nho nhat la: \n";
    hienthi();
    for( int i=0;i<n;i++)
        if(a[i].trluong==minn)a[i].xuat();
}
int main()
{
    HANGDIENTU a[20];
    int n;
    nhapmang(a,n);
    xuatmang(a,n);
    trluongmin(a,n);
    return 0;
}


