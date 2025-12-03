#include <iostream>

int main(){

    int r{};
    int n{};

    std::cout<<"Enter your no."<<std::flush;
    std::cin>>n;

    while(n>0){
        r=n%10;
        n/=10;
        std::cout<<r<<"\n";
    }
}
