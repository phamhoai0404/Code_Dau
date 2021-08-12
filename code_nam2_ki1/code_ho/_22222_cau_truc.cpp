#include <iostream>
#include <cstdlib>
using namespace std;
struct person {
	int maso;
   	char name[30];
	char gioitinh [30];
	//public :DateTime( int ngay, int thang, int nam);
   	char chucvu[30];
	int bacluong;
};
int main()
{
   struct person *ptr;
   int i, n;
   do{
   	cout<<"\n so can bo: "; cin>>n;
   	if(!(n>=3&&n<=50))cout<<"nhap lai so can bo, sao cho 3<=n<=50 , ";
   	}while (!(n>=3&&n<=50));
   ptr = (struct person*) malloc(n * sizeof(struct person));
   for(i = 0; i < n; ++i)
   {	fflush(stdin);
       cout<<"\n thong tin cua nguoi thu  "<< i+1<< " la: ";fflush(stdin);
       cout<<" \t ma so : ";cin>>(ptr+i)->maso;fflush(stdin);
	   cout<<" \t ten  : ";cin>>(ptr+i)->name;fflush(stdin);
	   cout<<" \t gioi tinh : ";cin>>(ptr+i)->gioitinh;
//	   cout<<" \t ngay sinh : "; cin>>(ptr+i)->DateTime &ngay;cin>>(ptr+i)->DateTime &thang;
//	   cin>>(ptr+i)->DateTime &nam;
fflush(stdin);
	   cout<<" \t chuc vu : "; cin>>(ptr+i)->chucvu;
	   fflush(stdin);
	   cout<<" \t bac luong: ";cin>>(ptr+i)->bacluong;
	   fflush(stdin);
   }
   printf("\n \n hien thi  :\n");
   for(i = 0; i < n; ++i)
   {
       cout<<"\n thong tin cua nguoi thu  "<< i+1<< " la: ";
       cout<<" \t ma so : "<<(ptr+i)->maso;
	   cout<<" \t ten  : "<<(ptr+i)->name;
	   cout<<" \t gioi tinh : "<<(ptr+i)->gioitinh;
//	   cout<<" \t ngay sinh : " <<(ptr+i)->DateTime->ngay<<(ptr+i)->DateTime->thang
//	   <<(ptr+i)->DateTime->nam;
	   cout<<" \t chuc vu : "<<(ptr+i)->chucvu;
	   cout<<" \t bac luong: "<<(ptr+i)->bacluong;
    }
   return 0;
}
