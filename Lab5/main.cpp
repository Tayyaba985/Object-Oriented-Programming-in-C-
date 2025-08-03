#include <iostream>
using namespace std;
class Area
{private:
    int a;
    float b;
 public:
    float area(double,int);
    float area(float,int,int);
    int area(int,int);
    int area(int);
};
    float Area::area(double a,int b)
    { float c;
      c=a*b*b;
      return c;}
    float Area::area(float a,int b,int c)
      { float d;
        d=a*b*b;
        return d;}
    int Area::area(int b,int c)
      {  int a;
         a=b*c;
        return a;}
    int Area::area(int b)
      {  int a;
         a=b*b;
         return a;}

    class Counter
{private:
    int count0;
 public:
    Counter()
    { count0=0;
      count0++;
      cout<<" Object is created "<<count0<<endl;
    }
    Counter(int i)
    { count0=0;
      count0=count0+i;
      cout<<" Object is created "<<count0<<endl;}
    void inc_count()
    {count0++;}
    int get_count()
    {return count0;}
};


class Race
{   private:
     int carNo;
     int driverID;
     int carModel;
    public:
    Race()
    {carNo=0;
     driverID=0;
     carModel=0;}
    Race(int a,int b,int c)
    {carNo=a;
     driverID=b;
     carModel=c;}
    void InputValues()
    {cout<<" Enter Car no.  ";cin>>carNo;
     cout<<" Enter id of driver  ";cin>>driverID;
     cout<<" Enter car model of driver  ";
     cin>>carModel;cout<<endl;}
    void setValues(int cn, int di, int cm)
    {carNo=cn;
     driverID=di;
     carModel=cm;}
     void display()
     {cout<<endl<<" The Car no. is: "<<carNo;
      cout<<endl<<" The id of driver is: "<<driverID;
      cout<<endl<<" The car model of driver is: "<<carModel<<endl<<endl;}
};

class Distance
{private:
    int feet;
    float inches;
    const int id=245;
 public:
  Distance()
     {cout<<"default constructor"<<endl;feet = 0; inches = 0;}
  Distance(float mtrs)
     {cout<<"one argument constructor"<<endl;
      float ft = mtrs * 3.28084;
      feet = (int)
      ft;inches = (ft - feet)*12;}
  Distance (int f, float i)
     {cout<<"two argument constructor"<<endl;
      feet = f;
      inches = i;}
  void setdist(int ft, float in)
     {feet = ft;inches = in;}
  void getdist()
     {cout << "\nEnter feet: ";
      cin >> feet;
      cout << "Enter inches: ";
      cin >> inches;}
  void initialize()
     {feet = 0;inches = 0;}
  void showdist()
     const{cout << "feet = "<< feet <<"\t inches = "<<inches<<endl;}
};

class Date{
    int day, month, year;
    public:
    Date()
    {day = month = year = 0;
    }
    Date(int dd, int mm, int yy){
        while(dd > 30)
        {dd -= 30;
         mm++;
        }
        while(mm > 12){
            mm -= 12;
            yy++;
        }
        day = dd;
        month = mm;
        year = yy;
    }
    void display() const {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
    Date add(Date first, Date second) const{
        return Date(first.day + second.day, first.month + second.month, first.year + second.year);
    }
};

    int main()

    {
        Area a1, a2, a3, a4;
        a1.area(3.14 ,8);
        a2.area(0.5,8,8);
        a3.area(6,4);
        a4.area(10);
        cout<<"area of circle"<<endl;
        cout<<" the area of circle is"<<a1.area(3.14,8)<<endl;
        cout<<"area of triangle"<<endl;
        cout<<" the area of triangle is"<<a2.area(0.5,8,8)<<endl;
        cout<<"area of rectangle"<<endl;
        cout<<" the area of rectangle is"<<a3.area(6,4)<<endl;
        cout<<"area of square"<<endl;
        cout<<" the area of square is"<<a4.area(10)<<endl<<endl;

        Counter c1;
        Counter c2(6);
        c1.inc_count();
        c2.inc_count();
        c1.get_count();
        c2.get_count();

        Race r1;
        Race r2;
        r1.InputValues();
        r2.setValues(23,456,29);
        cout<<"the details entered by user:"<<endl;
        r1.display();
        cout<<"the details entered by using setValues function:"<<endl;
        r2.display();

        Distance dist1, dist2;
        dist1.setdist(11, 6.25);
        Distance dist3(3, 5.75);
        Distance dist4(1);
        cout << "dist1 : "; dist1.showdist();
        cout << "dist2 : "; dist2.showdist();
        cout << "dist3 : "; dist3.showdist();
        cout << "dist4 : "; dist4.showdist();

        Date today(14, 4, 2023), dob(12, 03, 1998), empty;
        empty = today.add(today, dob);
        cout<<"Today: "; today.display();
        cout<<"DOB: "; dob.display();
        cout<<"Today + DOB: ";
        empty.display();


        return 0;

    }
