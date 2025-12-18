/*
Overflow
When the value is more than the capacity it will take the values
again from the beginning this concept is called overflow
*/

#include <iostream>

int main() {
    
    char y =-128;
    --y;
    std::cout << (int)y << std::endl; //-128 to 127

    char x =127;
    ++x;
    std::cout << (int)x << std::endl; //127 to -128
    
    return 0;
}
