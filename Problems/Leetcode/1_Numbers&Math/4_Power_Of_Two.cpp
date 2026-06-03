#include<iostream>
using namespace std;

bool PowerOfTwoBrute(int num){
    if(num<=0){
        return false;
    }

    int power{1};
    while(power<num){
        power*=2;
    }
    
    return power==num;
}

bool PowerOfTwoBetter(int num){
    if(num<=0){
        return false;
    }
    while(num%2==0){
        num/=2;
    }
    return num==1;
}

//Bit manipulation
bool PowerOfTwoOptimal(int num){
    if(num<=0){
        return false;
    }

    return (num & (num-1))==0;
}

int main(){
    int n{};
    cin>>n;

    cout<<PowerOfTwoBrute(n)<<" ";
    cout<<PowerOfTwoBetter(n)<<" ";
    cout<<PowerOfTwoOptimal(n)<<" ";    

}
