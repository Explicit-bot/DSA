/*
💡 What is a Perfect Number?
A perfect number is a positive integer that is equal to the sum of all its proper divisors (excluding itself).
⸻
🔹 Definition:
A number n is perfect if:
sum of divisors of n (excluding n) = n
*/

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
    std::cout<<"Sum of Factors is "<<sum<<"\n";
    if(sum==n){
        std::cout<<n<<" is a perfect number."<<std::endl;
    }
    else{
        std::cout<<n<<" is not a perfect number."<<std::endl;
    }
    return 0;

}
