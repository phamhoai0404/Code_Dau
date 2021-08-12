#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
class SINHVIEN
{
    protected:
        char hoten[20];
        char SBD[20];
    public:
        void nhap();
        void xuat();
};
class DIEMTHI
{
    protected:
        float mon1;
        float mon2;
    public:
        void nhap();
        void xuat();
};
class KETQUA: private SINHVIEN, private DIEMTHI
{
    private:
        float tong(){
            return mon1+mon2;
        }
    public:
        void nhap();
        void xuat();
};
void SINHVIEN::nhap()
{
    cout<<"\nho va ten: ";fflush(stdin);gets(hoten);
    cout<<"so bao danh ";fflush(stdin);gets(SBD);
}
void SINHVIEN::xuat()
{
    cout<<setw(10)<<hoten;
    cout<<setw(10)<<SBD;
}
void DIEMTHI::nhap()
{
    cout<<"mon 1: ";cin>>mon1;
    cout<<"mon 2: ";cin>>mon2;
}
void DIEMTHI::xuat()
{
    cout<<setw(10)<<mon1;
    cout<<setw(10)<<mon2;
}
void KETQUA:: nhap()
{
    SINHVIEN::nhap();
    DIEMTHI::nhap();
}
void KETQUA:: xuat()
{
    SINHVIEN::xuat();
    DIEMTHI::xuat();
    cout<<setw(10)<<tong()<<endl;
}
void hienthi()
{
    cout<<setw(10)<<"tensv";
    cout<<setw(10)<<"SBD";
    cout<<setw(10)<<"mon1";
    cout<<setw(10)<<"mon2";
    cout<<setw(10)<<"tong"<<endl;
}
void nhapmang( KETQUA a[], int &n)
{
    do{
        cout<<"\n nhap vao so sinh vien: ";cin>>n;
        if(n<0||n>100)cout<<"\n vui long nhap lai !";
    }while(n<0||n>100);
    for( int i=0;i<n;i++)
    {
        cout<<"\n   sinh vien thu "<<i+1<<":";
        a[i].nhap();
    }
}
void xuatmang( KETQUA a[], int n)
{
    hienthi();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
int main()
{
    KETQUA a[100];
    int n;
    nhapmang(a,n);
    xuatmang(a,n);
    return 0;
}


