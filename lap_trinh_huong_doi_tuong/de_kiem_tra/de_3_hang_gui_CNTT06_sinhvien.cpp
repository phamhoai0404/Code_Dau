#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class Sinh_Vien;
class Datet
{
    private:
        int day;
        int month;
        int year;
    friend class Sinh_Vien;
    friend void y_c( Sinh_Vien a[], int n);
    friend void y_e( Sinh_Vien a[], int &n);
};
class Sinh_Vien
{
    private:
        char masv[20];
        char tensv[30];
        Datet ngaysinh;
        float dtoan;
        float dly;
        float dhoa;
    public:
        void nhap();
        void xuat();
        float tong_diem(){
            return dtoan+dly+dhoa;
        }
    friend void y_b( Sinh_Vien a[], int n);
    friend void y_c( Sinh_Vien a[], int n);
    friend void y_d( Sinh_Vien a[], int n);
    friend void xoa1( Sinh_Vien a[], int &n, int k);
    friend void y_e( Sinh_Vien a[], int &n);
};
void Sinh_Vien::nhap()
{
      cout<<"\nMa sinh vien: ";fflush(stdin);gets(masv);
      cout<<"Ten sinh vien:  ";fflush(stdin);gets(tensv);
      cout<<"Ngay sinh: ";cin>>ngaysinh.day;
      cout<<"Thang sinh: ";cin>>ngaysinh.month;
      cout<<"Nam sinh: ";cin>>ngaysinh.year;
      cout<<"Diem Toan: ";cin>>dtoan;
      cout<<"Diem Ly: ";cin>>dly;
      cout<<"Diem Hoa: ";cin>>dhoa;
}
void cot_mau()
{
    cout<<setw(15)<<"Masv";
    cout<<setw(15)<<"Tensv";
    cout<<setw(20)<<"ngaysinh";
    cout<<setw(15)<<"Toan";
    cout<<setw(15)<<"Ly";
    cout<<setw(15)<<"Hoa"<<endl;
}
void Sinh_Vien::xuat()
{
    cout<<setw(15)<<masv;
    cout<<setw(15)<<tensv;
    cout<<setw(15)<<ngaysinh.day<<"/"<<ngaysinh.month<<"/"<<ngaysinh.year;
    cout<<setw(15)<<dtoan;
    cout<<setw(15)<<dly;
    cout<<setw(15)<<dhoa<<endl;
}
void nhapds(Sinh_Vien a[], int &n)
{
    do{
        cout<<"\n nhap vao so sinhvien:  ";cin>>n;
        if(n<=0||n>100)cout<<"\n vui long nhap lai, ";
    }while(n<=0||n>100);
    for( int i=0;i<n;i++)
    {
        cout<<"\n==== sinh vien thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthi( Sinh_Vien a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void y_b( Sinh_Vien a[], int n)
{
    float minn=a[0].tong_diem();
    for( int i=1;i<n;i++)
        if(a[i].tong_diem()<minn)minn=a[i].tong_diem();
    cout<<"\n\n Sinh vien co tong diem "<<minn<<" thap nhat theo dang (masv)tensv la: ";
    for( int i=0;i<n;i++)
        if(a[i].tong_diem()== minn)cout<<"\t("<<a[i].masv<<") "<<a[i].tensv;
    cout<<endl;
}
void y_c( Sinh_Vien a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if((a[i].ngaysinh.day==30)&&(a[i].ngaysinh.month==4))
        {
            k=1;break;
        }
    if(k==0)cout<<"\n\n khong co sinh vien sinh ngay 30/4 !"<<endl;
    else{
        cout<<"\n thong tin nhung sinh vien sinh ngay 30/4 la: "<<endl;
        cot_mau();
        for( int i=0;i<n;i++)
            if(a[i].ngaysinh.day==30&&a[i].ngaysinh.month==4)a[i].xuat();
        cout<<endl;
    }
}
void y_d(Sinh_Vien a[], int n)
{
    cout<<"\n\t\t\t\t===== THONG TIN SINH VIEN SAU KHI DUOC SAP XEP ===="<<endl<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(strcmp(a[j].tensv,a[j-1].tensv)<0)
            {
                Sinh_Vien tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)break;
    }
    hienthi(a,n);
}
void xoa1( Sinh_Vien a[], int &n, int k)
{
    for( int i=k;i<n-1;i++)
        a[i]=a[i+1];
    n--;
}
void y_e( Sinh_Vien a[], int &n)
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
int main()
{
    Sinh_Vien a[100];
    int n;
    nhapds(a,n);
    system("cls");
    cout<<"\n\t\t\t\t======== THONG TIN SINH VIEN ==========="<<endl<<endl;
    hienthi(a,n);
    y_b(a,n);
    y_c(a,n);
    y_d(a,n);
    y_e(a,n);
}
