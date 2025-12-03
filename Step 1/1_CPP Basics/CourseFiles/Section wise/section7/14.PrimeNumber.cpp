#include <iostream>

int main(){

    int n{};
    int i{1};
    int factorcount{1};

    std::cout<<"Enter no.:"<<std::flush; 
    std::cin>>n;

    while(i<=n){
        if (n%i==0)
        {
            std::cout<<"Factor "<<factorcount<<" ="<<i<<"\n";     
            ++factorcount;
        }
        ++i;
    }
    if(factorcount==2){
        std::cout<<n<<" is a Prime number.\n";
    }
    else{
        std::cout<<n<<" is not a Prime number.\n";
    }

}
