#include <iostream>

int main(){
    int n{};
    int factorcount{1};

    std::cout<<"Enter no.:";
    std::cin>>n;

    for(int i{1};i<=n;++i)
    {
        if(n%i==0){
            std::cout<<"Factor "<<factorcount<<" ="<<i<<std::endl;
            ++factorcount;
        }
        
    }

}
