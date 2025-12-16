#include <iostream>

int main(){
    int n{};
    std::cout<<"Enter the no. whose multiplication table u want to print:";
    std::cin>>n;



    for(int i{};i<=10;++i)
    {
        std::cout<<n<<" * "<<i<<" = "<< n*i << std::endl;   
    }
   
    return 0;
}




