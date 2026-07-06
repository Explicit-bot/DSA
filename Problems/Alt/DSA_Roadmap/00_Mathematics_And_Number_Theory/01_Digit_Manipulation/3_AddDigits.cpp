//258
#include<iostream>
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
    cout<<AddDigitsOptimal(n)<<" ";
}
