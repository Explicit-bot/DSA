#include <iostream>

int main(){

    int n{};
    int i{1};
    int factorcount{1};
    int sum{};

    std::cout<<"Enter no.:";
    std::cin>>n;

    while(i<n){
        if (n%i==0)
        {
            sum+=i;
            std::cout<<"Factor "<<factorcount<<" ="<<i<<std::endl;   
            ++factorcount;
        }
        ++i;
    }
    std::cout<<"Sum of Proper Factors(excluding the no.) is "<<sum<<"\n";

    return 0;

}
