#include <iostream>
using namespace std;

template <class T>
void fun(T a)
{
    cout << "The main template fun(): "<< a << endl;
}

template<>
void fun(int a)
{
	cout << "Specialized Template for int type: "<< a << endl;
}


template <class T>
class Test
{
    // Data members of test
    public:
    Test()
    {
        // Initialization of data members
        cout << "General template object \n";
    }
    // Other methods of Test
};

template <>
class Test <int>
{
    public:
    Test()
    {
        // Initialization of data members
        cout << "Specialized template object\n";
    }
};

int main()
{
	fun<char>('a');
	fun<int>(10);
	fun<float>(10.14);	
    Test<int> a;
	Test<char> b;
	Test<float> c;
	return 0;
}
