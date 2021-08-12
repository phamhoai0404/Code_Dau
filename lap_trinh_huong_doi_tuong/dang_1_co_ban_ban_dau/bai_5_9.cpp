#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>
using namespace std;
class SANPHAM
{
    protected:
        char tensp[20];
        int namsx;
        float giathanh;
    public:
        void nhap();
        void xuat();
};
class HOADON:  private SANPHAM
{
    private:
        int slban;
        float giaban;
    public:
        void nhap();
        void xuat();
        float tinh_thanh_tien();
        float thue();
        float tinh_lai();
};
float HOADON::tinh_thanh_tien()
{
    return slban*giaban;
}
float HOADON::thue()
{
    return tinh_thanh_tien()*0.1;
}
float HOADON::tinh_lai()
{
    return (giaban-giathanh)*slban;
}
void SANPHAM::nhap()
{
    cout<<"\nten san pham: ";fflush(stdin);gets(tensp);
    cout<<"nam san xuat: ";cin>>namsx;
    cout<<"gia thanh : ";cin>>giathanh;
}
void SANPHAM::xuat()
{
    cout<<setw(10)<<tensp;
    cout<<setw(10)<<giathanh;
}
void HOADON::nhap()
{
    SANPHAM::nhap();
    cout<<"so luong ban : ";cin>>slban;
    cout<<"gia ban : ";cin>>giaban;
}
void HOADON:: xuat()
{

    SANPHAM::xuat();
    cout<<setw(10)<<slban;
    cout<<setw(10)<<giaban;
    cout<<setw(10)<<tinh_thanh_tien();
    cout<<setw(10)<<thue();
    cout<<setw(10)<<tinh_lai();
    cout<<endl;
}
void hienthi()
{
    cout<<setw(10)<<"STT";
    cout<<setw(10)<<"tensp";
    cout<<setw(10)<<"giathanh";
    cout<<setw(10)<<"slban";
    cout<<setw(10)<<"giaban";
    cout<<setw(10)<<"thanhtien";
    cout<<setw(10)<<"thue";
    cout<<setw(10)<<"lai"<<endl;
}
void nhapmang( HOADON a[], int &n)
{
    do{
        cout<<"\n nhap vao so hoa don : ";cin>>n;
        if(n<0||n>20)cout<<"\n vui long nhap lai !";
    }while(n<0||n>20);
    for( int i=0;i<n;i++)
    {
        cout<<"\n hoa don thu "<<i+1<<":";
        a[i].nhap();
    }
}
void xuatmang( HOADON a[], int n)
{
    hienthi();
    for( int i=0;i<n;i++)
    {
        cout<<setw(10)<<i+1;
        a[i].xuat();
    }

}
void sap_xep(HOADON a[], int n)
{
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(a[j].tinh_lai()>a[j-1].tinh_lai())
            {
                HOADON tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)return;
    }
}
void tong_tien( HOADON a[], int n)
{
    float x=0;
    for( int i=0;i<n;i++)
        x+=a[i].tinh_thanh_tien();
    cout<<"\n tong tien cua cac hoa don ban sp la: "<<x;
}
void thue_max( HOADON a[], int n)
{
    float maxx=a[0].thue();
    for( int i=1;i<n;i++)
        if(maxx<a[i].thue())maxx=a[i].thue();
    cout<<"\n mat hang co trong luong nho nhat la: \n";
    hienthi();
    int o=0;
    for( int i=0;i<n;i++)
        if(a[i].thue()==maxx)
        {
            o++;
            cout<<setw(10)<<o;
            a[i].xuat();
        }
}
int main()
{
    HOADON a[20];
    int n;
    nhapmang(a,n);
    cout<<"\n danh sach hoa don vua nhap la: "<<endl;
    xuatmang(a,n);
    sap_xep(a,n);
    cout<<"\n danh sach hoa don sau khi sx la: "<<endl;
    xuatmang(a,n);
    tong_tien(a,n);
    thue_max(a,n);
    return 0;
}


