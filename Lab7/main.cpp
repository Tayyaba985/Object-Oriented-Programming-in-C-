#include<iostream>
using namespace std;

class publication
{
    private:
               string title;
               float price;
   public:
            void getData()
            {
                cout<<"\nEnter Title of the Publication :";
                getline(cin, title);
                cout<<"\nEnter the price of Publication :";
                cin>>price;
            }
           void putData()
            {
                cout<<"\n";
                cout<<"Title :"<<title<<endl;
                cout<<"Price :"<<price<<endl;
            }
};
class book :public publication
{
    int page_count;
    public :
                void getData()
                 {
                     publication::getData();
                     cout<<"\nEnter the page count of Book :";
                     cin>> page_count;
                 }
                 void putData()
                 {
                     publication::putData();
                     cout<<"Page count of  Book is :"<< page_count<<endl;
                 }
};
class tape :public publication
{
    float ptime;
    public :
                void getData()
                {
                    publication::getData();
                    cout<<"\nEnter playing time in minutes :";
                    cin>>ptime;
                }
                void putData()
                {
                    publication::putData();
                    cout<<"Playing time in minutes :"<<ptime<<endl;
                }
};
class Person
{
	double ID;
	string name;
	string address;
  public:
  	Person():ID(0),name(),address(){}

 	void SetPerson()
 	{
 		cout<<"\nEnter an ID for new person:";
 		cin>>ID;
 		cout<<"Enter a name for new person:";
 		fflush(stdin);
 		getline(cin,name);
 		cout<<"Enter an address of new person:";
 		getline(cin,address);
	}
	void PrintPerson()
	{
		cout<<"\nData of the person:"
			<<"\nID: "<<ID
			<<"\nName: "<<name
			<<"\nAddress: "<<address;
	}
};
class Student:public Person
{
	int rollnumber;
	int marks;
  public:
  	void SetStudent()
	{
		Person::SetPerson();
		cout<<"\nEnter a roll number for new student:";
 		cin>>rollnumber;
 		cout<<"Enter marks for new student:";
 		cin>>marks;
	}
	void PrintStudent()
	{
		Person::PrintPerson();
		cout<<"\nData of the student:";
		cout<<"\nRoll number: "<<rollnumber;
        cout<<"\nMarks: "<<marks;
	}
};
class Computer{
private:
	int wordsize;
	float memorysize;
	float storagesize;
	float speed;
public:
	Computer(){}
	Computer(int w,float m,float st,float s): wordsize(w), memorysize(m), storagesize(st), speed(s)
	{}
	void display(){
		cout<<"\nWord size: "<<wordsize<<" bits\n";
		cout<<"Memory size: "<<memorysize<<" megabytes\n";
		cout<<"Storage size: "<<storagesize<<" megabytes\n";
		cout<<"Speed: "<<speed<<" megahertz\n";
	}
};
class Laptop:public Computer
{
private:
	float length;
	float height;
	float width;
	float weight;
public:
	Laptop(){}
	Laptop (float l, float w, float h, float we, int word, float m, float s, float sp):
	     Computer(word,m,s,sp),length(l),width(w),height(h),weight(we)
	{}
	void display(){
		Computer::display();
		cout<<"Length: "<<length<<"\n";
		cout<<"Width: "<<width<<"\n";
		cout<<"Height: "<<height<<"\n";
		cout<<"Weight: "<<weight<<"\n";
	}
};
class student
{
    int rollno;
    string name;
    string clas;
public:
    void getData()
    {
        cout<<"\nEnter Student Data\n";
        cout<<"Enter roll no:";
        cin>>rollno;
        cout<<"Enter Name:";
        fflush(stdin);
        getline(cin,name);
        cout<<"Enter class:";
        fflush(stdin);
        getline(cin,clas);
    }
    void putData()
    {
        cout<<"\n Student Data \n";
        cout<<" Roll number:"<<rollno<<endl;
        cout<<" Name:"<<name<<endl;
        cout<<" Class:"<<clas<<endl;
    }
};
class Test: public student
{
    int t1,t2,t3,s1,s2,assignment,f;
public:
    void getmarks()
    {   cout<<"\n Enter Marks:\n";
        cout<<"Test 1: ";cin>>t1;
        cout<<"Test 2: ";cin>>t2;
        cout<<"Test 3: ";cin>>t3;
        cout<<"Sessional 1: ";cin>>s1;
        cout<<"Sessional 2: ";cin>>s2;
        cout<<"Assignment: ";cin>>assignment;}
    void putmarks()
    {   cout<<"\n Marks: \n";
        cout<<"Test 1: "<<t1<<endl;
        cout<<"Test 2: "<<t2<<endl;
        cout<<"Test 3: "<<t3<<endl;
        cout<<"Sessional 1: "<<s1<<endl;
        cout<<"Sessional 2: "<<s2<<endl;
        cout<<"Assignment: "<<assignment<<endl;}
    void final()
    {f=(t1+t2+t3)*0.15 + (s1+s2)*0.25 + assignment*0.1;}
    void putResult()
    {cout<<"\n Final:"<<f<<endl;}
};
class Simple
{
protected:
    int num1, num2;
public:
    void add()
    {
        cout<<"Sum:"<<num1+num2<<endl;
    }
    void sub()
    {
        cout<<"Difference:"<<num1-num2<<endl;
    }
    void mul()
    {
        cout<<"Product:"<<num1*num2<<endl;
    }
    void div()
    {
        cout<<"Division:"<<num1/num2<<endl;
    }
};
class Complex: public Simple
{
public:
    void getnum()
    {
        cout<<"Enter two numbers:";
        cin>>num1>>num2;
    }
    void add()
    {
        (num1>0 && num2>0) ? Simple::add(): (void(cout<<"Invalid input"<<endl));
    }
    void sub()
    {
        (num1>0 && num2>0) ? Simple::sub(): (void(cout<<"Invalid input"<<endl));
    }
    void mul()
    {
        (num1>0 && num2>0) ? Simple::mul(): (void(cout<<"Invalid input"<<endl));
    }
    void div()
    {
        (num1>0 && num2>0) ? Simple::div(): (void(cout<<"Invalid input"<<endl));
    }

};
class Electricity
{
protected:
    int units;
    int cost;
public:
    void Bill()
    {
        cout<<"Enter the number of unit consumed:";
        cin>>units;
        if(units<= 100)
            cost=units*0.50;
        else
            cost+100*0.50 + (units-100)*0.60;
        cout<<"Total bill: Rs."<<cost<<endl;
    }
};
class more:public Electricity
{
public:
    void Bill()
    {
        Electricity::Bill();
        if (cost>250.00)
        {
            double subcharge= (cost-250.0)*0.15;
            cost= cost+ subcharge;
            cout<<"Additional subcharge: Rs."<<subcharge<<endl;
            cout<<"Total bill:Rs. "<<cost<<endl;
        }
    }
};
int main()
{
    cout<<"\n Book \n";
    book B1;
    B1.getData();
    B1.putData();
    cout<<"\n Tape \n";
    fflush(stdin);
    tape T1;
    T1.getData();
    T1.putData();

    Student a;
    a.SetStudent();
	a.PrintStudent();
	Student d;
	d.SetStudent();
	d.PrintStudent();

	Laptop laptop(5.5,2.6,5.20,2.5,20,30,40,240);
	laptop.display();

	Test tes;
	tes.getData();
	tes.getmarks();
	tes.final();
	tes.putData();
	tes.putmarks();
	tes.putResult();

	Complex num;
	num.getnum();
	cout<<"Results;\n";
	num.add();
	num.sub();
	num.mul();
	num.div();

    more cos;
    cos.Bill();
	return 0;
}
