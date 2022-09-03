#include <iostream>
using namespace std;
class Test
{   
    int a, b, c;   
    public:
        Test()
        {
            a = b = c = 0;
        }
        Test(int i, int j, int k)
        {
            a = i;
            b = j;
            c = k;
        }

        // use a reference to overload the ++
        friend Test operator ++ (Test & op1);
        friend Test operator ++ (Test & op1, int not_used);

        void Display();
};

/* Overload prefix ++ using a friend function.
   This requires the use of a reference parameter. */
Test operator ++(Test & op1)
{
    op1.a ++;
    op1.b ++;
    op1.c ++;
    return op1;
}

 /* Overload postfix ++ using a friend function.
    This requires the use of a reference parameter. */
Test operator ++ (Test & op1, int not_used)
{
    Test temp = op1;
    op1.a ++;
    op1.b ++;
    op1.c ++;
    return temp;
}

 // Display a, b, c coordinates.
void Test::Display()
{
    cout << a << ", ";
    cout << b << ", ";
    cout << c << "\n";
}

int main()
{
    Test a (12, 22, 33);
    a.Display();

    ++a; // prefix increment
    a.Display();

    a++; // postfix increment
    a.Display();

    return 0;
}