#include<conio.h> // thu vien nay dung cho getch , con nhung cai khac thi khong biet
#include<iostream>
#include<stdlib.h> //thu vien nay la dung cho system
using namespace std;
void bai1()
{	
}
void bai2()
{
}
int main()
{
	do{
		int x;
		cout<<"\t\t\tHAY CHON MENU SAU ! ";
		cout<<"\n 1: Bai 1";
		cout<<"\n 2: Bai 2";
		cout<<"\n 3: Ket thuc chuong trinh! ";
		cout<<"\n\n Ban lua chon: ";
		cin>>x;
		switch(x)
		{
			case 1:bai1();break;
			case 2:bai2();break;
			case 3: return 0;
		}
		cout<<"\n Press  any key to continues...";
		getch();
		system("cls");
	}while(1);
}
	
