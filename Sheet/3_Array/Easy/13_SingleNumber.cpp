#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Brute     (O(n*n),O(1))
int SingleBrute(vector <int>& nums){
    for(auto x:nums){
        int cnt{};
        for(auto y:nums){
            if(x==y){
                ++cnt;
            }
        }
        if(cnt==1){
            return x;
        }
    }
    return -1;
}

//Better    {O(N log N) + O(N)= O(N log N)}
int SingleBetter(vector<int>& nums){
    unordered_map<int,int> mp{};
    for(auto x:nums){
        ++mp[x];
    }
    for(auto x:mp){
        if(x.second==1){
            return x.first;
        }
    }
    return -1;
}

//Optimal   (O(N),O(1))
int SingleOptimal(vector<int>& nums){
    int xor1{};
    for(auto x:nums){
        xor1=xor1^x;
    }
    if(xor1!=0){
        return xor1;
    }
    else{
        return -1;
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<SingleBrute(nums)<<"\n";
    cout<<SingleBetter(nums)<<"\n";
    cout<<SingleOptimal(nums)<<"\n";
}
