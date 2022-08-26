// constructing vectors

#include <iostream>
#include <vector>

void constructor()
{
  std::vector<int> v0;        

  std::vector<int> v1(15);        

  std::vector<int> v2 (4, 100);               
  
  int myints[] = {16,2,77,29};
  
  std::vector<int> v3 (myints, myints + 4 );
  
  std::vector<int> v4 (v3.rbegin(),v3.rend());
  
  std::vector<int> v5 (v4.begin(),v4.end());

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

int main ()
{ 

  constructor();

  
  // const int& val = int();
  // int val1;
  // std::cout << "val = " << val << std::endl;
  // std::cout << "val1 = " << val1;
  return 0;
}