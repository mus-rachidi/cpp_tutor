// constructing vectors
#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> first ;                          
    std::vector<int> second (4,100);                   
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + 4 );
    std::vector<int> third (fifth.rbegin(),fifth.rend());
    std::vector<int> third2 (third.begin(),third.end());

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = third2.begin(); it != third2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';



  return 0;
}