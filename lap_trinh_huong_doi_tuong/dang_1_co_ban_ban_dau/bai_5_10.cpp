#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>
using namespace std;
class CANBO
{
    protected:
        int macb;
        int madv;
        int namsinh;
        float heluong;
        float phu_cap_an_ca;
        float baohiem;
};
class GIANGVIEN:  private CANBO
{
    public:
        void nhap();
        void xuat();
        float phu_cap_dung_lop();
        float phu_cap_doc_hai();
        float luong_thuc_linh();
};
float GIANGVIEN::phu_cap_dung_lop()
{
    return heluong*0.25;
}
float GIANGVIEN::phu_cap_doc_hai()
{
    return heluong*0.1;
}
float GIANGVIEN::luong_thuc_linh()
{
    return heluong+phu_cap_an_ca-baohiem+phu_cap_dung_lop()+phu_cap_doc_hai();
}
void GIANGVIEN::nhap()
{
    cout<<"\nma can bo:";cin>>macb;
    cout<<"ma don vi: ";cin>>madv;
    cout<<"nam sinh: ";cin>>namsinh;
    cout<<"he luong: ";cin>>heluong;
    cout<<"phu cap an ca: ";cin>>phu_cap_an_ca;
    cout<<"bao hiem: ";cin>>baohiem;
}
void GIANGVIEN::xuat()
{
    cout<<setw(10)<<macb;
    cout<<setw(10)<<madv;
    cout<<setw(10)<<namsinh;
    cout<<setw(10)<<heluong;
    cout<<setw(10)<<phu_cap_an_ca;
    cout<<setw(10)<<baohiem;
    cout<<setw(15)<<phu_cap_dung_lop();
    cout<<setw(15)<<phu_cap_doc_hai();
    cout<<setw(15)<<luong_thuc_linh()<<endl;
}
void hienthi()
{
    cout<<setw(10)<<"macb";
    cout<<setw(10)<<"madv";
    cout<<setw(10)<<"namsinh";
    cout<<setw(10)<<"heluong";
    cout<<setw(10)<<"pcanca";
    cout<<setw(10)<<"baohiem";
    cout<<setw(15)<<"pcdunglop";
    cout<<setw(15)<<"pcdochai";
    cout<<setw(15)<<"luongthuclinh"<<endl;
}
void nhapmang( GIANGVIEN a[], int &n)
{
    do{
        cout<<"\n nhap vao so giang vien : ";cin>>n;
        if(n<0||n>20)cout<<"\n vui long nhap lai !";
    }while(n<0||n>20);
    for( int i=0;i<n;i++)
    {
        cout<<"\n gian vien thu "<<i+1<<":";
        a[i].nhap();
    }
}
void xuatmang( GIANGVIEN a[], int n)
{
    hienthi();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void dong_thue_thu_nhap( GIANGVIEN a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(a[i].luong_thuc_linh()>5000000)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n khong co giang vien nao phai dong thue thu nhap !";
    else{
        cout<<"\n danh sach giang vien dong thue thu phap la: \n";
        hienthi();
        for( int i=0;i<n;i++)
            if(a[i].luong_thuc_linh()>5000000)
                a[i].xuat();
    }
}
int main()
{
   GIANGVIEN a[20];
    int n;
    nhapmang(a,n);
    cout<<"\n danh sach giang vien vua nhap la: "<<endl;
    xuatmang(a,n);
    dong_thue_thu_nhap(a,n);
    return 0;
}


