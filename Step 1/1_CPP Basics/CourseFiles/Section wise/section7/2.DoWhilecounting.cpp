
#include <iostream>

int main(){
    int n{};
    int i{1};
    std::cout<<"Enter value of n: ";
    std::cin>>n;
    do
    {
        std::cout<<i<<std::endl;
        ++i;            //++i is faster than i++
    }while (i<=n);      //; is required
    return 0;
}
