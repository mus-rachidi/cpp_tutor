
// https://eli.thegreenplace.net/2012/02/06/dependent-name-lookup-for-c-templates


/*
    1) Dependent : names that depend on the template parameters but aren't declared within the template.
    2) Non-dependent : names that don't depend on the template parameters, plus the name of the template itself and names declared within it.
    Example => 
        the name f does not depend on template parameter T, so f is known as a non-dependent name.
        B<T> is dependent on template parameter T so B<T> is called a dependent name.
*/
#include <iostream>

template <typename T> 
struct Base 
{
   void f() 
   {
       std::cerr << "Base<T>::f\n";
   }
};

template <typename T> 
struct Derived : Base<T> 
/*  Here's the rule: the compiler does not look in dependent base classes (like B<T>)
    when looking up nondependent names (like f). */

{
   void g() 
   {
       std::cerr << "Derived<T>::g\n  ";
         Base<T>::f();
            // this->f();//this is always implicitly dependent in a template
    //      f();// compiler can't understand that the call f depends on the template parameter T
   }
};


/* this rule lookup changes for types  */
 template <typename T> 
 struct Base1
{
   typedef int MyType;
};

template <typename T> 
struct Derived1 : Base1<T> 
{
   void g() 
   {
       // A. error: ‘MyType’ was not declared in this scope
       // MyType k = 2;

       // B. error: need ‘typename’ before ‘Base<T>::MyType’ because
       // ‘Base<T>’ is a dependent scope
       // Base<T>::MyType k = 2;

       // C. works!
       typename Base1<T>::MyType k = 2;

       std::cerr << "Derived<T>::g --> " << k << "\n";
   }
};

int main()
{
    Derived<float> df;
    df.g();

    Derived1<int> di;
    di.g();
}