#include <iostream>

int main() {
    float v,u,a,distance;
    
    std::cout << "Enter intial velocity(u):";
    std::cin >>u;

    std::cout << "Enter final velocity(v):";
    std::cin >>v;

    std::cout << "Enter accelaration(a):";
    std::cin >>a;

    distance=(std::pow(v,2)-std::pow(u,2))/(2*a);

    std::cout<<"Distance is equal to" <<" "<<distance<<" ."<<std::endl;
    return 0;
}
//✅ Best Practice (Recommended)
//To ensure portability and clarity, always write: std::pow
