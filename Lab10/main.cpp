#include <iostream>
using namespace std;
class base
 {
   public:
    void iam()
   {cout << "Base\n";}
};
class derived1:public base
{
   public:
    void iam()
   {cout << "Derived 1\n";}
};
class derived2:public base
{
   public:
   void iam()
   {cout << "Derived 2\n";}
};
class Employee
{
public:
    virtual void salary()=0;
    virtual void display()=0;
};
class salaried_employee: public Employee
{
protected:
    int no;
    string name;
    int sal;
public:
    void salary()
    {
        cout<<"Enter salaried employee name:";
        cin>>name;
        cout<<"Enter salaried employee number:";
        cin>>no;
        cout<<"Enter salaried employee salary:";
        cin>>sal;
    }
    void display()
    {
        cout<<"\nThe details of salaried employee is:"<<endl;
        cout<<"Salaried employee name:"<< name<<endl;
        cout<<"Salaried employee number:"<< no<<endl;
        cout<<"Salaried employee salary:"<< sal<<endl;
    }
};
class hourly_employee: public Employee
{
protected:
    int no;
    string name;
    int sal;
    int hour;
    int t;
public:
    void salary()
    {
        cout<<"Enter hourly employee name:";
        cin>>name;
        cout<<"Enter hourly employee number:";
        cin>>no;
        cout<<"Enter hourly employee salary:";
        cin>>sal;
        cout<<"Enter hours:";
        cin>>hour;
    }
    void display()
    {
        t=hour*sal;
        cout<<"\nThe details of Hourly employee is:"<<endl;
        cout<<"Hourly employee name:"<< name<<endl;
        cout<<"Hourly employee number:"<< no<<endl;
        cout<<"Hourly employee salary:"<< t<<endl;
    }
};
class comissioned_employee: public Employee
{
protected:
    int no;
    string name;
    int sal;
    int bonus;
    int t;
public:
    void salary()
    {
        cout<<"Enter comissioned employee name:";
        cin>>name;
        cout<<"Enter comissioned employee number:";
        cin>>no;
        cout<<"Enter comissioned employee salary:";
        cin>>sal;
        cout<<"Enter comissioned employee bonus per task:";
        cin>>bonus;
    }
    void display()
    {
        t=bonus+ sal;
        cout<<"\nThe details of comissioned employee is:"<<endl;
        cout<<"Comissioned employee name:"<< name<<endl;
        cout<<"Comissioned employee number:"<< no<<endl;
        cout<<"Comissioned employee bonus:"<< bonus<<endl;
        cout<<"Comissioned employee salary:"<< t<<endl;
    }
};
class shape
{
public:
    double height, width;
    shape()
    {
        height =0;
        width =0;
    }
    void getData()
    {
        cout<<"\n Enter height:";
        cin>>height;
        cout<<"\n Enter width:";
        cin>>width;
    }
    virtual void display_area()=0;
};
class triangle: public shape
{
public:
    void display_area()
    {
        cout<<"\n Area of Triangle="<<(height*width* 0.5);
    }
};
class rectangle: public shape
{
public:
    void display_area()
    {
        cout<<"\n Area of Rectangle="<<(height*width);
    }
};
class Convert
{
protected:
    float val1,val2;
public:
    Convert(): val1(0),val2(0){}
    float getinitial()
    {
        cout<<"Enter Initial value :"<<endl;
        cin>>val1;
    }
    float getconv()
    {
        cout<<"Converted value is  :"<<val2<<endl;
    }
    virtual float compute() = 0;
};
class ltog :public Convert
{
public:
    float compute()
    { Convert::getinitial();
    val2 = val1/0.264;
    return val2;
    }
};
class ftoc:public Convert
{
public:
    float compute()
    {
        Convert::getinitial();
        val2 = ((val1 * 5.0)-(5.0 * 32))/9;
        return val2;
    }
};
class ftom:public Convert
{
public:
    float compute()
    {
        Convert::getinitial();
        val2 = val1*0.3048;
        return val2;
    }
};

int main()
{
    base *A= new base;
    base *B1= new derived1;
    base *B2= new derived2;
    A->iam();
    B1->iam();
    B2->iam();

    Employee *arr[3];
    salaried_employee s;
    hourly_employee h;
    comissioned_employee c;
    arr[0]=&s;
    arr[1]=&h;
    arr[2]=&c;
    arr[0]->salary();
    arr[0]->display();
    cout<<endl;
    arr[1]->salary();
    arr[1]->display();
    cout<<endl;
    arr[2]->salary();
    arr[2]->display();

    shape *s1, *s2;
    triangle t1;
    t1.getData();
    s1=&t1;
    s1-> display_area();
    rectangle r1;
    r1.getData();
    s2=&r1;
    s2->display_area();

    cout<<"\n\n";
    Convert* g[100];
    ltog l;
    ftoc f;
    ftom fm;
    g[0] = &l;
    g[1] = &f;
    g[2] = &fm;
    g[0] -> compute();
    g[0] -> getconv();
    g[1] -> compute();
    g[1] -> getconv();
    g[2] -> compute();
    g[2] -> getconv();
}
