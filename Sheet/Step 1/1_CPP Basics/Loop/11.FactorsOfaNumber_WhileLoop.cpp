#include <iostream>

int main(){

    int n{};
    int i{1};
    int factorcount{1};

    std::cout<<"Enter no.:";
    std::cin>>n;

    while(i<=n){
        if (n%i==0)
        {
            std::cout<<"Factor "<<factorcount<<" ="<<i<<"\n";     
            ++factorcount;
        }
        ++i;
    }

}
