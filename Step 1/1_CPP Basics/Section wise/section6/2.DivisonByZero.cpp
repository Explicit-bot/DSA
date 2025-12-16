#include <iostream>

int main() {
    int a{};
    int b{};
    int c{};

    std::cout<<"Enter a and b for a/b"<<std::endl;
    std::cin>>a>>b;
    
    if(b==0){
        std::cout<<"Divison by zero "<<std::endl;
    }
    else{
        c=a/b;
        std::cout << "a/b="<<c << std::endl;
    }
    
    return 0;
}
