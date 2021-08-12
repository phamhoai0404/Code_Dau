#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
class date
{
    private:
        int ngay;
        int thang;
        int nam;
    friend class congchuc;
};
class nhansu
{
    protected:
        char hoten[50];
        char gioitinh[5];
        date x;
        char diachi[100];
};
class congchuc : private nhansu
{
    private:
        char nganhnghe[20];
        int namvao;
        char trinhdo[50];
        float hsluong;
        float phcap;
    public:
        void nhap();
        void xuat();
        float thunhap()
        {
            return hsluong*830+phcap;
        }
    friend void nhapds( congchuc a[], int &n);
    friend void hienthids( congchuc a[], int n);
    friend void thu_nhapmin( congchuc a[], int n);
    friend void sapxep( congchuc a[], int n);
};
void congchuc::nhap()
{
    cout<<"\nHo ten: ";fflush(stdin);gets(hoten);
    cout<<"Gioi tinh: ";fflush(stdin);gets(gioitinh);
    cout<<"nam sinh : \n\tngay: ";cin>>x.ngay;
    cout<<"\tthang:";cin>>x.thang;
    cout<<"\tnam: ";cin>>x.nam;
    cout<<"Dia chi: ";fflush(stdin);gets(diachi);
    cout<<"Nganh nghe: ";fflush(stdin);gets(nganhnghe);
    cout<<"Nam vao: ";cin>>namvao;
    cout<<"Trinh do: ";fflush(stdin);gets(trinhdo);
    cout<<"He so luong : ";cin>>hsluong;
    cout<<"phcap : ";cin>>phcap;
}
void congchuc:: xuat()
{
    cout<<setw(10)<<hoten;
    cout<<setw(10)<<gioitinh;
    cout<<setw(10)<<x.ngay<<"/"<<x.thang<<"/"<<x.nam;
    cout<<setw(10)<<diachi;
    cout<<setw(10)<<nganhnghe;
    cout<<setw(10)<<namvao;
    cout<<setw(10)<<trinhdo;
    cout<<setw(10)<<hsluong;
    cout<<setw(10)<<phcap;
    cout<<setw(10)<<thunhap()<<endl;
}
void hien_thi()
{
    cout<<setw(10)<<"hoten";
    cout<<setw(10)<<"gioitinh";
    cout<<setw(15)<<"namsinh";
    cout<<setw(10)<<"diachi";
    cout<<setw(10)<<"nganhnghe";
    cout<<setw(10)<<"namvao";
    cout<<setw(10)<<"trinhdo";
    cout<<setw(10)<<"hsluong";
    cout<<setw(10)<<"phcap";
    cout<<setw(10)<<"thunhap"<<endl;
}
void nhapds( congchuc a[], int &n)
{
    do{
        cout<<"\n so cong chuc: ";cin>>n;
        if( !((n>0)&& (n<=50)) ) cout<<"\n vui long nhap lai , ";
    }while ( !((n>0)&& (n<=50))) ;
    for( int i=0 ;i<n;i++)
    {
        cout<<"\n ======== cong chuc thu " <<i+1 << " : ";
        a[i].nhap();
    }
}
void hienthids(congchuc a[], int n)
{
    hien_thi();
    for(int i=0;i<n;i++)
        a[i].xuat();
}
void thu_nhapmin( congchuc a[], int n)
{
    float minn= a[0].thunhap();
    for( int i=1;i<n;i++)
        if(minn>a[i].thunhap())minn=a[i].thunhap();
    cout<<"\n ds cong chuc thu nhap min la : "<<endl;
    hien_thi();
    for( int i=0;i<n;i++)
        if(a[i].thunhap()==minn)
            a[i].xuat();
}
void hoandoi( congchuc &a, congchuc &b)
{
    congchuc tam=a;
    a=b;
    b=tam;
}
void sapxep( congchuc a[], int n)
{
    for( int i=0;i<n-1;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(strcmp(a[j].hoten,a[j-1].hoten)>0)
            {
                hoandoi(a[j],a[j-1]);
                k=1;
            }
        if(k==0)break;
    }
    cout<<"\n thong tin sau khi sapxep: "<<endl;
    hienthids(a,n);
}
int main()
{
    congchuc a[51]; int n;
    nhapds(a,n);
    hienthids(a,n);
    thu_nhapmin( a, n);
    sapxep(a,n);

    return 0;
}
