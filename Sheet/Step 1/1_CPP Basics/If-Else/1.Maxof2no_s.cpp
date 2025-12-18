#include <iostream>

int main() {
    int x{};
    int y{};

    std::cout << "Enter 2 no.s:" << std::endl;
    std::cin>>x>>y;

    if(x>y){
        std::cout << x << " is larger than " <<y << std::endl;
    }
    
    else{
         std::cout << y << " is larger than or equal to " <<x << std::endl;
    }
        return 0;
   
 }
    

