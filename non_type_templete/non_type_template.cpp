                        /*  Non-Type and Type Template Parameters */


/* 

    -   Non-Type Template Parameters
        A non-type template argument provided within a template argument list
        is an expression whose value can be determined at compile time.

    -   Non-type template arguments are normally used to initialize a class or to   
        specify the sizes of class members.

*/

template<class T, int size> 
class Myfilebuf
{
        T* filepos;
        static int array[size];
    public:
        Myfilebuf() { /* ... */ }
        ~Myfilebuf();
};

// A class template does not need to have a type argument if it has non-type arguments

template<int i> 
class C
{
      public:
            int k;
            C() 
            { 
                k = i; 
            }
};

int main()
{
    Myfilebuf<double,200> x1;
    Myfilebuf<double,10*20> x2;
    Myfilebuf<double, (75>25)> x3;          // valid
   // Myfilebuf<double, 75>25> x4;            // error
    Myfilebuf<double,200> x;                // create object x of class
                                            // Myfilebuf<double,200>
    //Myfilebuf<double, 200.0> y;              // error, 200.0 is a double,
                                            // not an int
   // Myfilebuf<double> z;
    C<100> a;
    C<200> b;
}


template<class T> void f() { };
template<int i> void f() { };

int main() {
  f<int()>();
}
