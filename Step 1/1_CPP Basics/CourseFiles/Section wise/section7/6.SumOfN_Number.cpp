#include<iostream>

int main(){
    int n{};
    int sum{};
    std::cout<<"Enter no. till where sum is req.:";
    std::cin>>n;
   
    for( int i{};i<=n;++i)  
    {
        sum+=i;
    }
    std::cout<< "sum of first "<<n<<" natural numbers is "<<sum<<std::endl;

    return 0;
}
