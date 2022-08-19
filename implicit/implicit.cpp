class Y 
{
  int a, b; 
  char* name;
  public:
    Y(int i) { 

    };
    Y(const char* n, int j = 0) { 

    };
};

void add(Y) {

};

int main() 
{

  // equivalent to
  Y obj1 = Y(2);
  Y obj11 = 2;

  // equivalent to
  Y obj2 = Y("somestring",0);
  // Y obj2 = "somestring";

  // equivalent to
  // obj1 = Y(10)
  obj1 = 10;

  // equivalent to
  add(Y(5));
  // add(5);
}