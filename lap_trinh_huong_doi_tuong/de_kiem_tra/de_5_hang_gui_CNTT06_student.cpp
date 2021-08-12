#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
using namespace std;
class FACULTY;
class STUDENT;
class SCHOOL
{
    private:
        char name[20];
        int date;
    friend class FACULTY;
    friend void y_b(STUDENT a[], int n);
};
class FACULTY
{
    private:
        char name[20];
        int date;
        SCHOOL x;
    public:
        void input();
        void output();
    friend class STUDENT;
    friend void y_b(STUDENT a[], int n);
};
class STUDENT
{
    private:
        char masv[20];
        char tensv[20];
        FACULTY y;
        char Class[10];
        float score;
    public:
        void input();
        void output();
    friend void y_b(STUDENT a[], int n);
    friend void y_c(STUDENT a[], int n);
    friend void y_d(STUDENT a[], int n);
    friend void y_e(STUDENT a[], int n);
};
void FACULTY::input()
{
    cout<<"ten giao vien: ";fflush(stdin);gets(name);
    cout<<"nam sinh cua giao vien: ";cin>>date;
    cout<<"truong day cua giao vien: ";fflush(stdin);gets(x.name);
    cout<<"nam thanh lap truong: ";cin>>x.date;
}
void FACULTY::output()
{
    cout<<setw(10)<<name;
    cout<<setw(10)<<date;
    cout<<setw(10)<<x.name;
    cout<<setw(10)<<x.date;
}
void STUDENT::input()
{
    cout<<"\nma sinh vien: ";fflush(stdin);gets(masv);
    cout<<"ten: ";fflush(stdin);gets(tensv);
    y.input();
    cout<<"lop hoc: ";cin>>Class;
    cout<<"score: ";cin>>score;
}
void STUDENT::output()
{
    cout<<setw(10)<<masv;
    cout<<setw(10)<<tensv;
    y.output();
    cout<<setw(10)<<Class;
    cout<<setw(10)<<score<<endl;
}
void cot_mau()
{
    cout<<setw(10)<<"masv";
    cout<<setw(10)<<"tensv";
    cout<<setw(10)<<"giaovien";
    cout<<setw(10)<<"namsgv";
    cout<<setw(10)<<"truong";
    cout<<setw(10)<<"namtltrg";
    cout<<setw(10)<<"lop";
    cout<<setw(10)<<"score"<<endl;
}
void nhapds(STUDENT a[], int &n)
{
    do{
        cout<<"\n nhap vao so hoc sinh:   ";cin>>n;
        if(n<=0||n>=100)cout<<"\n vui long nhap lai, ";
    }while(n<=0||n>=100);
    for( int i=0;i<n;i++)
    {
        cout<<"\n ====hoc sinh thu: "<<i+1;
        a[i].input();
    }
}
void hienthi( STUDENT a[], int n)
{
    cot_mau();
    for( int i=0;i<n;i++)
        a[i].output();
}
void y_b( STUDENT a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].y.x.name,"DHCN")==0)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n\n khong co sinh vien nao hoc DHCN !"<<endl;
    else{
        cout<<"\n thong tin nhung sinh vien hoc truong DHCN la:  "<<endl;
        cot_mau();
        for( int i=0;i<n;i++)
           if(strcmp(a[i].y.x.name,"DHCN HA NOI")==0)a[i].output();
        cout<<endl;
    }
}
void y_c( STUDENT a[], int n)
{
    int k=0;
    for( int i=0;i<n;i++)
        if(a[i].score>6.5)
        {
          k=1;break;
        }
    if(k==0)cout<<"\n\n khong co sinh vien nao co score >6.5 !"<<endl;
    else{
        float tong=0;
        for( int i=0;i<n;i++)
            if(a[i].score>6.5)tong+=a[i].score;
        cout<<"\n\n tong diem cua nhung sinh vien co diem score >6.5 la: "<<tong<<endl;
    }
}
void y_d(STUDENT a[], int n)
{
    cout<<"\n\t\t\t\t===== THONG TIN SINH VIEN SAU KHI DUOC SAP XEP ===="<<endl<<endl;
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(a[j].score<a[j-1].score)
            {
                STUDENT tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)break;
    }
    hienthi(a,n);
}
void y_e( STUDENT a[], int n)
{
    cout<<"\n nhap vao class can doi thong tin sinh vien: ";char x[10];
    fflush(stdin);gets(x);
    int k=0;
    for( int i=0;i<n;i++)
        if(strcmp(a[i].Class,x)==0)
        {
            k=1;break;
        }
    if(k==0)cout<<"\n\n trong danh sach khong co class "<<x<<endl;
    else{
        int z=1;
        cout<<"\n\n sua sinh vien trong class "<<x<<" la: ";
        for( int i=0;i<n;i++)
            if(strcmp(a[i].Class,x)==0)
            {
                cout<<"\n ===sua sinh vien thu : "<<z++;
                a[i].input();
            }
        cout<<"\n\n\t\t======DANH SACH SAU KHI SUA========"<<endl;
        hienthi(a,n);
    }
}
int main()
{
    STUDENT a[100];
    int n;
    nhapds(a,n);
    system("cls");
    cout<<"\n\t\t==============THONG TIN SINH VIEN============="<<endl<<endl;
    hienthi(a,n);
    y_b(a,n);
    y_c(a,n);
    y_d(a,n);
    y_e(a,n);
    return 0;
}

