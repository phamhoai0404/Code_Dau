#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
////
////CLASS NGAY
class date
{
    private:
        int d;
        int m;
        int y;
    public:
        void nhap();
        void xuat();
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
//MOT CLASS THONG THUONG
class PHONG
{
    private:
        char x[30];
        float y;
    public:
        void nhap();
        void xuat();

};
// PHAN NHAP XUAT CHUNG
void PHONG::nhap()
{
    cout<<"  ";fflush(stdin);gets();
    cout<<" ";cin>>;
}
void TAISAN :: xuat()
{
    cout<<setw(15)<<;
    cout<<setw(15)<<;
    cout<<setw(15)<<<<endl<<endl;
}
// PHAN COT MAU
void cot_mau()
{
    cout<<setw(15)<<"";
    cout<<setw(15)<<"";
    cout<<setw(15)<<" "<<endl<<endl;
}
// DAY LA NHAP n SO LUONG CLASS
void nhapds(XEHOI a[], int &n)
{
    do{
        cout<<"\n nhap vao :  ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthi( XEHOI a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
////TÌM KIẾM
void tim_kiem(XEHOI a[], int n)
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
// PHAN SAP XEP
void sap_xep( doanhnghiep a[], int n)
{
    cout<<"\n doanh nghiep sau khi sap xep theo chieu giam dan cua ten thanh pho la: "<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
        {
            if(strcmp(a[j].dc.thanhpho,a[j-1].dc.thanhpho)>0)
            {
                doanhnghiep tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        }
        if(k==1)break;
    }
    hienthids(a,n);
}
//PHAN XOA VA XOA HET
void xoa1( Sinh_Vien a[], int &n, int k)
{
    for( int i=k;i<n-1;i++)
        a[i]=a[i+1];
    n--;
}
void xoa_het( Sinh_Vien a[], int &n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(a[i].ngaysinh.year==1998)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n\n Trong danh sach khong co sinh vien sinh nam 1987 !";
    else{
        for( int i=0;i<n;i++)
            if(a[i].ngaysinh.year==1998)
            {
                xoa1(a,n,i);
                i--;
            }
        cout<<"\n\t\t\t\t==THONG TIN SINH VIEN SAU KHI XOA NGUOI SINHH NAM 1987 =="<<endl<<endl;
        hienthi(a,n);
    }
}
//NHAP VA SUA DOI TOAN BO THONG TIN
void thay_the(XEHOI a[], int n)
{
    char x[20];
    cout<<"\n nhap vao nhan hieu xe hoi can sua: ";fflush(stdin);gets(x);
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].nhanhieu,x)==0)k++;
    if(k==0)cout<<"\n trong danh sach khong co xehoi nao thuoc hang "<<x<<" !"<<endl;
    else{
        cout<<"\n  Sua thong tin  xe hoi thuoc hang "<<x<<" la: "<<endl;
        int z=1;
        for( int i=0;i<n;i++)
        {
            if(strcmp(a[i].nhanhieu,x)==0)
            {
                cout<<"==>> xe "<<z++<<":";
                a[i].nhap();k--;
            }
            if(k==0)break;
        }
        cout<<"\n thong tin sau khi sua la : "<<endl;
        hienthi(a,n);
    }
}
//CHEN
void chen1( XEHOI a[], int &n, int k, XEHOI x)
{
    for( int i=n;i>k-1;i--)
        a[i]=a[i-1];
    a[k-1]=x;
    n++;
}
int main()
{
    cout<<"\n\t\t\t\t========  ==========="<<endl<<endl;
}






















