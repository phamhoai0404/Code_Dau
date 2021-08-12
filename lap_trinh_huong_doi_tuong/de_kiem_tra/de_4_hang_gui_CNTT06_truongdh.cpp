#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class TRUONGDH;
class BAN;
class date
{
    private:
        int day;
        int month;
        int year;
    friend class BAN;
    friend class TRUONGDH;
};
class BAN
{
    private:
        char maban[20];
        char tenban[30];
        date namtl;
    friend class TRUONGDH;
};
class KHOA
{
    private:
        char makhoa[20];
        char tenkhoa[30];
        char truongkhoa[30];
    friend class TRUONGDH;
    friend void y_b(TRUONGDH a[], int n);
};
class TRUONGDH
{
    private:
        char matruong[20];
        char tentruong[30];
        KHOA x[30];
        int sokhoa;
        BAN y[30];
        int soban;
    public:
        void nhap();
        void xuat();
    friend void y_b(TRUONGDH a[], int n);
    friend void y_c(TRUONGDH a[], int n);
    friend void y_d(TRUONGDH a[], int &n);


};
void TRUONGDH::nhap()
{
      cout<<"\nMa truong:  ";fflush(stdin);gets(matruong);
      cout<<"Ten truong: ";fflush(stdin);gets(tentruong);
      cout<<"so khoa: ";cin>>sokhoa;
      for( int i=0;i<sokhoa;i++)
      {
          cout<<"==== khoa thu: "<<i+1;
          cout<<"\n\t ma khoa: ";fflush(stdin);gets(x[i].makhoa);
          cout<<"\t ten khoa: ";fflush(stdin);gets(x[i].tenkhoa);
          cout<<"\t truong khoa: ";fflush(stdin);gets(x[i].makhoa);
      }
      cout<<"so ban : ";cin>>soban;
      for( int i=0;i<soban;i++)
      {
          cout<<"==== ban thu: "<<i+1;
          cout<<"\n\t ma ban: ";fflush(stdin);gets(y[i].maban);
          cout<<"\t ten ban: ";fflush(stdin);gets(y[i].tenban);
          cout<<"\t ngay tl: ";cin>>y[i].namtl.day;
          cout<<"\t thang tl: ";cin>>y[i].namtl.month;
          cout<<"\t nam tl: ";cin>>y[i].namtl.year;
      }
}
void cot_mau()
{
    cout<<setw(35)<<"matruong";
    cout<<setw(15)<<"tentruong";
    cout<<setw(15)<<"sokhoa";
    cout<<setw(15)<<"soban" <<endl;

}
void TRUONGDH::xuat()
{
    cout<<setw(35)<<matruong;
    cout<<setw(15)<<tentruong;
    cout<<setw(15)<<sokhoa;
    cout<<setw(15)<<soban<<endl;
}
void nhapds(TRUONGDH a[], int &n)
{
    do{
        cout<<"\n nhap so truong dai hoc :  ";cin>>n;
        if(n<=0||n>50)cout<<"\n vui long nhap lai, ";
    }while(n<=0||n>50);
    for( int i=0;i<n;i++)
    {
        cout<<"\n truong dai hoc thu: "<<i+1;
        a[i].nhap();
    }
}
void hienthi( TRUONGDH a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void y_b(TRUONGDH a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
    {
        for( int j=0;j<a[i].sokhoa;i++)
            if(strcmp(a[i].x[j].tenkhoa,"CNTT")==0)
            {
                k=1;
                break;
            }
        if(k==1)break;
    }
    if(k==0)cout<<"\n\n Khong co truong dai hoc nao co khoa CNTT ! "<<endl;
    else{
        cout<<"\n thong tin truong dai hoc co khoa CNTT la: "<<endl;
        cot_mau();
        for( int i=0;i<n;i++)
            for( int j=0;j<a[i].sokhoa;i++)
                if(strcmp(a[i].x[j].tenkhoa,"CNTT")==0)a[i].xuat();
        cout<<endl;
    }
}
void y_c(TRUONGDH a[], int n)
{
    cout<<"\n\t\t\t\t===== THONG TIN TRUONG SAU KHI DUOC SAP XEP ===="<<endl<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(strcmp(a[j].tentruong,a[j-1].tentruong)<0)
            {
                TRUONGDH tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)break;
    }
    hienthi(a,n);
}
void y_d(TRUONGDH a[], int &n)
{
    cout<<"\n Nhap thong tin truong can chen: ";TRUONGDH x;x.nhap();
    int k;
    do{
        cout<<"\n vi tri can chen: ";cin>>k;
        if(!( (k>=1)&&(k<=n+1)))cout<<"\n trong danh sach khong co vi tri nay vui long nhap lai,";
    }while(!( (k>=1)&&(k<=n+1)));
    for( int i=n;i>k-1;i--)
        a[i]=a[i+1];
    a[k-1]=x;
    n++;
    cout<<"\n\t\t\t\t==== THONG TIN TRUONG DAI HOC SAU KHI CHEN ===="<<endl<<endl;
    hienthi(a,n);
}
int main()
{
    int n;
    TRUONGDH a[50];
    nhapds(a,n);
    system("cls");
    cout<<"\n\t\t\t\t======== THONG TIN TRUONG DAI HOC ==========="<<endl<<endl;
    hienthi(a,n);
    y_b(a,n);
    y_c(a,n);
    y_d(a,n);
    return 0;
}
