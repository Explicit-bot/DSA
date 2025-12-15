#include <iostream>

int main() {
    int a=5,b=5,e=5,f=10,c,d,g,i=4;

    // pre Increment
    std::cout << "Pre Increment" << std::endl;
    c=++a;
    std::cout << a << std::endl;
    std::cout << c << std::endl;

    std::cout << "Post Increment" << std::endl;
    d=b++;
    
    std::cout << b << std::endl;
    std::cout << d << std::endl;

    std::cout << "Post Increment another example" << std::endl;
    g= e++ * f;  //First multiply(e*f) then increment e.

    std::cout << g << std::endl;
    std::cout << e << std::endl;

    //these all mean the same thing
    //i = i + 1;   ->  i +=1 ;   ->   i++;
    std::cout << "Value of i increased" << std::endl;    
    ++i; //alway use ++i for these type statements it is fast 
    std::cout<<i<<std::endl;
    return 0;
}

/*
Increment and Decrement Operator
• Increment and Decrement are of two types I.e pre increment,
post increment and pre decrement ,post decrement

Example :
Pre inc : ++x ;               
Post inc : x++;              
Pre dec : ++x ;                     
Post dec : x++;     
  
• This is used mostly in loops
  int x = 5,y;

  pre increment
  y=++x;  -> y=6
             x=6

  post increment
  y=x++;  -> y=5
             x=6

j=2* ++i + 2* i++   
In C++, these kind of lines causes undefined behavior.
  the compiler is free to do anything:
	  •	It might do ++i first
	  •	Or i++ first
	  •	Or reuse i in an intermediate form
	  •	Or optimize in strange ways


What should be used in for loop i++ or ++i ?
Anyone can be used.
++i; is known to be faster than i++;.
Reason:
i++; is same as i=i+1; here i+1 is evaluated and the result is
stored in a temporary variable and then assigned to i.

++i; here i+1 is not stored in a temporary variable, directly i is
increased by 1 
*/
