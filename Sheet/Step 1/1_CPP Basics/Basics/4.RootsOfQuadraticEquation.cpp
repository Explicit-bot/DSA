#include <iostream>
#include <cmath> 


 int main() {
    float a, b, c, root1, root2;
    
    std::cout << "Enter the coefficients respectively"<<std::endl;
    std::cin>>a>>b>>c;

    root1=(-b+std::sqrt(std::pow(b,2)-4*a*c))/(2*a);
    root2=(-b-std::sqrt(std::pow(b,2)-4*a*c))/(2*a);
    
    std::cout<<"Roots are "<<root1<<" and "<<root2<<"."<<std::endl;
    return 0;
}

//NaN stands for “Not a Number” 
//so if you get nan it maybe because roots are complex

/*
✅ Always use #include <cmath> in C++.
Unless you’re writing C code or interfacing with C libraries, avoid math.h.
*/
