#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<conio.h>
using namespace std;
class XEHOI;
class DATE{
    private:
        int namsx;
    friend class XEHOI;
    friend void y_b(XEHOI a[], int n);
};
class XEHOI
{
    private:
        char nhanhieu[20];
        char hangsx[30];
        DATE nam;
        char xuatxu[20];
        float gia;
        int sluong_ban;
    public:
        void nhap();
        void xuat();
        float thanh_tien(){
            return gia*sluong_ban;
        }
    friend void y_b(XEHOI a[], int n);
    friend void y_c(XEHOI a[], int n);
    friend void y_d(XEHOI a[], int n);
    friend void y_e(XEHOI a[], int n);
};
void XEHOI::nhap()
{
      cout<<"\nnhan hieu:  ";fflush(stdin);gets(nhanhieu);
      cout<<"hang sx: ";fflush(stdin);gets(hangsx);
      cout<<"nam sx: ";cin>>nam.namsx;
      cout<<"xuat xu: ";fflush(stdin);gets(xuatxu);
      cout<<"gia ban: ";cin>>gia;
      cout<<"so luong ban: ";cin>>sluong_ban;
}
void cot_mau()
{
    cout<<setw(15)<<"nhan hieu";
    cout<<setw(15)<<"hang sx";
    cout<<setw(15)<<"namsx";
    cout<<setw(15)<<"xuat xu";
    cout<<setw(15)<<"gia ban";
    cout<<setw(15)<<"soluong";
    cout<<setw(15)<<"thanhtien"<<endl;
}
void XEHOI::xuat()
{
    cout<<setw(15)<<nhanhieu;
    cout<<setw(15)<<hangsx;
    cout<<setw(15)<<nam.namsx;
    cout<<setw(15)<<xuatxu;
    cout<<setw(15)<<gia;
    cout<<setw(15)<<sluong_ban;
    cout<<setw(15)<<thanh_tien()<<endl;
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
void hienthi( XEHOI a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].xuat();
}
void y_b( XEHOI a[], int n)
{
    int  max=a[0].nam.namsx;
    for( int i=1;i<n;i++)
        if(a[i].nam.namsx>max)max=a[i].nam.namsx;
    cout<<"\n nhung xe hoi san xuat moi nhat la :"<<endl;
    cot_mau();
    for( int i=0;i<n;i++)
        if(a[i].nam.namsx==max)a[i].xuat();
}
void y_c(XEHOI a[], int n)
{
    cout<<"sap xep XE HOI theo chieu tang dan cua thanh tien la: "<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(a[j].thanh_tien()<a[j-1].thanh_tien())
            {
                XEHOI tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)break;
    }
    hienthi(a,n);
}
void y_d(XEHOI a[], int n)
{
    char x[20];
    cout<<"\n nhap vao nhan hieu xe hoi can sua: ";fflush(stdin);gets(x);
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].nhanhieu,x)==0)
        {
            k=-1;break;
        }
    if(k==0)cout<<"\n trong danh sach khong co xehoi nao thuoc hang "<<x<<" !"<<endl;
    else{
        cout<<"\n  Sua thong tin  xe hoi thuoc hang "<<x<<" la: "<<endl;
        int z=1;
        for( int i=0;i<n;i++)
        {
            if(strcmp(a[i].nhanhieu,x)==0)
            {
                cout<<"==>> xe "<<i+1<<":";
                a[i].nhap();
                i--;
            }
        }
        cout<<"\n thong tin sau khi sua la : "<<endl;
        hienthi(a,n);
    }
}
void y_e( XEHOI a[], int n)
{
    int tongxe=0;
    for( int i=0;i<n;i++)
        if(a[i].gia<5100)tongxe+=a[i].sluong_ban;
    if(tongxe==0)cout<<"\n khong co xe hoi nao co gia ban < 5100 !"<<endl;
    else cout<<"\n tong xe hoi co gia ban <5100 la: "<<tongxe;
}
int main()
{
    int n;
    XEHOI a[20];
    nhapds(a,n);
    cout<<"\n danh sach vua nhap vao la: "<<endl;
    hienthi(a,n);
    y_b(a,n);
    y_c(a,n);
    y_d(a,n);
    y_e(a,n);
    getch();
    return 0;
}
