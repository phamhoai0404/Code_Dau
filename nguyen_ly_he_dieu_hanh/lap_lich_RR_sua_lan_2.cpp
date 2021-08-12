#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<windows.h>
using namespace std;
int q,n,tong=0;
// q: la time quantume, n : la so tien trinh, tong: la tong thoi gian thuc hien
int chinh[50],ic=0,c[30],o=0;
//chinh[] :la mang dung de luu tru chinh thuc ten tien trinh thuc hien trong gian do GANTT; ic : la so phan tu trong mang chinh[].
// c[] : la mang dung de luu tru chinh thoi gian thuc hien trong gian do GANTT; o: la so phan tu trong mang c[].
class tien_trinh
{
    private:
        int tenso,Tth,Txh;// Tth: cpu burst time , Txh: thoi diem  xuat hien, tenso: ten cua tien trinh
        int SC,finish; // sao chep SC = Tth (thoi gian thuc hien).
//finish:  kiem tra tien trinh da ket thuc hay chua
        int TH,t,TC,xl; // TH: thoi gian ma tien trinh do ket thuc ; t : la tong thoi diem xuat hien + thoi gian thuc hien; TC: thoi gian cho cua tung tien trinh.
        //xl: thoi gian xu ly cua tung tien trinh.
    public:
        void nhap();
        void xuat();
    friend void sap_xep();
    friend void sao_chep();
    friend void thuc_hien_ve();
    friend void nhap_nhap_tung_tien_trinh();
    friend void TG_cho();
    friend void TG_xu_ly();
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
void nhap_ban_dau () //dung de nhap q va nhap so tien trinh
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
void nhap_nhap_tung_tien_trinh() //nhap tung tien trinh 1
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
void hienbang()//xuat bang
{
    cout<<"\n\n\t\t\t\t q = "<<q<<endl<<endl;
    cout<<setw(40)<<"Process"<<setw(9)<<"Tth "<<setw(9)<<"Txh"<<endl<<endl;
    for(int i=0;i<n;i++)
        a[i].xuat();
}
void sap_xep()  //muc dich  : sap xep mang tien trinh  a[] theo thu tu tang dan  Txh(thoi gian xuat hien)
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
void sao_chep() // Sao chep Tth, tinh t va dat finish = 0 cua tung tien trinh trong a[]
{
    for( int i=0;i<n;i++)
    {
        a[i].SC=a[i].Tth;
        a[i].finish=0;
        a[i].t=a[i].Tth+a[i].Txh;
    }
}
void xoa_bat_ki( int a[], int &p, int k) //muc dich tao ra ham nay la dung phuc vu xoa tien trinh da ket thuc cua vong tron
{
    for( int i=k;i<p-1;i++)
        a[i]=a[i+1];
    p--;
}
void hien_giando_GANTT() // Hien thi gian do gian ma minh da ve
{
    cout << endl;
    cout << "    |";
    for( int i=0;i<ic;i++)
        cout<<setw(2)<<"P"<<chinh[i]<<setw(2)<<"|";
    cout<<endl<<endl;
    for( int i=0;i<o;i++)
        cout<<setw(5)<<c[i];
    cout<<endl<<endl;
}
void thuc_hien_ve() // Qua trinh thao tac thuc hien va luu tru.
{
    int  time=0,j=0;
 // time: khoi tao bang 0 va la thoi gian thuc hien trong gian do GANTT
    int vong_tron1[20],vong_tron2[20], ivt2=0,ivt1=0;
// Xet tien trinh a[] so sanh thoi diem xuat hien cua tung tien trinh voi q+time( se giai thich o duoi ) neu nho hon  thi :
//    - vong_tron1: la  luu tru tam thoi  ten cac phan tu trong hang doi cua  tien trinh a[];  ivt1: la so phan tu trong mang vong_tron1[].
 //   - vong_tron2: la luu tru tam thoi vi tri cac phan tu trong hang doi cua tien trinh a[]; ivt2: la so phan tu trong mang vong_tron2[].

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
        int h=vong_tron2[0]; // Gia tri dau tien trong mang cho cua vong_tron2;
        if( a[h].finish == 0) // Kiem tra xem tien trinh nay vua trong hang doi da ket thuc hay chua neu chua ket thuc thi tiep tuc ve, neu ket thuc roi thi xoa tien trinh do di
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
           // tien trinh quay ve hang cuoi doi va cho tien trinh ke tiep len dau
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
    cout<<"\ta)";
    cout<<"\n\t\t\t============= GIAN DO  GANTT============= "<<endl<<endl;
    thuc_hien_ve();
    hien_giando_GANTT();
}
void TG_cho() //dung de tinh thoi gian cho
{
    int k=0;
    cout<<"\tb)";
    for( int i=0;i<n;i++)
    {
        a[i].TC=a[i].TH-a[i].t;
// Thoi gian cho cua tien trinh =  thoi diem bat dau xu ly tien trinh –thoi diem xuat hien tien trinh  = thoi gian tien trinh ket thuc - ( thoi diem xuat hien cua tien trinh + CPU burst time cua tien trinh ).

        k+=a[i].TC;
    }
    for( int i=0;i<n;i++)
        cout<<"\n\t TG cho P"<<a[i].tenso<<": "<<a[i].TH<<" - ("<<a[i].Txh<<"+"<<a[i].Tth<<") = "<<a[i].TC;
    cout<<"\n\n\tThoi Gian cho doi TB cua cac tien trinh la: ";
    for( int i=0;i<n;i++)
        if(i==0)cout<<"( "<<a[i].TC<<" + ";
        else
            if(i==n-1) cout<<a[i].TC<<")/"<<n<<" = "<<(float)k/n<<endl<<endl;
            else cout<<a[i].TC<<" + ";
}
void TG_xu_ly() //dung de tinh thoi gian xu ly
{
    int tong_xu_ly=0;
    cout<<"\tc)";
    for( int i=0;i<n;i++)
    {
        a[i].xl=a[i].TH-a[i].Txh;// thoi gian xu ly = thoi gian ket thuc- thoi diem xuat hien
        cout<<"\n\t TG xu ly cua P"<<a[i].tenso<<": "<<a[i].TH <<" - "<<a[i].Txh <<" = "<<a[i].xl;
        tong_xu_ly+=a[i].xl;
    }
    cout<<"\n\n\t Thoi Gian cho doi TB cua cac tien trinh la: ";
    for( int i=0;i<n;i++)
        if(i==0)cout<<"( "<<a[i].xl<<" + ";
        else
            if(i==n-1) cout<<a[i].xl<<")/"<<n<<" = "<<(float)tong_xu_ly/n<<endl<<endl;
            else cout<<a[i].Tth<<" + ";
}
int main()
{
    nhap();
    ve_giando_GANTT();
    TG_cho();
    TG_xu_ly();
    return 0;
}
