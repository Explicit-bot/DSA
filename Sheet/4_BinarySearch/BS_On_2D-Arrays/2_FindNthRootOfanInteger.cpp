#include<iostream>
#include<vector>
using namespace std;

long long Power(long long a, long long b, long long limit) {
    long long ans{1};
    while(b > 0){
        // if current bit is set
        if(b & 1){
            // overflow / limit check
            if(ans > limit / a){
                return limit + 1;
            }
            ans *= a;
        }
        b >>= 1;
        if(b){
            // overflow / limit check
            if(a > limit / a){
                return limit + 1;
            }
            a *= a;
        }
    }
    return ans;
}

int findFloorSquareRootBrute(int n,int m){
    int ans{};
    for(int i{1};i<=n;++i){
        if(Power(i,m,n)<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

int findFloorSquareRootOptimal(int n,int m){
    if(n==0||n==1){
        return n;
    }
    int l{1};
    int h{n};
    int ans{1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(Power(mid,m,n)<=n){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;
    int m{};
    cin>>m;
    
    cout<<findFloorSquareRootBrute(n,m)<<"\n";
    cout<<findFloorSquareRootOptimal(n,m)<<"\n";
}
