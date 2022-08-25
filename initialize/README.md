


There are various ways to initialize a variable, in C++.
The following declarations all may have a local variable initialized to its default value:

         T1 var1;
         T2 var2 = 0;
         T3 var3 = {};
         T4 var4 = T4();


      1) T a1;
      
         -  It correctly initializes the variable when it's an instance of a class.
         -  indeterminate when its type is an arithmetic type, like int, float, or char. 

      
      2) T   a3 = 0;

         -  An arithmetic variable is of course
            initialized properly by the second declaration.
         -  But this initialization form usually won't work for a class type.

      4) T   a2 = {}; c++11

         -  initializes an aggregate, typically a "C-style" struct or a "C-style" array
         -  However, the syntax is not allowed for a class that has an explicitly declared constructor.
         
      3) T   a4 = T();
         -  is the most generic form
         -  it can be used to initialize arithmetic types, class types, aggregates, pointers, and other types
            -> First a temporary object (v-object) is created, by T()
            -> Next the temporary object is copied to the named variable
            -> the temporary is destroyed
