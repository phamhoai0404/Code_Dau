#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<windows.h>
using namespace std;
int q,n,tong=0;
int vong_tron1[20],vong_tron2[20], ivt2=0,ivt1=0,chinh[50],ic=0,c[30],o=0;
class tien_trinh
{
    private:
        int tenso,Tth,Txh;
        int SC,finish;
        int TH,t,TC;
    public:
        void nhap();
        void xuat();
    friend void sap_xep();
    friend void sao_chep();
    friend void thuc_hien_ve();
    friend void nhap_nhap_tung_tien_trinh();
    friend void TG_cho();
};
tien_trinh a[20];
void tien_trinh::nhap()
{
    cout<<endl;
    cout<<"\t\tTG thuc hien: ";cin>>Tth;
    cout<<"\t\tTG xuat hien: ";cin>>Txh;
}
void tien_trinh::xuat()
{
    cout<<setw(35)<<"P["<<tenso<<"]"<<setw(10)<<Tth<<setw(10)<<Txh<<endl<<endl;
}
void nhap_ban_dau()
{
    cout<<"\n==========LAP LICH CPU THEO RR==========";
    do{
        cout<<"\n nhap time quantum : q = ";cin>>q;
        if(q<=0)cout<<"\n vui long nhap lai q>0 , ";
    }while(q<=0);
    do{
        cout<<" \n nhap so tien trinh : ";cin>>n;
        if(n<2)cout<<"\n vui long nhap lai, ";
    }while(n<2);
}
void nhap_nhap_tung_tien_trinh()
{
    for(int i=0;i<n;i++)
    {
        do{
            cout<<"\n\t P["<<i+1<<"] : ";
            a[i].nhap();
            a[i].tenso=i+1;
            if(!(a[i].Txh>=0&&a[i].Tth>0))cout<<"\n vui long nhap lai, ";
        }while (!(a[i].Txh>=0&&a[i].Tth>0));
        for(int j=0;j<i;j++)
            if(a[j].Txh==a[i].Txh)
            {
                cout<<"\n vui long nhap lai vi trung thoi gian xuat hien, ";
                do{
                    cout<<"\n\t P["<<i+1<<"] : ";
                    a[i].nhap();
                    a[i].tenso=i+1;
                    if(!(a[i].Txh>=0&&a[i].Tth>0))cout<<"\n vui long nhap lai, ";
                }while (!(a[i].Txh>=0&&a[i].Tth>0));
                j=-1;
            }
        tong+=a[i].Tth;
    }
}
void hienbang()
{
    cout<<"\n\n\t\t\t\t q = "<<q<<endl<<endl;
    cout<<setw(40)<<"Process"<<setw(9)<<"Tth "<<setw(9)<<"Txh"<<endl<<endl;
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
    nhap_ban_dau();
    nhap_nhap_tung_tien_trinh();
    system("cls");
    cout<<"\n\t\t\t ============ THONG TIN BANG BAN DAU============";
    hienbang();
    cout<<"\n \t\t\t============ THONG TIN BANG SAU KHI SAP XEP============"<<endl;
    sap_xep();
    hienbang();
}
void daomang( int a[], int u)
{
    int tam=a[0];
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
void xoa_bat_ki( int a[], int &p, int k)
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
    cout<<endl<<endl;
}
void thuc_hien_ve()
{
    int  time=0,j=0;
    while(time<tong)
    {
        for( int i=j ;i<n;i++)
            if(j==0||j==1)
            {
                if(a[i].Txh<q+time)
                {
                    vong_tron1[ivt1++]=a[i].tenso;
                    vong_tron2[ivt2++]=i;
                    j++;
                }
            }else{
                if(a[i].Txh<=q+time)
                {
                    vong_tron1[ivt1++]=a[i].tenso;
                    vong_tron2[ivt2++]=i;
                    j++;
                }
            }
        int h=vong_tron2[0];
        if( a[h].finish == 0)
        {
            chinh[ic++]=vong_tron1[0];
            int k;
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
            daomang(vong_tron2,ivt2);
            daomang(vong_tron1,ivt1);
        }else {
            xoa_bat_ki(vong_tron1,ivt1,0);
            xoa_bat_ki(vong_tron2,ivt2,0);
        }
    }
    c[o++]=tong;
}
void ve_giando_GANTT()
{
    sao_chep();
    cout<<"\n\t\t\t============= GIAN DO  GANTT============= "<<endl<<endl;
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
        cout<<"\n\t TG cho P"<<a[i].tenso<<": "<<a[i].TH<<" - ("<<a[i].Txh<<"+"<<a[i].Tth<<") = "<<a[i].TC;
    cout<<"\n\n Thoi Gian cho doi TB cua cac tien trinh la: ";
    for( int i=0;i<n;i++)
        if(i==0)cout<<"( "<<a[i].TC<<" + ";
        else
            if(i==n-1) cout<<a[i].TC<<")/"<<n<<" = "<<(float)k/n;
            else cout<<a[i].TC<<" + ";

}
int main()
{
    nhap();
    ve_giando_GANTT();
    TG_cho();
    return 0;
}










