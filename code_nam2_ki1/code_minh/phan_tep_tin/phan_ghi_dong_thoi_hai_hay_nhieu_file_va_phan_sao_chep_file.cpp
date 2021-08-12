#include<iostream>
#include<fstream>
using namespace std;
void vietfile( char *tenfile, char *f2)///cai ham nay la ghi dong
{                                      ///thoi ca hai tep, ghi xong tep
	ofstream  f(tenfile);             ///thu nhat thi dong vao roi lai tepthu hai
	f<<"\n toi la mot thang that bai tham ha====hoi ";
	f<<"\n gia tri do la khi nao do nhi !";
	f.close();
	f.open(f2);
	f<<"\n 133333333333333";
	f<<"\n 33333333333 ";
	f.close();
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
void saochepfile(char *lan, char*hue, char*may)
{
	ifstream f(lan);
	ofstream f2(hue);
	char s[255];
	while(!f.eof())
	{
		f.getline(s,255);
		f2<<s<<endl;
	}
	f.close();
	f2.close();
	f.open(may);
	f2.open(hue, ios::app);
	while(!f.eof())
	{
		f.getline(s,255);
		f2<<s<<endl;
	}
	f.close();
	f2.close();
}
main()
{
	vietfile("a","b");
	vietfile("a","c");
	saochepfile("a","b","c");
	docfile("b");
}

