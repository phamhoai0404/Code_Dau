#include <iostream>

using namespace std;
class SoPhuc{
	private:
		int a,b;
	public:
		SoPhuc(){
			a = b = 1;
		}
		SoPhuc(int x, int y){
			a = x;
			b = y;
		}
		SoPhuc(int x){
			a = x;
			b = 0;
		}
//		void nhap();
//		void xuat();
		friend istream& operator>>(istream& is, SoPhuc &x);
		friend ostream& operator<<(ostream& os, SoPhuc x);
};
//void SoPhuc::xuat(){
//	cout<<a<<" + "<<b<<"i"<<endl;
//}
istream& operator>>(istream& is, SoPhuc &x){
	cout<<"Nhap phan thuc: ";
	is>>x.a;
	cout<<"Nhap phan ao: ";
	is>>x.b;
	return is;
}
ostream& operator<<(ostream& os, SoPhuc x){
	os<<x.a<<" + "<<x.b<<"i"<<endl;
	return os;
}
int main()
{
   	SoPhuc t;
	cin>>t;
	cout<<"So phuc vua nhap: "<<t;
    return 0;
}

