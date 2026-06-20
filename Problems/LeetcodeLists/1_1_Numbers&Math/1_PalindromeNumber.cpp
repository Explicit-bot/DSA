#include <iostream>
#include <climits>
using namespace std;

bool ispal(int N){
    int revn{};
    int num{N};  //***
    while(N!=0){
        int ld=N%10;

        if(revn>(INT_MAX/10)||(revn==INT_MAX&&ld>7)){
            return 0;
        }
        if(revn<(INT_MIN/10)||(revn==INT_MIN&&ld<-8)){
            return 0;
        }

        revn=revn*10 + ld;
        N/=10;
    }
    if(num>=0){
        return revn==num;
    }
    else{
        return false;
    }
}


int main(){
    int N{};

    cout<<"Enter your no.";
    cin>>N;

    if(ispal(N)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
}

