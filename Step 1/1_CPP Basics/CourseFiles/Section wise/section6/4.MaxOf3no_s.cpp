#include <iostream>

int main() {
    int x{};
    int y{};
    int z{};

    std::cout << "Enter 3 no.s:" << std::endl;
    std::cin>>x>>y>>z;

    if(x>y && x>z){
        std::cout << x << " is largest. "<< std::endl;
    }
    
    else{
        if(y>z){
            std::cout << y << " is largest. "<< std::endl;
        }
        else{
            std::cout << z << " is largest. "<< std::endl;
        }
         
    }
        return 0;
   
 }
    

