#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class XEHOI
{
    private:
        char nhanhieu[20];
        char hangsx[30];
        char kieudang[30];
        char mauson[30];
        int namsx;
        char xuatxu[20];
        float gia;
    public:
        void nhap();
        void xuat();
        friend void timkiem(XEHOI a[], int n);
        friend void sap_xep(XEHOI a[], int n);
};
void XEHOI::nhap()
{
      cout<<"\nnhan hieu:  ";fflush(stdin);gets(nhanhieu);
      cout<<"hang sx: ";fflush(stdin);gets(hangsx);
      cout<<"kieu dang: ";fflush(stdin);gets(kieudang);
      cout<<"mau son: ";fflush(stdin);gets(mauson);
      cout<<"nam sx: ";cin>>namsx;
      cout<<"xuat xu: ";fflush(stdin);gets(xuatxu);
      cout<<"gia ban: ";cin>>gia;
}
void cot_mau()
{
    cout<<setw(15)<<"nhan hieu";
    cout<<setw(15)<<"hang sx";
    cout<<setw(15)<<"kieu dang";
    cout<<setw(15)<<"mau son";
    cout<<setw(15)<<"namsx";
    cout<<setw(15)<<"xuat xu";
    cout<<setw(15)<<"gia ban"<<endl;
}
void XEHOI::xuat()
{
    cout<<setw(15)<<nhanhieu;
    cout<<setw(15)<<namsx;
    cout<<setw(15)<<kieudang;
    cout<<setw(15)<<mauson;
    cout<<setw(15)<<namsx;
    cout<<setw(15)<<xuatxu;
    cout<<setw(15)<<gia<<endl;
}
void nhapds(XEHOI a[], int &n)
{
    do{
        cout<<"\n nhap vao so xehoi:  ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n xe hoi thu: "<<i+1;
        a[i].nhap();
    }
}
void timkiem(XEHOI a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].nhanhieu,"Toyota")==0)
        {
           k=1;break;
        }
    if(k==0)cout<<"\n trong danh sach khong co xehoi nao thuoc hang Toyota !"<<endl;
    else{
        cout<<"\n xe hoi thuoc hang Toyota la: "<<endl;
        cot_mau();
        for( int i=0;i<n;i++)
            if(strcmp(a[i].nhanhieu,"Toyota")==0)
                a[i].xuat();
    }
}
void sap_xep(XEHOI a[], int n)
{
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(a[j].gia<a[j-1].gia)
            {
                XEHOI tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)return;
    }
}
void hienthi( XEHOI a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
int main()
{
    int n;
    XEHOI a[20];
    nhapds(a,n);
    cout<<"\n danh sach vua nhap vao la: "<<endl;
    hienthi(a,n);
    timkiem(a,n);
    sap_xep(a,n);
    cout<<"\n danh sach sau khi sap xep la: "<<endl;
    hienthi(a,n);
    return 0;
}
