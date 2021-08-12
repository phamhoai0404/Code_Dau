#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
void nhap(int *&a,int &n)
{
	cout<<"\n nhap n:";cin>>n;
	a=(int *)malloc(n*sizeof(int ));
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";
	    cin>>a[i];
	}
}
void xuat(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
}
void ghifile( ofstream &sochan,int *a,int n)
{
	sochan<<"cac so nguyen duong chan trong mang la:\n";
	for(int i=0;i<n;i++)
	{		
		   sochan<<a[i]<<" ";
	}
	sochan.close();
}
/*void ghifile1(ofstream &sochan,int *a,int n)
{
	sochan<<"cac so chia het cho 3 nhung khong chia het cho 5 la:\n";
	for(int i=0;i<n;i++)
	{
		if(a[i]%3==0&&a[i]%5!=0)
		{
			sochan<<"a[i]"<<"";
		
		}
	}
	sochan.close();
}
*/
int  readfile (ifstream &sochan,int *b,int n)
{
	
	if(! sochan)
	{
		cout<<"khong mo duoc file\n:";
		return 0;
	}
	else{
		for(int i=0;i<n;i++)
		{
			sochan>>b[i];
		
		}
	}
	
}
int main()
{
	int *a;
	int n;
	ofstream sp("file.txt");
	ifstream sp2("file.txt");
	nhap(a,n);
	cout<<"mang sau khi nhap la:";
	ghifile(sp,a,n);
	int *b = new int[n];
	readfile(sp2,b,n);
	xuat(b,n);
	return 0;
}
