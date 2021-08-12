#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
using namespace std;
void nhap( int a[][100], int m, int n)
{	
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<n;j++)
		{
			cout<<" phan tu hang "<<i+1<<" cot "<<j+1<<" =  ";
			cin>>a[i][j];
		}
	}
}
void xuat( int a[][100], int m, int n)
{
	for( int i =0;i< m;i++)
	{
		cout<<"\n\n";
		for( int j=0;j<n;j++)
		{
			cout<<"\t"<<a[i][j];
		}
	}
}
void cong( int a[][100], int b[][100], int c[][100], int m, int n)
{
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void chuyenvi( int a[][100], int b[][100], int m, int n)
{
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<n;j++)
		{
			b[j][i]=a[i][j];
		}
	}
}
/*void nhan( int a[][100], int b[][100],int c[][100], int m, int n, int x )
{
	int d[100][100];
	chuyenvi(b,d,n,x);
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<x;j++)
		{
			int s=0;
			for(int z=0;z<n;z++)
			{
				s+=a[i][z]*d[j][z];//dong nay phai ghi nho (minh tu lam)nhung suy luan linh tinh qua ma
			} cach này là mình ngu ng??i thôi hãy c? g?ng lên nhé b?n c?a tôi ?i
			c[i][j]=s;
		}				
	}
}*/
void nhann( int a[][100], int b[][100],int c[][100], int m, int n, int x)
{
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<x;j++)
		{
			int s=0;
			for( int z=0;z<n;z++)
			{
				s+= a[i][z]*b[z][j];
			}
			c[i][j]=s;
		}
	}
}
void duongcheochinh( int a[][100], int n)
{		
	for( int i=0;i<n;i++)
	{
		cout<<"\n\n\n";
		for( int j=0;j<n;j++)
		{
			if(i==j)cout<<"\t"<<a[i][j];
			else cout<<"\t * ";
		}
	}
}
void duongcheophu( int a[][100], int n)
{
	for( int i=0;i<n;i++)
	{
		cout<<"\n\n\n";
		for( int j=0;j<n;j++)
		{
			if(j==n-1-i)cout<<"\t"<<a[i][j];
			else cout<<"\t * ";
		}
	}
}
double nangluong( int a[][100], int m, int n)
{
	double x=0;
	for( int i=0;i<m;i++)
	{
		for( int j=0;j<n;j++)
		{
			x+=pow(a[i][j],2);
		}
	}
	return x;
}
void bai1()
{
	int a[100][100],b[100][100],m,n,x,y;
	cout<<"\n nhap so hang: ";cin>>m;
	cout<<"\n nhap so cot cua a: ";cin>>n;
	nhap(a,m,n);
	cout<<"\n mang la a la : \n";
	xuat(a,m,n);
	cout<<"\n ";
	cout<<"\n nhap so hang: ";cin>>x;
	cout<<"\n nhap so cot cua a: ";cin>>y;	
	nhap(b,x,y);
	cout<<"\n mang la b la : \n";
	xuat(b,x,y);
}
void bai2()
{
	int a[100][100],b[100][100],m,n, c[100][100];
	cout<<"\n nhap so hang: ";cin>>m;
	cout<<"\n nhap so cot cua a: ";cin>>n;
	nhap(a,m,n);
	cout<<"\n ma tran a: ";
	xuat(a,m,n);
	cout<<"\n nhap man tran b: ";
	nhap(b,m,n);
	cout<<"\n mang la b la : \n";
	xuat(b,m,n);
	cong(a,b,c,m,n);
	cout<<"\n tong hai ma tran la: ";
	xuat(c,m,n);
}
void bai3()
{
	int a[100][100],b[100][100],m,n;
	cout<<"\n nhap so hang: ";cin>>m;
	cout<<"\n nhap so cot cua a: ";cin>>n;
	nhap(a,m,n);
	cout<<"\n ma tran a: ";
	xuat(a,m,n);
	chuyenvi(a,b,m,n);
	cout<<"\n ma tran chuyen vi la: ";
	xuat(b,n,m);
}
void bai4()
{
	int a[100][100],b[100][100],c[100][100],m,n,x;
	cout<<"\n nhap so hang: ";cin>>m;
	cout<<"\n nhap so cot cua a, hay so hang cua b : ";cin>>n;
	nhap(a,m,n);
	cout<<"\n mang la a la : \n";
	xuat(a,m,n);
	cout<<"\n ";
	cout<<" so cot cua b: ";cin>>x;
	nhap(b,n,x);
	cout<<"\n mang la b la : \n";
	xuat(b,n,x);
	nhann(a,b,c,m,n,x);
	cout<<"\n mang nhan la: ";
	xuat(c,m,x);
}
void bai5()
{
	int a[100][100], n;
	cout<<"\n nhap vao n: ";
	cin>>n;
	nhap(a,n,n);
	cout<<" mang la: ";
	xuat(a,n,n);
	cout<<"\n hien thi duong cheo chinh";
	duongcheochinh(a,n);
	cout<<"\n hien thi duong cheo phu !";
	duongcheophu(a,n);
}
void bai6()
{
	int a[100][100], m,n;
	cout<<"\n nhap hang: ";cin>>m;
	cout<<"\n nhap cot: ";cin>>n;
	nhap(a,m,n);
	cout<<"\n nang luong la: "<<nangluong(a,m,n);
}
int main()
{
	int op;
	do{
		cout<<"\t \t\t HAY CHON LUA CHON CUA BAN !";
		cout<<"\n 1: bai 1";
		cout<<"\t 2: bai 2";
		cout<<"\t 3: bai 3";
		cout<<"\t 4: bai 4";
		cout<<"\t 5: bai 5";
		cout<<"\t 6: bai 6";
		cout<<"\n 7: ket thuc chuong trinh ! ";
		cout<<"\n\n Nhap vao lua chon cua ban: ";
		cin>>op;
		switch(op)
		{
			case 1: bai1();break;
			case 2: bai2();break;
			case 3: bai3();break;
			case 4: bai4();break;
			case 5: bai5();break;
			case 6: bai6();break;
			case 7: return 0;
		}
		cout<<"\n Press to continues...";
		getch();
		system("cls");
	}while(1);
}






