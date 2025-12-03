//print reverse no. and check if it is a palindrome
#include <iostream>

int main(){

    int r{};
    int n{};
    int rev{};

    std::cout<<"Enter your no."<<std::flush;
    std::cin>>n;

    int temp{n};
    while(temp>0){
        r=temp%10;
        temp=temp/10;
        rev=rev*10 + r;
        
    }
    std::cout<<"Reverse of "<< n<<" is "<<rev<<".\n";
    if(rev==n){
        std::cout<<"Entered number is a palindrome.\n";
    }
    else{
        std::cout<<"Entered number is not a palindrome.\n";
    }
}
