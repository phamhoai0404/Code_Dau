#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void bai1()
{
	int a,b,min,ucln;
	cout<<"nhap a va b: ";
	cin>>a>>b;
	if(a<b)
	{
	    int tg=a;
		a=b;
		b=tg;
	}
	while(b>0)
	{
		int n;
		n=a%b;
		if(n==0)
		{
			cout<<"ucln= "<<b;
			break;
		}else{
			a=b;
			b=n;	
		}	
	}
}
void bai2()
{
	int n,d=-1;
	float s=0;
	cout<<"n: ";cin>>n;
	for(float i=1;i<=n;i++)
	{
		d*=-1;
		s+=d/i;
	}	 
	cout<<"ket qua la "<<s;
}
void bai3()
{
	int n,s=1;
	cout<<"n: ";cin>>n;
	for(int i=1;i<=n;i++)s*=i;
	cout<<"tich cac so la "<<s;
}
void bai4()
{
	float x,n=1,e=1;
	int i=1;
	cout<<"nhap x: ";
	cin>>x;
	int c=x;
	cout<<x/n+1;
	while(x/n>0.0000001)
	{
		e+=x/n;
		x*=c;
		n*=i;
		
		i++;
	}
	cout<<"ket qua: "<<e;
	getch();	
		
}
int main()
{
	int op;
	cout<<"bai1: Tim UCLN cua a va b"<<endl;
	cout<<"bai2: Tinh tong s"<<endl;
	cout<<"bai3: Tinh n!"<<endl;
	cout<<"bai4: Tinh e^x";
	do
	{
		cout<<"\n nhap lua chon: ";
		cin>>op;
		switch(op)
		{
			case 1:bai1(); break;
			case 2:bai2(); break;
			case 3:bai3(); break;
			case 4:bai4(); break;	
		}
		cout<<"\n nhan nut bat ki de tiep tuc...";
		getch();
	}
	while(1);
	return 0;
}
