#include <iostream>

template<typename Comparator>
void f(int a, int b, Comparator compare)
{
    if (compare(a, b))
    {
        std::cout << "Hello\n";
    }
}

int main()
{
    f( 1, 2, std::less<char>());    
}