#include <vector>
#include <iostream>
int y;
template<class T> 
class A
{
  typename T::x(y) ;

};
int main()
{
    
    typedef std::vector<int> _vector;
    _vector v(1,200);
    std::cout<< v.at(0);
}