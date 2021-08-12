#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class CAUTHU;
class date
{
    private:
        int ngay;
        int thang;
        int nam;
    friend class CAUTHU;
};
class PERSON
{
    protected:
        char hoten[50];
        date x;
        char quequan[100];
};
class VANDONGVIEN : protected PERSON
{
    protected:
        char bomon[30];
        float thunhap;
};
class CAUTHU: private VANDONGVIEN
{
    private:
        char CLB[100];
        char vitri[100];
    public:
        void nhap();
        void xuat();
    friend void nhapds( CAUTHU a[], int &n);
    friend void sosanh( CAUTHU a[], int n);
    friend void thu_nhapmax( CAUTHU a[], int n);
};
void CAUTHU:: nhap()
{
    cout<<"\nHo ten: ";fflush(stdin);gets(hoten);
    cout<<"\nNgay sinh: \n\tNgay:";cin>>x.ngay;
    cout<<"\tThang: ";cin>>x.thang;
    cout<<"\tNam: ";cin>>x.nam;
    cout<<"Que quan: ";fflush(stdin);gets(quequan);
    cout<<"Bo mon: ";fflush(stdin);gets(bomon);
    cout<<"Thu nhap: ";cin>>thunhap;
    cout<<"Cau lac bo: ";fflush(stdin);gets(CLB);
    cout<<"Vi tri:";fflush(stdin);gets(vitri);
}
void CAUTHU:: xuat()
{
    cout<<setw(10)<<hoten;
    cout<<setw(10)<<x.ngay<<"/"<<x.thang<<"/"<<x.nam;
    cout<<setw(10)<<quequan;
    cout<<setw(10)<<bomon;
    cout<<setw(10)<<thunhap;
    cout<<setw(10)<<CLB;
    cout<<setw(10)<<vitri<<endl;
}
void hien_thi()
{
    cout<<setw(10)<<"hoten";
    cout<<setw(15)<<"ngay";
    cout<<setw(10)<<"quequan";
    cout<<setw(10)<<"bomon";
    cout<<setw(10)<<"thunhap";
    cout<<setw(10)<<"CLB";
    cout<<setw(10)<<"vitri"<<endl;
}
void nhapds( CAUTHU a[], int &n)
{
    do{
        cout<<"\n nhap vao danh sach cau thu: ";cin>>n;
        if( !((n>0)&&(n<50)) )cout<<"\n vui long nhap lai : ";
    }while(!((n>0)&&(n<50)));
    for(int i=0;i<n;i++)
    {
        cout<<"\n ====Cau thu thu "<<i+1 << ":";
        a[i].nhap();
    }
}
void sosanh( CAUTHU a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].CLB,"AA")==0)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n trong danh sach khong co cau thu o cau lac bo aa ! ";
    else{
        cout<<"\n danh sach cau thu o cau lac bo aa la: "<<endl;
        hien_thi();
        for( int i=0;i<n;i++)
            if(strcmp(a[i].CLB,"AA")==0)
                a[i].xuat();
    }
}
void thu_nhapmax( CAUTHU a[], int n)
{
    float maxx=a[0].thunhap;
    for( int i=1;i<n;i++)
        if(maxx<a[i].thunhap)maxx=a[i].thunhap;
    cout<<"\n danh sach cau thu co thu nhap max la: "<<endl;
    hien_thi();
    for( int i=0;i<n;i++)
        if(a[i].thunhap==maxx)a[i].xuat();
}
void hienthids( CAUTHU a[], int n)
{
    hien_thi();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
int main()
{
    CAUTHU a[50];
    int n;
    nhapds(a,n);
    hienthids(a,n);
    sosanh(a,n);
    thu_nhapmax(a,n);
    return 0;
}







