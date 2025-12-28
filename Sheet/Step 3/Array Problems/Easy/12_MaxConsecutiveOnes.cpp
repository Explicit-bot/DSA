#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Better (O(N),O(N))
int findMaxConsecutiveOnesBrute(vector<int>& nums) {
    vector<int> cnt;
    int count{};
    for(auto x:nums){
        if(x==1){
            ++count;
        }
        else if(x!=1&&count!=0){
            cnt.push_back(count);
            count=0;
        }
    }
    if(count!=0){
        cnt.push_back(count);
    }
    if(cnt.size()>=1){
        return *max_element(cnt.begin(),cnt.end());
    }
    return 0;
}

//Optimal   (O(N),O(1))
int findMaxConsecutiveOnesOptimal(vector<int>& nums) {
        int maxi{};
        int cnt{};

        for(auto x:nums){
            if(x==1){
                ++cnt;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=0;
            }
        }

        return maxi;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<findMaxConsecutiveOnesBrute(nums)<<"\n";
    cout<<findMaxConsecutiveOnesOptimal(nums)<<"\n";
}
