#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
void nhap(int *&a,int n)
{
	a=(int *)malloc(n*sizeof(int ));
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"]=";
	    cin>>a[i];
	}
}
void ghifile(ofstream &ghiso,int *a,int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			dem++;
			break;
		}
	}
	if(dem==0)
	{
		ghiso<<"\n khong co so chan trong mang!";
		ghiso.close();
	}
	else{
		ghiso<<"so chan trong mang la:";
		for(int i=0;i<n;i++)
		{
			if(a[i]%2==0)
			{
				ghiso<<a[i]<<" ";
			}
		}
		ghiso.close();
	}
}
void docfile(ifstream &docso)
{
	char s[255];
	while(!docso.eof())
	{
		docso.getline(s,255);
		cout<<s;
	}
    docso.close();
}
int main()
{
	int *a;
	int n;
	cout<<"nhap n:";cin>>n;
	nhap(a,n);
   ofstream  sp1("hello.txt");
   ifstream sp2("hello.txt");
   ghifile(sp1,a,n);
   docfile(sp2);
}

