//For this question reverse of 10400 will be 401 instead of 00401.
#include <iostream>
#include <climits>
using namespace std;

int revnum(int N){
    int revn{};

    while(N!=0){
        int ld=N%10;

        if(revn>(INT_MAX/10)||(revn==INT_MAX/10&&ld>7)){
            return 0;
        }
        if(revn<(INT_MIN/10)||(revn==INT_MIN/10&&ld<-8)){
            return 0;
        }
        revn=revn*10 + ld;
        N/=10;
    }

    return revn;
}

int main(){
    int N{};
    int rn{};
    cout<<"Enter your no.";
    cin>>N;

    rn=revnum(N);
    if(rn==0){
        cout<<"Out of limit or zero.";
    }
    else{
        cout<<rn;
    }

}

