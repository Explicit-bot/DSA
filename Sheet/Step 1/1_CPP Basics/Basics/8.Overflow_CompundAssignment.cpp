/*
Overflow
When the value is more than the capacity it will take the values
again from the beginning this concept is called overflow
*/

#include <iostream>

int main() {
    //Overflow
    char y =-128;
    --y;
    std::cout << (int)y << std::endl; //-128 to 127

    char x =127;
    ++x;
    std::cout << (int)x << std::endl; //127 to -128
    
    //Compund Assignment
    int a{10};
    int b{20};
    int c{30};
    int sum{};
    
    sum += a+b+c;

    std::cout << "Sum is " << sum<< "." <<std::endl;

    return 0;
}
/*
so instead of doing sum=sum+a+b+c we can use sum+=a=b=c
Compound assignment
+=
-=
*=
/=
%=
sum+= a+b+c;
*/
