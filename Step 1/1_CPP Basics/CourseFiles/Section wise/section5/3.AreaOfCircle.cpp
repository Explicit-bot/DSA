
#include <iostream>

int main() {
    float r;
    float area;
    std::cout << "Enter radius" << std::endl;
    std::cin >> r;
    area=3.14f*r*r; 
    std::cout<<"Area is :"<< area;
    return 0;
}

/*
if you write 22/7 answer will be wrong as 22/7 gives 3 
so if you want to write 22/7 u have to use 
explicit type casting(You manually force the conversion using cast syntax)
like (float)22/7*r*r 
or
you can use 22.0/7  or  22/7.0  but it will give double data type 
*/
