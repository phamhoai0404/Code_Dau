#include<iostream>
#include<string.h>
using namespace std;
void nhap( char *s)
{
	cout<<"\n nhap chuoi: ";
	gets(s);
}
void xuat( char *s)
{
	cout<<s;
}
void xoa ( char *s, int k)
{
	int n= strlen(s);
	for( int i=k;i<n-1;i++)
	{
		s[i]=s[i+1];
	}
	s[n-1]='\0';
}
void chuanhoa(char *s)
{
	for( int i=0;i<1;i++)
	{
		if(i==0&&s[i]==' ')
		{
			xoa(s,i);
			i--;
		}
	}
	
	for(int i=0;i<strlen(s)-1;i++)
	{
		if( s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		} 
	}
	int n=strlen(s);
	if(s[n-1]==' ')xoa(s,n-1);
}
// xoa mot ki tu bat ki
void xoax( char *s)
{
	char x;
	cout<<"\n nhap vao ki tu can xoa: ";cin>>x;
	for( int i=0;i<strlen(s);i++)
	{
		if(s[i]==x)
		{
			xoa(s,i);
			i--;
			
		}
	}
	chuanhoa(s);// chú ý sau khi xoa xong thì phai chuan hoa tiep chu khong the de nguyen duoc no se thua khoang trang
}
void chen( char*s, char c, int k)
{
	int n = strlen(s);
	for( int i=n;i>k;i--)
	{
		s[i]=s[i-1];
	}
	s[k]=c;
	s[n+1]='\0';
}
void chenchuoi( char*s)
{
	char x;
	cout<<"\n nhap vao ki tu can chen: ";cin>>x;
	for( int i=0;i<strlen(s);i++)
	{
		if(s[i]=='s')
		{
			chen(s,x,i);
			i++;//chu y cai phan nay la phai i++ vi khi chen them vao.....
		}
	}
}
int main()
{
	char *s;
	s=new char[50];
	nhap(s);
	cout<<"\n chuoi vua nhap  la: ";xuat(s);
	chuanhoa(s);
	cout<<"\n mang sau khi chuan hoa la: ";
	xuat(s);cout<<"s";
	chenchuoi(s);cout<<"\n chuoi la: "<<s<<"K";
	delete(s);
	return 0;
}

