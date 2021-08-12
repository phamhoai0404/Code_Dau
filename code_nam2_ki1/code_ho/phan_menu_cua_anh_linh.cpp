#include<stdio.h>
#include<iostream>
using namespace std;
main() 
{
		int choose;
		cout<<"-----CHUONG TRINH QUAN LY BAN HANG-----";
		cout<<"\n Chon mot trong cac chuc nang";
		cout<<"\n t1. Quan ly danh sach loai hang";
		cout<<"\n t2. Quan ly danh sach hang hoa";
		cout<<"\n t3. Quan l? khach hang";
		cout<<"\n t4. Quan ly gio hang cua khach";
		cout<<"\n t5. Thoat chuong trinh";
		while(1)
		{
			cout<<("\n Hay chon 1 chuc nang: ");
			cin>>choose;
			switch(choose) {
				case 1: cout<<"a"; break;
				case 2: cout<<"b"; break;
				case 3: cout<<"c ";break;
				case 4: cout<<"d "; break;
				case 5: cout<<"e" ;return 2;
				//default: cout<<"Khong hop le, chon lai";
			}
		}
}	
