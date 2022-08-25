#include <iostream>

int global;    //zero-initialization, then default-initialization
void foo() 
{
    int i;            //default-initialization

    
    int k = int();    //value-initialization



    int m();          //function-declaration
    new int;          //default-initialization
    new int();        //value-initialization
}

//t is value-initialized
struct A 
{ 
    int t; 
    A() : t() 
    {

    } 
};

//t is default-initialized
struct C 
{
    int t; 
    C()       
    {

    } 
};