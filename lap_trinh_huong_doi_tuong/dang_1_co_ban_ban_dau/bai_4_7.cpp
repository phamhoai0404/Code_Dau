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
    friend void tinh_doanh_thu( doanhnghiep a[], int n);
};
class diachi
{
    private:
        char dienthoai[12];
        char phuong[30];
        char quan[30];
        char thanhpho[30];
    friend class doanhnghiep;
    friend void timkiem( doanhnghiep a[],int n);
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
    friend void timkiem( doanhnghiep a[],int n);
    friend void tinh_doanh_thu( doanhnghiep a[], int n);
    friend void thay_doi( doanhnghiep a[], int n);
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
     cout<<"\n ten doanh nghiep : ";fflush(stdin);gets(tendn);
     cout<<"\n ngay thanh lap: "; ngaytl.nhap();
     cout<<"\n dien thoai :"; fflush(stdin);gets(dc.dienthoai);
     cout<<"\n  phuong : ";fflush(stdin);gets(dc.phuong);
     cout<<"\n quan : ";fflush(stdin);gets(dc.quan);
     cout<<"\n thanh pho:  ";fflush(stdin);gets(dc.thanhpho);
     cout<<"\n giam doc: ";fflush(stdin);gets(giamdoc);
     cout<<"\n doanh thu: ";cin>>doanhthu;
}
void cot_mau()
{
    cout<<setw(5)<<right<<"madn";
    cout<<setw(10)<<right<<"tendn";
    cout<<setw(15)<<right<<"ngaytl";
    cout<<setw(15)<<right<<"dienthoai";
    cout<<setw(20)<<right<<"diachi";
    cout<<setw(10)<<right<<"giamdoc";
    cout<<setw(10)<<right<<"doanhthu"<<endl;
}
void doanhnghiep::xuat()
{
    cout<<setw(5)<<right<<madn;
    cout<<setw(10)<<right<<tendn;
    cout<<setw(15)<<right; ngaytl.xuat();
    cout<<setw(15)<<right<<dc.dienthoai;
    cout<<setw(20)<<right<<dc.phuong<<"/"<<dc.quan<<"/"<<dc.thanhpho;
    cout<<setw(10)<<right<<giamdoc;
    cout<<setw(10)<<right<<doanhthu<<endl;
}
void timkiem( doanhnghiep a[], int n )
{
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].dc.thanhpho,"ha noi")==0)
        {
           k=1;break;
        }
    if(k==0)cout<<"\n trong danh sach khong co doanh nghiep nao o ha noi !";
    else{
        cout<<"\n nhung doanh nghiep o ha noi la: ";
        for( int i=0;i<n;i++)
            if(strcmp(a[i].dc.thanhpho,"ha noi")==0)
                cout<<"\t "<<a[i].tendn;
    }
}
void tinh_doanh_thu( doanhnghiep a[], int n)
{
    long tong=0;
    int k=0;
    for( int i=0;i<n;i++)
        if(a[i].ngaytl.year==2015)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n khong co nam 2015 trong ho so !";
    else{
        long tong=0;
        for( int i=0;i<n;i++)
            if(a[i].ngaytl.year==2015)
                tong+=a[i].doanhthu;
        cout<<"\n tong doanh thu trong nam 2015 la: "<<tong;
    }
}
void thay_doi( doanhnghiep a[], int n)
{
    cout<<"\n nhap vao ma doanh nghiep can sua doi thong tin : ";int x;cin>>x;
    int k=-1;
    for( int i=0 ;i<n;i++)
        if(a[i].madn==x)
        {
            k=i;break;
        }
    if (k==-1)cout<<"\n khong co ma can sua doi !";
    else{
        cout<<"\n nhap lai: ";
        a[k].nhap();
        cot_mau();
        for( int i=0;i<n;i++)
            a[i].xuat();
    }
}
int main()
{
    int n;
    doanhnghiep a[20];

    do{
        cout<<"\n nhap vao so doanh nghiep: ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);

    for( int i=0;i<n;i++)
    {
        cout<<"\n doanh nghiep thu: "<<i+1;
        a[i].nhap();
    }
    cout<<"\n danh sach vua nhap vao la: "<<endl;
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
    timkiem(a, n);
    tinh_doanh_thu(a,n);
    thay_doi(a,n);
    return 0;
}
