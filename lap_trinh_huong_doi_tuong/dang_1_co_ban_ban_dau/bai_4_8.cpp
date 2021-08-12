#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class NHANVIEN;
class DATE
{
    private:
        int day;
        int month;
        int year;
    friend class NHANVIEN;
};
class PHONGBAN
{
    private:
        int mapb;
        char tenpb[50];
        char truongphong[10];
        int sonv;
    friend class NHANVIEN;
};
class NHANVIEN
{
    private:
        int manv;
        char hodem[25];
        char ten[10];
        DATE ngaysinh;
        PHONGBAN phong;
    public:
        void nhap();
        void xuat();
        friend void sap_xep(NHANVIEN a[], int n);
        friend void xoa(NHANVIEN a[], int &n);
};
void NHANVIEN::nhap()
{
    cout<<"\n manv : ";cin>>manv;
    cout<<"ho dem: ";fflush(stdin);gets(hodem);
    cout<<"ten: ";fflush(stdin);gets(ten);
    cout<<"ngays: ";cin>>ngaysinh.day;
    cout<<"thangs: ";cin>>ngaysinh.month;
    cout<<"namsinh: ";cin>>ngaysinh.year;
    cout<<"ma phong ban: ";cin>>phong.mapb;
    cout<<"ten pb: ";fflush(stdin);gets(phong.tenpb);
    cout<<"truong phong: ";fflush(stdin);gets(phong.truongphong);
    cout<<"sonv trg phong: ";cin>>phong.sonv;
}
void cot_mau()
{
    cout<<setw(10)<<"manv";
    cout<<setw(10)<<"hodem";
    cout<<setw(10)<<"ten";
    cout<<setw(20)<<"ngaysinh";
    cout<<setw(10)<<"mapb";
    cout<<setw(10)<<"tenpb";
    cout<<setw(10)<<"truongph";
    cout<<setw(10)<<"sonv"<<endl;
}
void NHANVIEN::xuat()
{
    cout<<setw(10)<<manv;
    cout<<setw(10)<<hodem;
    cout<<setw(10)<<ten;
    cout<<setw(15)<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year;
    cout<<setw(10)<<phong.mapb;
    cout<<setw(10)<<phong.tenpb;
    cout<<setw(10)<<phong.truongphong;
    cout<<setw(10)<<phong.sonv<<endl;
}
void nhapds(NHANVIEN a[], int &n)
{
    do{
        cout<<"\n nhap vao so nv:  ";cin>>n;
        if(n<=0)cout<<"\n vui long nhap lai, ";
    }while(n<=0);
    for( int i=0;i<n;i++)
    {
        cout<<"\n nv thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthi( NHANVIEN a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void sap_xep(NHANVIEN a[], int n)
{
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(strcmp(a[j].ten,a[j-1].ten)<0)
            {
                NHANVIEN tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)return;
    }
}
void chen1( NHANVIEN a[], int &n, int k, NHANVIEN x)
{
    for( int i=n;i>k-1;i--)
        a[i]=a[i-1];
    a[k-1]=x;
    n++;
}
void chen(NHANVIEN a[], int &n)
{
    cout<<"\n nhap thong tin nhan vien moi: ";
    NHANVIEN x;x.nhap();
    int k;
    do{
        cout<<"\n vi tri can chen nhan vien: ";cin>>k;
        if(!((k-1>=0)&&(k-1<=n)))cout<<"\n khong co vi tri nay khong ds!, Vui long nhap lai ";
    }while(!((k-1>=0)&&(k-1<=n)));
    if(k==n+1)a[n++]=x;
    else chen1(a,n,k,x);
}
void xoa( NHANVIEN a[], int &n)
{
    int k=-1;
    for( int i=0 ;i<n;i++)
        if(a[i].manv==123)
        {
            k=i;break;
        }
    if (k==-1)cout<<"\n khong co ma nhan vien do !"<<endl;
    else{
        for( int i=k;i<n;i++)
            a[i]=a[i+1];
        n--;
        cout<<"\n danh sach sau khi xoa la: "<<endl;
        hienthi(a,n);
    }
}
int main()
{
    int n;
    NHANVIEN a[20];
    nhapds(a,n);
    cout<<"\n danh sach vua nhap vao la: "<<endl;
    hienthi(a,n);
    //sap_xep(a,n);
    //cout<<"\n danh sach sau khi sap xep la: "<<endl;
    //hienthi(a,n);
    //chen(a,n);
    //cout<<"\n danh sach sau khi chen la: "<<endl;
    //hienthi(a,n);
    xoa(a,n);
    return 0;
}

