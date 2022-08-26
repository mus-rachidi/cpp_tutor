#include <iostream>

class const_refer
{
    private:
        /* data */
    public:
        const_refer(/* args */);
        ~const_refer();
};

const_refer::const_refer(/* args */)
{
    std::cout << "hey";
}

const_refer::~const_refer()
{
}
int main()
{
    
}