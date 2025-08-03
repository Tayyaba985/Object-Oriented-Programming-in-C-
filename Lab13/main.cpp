#include <iostream>

using namespace std;

template <class T>
int swap_numbers(T& x, T& y)
{
    T t;
    t = x;
    x = y;
    y = t;
    return 0;
}
template <typename T>
double average(T elements[], int size){
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += elements[i];
	}
	return sum/(double)size;
}
template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int topIndex;
public:
    Stack() : topIndex(-1) {}
    bool Empty() const
    {return topIndex == -1;}
    void Push(const T& item)
    {
        if (topIndex == MAX_SIZE - 1)
            {throw std::overflow_error("Stack is full");}
        data[++topIndex] = item;
    }
    T Pop()
    {
        if (Empty())
            {throw std::underflow_error("Stack is empty");}
        return data[topIndex--];
    }
    T Top() const {
        if (Empty())
        {throw std::underflow_error("Stack is empty");}
        return data[topIndex];
    }
};

int main()
{
   int a, b;
    a = 10, b = 20;
    // Invoking the swap()
    swap_numbers(a, b);
    cout << a << " " << b << endl;

    int integers[] = {1, 2, 1, 4, 5};
	double doubles[] = {5.1, 5.5, 2.9, 1.7,8.45};
	long longs[] = {2147483, 456764, 132684, 4445,78754};
	char chars[] = {'a', 'b', 'c', 'd', 'e'};


	cout << "Average of integers: " << average<int>(integers, 5) << endl;
	cout << "Average of doubles: " << average<double>(doubles, 5) << endl;
	cout << "Average of long: " << average<long>(longs, 5) << endl;
	cout << "Average of chars: " << average<char>(chars, 5) << endl;

	system("pause");

	 Stack<int> intStack;
    intStack.Push(5);
    intStack.Push(10);
    intStack.Push(15);
    std::cout << "Top element of intStack: " << intStack.Top() << std::endl;
    while (!intStack.Empty())
    {
        std::cout << "Popped element: " << intStack.Pop() << std::endl;
    }
    Stack<float> floatStack;
    floatStack.Push(3.14f);
    floatStack.Push(2.718f);
    floatStack.Push(1.618f);
    std::cout << "Top element of floatStack: " << floatStack.Top() << std::endl;
    while (!floatStack.Empty())
    {
        std::cout << "Popped element: " << floatStack.Pop() << std::endl;
    }
    return 0;
}
