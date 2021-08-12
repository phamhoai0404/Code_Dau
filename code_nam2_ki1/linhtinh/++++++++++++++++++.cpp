#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
struct ns
{
	int ngay;
	int thang;
	long nam;
};
struct nv
{
	char ten[30];
	char gt[10];
	char cv[30];
	ns d;
	double l;
};
void nhap( nv *&a , int &n)
{
//	do{
	cout<<"\n Nhap vao so can bo: ";cin>>n;
//		if(!(n>=3&&n<=50))cout<<" Vui long nhap lai,";
//	}while(!(n>=3&&n<=50));
	a=(nv*)malloc(n*sizeof(nv));
	for( int i=0;i<n;i++)
	{
		cout<<"\n nhan vien thu : "<<i+1;fflush(stdin);
		cout<<"\n ten: ";gets(a[i].ten);fflush(stdin);
		cout<<"\n gioi tinh: ";gets(a[i].gt);fflush(stdin);
		cout<<"\n cong viec: "; gets(a[i].cv);fflush(stdin);
		cout<<"\ ngay: ";cin>>a[i].d.ngay;fflush(stdin);
		cout<<"\n thang: ";cin>>a[i].d.thang;fflush(stdin);
		cout<<"\n nam: ";cin>>a[i].d.nam;fflush(stdin);
	}
}
void xuat( nv *a, int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\n can bo thu : "<<i+1;
		cout<<"\n ten: "<<a[i].ten;
		cout<<"\n gioi tinh: "<<a[i].gt;
		cout<<"\n cong viec: "<<a[i].cv;
		cout<<"\n ngay sinh: "<<a[i].d.ngay<<"\t thang :"<<a[i].d.thang<<"\t nam : "<<a[i].d.nam;
	}
}
void sapxep( nv *a, int n)
{
	for( int i=0;i<n-1;i++)
	{
		int x=0;
		for( int j=n-1;j>i;j--)
		{
			if(a[j].d.nam>a[j-1].d.nam)
			{
				nv tam=a[j];
				a[j]=a[j-1];
				a[j-1]=tam;
				x=1;
			}
		}
		if(x==1)break;
	}
	cout<<"\n mang sau khi sap xep la: ";xuat(a,n);
}
void timkiem( nv *a, int n)
{
	int k=0;
	cout<<"\n nhap ten danh sach nhan vien can tim kiem; ";char x[30];gets(x);
	for( int i=0;i<n;i++)
	{
		if(strcmp(x,a[i].ten)==0)
		{
			k=1;
			cout<<"\n trong danh sach nay co!";
			break;
		}
	}
	if(k==0)cout<<"\ 0 co nhe!";
}
main()
{
	nv *a;int n;
	nhap(a,n);
	//xuat(a,n);
	//sapxep(a,n);
	timkiem(a,n);
	free(a);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
