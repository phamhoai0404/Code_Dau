#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class doanhnghiep;
class date
{
    private:
        int day;
        int month;
        int year;
    public:
        void nhap();
        void xuat();
    friend class doanhnghiep;
};
class diachi
{
    private:
        char dienthoai[12];
        char phuong[30];
        char quan[30];
        char thanhpho[30];
    friend class doanhnghiep;
    friend void y_c(doanhnghiep a[], int n);
};
class doanhnghiep
{
    private:
        int madn;
        char tendn[60];
        date ngaytl;
        diachi dc;
        char giamdoc[30];
        long doanhthu;
    public:
        void nhap();
        void xuat();
    friend void y_a( doanhnghiep a[],int n);
    friend void y_b( doanhnghiep a[],int n);
    friend void y_c( doanhnghiep a[], int n);
};
void date::nhap()
{
    cin>>day>>month>>year;
}
void date:: xuat()
{
    cout<<day<<"/" <<month << "/" <<year;
}
void doanhnghiep::nhap()
{
     cout<<"\n ma doanh nghiep: ";  cin>>madn;
     cout<<"ten doanh nghiep : ";fflush(stdin);gets(tendn);
     cout<<"ngay thanh lap: "; ngaytl.nhap();
     cout<<"dien thoai :"; fflush(stdin);gets(dc.dienthoai);
     cout<<"phuong : ";fflush(stdin);gets(dc.phuong);
     cout<<"quan : ";fflush(stdin);gets(dc.quan);
     cout<<"thanh pho:  ";fflush(stdin);gets(dc.thanhpho);
     cout<<"giam doc: ";fflush(stdin);gets(giamdoc);
     cout<<"doanh thu: ";cin>>doanhthu;
}
void cot_mau()
{
    cout<<setw(5)<<"madn";
    cout<<setw(10)<<"tendn";
    cout<<setw(20)<<"ngaytl";
    cout<<setw(15)<<"dienthoai";
    cout<<setw(24)<<"diachi";
    cout<<setw(10)<<"giamdoc";
    cout<<setw(10)<<"doanhthu"<<endl;
}
void doanhnghiep::xuat()
{
    cout<<setw(5)<<madn;
    cout<<setw(10)<<tendn;
    cout<<setw(15); ngaytl.xuat();
    cout<<setw(15)<<dc.dienthoai;
    cout<<setw(20)<<dc.phuong<<"/"<<dc.quan<<"/"<<dc.thanhpho;
    cout<<setw(10)<<giamdoc;
    cout<<setw(10)<<doanhthu<<endl;
}
void nhapds( doanhnghiep a[], int &n)
{
    do{
        cout<<"\n nhap vao so doanh nghiep: ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n doanh nghiep thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthids(doanhnghiep a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void y_a(doanhnghiep a[], int n)
{

    int k=-1;
    for( int i=0;i<n;i++)
        if(a[i].doanhthu<250)
        {
            k=0;break;
        }
    if(k==-1)cout<<"\n khong co doanh nghiep nao co doanh thu < 250";
    else{
        cout<<"\n nhung doanh nghiep co doanh thu < 250 :  ";
        for( int i=0;i<n;i++)
            if(a[i].doanhthu<250)cout<<"\t "<<a[i].tendn;
    }
}
void y_b( doanhnghiep a[], int n )
{
    int k=-1;
    for( int i=0;i<n;i++)
        if(a[i].madn==2010)
        {
           k=i;break;
        }
    if(k==-1)cout<<"\n trong danh sach khong co doanh nghiep ma 2010 !"<<endl;
    else{
        cout<<"\n doanh nghiep co ma 2010 trong ds la: "<<endl;
        cot_mau();
        a[k].xuat();
    }
}

void y_c( doanhnghiep a[], int n)
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
int main()
{
    int n;
    doanhnghiep a[20];
    nhapds(a,n);
    cout<<"\n danh sach vua nhap vao la: "<<endl;
    hienthids(a,n);
    y_a(a,n);
    y_b(a,n);
    y_c(a,n);
    return 0;
}
