#include <iostream>

void foo(unsigned int i) 
{
  std::cout << "unsigned int " << i << "\n";
}

template <typename T>
void foo(const T& t)
{
  std::cout << "template " << t << "\n";
}



int negate(int i) {
  return -i;
}

template <typename T>
typename T::value_type negate(const T& t) 
// There's no error involved
// compiler simply ignores this candidate and looks at the others.
// In the C++ folklore, this rule was dubbed "Substitution Failure Is Not An Error", or SFINAE.
{
  return -T(t);
}

template <typename T>
void negate(const T& t) 
{
  typename T::value_type n = -t();
  /*
    - we'll actually get a compile error due to the T::value_type inside the function body.
  */
}

int main()
{
    foo((unsigned int)42);
    std::cout << negate(42);
    // bc integer signed by default
}