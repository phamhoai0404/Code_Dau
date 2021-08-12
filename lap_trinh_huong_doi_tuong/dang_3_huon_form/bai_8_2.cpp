#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
class phieuBaoDiem;
class BangDiem
{
    private:
        char TenMon[20];
        float SoTrinh;
        float Diem;
    public:
    	void nhap();
    	void xuat();
       friend class phieuBaoDiem;
       friend float DiemTrungBinh(BangDiem x[], int n);
};
class phieuBaoDiem
{
    public:
        char MaSV[10];
        char TenSV[15];
        int Khoa;
        char Lop[15];
        int n;
        BangDiem x[20];
    public:
        void nhap();
		void xuat();
        friend class BangDiem;
        friend float DiemTrungBinh(BangDiem x[], int n);
};
 void BangDiem::nhap()
{
    cout<<"\nNhap ten mon:";       fflush(stdin);  gets(TenMon);
    cout<<"\nNhap So trinh:";        cin>>SoTrinh;
    cout<<"\nNhap Diem:";       cin>>Diem;
}
void BangDiem::xuat()
{
    cout<<setw(15)<<TenMon;
    cout<<setw(15)<<SoTrinh;
    cout<<setw(15)<<Diem<<endl<<endl;
}

void phieuBaoDiem::nhap()
{
    cout<<"\nNhap ma sinh vien:";       fflush(stdin);  gets(MaSV);
    cout<<"\nNhap ten sinh vien:";      fflush(stdin);  gets(TenSV);
    cout<<"\nNhap lop:";        		fflush(stdin);  gets(Lop);
    cout<<"\nNhap khoa:";       cin>>Khoa;
    cout<<"\nNhap so hang:";        cin>>n;
    for(int i=0;i<n;i++)
        x[i].nhap();
}
void phieuBaoDiem::xuat()
{
    cout<<"\tMa sinh vien:"<<MaSV<<"\t\tTen sinh vien:"<<TenSV<<endl;
    cout<<"\n\tLop:"<<Lop<<"\t\tKhoa:"<<Khoa <<endl<<endl;
    cout<<setw(15)<<"TenMon";
    cout<<setw(15)<<"SoTrinh";
    cout<<setw(15)<<"Diem"<<endl<<endl;
    for(int i=0;i<n;i++)
         x[i].xuat();
    cout<<"\t\t\tDiem Trung Binh : "<<DiemTrungBinh(x,n)<<endl;;

}
float DiemTrungBinh(BangDiem x[], int n)
{
   	float sum1 = 0;
	float  sum2 = 0;
	float DiemTrungBinh = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum1 += x[i].SoTrinh * x[i].Diem;
		sum2 +=x[i].SoTrinh;
	}
	DiemTrungBinh = sum1 / sum2;
	return DiemTrungBinh;
}
int main()
{
    phieuBaoDiem a;
    a.nhap();
    cout<<"\n\n    =================PHIEU BAO DIEM==================="<<endl<<endl;
    a.xuat();

}
