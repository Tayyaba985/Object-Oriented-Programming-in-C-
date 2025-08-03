#include <iostream>
using namespace std;
class base
{ protected:
    int a,b;
    public:
         void getdata()
         {
             cout<<" enter first number = ";
             cin>>a;
             cout<<" enter 2nd number = ";
             cin>>b;
             }
         void display()
         {
             cout<<"\n\n 1st digit = "<<a<<endl<<"2nd digit = "<<b<<endl;
         }
};
class derived1:public base
{
    protected:
        int c;
        base A1;
        public:
            void getdata()
            {          cout<<"enter the 3rd number = ";
                       cin>>c;
            }
            void display()
            {      A1.display();
                   cout<<" 3rd digit is "<<c<<endl;
            }
};
class derived2:public derived1
{
    public:
        void display()
        {         cout<<"num1 ="<<a<<endl<<"num2 = "<<b<<endl<<"num3 = "<<c<<endl;
        }
};
class person
{
    protected:
        string name;
        int age;
        char gender;
    public:
        void setdata()
        {
            cout<<"\n\tENTER THE NAME = ";
            cin>>name;
            cout<<"\n\tENTER THE AGE = ";
            cin>>age;
            cout<<"\n\tENTER THE GENDER M/F = ";
            cin>>gender;
        }
        void display()
        {
            cout<<"NAME = "<<name<<endl<<"AGE = "<<age<<endl<<"GENDER = "<<gender<<endl;
        }
};
class employee
{
 protected:
 string employee_name;
 int daily_wages;
 person A;
 public:
     void setdata()
     {
         A.setdata();
         cout<<"\n\tENTER THE EMPLOYEE NAME = ";
         cin>>employee_name;
         cout<<"\n\tENTER THE DAILY WAGES = ";
         cin>>daily_wages;
     }
     void display()
     {
         A.display();
         cout<<"EMPLOY NAME = "<<employee_name<<endl<<"DAILY WAGES = "<<daily_wages<<endl;
     }
};
class teacher:public person,public employee
     { protected:
         char grade;
       public:
         void setdata()
         {
             employee::setdata();
             cout<<"\n\tENTER THE GRADE = ";
             cin>>grade;
         }
         void display()
         {
             employee::display();
             cout<<"GRADE = "<<grade<<endl;
         }
};
class Date
{
    protected:
        int day;
        int month;
        int year;
    public:
        Date(int dys,int mnths,int yrs):day(dys),month(mnths),year(yrs)
        {     }
        ~Date()
        {    }
        void sett(int dy,int mnt, int yr)
        {
            day=dy;
            month=mnt;
            year=yr;
        }
        Date get()
        {
            return Date(day,month,year);
        }
        void display()
        {
            cout<<"\n\tday :"<<day<<endl<<"\tmonth :"<<month<<endl<<"\tyear :"<<year<<endl;
        }
};
class Time
    {
         protected:
             int hour;
             int minute;
             int second;
         public:
             Time(int hrs,int minte,int scnd):hour(hrs),minute(minte),second(scnd)
             {      }
              ~Time()
             { }
             void sett(int hr,int mnt,int scnds)
             {
                 hour=hr;
                 minute=mnt;
                 second=scnds;
             }
             Time get()
             {
                 return Time(hour,minute,second);
             }
             void display()
             {
                 cout<<"\nTIME IN HOURS MINTS AND SECONDS";
                 cout<<"\n\tTIME IS :"<<hour<<":"<<minute<<":"<<second<<endl;
             }
};
class DateAndTime : public Date, public Time
    {
        protected:
             int digital;
        public:
DateAndTime(int  dys,int  mnths,int  yrs,  int  hrs,int  mints,int scnds):Date(dys,mnths,yrs),Time(hrs,mints,scnds)
            {      }
            void sett(int dys,int mnths,int yrs,int hrs,int mints,int scnds)
            {
                Date::sett(dys,mnths,yrs);
                Time::sett(hrs,mints,scnds);
            }
            void display()
            {
                Date::display();
                Time::display();
            }
};
class Teacher
{
    string name , address;
    int age;
public:
void input()
{
    cout<<"\n Enter Name:";
    fflush(stdin);
    getline(cin , name);
    cout<<"\n Enter Address:";
    getline(cin , address);
    cout<<"\n Enter Age:";
    cin>>age;
}
void display()
{
    cout<<"\n Name:"<<name<<endl;
    cout<<"\n Age:"<<age<<endl;
    cout<<"\n Address:"<<address<<endl;
}
};
class Author
{
    string name , address;
    int no_of_books;
public:
void input()
{
    cout<<"\n Enter Name:";
    fflush(stdin);
    getline(cin, name);
    cout<<"\n Enter Address:";
    getline(cin, address);
    cout<<"\n Enter number of books written by Author:";
    cin>>no_of_books;
}
void display()
{
    cout<<"\n Name: "<<name<<endl;
    cout<<"\n Address: "<<address<<endl;
    cout<<"\n Number of books written by author: "<<no_of_books<<endl;
}
};
class Scholar: public Teacher , public Author
{
public:
    void input()
    {
      Teacher::input();
      Author::input();
    }
    void display()
    {
      Teacher::display();
      Author::display();
    }
};
class Employee
{
protected:
    string name;
    float basic , wage;
public:
    Employee(float b, int w, string n): basic(b), wage(w), name(n)
    {}
    float calDA()
    {
        return (basic*0.1);
    }
    float calHRA()
    {
        return (basic*0.3);
    }
    ~Employee()
    {}
};
class Regular: public Employee
{
public:
    Regular(float b, string n): Employee(b, 0.0, n)
    {}
    float salary()
    {
        return (Employee::basic * calDA() * calHRA());
    }
    void displaydata()
    {
       cout<<"Regular Employee\n";
       cout<<"Name: " << Employee::name;
       cout<<"\n Basic Salary:"<< Employee::basic;
       cout<<"\n Total Salary: "<<salary();
    }
    ~Regular()
    {}
};
 class Adhoc: public Employee
 {
     int days_count;
 public:
    Adhoc(int w, string n): Employee(0.0, w, n)
    {}
    void days(int d)
    {
        days_count=d;
    }
    float salary()
    {
        return (Employee::wage*days_count*1.0);
    }
    void displaydata()
    {
        cout<<"\n Adhoc Employee";
        cout<<"\nName: "<<Employee::name;
        cout<<"\n Total Salary: "<<salary();
    }
    ~Adhoc()
    {}
 };
 class student
 {
 protected:
    int rollno;
 public:
    void getnum()
    {
        cout<<"\n\n Enter Roll Number:";
        cin>>rollno;
    }
    void putnum()
    {
        cout<<"\nRoll Number: "<<rollno<<endl;
    }
 };
 class Test: public student
 {
 protected:
    int marks;
 public:
    void getmarks()
    {
        cout<<"\nEnter marks: ";
        cin>>marks;
    }
    void putmarks()
    {
        cout<<"\n Marks: "<<marks<<endl;
    }
 };
  class Sports: public student
 {
 protected:
    int score;
 public:
    void getscore()
    {
        cout<<"\nEnter score: ";
        cin>>score;
    }
    void putscore()
    {
        cout<<"\n Score: "<<score<<endl;
    }
 };
 class result: public Test, public Sports
 {
     int total;
 public:
    void display()
    {
    Test::putnum();
    putmarks();
    putscore();
    cout<<"\n Total: "<<Test::marks + Sports::score;
    }
 };
 class LocalPhone
 {
     long int phone;
 public:
    void input()
    {
        cout<<"\nEnter phone number:";
        cin>>phone;
    }
    void display()
    {
        cout<<"\nPhone number:"<<phone<<endl;
    }
};
class NatPhone: public LocalPhone
{
    string cityCode;
public:
    void input()
    {
        cout<<"\nEnter City Code:";
        fflush (stdin);
        getline(cin, cityCode);
    }
    void display()
    {
        cout<<" City Code:"<<cityCode<<endl;
    }
};
class IntPhone: public NatPhone
{
    string countryCode;
public:
    void input()
    {
        cout<<"\n Enter Country Code:";
        fflush(stdin);
        getline(cin,countryCode);
    }
    void display()
    {
        cout<<"Country Code:" <<countryCode<<endl;
    }
};
class Sales
{
    float sales[3];
public:
    void getdata()
    {
        cout<<"\n Enter Dollar sales for last 3 months\n";
        for(int i=1;i<=3; i++)
        {
            cout<<"Month"<<i<<":";
            cin>>sales[i];
        }
    }
    void putdata()
    {
        for(int i=1; i<=3; i++)
        cout<<"\n Month "<<i<<sales[i];
    }
};
class Publications
{
    string title;
    float price;
public:
    void getdata()
    {
        cout<<"Enter Book title:";
        fflush(stdin);
        getline(cin, title);
        cout<<"Enter price:";
        cin>> price;
    }
    void  putdata()
    {
        cout<<"Book Title:"<<title<<endl;
        cout<<"Price:"<<price;
    }
};
class Book: public Sales, public Publications
{ };
class Tape: public Sales, public Publications
{ };

int main()
{
    derived2 a2;
    a2.base::getdata();
    a2.derived1::getdata();
    a2.display();

    teacher a1;
    a1.setdata();
    a1.display();

     cout<<"\nBEFORE SET FUNCTION";
     DateAndTime Watch(0,0,0,0,0,0);
     Watch.display();
     cout<<"\nAFTER SET FUNCTION";
     Watch.sett(13,05,2023,23,10,55);
     Watch.display();

     Scholar S1;
     S1.input();
     S1.display();

     Regular emp1(234.6, "Maheen");
     emp1.displaydata();
     Adhoc emp2(167.9, "Tayyaba");
     emp2.displaydata();

     result obj;
     obj.Test::getnum();
     obj.getmarks();
     obj.getscore();
     obj.display();

     IntPhone p;
     p.LocalPhone::input();
     p.NatPhone::input();
     p.input();
     p.LocalPhone::display();
     p.NatPhone::display();
     p.display();

     cout<<"\n Tape";
     Tape t;
     t.Sales::getdata();
     t.Sales::putdata();
     cout<<"\n Book \n";
     Book b;
     b.Publications::getdata();
     b.Publications::putdata();


     return 0;


}






