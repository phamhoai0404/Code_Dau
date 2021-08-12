#include<iostream>
#include<math.h>
using namespace std;
void nhap(int a[][50],int &m,int &n )
{
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		cout<<"a["<<i<<"]["<<j<<"]=";
		cin>>a[i][j];
	}
}
void xuat(int a[][50],int m ,int n)
{
	cout<<"\n";
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		{
			cout<<"\t "<< a[i][j];
		}
		cout<<"\n";
	}
}
int  tong(int a[][50],int m ,int n)
{
	int sum=0;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		sum+=a[i][j];
	}
	return sum;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void hoanvi(int a[][50],int m)
{
	for(int i=0;i<m;i++)
	  for(int j=0;j<i;j++)
	   swap(a[i][j],a[j][i]);
}
int main()
{
	int a[50][50];
	int m,n,s;
	cout<<"\nnhap so hang la:";cin>>m;
	cout<<"\nnhap so cot la:";cin>>n;
	nhap(a,m,n);
	cout<<"\nma tran la:";
	xuat(a,m,n);
	s=tong(a,m,n);
	cout<<"\ntong cua ma tran la:"<<s;
	hoanvi(a,m);
	cout<<"\nmang sau khi hoan vi la:";
	xuat(a,m,n);
	return 0;
}
