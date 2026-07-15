#include<iostream>
using namespace std;

int numberOfSteps(int num) {
    int cnt{};
    while(num){
        if(num%2==0){
            num/=2;
        }
        else{
            --num;
        }
        ++cnt;
    }
    return cnt;
}

int numberOfStepsOptimal(int num){
    if (num == 0){
        return 0;
    }
    int setBits = __builtin_popcount(num);
    int bitLength = 32 - __builtin_clz(num);    //clz(0) UB.
    return setBits + bitLength - 1;
}
/*
Total operations= Number of divisions + Number of subtractions
                 = (Number of bits - 1) + (Number of set bits)
*/


int main(){
    int n{};
    cin>>n;

    cout<<numberOfSteps(n)<<"\n";
    cout<<numberOfStepsOptimal(n)<<"\n";    
}

