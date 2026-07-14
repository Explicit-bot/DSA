// 1945
#include <iostream>
#include <string>
using namespace std;

int getLucky(string s, int k){
    int sum{};
    
    for(auto& x:s){
        int val=x-'a'+1;
        
        if(val>=10){
            sum+=val%10;
            sum+=val/10;
        }
        else{
            sum+=val;
        }
    }
    
    while(--k){
        int newsum{};
        while(sum){
            newsum+=sum%10;
            sum/=10;
        }
        sum=newsum;
    }
    return sum;
}
