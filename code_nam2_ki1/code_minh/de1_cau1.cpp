#include<iostream>
#include<math.h>
using namespace std;
void nhap( float &x, int &n)
{
	cout<<"nhap x: ";cin>>x;
	cout<<"\n nhap n: ";cin>>n;
}
float tinh( float x, int n)
{
	float a=1;
	float s;
	if(x>0&&n>0)
	{
		s=100;
		for( int i=1;i<=n;i++)
		{
			a*=x;
			s+=sqrt(a)/n;
		}
	}else s=pow(sin(x),n);
	return s;
}
int main()
{
	int n;
	float x;
	nhap(x,n);
	cout<<"\n s= "<<tinh(x,n);
	return 0;
	}
