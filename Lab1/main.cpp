#include <iostream>
#include <cstring>
#define NO_OF_EMP	3
using namespace std;
void swaping(int number1, int number2);
void swap(int* number1, int* number2);
void sortArray1(int arr[10] , int size);
void sortArray2 (int*ptr_array, int size);
void revstr(char *str1);
struct employee
{
    int emp_code;
    string name;
    int date_of_joining;
};
struct Books
{
int id;
int price;
int pages;
};
int main()
{
    int num1, num2;
    int *ptr1, *ptr2;
    cout << "\n Enter first number: ";
    cin >> num1;
    cout << "\n Enter second number: ";
    cin >> num2;
    ptr1 = &num1;
    ptr2 = &num2;
    *ptr1 = *ptr1 +10;
    *ptr2 = *ptr2 +10;
    cout << "\n Value of 1st number:"  <<*ptr1;
    cout << "\n Value of 2nd number:" <<*ptr2;



    int a, b;
    cout << "\n Enter first number: ";
    cin >> a;
    cout << "\n Enter second number: ";
    cin >> b;
    cout << "\n before swapping by value ";
    cout << "\n a="<< a;
    cout << "\n b="<< b;
    cout << "\n after swapping by value ";
    swaping(a,b);


    int c, d;
    cout << "\n Enter first number: ";
    cin >> c;
    cout << "\n Enter second number: ";
    cin >> d;
    cout << "\n before swapping by reference ";
    cout << "\n c="<< c;
    cout << "\n d="<< d;
    cout << "\n after swapping by reference\n ";
    swap(c,d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

Books book1;
Books book2;

cout<<"book 1 id :";
cin>>book1.id;
cout<<"book 1 price :";
cin>>book1.pages;
cout<<"book 1 pages :";
cin>>book1.price;
cout<<"book 2 id :";
cin>>book2.id;
cout<<"book 2 price :";
cin>>book2.pages;
cout<<"book 2 pages :";
cin>>book2.price;

cout<< "\nDisplay the record of most costly book:";
if(book1.price>book2.price)
{
cout<<"\n Book1";
cout<<"\n Book id: " << book1.id;
cout<<"\n Book price:" << book1.price;
}
else
{
cout<<"\n Book2";
cout<<"\n Book id: " << book2.id;
cout<<"\n Book price:" << book2.price;
}

 int arr1[10] ={1 ,34 ,3 ,48 ,5 ,9 ,7 ,17 ,8 ,14 };
 cout<<"\n Sorting by value";
 cout<<"\n Array before sorting:";
  for (int i = 0; i < 10; ++i)
        std::cout << arr1[i] << " ";
    std::cout << "\n";
    sortArray1(arr1, 10);
    cout<<" \n Array after sorting:";
    for (int i = 0; i < 10; ++i)
        std::cout << arr1[i] << " ";
    std::cout << "\n";


    int arr2[10] ={87 ,34 ,36 ,8 ,1 ,9 ,7 ,65 ,8 ,24 };
    cout<<"\n Sorting by reference";
    cout<<"\n Array before sorting:";
    for (int i = 0; i < 10; ++i)
        std::cout << arr2[i] << " ";
    std::cout << "\n";
    sortArray2 (arr2 , 10);
    cout<<" \n Array after sorting:";
    for (int i = 0; i < 10; ++i)
        std::cout << arr2[i] << " ";
    std::cout << "\n";

 char str[50] = "Object Oriented Programming";
    cout << "\n Before reversing the string: " << str;
    revstr(str);
    cout<< "\n After reversing the string: " << str;

    int n;
    int current_date;
    cout<<"\n\n How many records you want to enter:";
    cin>>n;
    int arr[5];
    struct employee emp[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter details for employee "<<i+1<<endl;
        cout<<"\nEnter employee code:";
        cin>>emp[i].emp_code;
        cout<<"\nEnter employee name:";
        cin>>emp[i].name;
        cout<<"\nEnter employee date of joining:";
        cin>>emp[i].date_of_joining;

        cout<<"\nEnter current date: ";
        cin>>current_date;
        int tenure=current_date-emp[i].date_of_joining;
        arr[i]=tenure;
    }
    cout<<"\nNames of employees whose tenure is 3 or more than 3 years according to the given current date:\n";
    for (int i=0;i<n;i++){
        if (arr[i]>=3){
            cout<<emp[i].name<<endl;
        }
    }
    return 0;
}
void swaping(int number1, int number2)
{
    int temp;
    temp = number1;
    number1 = number2;
    number2 = temp;
    cout << "\n a = " << number1 << endl;
    cout << "b = " << number2 << endl;

    }
void swap(int* number1, int* number2)
 {
    int temp;
    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void sortArray1(int arr[10] , int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int small = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[small])
                small = j;
        }
        double temp=arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

void sortArray2 (int *ptr_array, int size)
{
    for (int i= size;i>0; i--)
    {
        for(int j=0; j<i-1;j++)
        {
            if(*(ptr_array+j)> *(ptr_array+j+1))
            {
                int temp= *(ptr_array+j+1);
                *(ptr_array+j+1)= *(ptr_array+j);
                *(ptr_array+j)= temp;
            }
        }
    }
}

void revstr(char *str1)
{
    int i, len, temp;
    len = strlen(str1);
    for(i = 0;i < len/2;i++)
    {
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
}
