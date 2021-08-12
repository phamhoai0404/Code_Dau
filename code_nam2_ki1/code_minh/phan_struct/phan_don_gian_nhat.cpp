#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
struct nhansu
{
	char ht[30];
	char dc[30];
	float l;
};
void nhap(nhansu a[], int &n)
{
	do{
		cout<<"\n Nhap vao so nhan su: ";cin>>n;
		if(n<2)cout<<"\vui long nhap lai so nhan vien, ";
	}while(n<2);
	for( int i=0;i<n;i++)
	{
		fflush(stdin);
		cout<<"\n so nhan vien thu "<<i+1;
		cout<<"\n Ten: ";gets(a[i].ht);fflush(stdin);
		cout<<"\n Dia chi: ";gets(a[i].dc);fflush(stdin);
		cout<<"\n Luong : ";cin>>(a[i].l);
	}
}
void xuat( nhansu a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n nhan su thu: "<<i+1;
		cout<<"\n Ten: "<<a[i].ht;
		cout<<"\n Dia chi: "<<a[i].dc;
		cout<<"\n Luong: "<<a[i].l;
	}
}
float tongluong( nhansu a[], int n)
{
	float tong=0;
	for( int i=0;i<n;i++)
	{
		tong+=a[i].l;
	}
	return tong;
}
main()
{
	nhansu a[20];int n;
	nhap(a,n);
	cout<<"\n Tong luong cua "<<n<<" nhan vien la: "<<tongluong(a,n);
	xuat(a,n);
}
	






