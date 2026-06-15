#include<iostream>
#include<vector>
using namespace std;

int findFloorSquareRootBrute(int n){
    int ans{};
    
    for(int i{1};i<=n;++i){
        if(i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

int findFloorSquareRootOptimal(int n){
    if(n==0||n==1){
        return n;
    }
    int l{2};
    int h{n/2};
    int ans{1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(mid*mid<=n){
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
    
    cout<<findFloorSquareRootBrute(n)<<"\n";
    cout<<findFloorSquareRootOptimal(n)<<"\n";
}
