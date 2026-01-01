#include <iostream>
#include <vector>
#include <map>
using namespace std;

//Brute     (O(n*n),O(1))
int SingleBrute(vector <int>& nums){
    int n=nums.size();
    for(int i {};i<n;++i){
        int num=nums[i];
        int cnt{};

        for(int j{};j<n;++j){
            if(nums[i]==nums[j]){
                ++cnt;
            }
        }
        if(cnt==1){
            return num;
        }
    }
    return -1;
}

//Better    {O(N log N) + O(N)= O(N log N)}
int SingleBetter(vector<int>& nums){
    int n=nums.size();
    map<int,int> mp;
    for (auto x:nums){
        ++mp[x];    //logk
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
    return xor1;
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
