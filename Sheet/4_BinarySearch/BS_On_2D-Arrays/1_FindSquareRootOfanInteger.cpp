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

int main(){
    int n{};
    cin>>n;
    
    cout<<findFloorSquareRootBrute(n);
}
