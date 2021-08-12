#include <iostream>
#include <queue>
#include <iomanip>
#include <windows.h>
using namespace std;
#define MAX 50
int n, quantum;
int total = 0;   // tong thoi gian xu ly cua he tien trinh
struct Process
{
    int index;       // vi tri cua tien trinh
    int Txh;         // thoi diem xuat hien
    int Tth;         // CPU burst time
    int wait_time;   // thoi gian cho cua tien trinh
    int process_time;//thoi gian xu ly cua tien trinh
    int t;           // tong thoi diem xuat hien va CPUb
    int en;         //luu thoi gian ket thuc phuc vu cua tt.
    int th;        //sao chep gia tri cua Tth;
};
Process x[MAX];
/*nhap xuat day tien trinh
 *sap xep lai day tien trinh theo thoi diem xuat hien */
//ham nhap xuat thong tin tung tien trinh
void input(Process &x)
{
    do
    {
        cout << "\nNhap CPU burst time:";

        cin >> x.Tth;
        x.th = X.Tth;
        if(x.Tth <= 0)
        {
            cout << "Gia tri khong hop le.Yeu cau nhap lai.";
            cout << endl;
        }
    }
    while(x.Tth <= 0);
    do
    {
cout << "\nNhap CPU arrival time:";

        cin >> x.Txh;
        if(x.Txh < 0)
        {
            cout << "Gia tri khong hop le.Yeu cau nhap lai.";
            cout << endl;
        }
    }
    while(x.Txh < 0);
}
void output(Process x)
{
    cout << setw(2) << x.index;
    cout << setw(15) << x.Tth;
    cout << setw(15) << x.Txh << endl;
}
// nhap xuat day tien trinh
void nhapdaytientrinh()
{
    do
    {
cout << "\nNhap so luong tien trinh:";

        cin >> n;
        if(n < 2)
        {
            cout << "Mot he tien trinh phai >= 2.Nhap lai.";
        }
    }
    while(n < 2);
    for( int i = 0; i < n; i++)
    {
        x[i].index = i+1;
cout << "\nNhap tien trinh :P" << x[i].index << endl;

        input(x[i]);
        total += x[i].Tth;
        x[i].t = x[i].Tth + x[i].Txh;
    }
    do
    {
cout << "\nNhap time quantum:";

        cin >> quantum;
        if(quantum <= 0)
        {
            cout << "Quantum phai lon hon 0.Nhap lai.";
        }
    }
    while(quantum <= 0);
}
void hienthidaytientrinh()
{
    cout << setw(10) << "\nProcess";
    cout << setw(15) << "T_thuc_hien";
    cout << setw(15) << "T_xuat_hien" <<endl;
    for(int i  = 0 ; i < n ; i++ )
        output(x[i]);
    cout << "\nTime Quantum : q = " << quantum << endl;
}
void sapxepdaytientrinh()
{
    for(int i= 0 ; i < n; i++)
    {
        for(int j = n- 1; j > i; j--)
        {
            if(x[j].Txh < x[j-1].Txh)
            {
                Process tmp = x[j];
                x[j]  = x[j-1];
                x[j-1]= tmp;
            }
        }
    }
    hienthidaytientrinh();
}
// giai quyet bai toan
queue<Process> ds; //Luu cac Process dang duoc phuc vu.
queue<Process> stoppt; //Luu Process dung de tinh TGXL.
queue<Process> stopwt; //luu Process dung de tinh TGC.
//Ham ve gian do Gantt
void vegiandoGantt()
{
    int bd = 0, kt = 0;
    int k = 0;
    int q = quantum;
    while(quantum <= total)
    {
        for(int i = k; i < n; i++)
        {
            if(x[i].Txh <= quantum)
            {
                ds.push(x[i]);
                k++;
            }
            else
                break;
        }
        Process X = ds.front();
        ds.pop();
        if(X.Tth <= q)
        {
            quantum += X.Tth;
            kt += X.Tth;
            X.Tth = X.Tth – X.Tth;
            cout<< "|" << bd <<" P"<<X.index<<" "<< kt << "| ";
            bd = kt;
            X.en = kt;
            stoppt.push(X);
            stopwt.push(X);
        }
        else
        {
            quantum += q;
            X.Tth = X.Tth – q;
            kt += q;
            cout<< “|” << bd <<“ P”<<X.index<<“ ”<< kt << “| ”;
            bd = kt;
            if(X.Tth != 0)
                ds.push(X);
        }
    }
}
// ham tinh thoi gian xu ly trung binh
void tinhThoiGianXuLyTB()
{
    // TGXL = TG ket thuc Process – T xuat hien
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        Process X = stoppt.front();
        X.process_time = X.en – X.Txh;
cout<< “/nThoi gian xu ly cua P”<<X.index<< “:
            ”;
        cout<< X.en << “ - ” <<X.Txh<< “=” << X.process_time;
        sum += X.process_time;
        stoppt.pop();
    }
cout << “\nThoi gian xu ly TB cua he tien trinh la :
         ”;
    cout << sum/n;
}
// ham tinh thoi gian cho trung binh cua he tien trinh
void tinhThoiGianChoTrungBinh()
{
    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        Process X = stopwt.front();
        X.wait_time = X.en – X.Txh – X.th;
cout<< “/nThoi gian cho cua P”<<X.index<< “:
            ”;
        cout<<X.en<<“-”<<X.Txh<<“-”<<X.th<<“=”<<X.wait_time;
        sum += X.wait_time;
        stopwt.pop();
    }
cout << “\nThoi gian cho TB cua he tien trinh la :
         ”;
    cout << sum/n;
}
int main()
{
    nhapdaytientrinh();
    system(“cls”);
    cout << “\n-----LAP LICH CPU VOI THUAT TOAN RR-----\n”;
    hienthidaytientrinh();
    cout << “\n---DAY TIEN TRINH SAU KHI DA SAP XEP THEO
         THOI DIEM XUAT HIEN---\n”;
    Sapxepdaytientrinh();
    cout << “\n-----VE GIAN DO GANTT-------\n”;
    vegiandoGantt();
    cout << “\n---TINH THOI GIAN XU LY TRUNG BINH---\n”;
    tinhThoiGianXuLyTB();
    cout << “\n---TINH THOI GIAN CHO TRUNG BINH---\n”;
    tinhThoiGianChoTrungBinh();
    cout << “\n-------------------------------------\n”;
    return 0;
}
