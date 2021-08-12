#include<iostream>
#include<fstream>

using namespace std;
void vietfile( char *tenfile)//*tenfile:la minh gi ten file do minh chon thoi
{
	ofstream  f(tenfile);//ofstream no kieu nhu la int, float, hay char thoi khong khac gi
	f<<"\n toi la mot thang that bai tham hai qua di mat thoi ";
	f<<"\n gia tri do la khi nao do nhi !";
	f.close();//sau khi lam ket thuc mot ham bao h cung phai dong file hay tep tin
}
void docfile( char *tenfile)
{
	ifstream f(tenfile);
	char s[255];
	while(!f.eof())
	{
		f.getline(s,255);
		cout<<s<<endl;
	}
	f.close();
}
main()
{
	vietfile("toiphaithaydoi");
	docfile("toiphaithaydoi");
}

