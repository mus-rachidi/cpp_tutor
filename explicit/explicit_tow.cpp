#include <iostream>
class A {};
    
// Another simple class with a single-argument constructor for class A
class B
{
    public:
        B() {
            
            std::cout<< "default construction B call \n";
        }
       explicit B(A const & t) {
            
            std::cout<< " B(A const & t) call \n";

        }
};
    
// A function that expects a 'B'
void f(B const & t) 
{
    std::cout<< "function call \n";
}
    
int main()
{
    A obj1;
    f(B(obj1)); // Spot the deliberate mistake



    A obj;
    {
        B obj_arg0(obj); // A temporary for the lifetime of the call
        f(obj_arg0);
    }
}