#include <iostream>

using namespace std;
double negative(int x) {

	if (x <= 0) {
		throw "negative number!";
	}
	return (x);
}

class AbsoluteNum
{
	int num;
public:
	AbsoluteNum(int _num)
	{
		try
		{
			if (_num < 0)
				throw "Negative number!";
			else
				num = _num;
		}
		catch (const char* e)
		{
			cout << "\nError! " << e;
		}

	}
	AbsoluteNum& operator=(int _num)
	{
		try
		{
			if (_num < 0)
				throw "Negative number!";
			else
				num = _num;
		}
		catch (const char* e)
		{
			cout << "\nError! " << e;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, const AbsoluteNum& an);
};
ostream& operator<<(ostream& os, const AbsoluteNum& an)
{
	os << an.num;
	return os;
}

class Queue
{private:
    int *array1;
    int front;
    int rear;
    int capacity;
    int c;
public:
    Queue(int size)
    {   array1 = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        c = 0;   }
    int size()
    {return c;}
    bool isEmpty()
    {return (size() == 0);}
    bool isFull()
    {return (size() == capacity);}
    void dequeue()
    {   if (isEmpty())
        {cout << "Underflow";}
        else
        {   cout<< array1[front]<<" is removed" << endl;
            front = (front + 1) % capacity;
            c--;   } }
    void enqueue(int n)
    {   if (isFull())
        {cout << "Overflow";}
        else
        {   cout << n<<" is inserted" << endl;
            rear = (rear + 1) % capacity;
            array1[rear] = n;
            c++;} }
};

int main()
{
    AbsoluteNum a(5);
	cout <<"Absolute num a: "<< a;
	AbsoluteNum b(-1);
	AbsoluteNum c(1);
	cout << "\nAbsolute num c: " << c;
	c = -2;
	c = a;
	cout << "\nAbsolute num c: " << c;

    Queue q(6);
    cout<<"\n";
    q.enqueue(23);
    q.enqueue(42);
    q.enqueue(34);
    q.dequeue();
    q.dequeue();
    q.enqueue(49);
    q.isEmpty();
    q.dequeue();

    return 0;
}
