#include <type_traits>
#include <iostream>
#include <vector>

class test
{

};

template <class T, typename std::enable_if<std::is_integral<T>::value, T>::type* = nullptr>
void do_stuff(T& t) 
{
    std::cout << "do_stuff integral\n";
    // an implementation for integral types (int, char, unsigned, etc.)
}

template <class T, typename std::enable_if<std::is_class<T>::value, T>::type* = nullptr>
void do_stuff(T& t) 
{
    std::cout << "do_stuff class\n";
    // an implementation for class types
}

int main()
{
    test obj;
    int  a;
   // do_stuff(a);
    do_stuff(obj);
    // =====> in vector STL
    std::vector<int> v1(4,8);
    std::vector<int> v2(std::begin(v1), std::end(v1));
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> v3(arr, arr + 4);

}