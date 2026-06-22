//For this question reverse of 0140 will be 41 instead of 0410 and -ve numbers can't be palindromes
#include <iostream>
#include <climits>
using namespace std;

int revnum(int N){
    int revn{};

    while(N!=0){
        int ld=N%10;

        if(revn>(INT_MAX/10)||(revn==INT_MAX/10 &&ld>7)){
            return 0;
        }
        if(revn<(INT_MIN/10)||(revn==INT_MIN/10 &&ld<-8)){
            return 0;
        }
        revn=revn*10 + ld;
        N/=10;
    }
    return revn;
}

bool ispal(int N){
    if(N<0){
        return false;
    }
    return N==revnum(N);    
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

