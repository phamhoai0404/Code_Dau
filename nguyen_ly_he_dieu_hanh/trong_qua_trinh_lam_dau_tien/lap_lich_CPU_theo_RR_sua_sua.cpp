#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
int q,n,tong=0;//trong do: q: la time quantume, n : la so tien trinh, tong: la tong thoi gian thuc hien
int vong_tron1[20],vong_tron2[20], ivt2=0,ivt1=0,chinh[50],ic=0,c[30],o=0;
// trong do vongtron1 la lưu thứ tự cac phần tử trong mảng tien_trinh a[]
//chinh[] là mảng dùng để lưu trữ giản đò GANTT;
// vong_tron2 la lưu tên của phần tử trong mang a[];
class tien_trinh
{
    private:
        int tenso,Tth,Txh;// Tth: thời gian thực hiện, Txh: thời gian xuất hiện, tenso: tên cua tien trinh
        int SC,finish;//SC: mục đích sử dụng nó là cho SC = Tth (thời gian thực hiện); finish: mục đích sử dụng là kiểm tra xem tiến trình đã kết thúc hay chưa
        int TH,t,TC;// TH: thời gian mà tiến trình nó kết thúc; t : là tổng thời gian xuất hiện + thời gian thực hiện; TC: là thời gian chờ của từng tiến trình
    public:
        void nhap();
        void xuat();
    friend void sap_xep();
    friend void sao_chep();
    friend void thuc_hien_ve();
    friend void nhap2();
    friend void TG_cho();
};
tien_trinh a[20];
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
void nhap1()//dùng để nhâp q mà thôi
{
    cout<<"\n==========LAP LICH CPU THEO RR==========";
    cout<<"\n nhap time quantum : q = ";cin>>q;
    do{
        cout<<" \n nhap so tien trinh : ";cin>>n;
        if(n<=1)cout<<"\n vui long nhap lai, ";
    }while(n<=1);
}
void nhap2()//nhap từng tiến trình một
{
    for(int i=0;i<n;i++)
    {
        a[i].nhap();
        tong+=a[i].Tth;
    }
}
void hienbang()// xuất bảng
{
    cout<<"\n\n \t q = "<<q<<endl;
    cout<<setw(10)<<"Process"<<setw(9)<<"Tth "<<setw(9)<<"Txh"<<endl;
    for(int i=0;i<n;i++)
        a[i].xuat();
}
void sap_xep()//mục đích : sắp xếp mảng tiến trình a[] theo thứ tự tăng dần của Txh(thời gian xuất hiện)
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
void daomang( int a[], int u)
{
    int tam=a[0];
    for( int i=0;i<u-1;i++)
       a[i]=a[i+1];
    a[u-1]=tam;
}
void sao_chep()//phần này tách ra thành hàm riêng mục đích là nhìn cho đỡ rối
{
    for( int i=0;i<n;i++)
    {
        a[i].SC=a[i].Tth;
        a[i].finish=0;
        a[i].t=a[i].Tth+a[i].Txh;
    }
}
void xoa_bat_ki( int a[], int &p, int k)//mục đích tạo ra hàm này là dùng phục vụ để xóa tiến trình đã kết thúc của vong_tron ma thoi
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
void thuc_hien_ve()
{
    int  time=0,j=0;
    int k;
    if(a[0].Txh<q)k=a[0].Txh;
    else k=q;
    while(time<tong)
    {
            for( int i=j ;i<n;i++)
                if(j==0||j==1)
                {
                    if(a[i].Txh<k+time)
                    {
                        vong_tron1[ivt1++]=a[i].tenso;
                        vong_tron2[ivt2++]=i;
                        j++;
                    }
                }else{
                    if(a[i].Txh<=k+time)
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
            int yy=vong_tron2[0];
            if(a[yy].finish!=0)
            {
                if(a[yy].SC>q)k=q;
                else k=a[yy].SC;
            }
        }else {
            xoa_bat_ki(vong_tron1,ivt1,0);
            xoa_bat_ki(vong_tron2,ivt2,0);
        }
    }
    c[o++]=tong;
    for( int i=0;i<ic;i++)
        cout<<"\t "<<chinh[i];
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










