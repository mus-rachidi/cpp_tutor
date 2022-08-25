class A 
{
  public:
    explicit A(int) 
    { 
 
    };
};

class B 
{
  public:

     B(int) { 
      
    };
};

int main() 
{
  A y = (A)1;
  // A x = 1;
  B w(1);
  B* v = new B(1);
  B u = (B)1;
  B t = static_cast<B>(1);
}