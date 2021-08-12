#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
class PERSON
{
    protected:
        char hoten[20];
        int ngsinh;
        char quequan[20];
};
class KYSU:private PERSON
{
    private:
        char nganh[20];
        int namtn;
    public:
        void nhap();
        void xuat();
    friend void timnamtnmax( KYSU a[], int n);
};
void KYSU :: nhap()
{
    cout<<"\n ho ten: ";fflush(stdin);gets(hoten);
    cout<<"\n ngay sinh: ";cin>>ngsinh;
    cout<<"\n que quan: ";fflush(stdin);gets(quequan);
    cout<<"\n nganh : "; fflush(stdin);gets(nganh);
    cout<<"\n nam tn: ";cin>>namtn;
}
void KYSU::xuat()
{
    cout<<setw(10)<<hoten;
    cout<<setw(10)<<ngsinh;
    cout<<setw(10)<<quequan;
    cout<<setw(10)<<nganh;
    cout<<setw(10)<<namtn<<endl;
}
void hienthi()
{
    cout<<setw(10)<<"hoten";
    cout<<setw(10)<<"ngsinh";
    cout<<setw(10)<<"quequan";
    cout<<setw(10)<<"nganh";
    cout<<setw(10)<<"namtn"<<endl;
}
void timnamtnmax( KYSU a[], int n)
{
    int maxx= a[0].namtn;
    for( int i=1;i<n;i++)
        if(a[i].namtn>maxx)maxx=a[i].namtn;
    cout<<"\n thong tin cua ky su tot nghiep gan day nhat: \n";
    hienthi();
    for( int i=0;i<n;i++)
        if(a[i].namtn==maxx)a[i].xuat();
}
int main()
{
    KYSU a[20];
    int n;
    do{
        cout<<"\n nhap vao so ky su: ";cin>>n;
        if(n<0||n>20)cout<<"\n vui long nhap lai ! ";
    }while(n<0||n>20);
    for( int i=0;i<n;i++)
    {
        cout<<"\n ki su "<<i+1 << ":";
        a[i].nhap();
    }
    hienthi();
    for( int i=0;i<n;i++)
        a[i].xuat();
    timnamtnmax(a,n);
    return 0;
}
