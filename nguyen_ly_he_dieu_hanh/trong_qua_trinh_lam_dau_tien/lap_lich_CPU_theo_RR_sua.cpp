#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
int q,n,tong=0;
int chinh[50],ic=0,c[30],o=0;
class vong_tron;
class tien_trinh
{
   public:
        int tenso,Tth,Txh;
        int SC,finish;
        int TH,t,TC;
    public:
        void nhap();
        void xuat();
    friend void sap_xep();
    friend void sao_chep();
    friend void thuc_hien_ve();
    friend void nhap2();
    friend void TG_cho();
    friend class vong_tron;
};
class vong_tron
{
    public:
        int chin;
        int phu;
    public:
    friend void tang_vong_tron();
    friend void thuc_hien_ve();
    friend void ve_giando_GANTT();
    friend class tien_trinh;


};
tien_trinh a[20];
vong_tron b[30];
int ivt=0,j=0;
void tien_trinh::nhap()
{
    cout<<endl;
    cout<<"\tTenTR: ";cin>>tenso;
    cout<<"\t\tTG thuc hien: ";cin>>Tth;
    cout<<"\t\tTG xuat hien: ";cin>>Txh;
}
void tien_trinh::xuat()
{
    cout<<setw(5)<<"P["<<tenso<<"]"<<setw(10)<<Tth<<setw(10)<<Txh<<endl;
}
void nhap1()
{
    cout<<"\n==========LAP LICH CPU THEO RR==========";
    cout<<"\n nhap time quantum : q = ";cin>>q;
    do{
        cout<<" \n nhap so tien trinh : ";cin>>n;
        if(n<=1)cout<<"\n vui long nhap lai, ";
    }while(n<=1);
}
void nhap2()
{
    for(int i=0;i<n;i++)
    {
        a[i].nhap();
        tong+=a[i].Tth;
    }
}
void hienbang()
{
    cout<<"\n\n \t q = "<<q<<endl;
    cout<<setw(10)<<"Process"<<setw(9)<<"Tth "<<setw(9)<<"Txh"<<endl;
    for(int i=0;i<n;i++)
        a[i].xuat();
}
void sap_xep()
{
    for( int i=0;i<n;i++)
    {
        int k=0;
        for( int j=n-1;j>i;j--)
            if(a[j].Txh<a[j-1].Txh)
            {
                tien_trinh tam=a[j];
                a[j]=a[j-1];
                a[j-1]=tam;
                k=1;
            }
        if(k==0)return;
    }
}
void nhap()
{
    nhap1();
    nhap2();
    sap_xep();
    hienbang();
}
void daomang( vong_tron a[], int u)
{
    vong_tron tam=a[0];
    for( int i=0;i<u-1;i++)
       a[i]=a[i+1];
    a[u-1]=tam;
}
void sao_chep()
{
    for( int i=0;i<n;i++)
    {
        a[i].SC=a[i].Tth;
        a[i].finish=0;
        a[i].t=a[i].Tth+a[i].Txh;
    }
}
void xoa_bat_ki( vong_tron a[], int &p, int k)
{
    for( int i=k;i<p-1;i++)
        a[i]=a[i+1];
    p--;
}
void hien_giando_GANTT()
{
    cout<<"   ";
    for( int i=0;i<ic;i++)
        cout<<setw(4)<<"P"<<chinh[i];
    cout<<endl;
    for( int i=0;i<o;i++)
        cout<<setw(5)<<c[i];
}
void tang_vong_tron( int i)
{
    b[ivt].chin=a[i].tenso;
    b[ivt].phu=i;
    ivt++;
    j++;
}
void thuc_hien_ve()
{
    int  time=0;
    int k;
    if(a[0].Txh<q)k=a[0].Txh;
    else k=q;
    while(time<tong)
    {
        for( int i=j ;i<n;i++)
            if(j==0||j==1)
                if(a[i].Txh<k+time)tang_vong_tron(1);
            else
                if(a[i].Txh<=k+time)tang_vong_tron(1);
        int h=b[0].phu;
        chinh[ic++]=b[0].chin;
        if(a[h].SC<q) k = a[h].SC;
        else k=q;
        a[h].SC-=k;
        c[o++]=time;
        time+=k;
        if(a[h].SC==0)
        {
            a[h].TH=time;
            a[h].finish=1;
        }
        daomang(b,ivt);
        for( int i=1;i<ivt;i++)
        {
            if(a[b[i].phu].finish==0)break;
            else{
                xoa_bat_ki(b,ivt,i);i--;
            }
        }
        if(ivt==1)break;
        else{
            int g=vong_tron2[1];
            k=a[g].SC;
            if(k>=q)k=q;
        }
    }
    c[o++]=tong;
}
void ve_giando_GANTT()
{
    sao_chep();
    cout<<"\n GIAN DO  GANTT: "<<endl;
    thuc_hien_ve();
    hien_giando_GANTT();

}
void TG_cho()
{
    int k=0;
    for( int i=0;i<n;i++)
    {
        a[i].TC=a[i].TH-a[i].t;
        k+=a[i].TC;
    }
    for( int i=0;i<n;i++)
        cout<<"\n\t TG cho P"<<a[i].tenso<<": "<<a[i].TC;
    cout<<"\n\n Thoi Gian cho doi TB cua cac tien trinh la: "<<(float)k/n<<endl;
}
int main()
{
    nhap();
    ve_giando_GANTT();
    TG_cho();
    return 0;
}










