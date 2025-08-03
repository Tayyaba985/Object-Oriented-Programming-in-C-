#include <iostream>
#include <iomanip>
using namespace std;
class Counter
{ int value;
public:
    Counter(int v=0) : value(v) {}
    Counter& operator++();          // Prefix
    Counter operator++(int);        // Postfix
    int getValue() const {
        return value;
    }
};
Counter& Counter::operator++() {
    value++;
    return *this;
}
Counter Counter::operator++(int) {
    Counter tmp = *this;
    value++;
    return *this;
}
class Complex
{   private:
        double real;
        double imaginary;
    public:
        Complex(double real=0, double imaginary=0);
        ~Complex();
        double getReal() const;
        double getImaginary() const;
};
std::ostream& operator<<(std::ostream& out, const Complex& complex);
Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}
Complex::~Complex() {}
double Complex::getReal() const
{    return this->real;  }
double Complex::getImaginary() const
{    return this->imaginary;   }
std::ostream& operator<<(std::ostream& out, const Complex& other) {
    return out << other.getReal() << "+" << other.getImaginary() << "i";
}
class Distance
{private:
    int feet;
    int inch;
public:
    Distance() : feet(0), inch(0) {};
    Distance(int ft, int in) : feet(ft)
    {
        feet += in / 12;
        inch = in % 12;
    };

    void getdata(int ft, int in) {
        feet = ft + in / 12;
        inch = in % 12;
    };


    void show() {
        cout << feet << " ft  " << inch << " in" << endl;
    };

    Distance& operator+=(const Distance& r) {
        feet += r.feet;
        inch += r.inch;
        feet = feet + inch / 12;
        inch = inch % 12;
        return *this;
    };


    friend bool operator<(const Distance& l, const Distance& r) {
        return l.feet * 12 + l.inch < r.feet * 12 + r.inch;
    };
};

class Complex
{


    double real;
    double image;


public:


    void setReal(double re)
    {
        real = re;
    }


    void setImage(double im)
    {
        image = im;
    }


    double getReal() const
    {
        return real;
    }


    double getImage() const
    {
        return image;
    }


    Complex(double re, double im): real(re), image(im){}


    Complex operator+(Complex &complexNum)
    {
        complexNum.real = real + complexNum.real;
        complexNum.image = image + complexNum.image;
        return complexNum;
    }


    Complex operator-(Complex &complexNum)
    {


        complexNum.real = real - complexNum.real;
        complexNum.image = image - complexNum.image;
        return complexNum;
    }


    Complex operator*(Complex &complexNum)
    {
        double i, j;
        i = real * complexNum.real - image * complexNum.image;
        j = real * complexNum.image + complexNum.real * image;
        complexNum.real = i;
        complexNum.image = j;
        return complexNum;
    }


    Complex operator / (Complex& complexNum)
    {
        double i, j, k;
        k = real * real + complexNum.image * complexNum.image;
        i = (real * complexNum.real + image * complexNum.image) / k;
        j = (complexNum.real * image - real * complexNum.image) / k;
        real = i;
        image = j;
    return *this;
    }


    Complex operator ++()
    {
        real++;
        return *this;
    }


    Complex operator --()
    {
        real--;
        return *this;
    }


    friend ostream &operator<< (ostream &out, const Complex &complexNum)
    {
        if (complexNum.image < 0)
            out << complexNum.real << "+i(" << complexNum.image << ")\n";
        else
            out << complexNum.real << "+i" << complexNum.image << "\n";
        return out;
    }


    friend istream &operator>>(istream &in, Complex &complexNum)
    {
        cout << "Введите реальную часть: ";
        in >> complexNum.real;
        cout << "Введите мнимую часть: ";
        in >> complexNum.image;
        return in;
    }

};
int main() {
    cout << " x | x^2" << endl;
    for (Counter c(1); c.getValue()<=10; ++c) {
        int x = c.getValue();
        cout << setw(2) << x << " | " << setw(3) << x*x << endl;
    }

    Complex z1(5, 6);
    Complex z2(3, 2);
    cout << "Complex number z1 is: " << z1 << "\n";
    cout << "Complex number z2 is: " << z2 << "\n";

     Distance d1;
    Distance d2(2, 13);
    cout << "d1 = ";  d1.show();
    cout << "d2 = "; d2.show();
    cout << "d1.getdata(3, 1);" << endl;
    cout << "d2 += Distance(1,0);" << endl;
    d1.getdata(3, 1);
    d2 += Distance(1, 0);
    if (d1 < d2) {
        cout << "Distance d1 is less than d2." << endl;
    }
    else {
        cout << "Distance d1 not less than d2." << endl;
    }
    cout << "d2.show();" << endl;
    d2.show();


    return 0;
}
