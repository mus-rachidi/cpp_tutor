#include <iostream>
#include <map>
using namespace std;
 
int main ()
{
    map<int, string> MyMap;
    map<int, string>::iterator it;

    MyMap[101] = "John";
    MyMap[102] = "Marry";
    MyMap[103] = "Kim";
    MyMap[104] = "Jo";
    MyMap[105] = "Ramesh";

    //creating a value_comp object
    map<int, string>::value_compare MyComp = MyMap.value_comp();

    //printing the content of the map using value_comp object
    it = MyMap.begin();
    cout<<"MyMap contains:\n ";
    do {
        cout<<it->first<<"  "<<it->second<<"\n ";
    } while(MyComp(*it++, *MyMap.rbegin()));

    return 0;
}