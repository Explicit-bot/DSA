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

/*
1. INT_MAX & INT_MIN do not come from <iostream> or <bits/stdc++.h> on macOS/Clang.
They are actually defined inside: #include <climits>

2. INT_MAX and INT_MIN Bounds:
    INT_MAX =  2147483647   (ends with 7)
    INT_MIN = -2147483648   (ends with 8)
As int so INT_MAX/10 would be 2147483647 not 214748364.7.So,when rev is near the boundary (INT_MAX/10 or INT_MIN/10),adding certain last digits would exceed the integer range.
Correct Overflow Checks:       
       // Positive limit
       if (rev > INT_MAX/10 || (rev == INT_MAX/10 && lastdigit > 7))
           return 0;

       // Negative limit
       if (rev < INT_MIN/10 || (rev == INT_MIN/10 && lastdigit < -8))
           return 0;
These checks ensure:
- Multiplying rev by 10 is safe
- Adding lastdigit will not push it outside the 32-bit range
*/

