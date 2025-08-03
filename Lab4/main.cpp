#include<iostream>
using namespace std;
class Complex
{
 private:
 double real, imag;
 public:
 Complex()
 {
 real = 0.0;
 imag = 0.0;
 }
 Complex (double r, double im)
 {
 real = r;
 imag = im;
 }
 void show()
  {cout<<real<<"+"<<imag<<"i"<<endl;}
 Complex Add (Complex& b)
  {return Complex(real + b.real, imag+ b.imag);}
 Complex Sub (Complex& b)
  {return Complex(real - b.real, imag - b.imag);}
 Complex Mul (Complex& b)
  {return Complex((real * b.real - imag*b.imag), (real*b.imag - b.real*imag));}
};

class Distance
{
  private:
  int feet;
  float inches;

  public:
  int n ,m ,o;
  Distance() : feet(0), inches(0.0)
  { }
  Distance(int ft, float in) : feet(ft), inches(in)
  { }
  void getdist()
  {
   cout<<"\nEnter feet: ";
   cin>>feet;
   cout<<"Enter inches: ";
   cin>>inches;
  }
   inline void showdist();
   void add_dist( Distance, Distance );
   void sub_dist( Distance, Distance );
   void mul_dist( Distance, Distance );
};
inline void Distance::showdist()
  {cout<<feet<<"\""<<inches<<"\'";  }
void Distance::add_dist(Distance d2, Distance d3)
 { inches = d2.inches + d3.inches;
   feet = 0;
   if(inches >= 12.0)
   { inches -= 12.0;
     feet++; }
   feet += d2.feet + d3.feet; }

   void Distance::sub_dist(Distance d2, Distance d3)
 {  if (d2.inches >= d3.inches)
    {inches = d2.inches - d3.inches;
     feet= d2.feet - d3.feet;}
    else
       d2.inches += 12;
       d2.feet --;
       feet= d2.feet - d3.feet;
 }

   void Distance::mul_dist(Distance d2, Distance d3)
   {  inches = d2.inches * d3.inches;
      feet = 0;
     if(inches >= 12.0)
    {
    inches -= 12.0;
    feet++;
    feet *= d2.feet * d3.feet;
   }}
int main()
 { Complex C1(11, 2.3);
   Complex C2(9, 2.3);
   cout<<"1st complex number:";
   C1.show();
   cout<<"2nd complex number:";
   C2.show();
   Complex C3, C4, C5;
   cout<<"Addition of complex numbers:";
   C3 = C1.Add(C2);
   C3.show();
   cout<<"Subtraction of complex numbers:";
   C4 = C1.Sub(C2);
   C4.show();
   cout<<"Multiplication of complex numbers:";
   C5 = C1.Mul(C2);
   C5.show();

   int n;
   Distance dist1, dist3, dist4, dist5;
   Distance dist2(11, 6.25);
   dist1.getdist();
   cout<<"Addition of distance:";
   dist3.add_dist(dist1, dist2);
   cout<<"\ndist1 = ";
   dist1.showdist();
   cout<<"\ndist2 = ";
   dist2.showdist();
   cout<<"\ndist3 = ";
   dist3.showdist();
   cout<<endl;
   cout<<"Subtraction of distance";
   dist4.sub_dist(dist1, dist2);
    cout<<"\ndist1 = ";
   dist1.showdist();
   cout<<"\ndist2 = ";
   dist2.showdist();
   cout<<"\ndist3 = ";
   dist4.showdist();
   cout<<endl;
    cout<<"multiplication of distance";

   dist5.mul_dist(dist1, dist2);
    cout<<"\ndist1 = ";
   dist1.showdist();
    cout<<"\ndist2 = ";
   dist2.showdist();
   cout<<"\ndist5 = ";
   dist5.showdist();
   cout<<endl;

// system("pause");
}
