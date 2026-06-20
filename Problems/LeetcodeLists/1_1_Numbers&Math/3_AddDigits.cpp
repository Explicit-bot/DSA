#include<iostream>
#include<vector>
using namespace std;

//O(logn)
int AddDigitsBrute(int num){
    if(num<=9) return num;
    while(num>9){
        int tempsum{};
        while(num>0){
            tempsum+=num%10;
            num/=10;
        }
        num=tempsum;
    }
    return num;
}

//O(logn)
int digitsum(int nums){
    int sum{};

    while(nums>9){
        sum+=nums%10;
        nums/=10;
    }
    return sum;
}

int AddDigitsBetter(int nums){
    if(nums<=9){
        return nums;
    }
    return AddDigitsBetter(digitsum(nums));
}

//O(1)
int AddDigitsOptimal(int nums){
    if(nums==0){
        return 0;
    }
    
    return 1+(nums-1)%9;
}
int main(){
    int n{};
    cin>>n;

    cout<<AddDigitsBrute(n)<<" ";
    cout<<AddDigitsBetter(n)<<" ";
    cout<<AddDigitsOptimal(n)<<" ";
}

/*
ITERATIVE VS RECURSIVE
Iterative:
Time  : O(log n)
Space : O(1)

Recursive:
Time  : O(log n)
Space : O(log n) due to call stack
So your iterative version is actually more space-efficient.
*/
