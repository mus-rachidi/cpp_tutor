#include <iostream>

template<typename T>
struct less
{
    bool operator()(T const& lhs, T const& rhs)
    {
        return lhs < rhs;
    }
};

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
    f( 1, 2, less<char>());    
    f( 1, 2, std::less<char>());
}