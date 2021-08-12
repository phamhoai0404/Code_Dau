#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class FACULTY;
class STUDENT;
class SCHOOL
{
    private:
        char name[20];
        int date;
    friend class FACULTY;
};
class FACULTY
{
    private:
        char name[20];
        int date;
        SCHOOL x;
    public:
        void input();
        void output();
    friend class STUDENT;
};
class PERSON
{
    protected:
        char name[20];
        int birth;
        char address[20];
    public:
        void input();
        void output();
};
class STUDENT: private PERSON
{
    private:
        FACULTY y;
        char Class[10];
        char score[20];
    public:
        void input();
        void output();
};
void FACULTY::input()
{
    cout<<"ten giao vien: ";fflush(stdin);gets(name);
    cout<<"nam sinh cua giao vien: ";cin>>date;
    cout<<"truong day cua giao vien: ";fflush(stdin);gets(x.name);
    cout<<"nam thanh lap truong: ";cin>>x.date;
}
void FACULTY::output()
{
    cout<<setw(10)<<name;
    cout<<setw(10)<<date;
    cout<<setw(10)<<x.name;
    cout<<setw(10)<<x.date;
}
void PERSON::input()

{
    cout<<"\nten: ";fflush(stdin);gets(name);
    cout<<"nam sinh: ";cin>>birth;
    cout<<"dia chi : ";fflush(stdin);gets(address);
}
void PERSON::output()
{
    cout<<setw(10)<<name;
    cout<<setw(10)<<birth;
    cout<<setw(10)<<address;
}
void STUDENT::input()
{
    PERSON::input();
    y.input();
    cout<<"lop hoc: ";cin>>Class;
    cout<<"ma sinh vien: ";fflush(stdin);gets(score);
}
void STUDENT::output()
{
    PERSON::output();
    y.output();
    cout<<setw(10)<<Class;
    cout<<setw(10)<<score;
}
void cot_mau()
{
    cout<<setw(10)<<"tenhs";
    cout<<setw(10)<<"namsinh";
    cout<<setw(10)<<"diachi";
    cout<<setw(10)<<"giaovien";
    cout<<setw(10)<<"namsgv";
    cout<<setw(10)<<"truong";
    cout<<setw(10)<<"namtltrg";
    cout<<setw(10)<<"lop";
    cout<<setw(10)<<"masv"<<endl;
}
int main()
{
    STUDENT x;
    cout<<"nhap vao thong tin sinh vien: "<<endl;
    x.input();
    cout<<"hien thi thong tin sinh vien: "<<endl;
    cot_mau();
    x.output();
}

