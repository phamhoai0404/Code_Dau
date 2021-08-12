#include <iostream>

using namespace std;

int main()
{
	float x, n, c;
	float i=2, t=1;	
	cout << "Nhap x: "; cin >> x;
	n=x;
	float e= 1+x;
	do{
		c=e;
		x*=n;
		t*=i;
		e+=x/t;
		i++;
	}while(e-c>=0.000001);
	cout << "e^x la: " << e;
}
