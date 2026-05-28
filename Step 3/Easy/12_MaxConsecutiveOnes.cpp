#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Better (O(N),O(N))
int findMaxConsecutiveOnesBrute(vector<int>& nums) {
    vector<int> ones{};
    int cnt{};
    for(auto x:nums){
        if(x==1){
            ++cnt;
        }
        else if(x!=1 && cnt!=0){
            ones.push_back(cnt);
            cnt=0;
        }
    }
    if(cnt!=0){
        ones.push_back(cnt);
    }
    if(!ones.empty()){
        return *max_element(ones.begin(),ones.end());
    }
    else{
        return 0;
    }
}

//Optimal   (O(N),O(1))
int findMaxConsecutiveOnesOptimal(vector<int>& nums) {
        int max1{};
        int cnt{};

        for(auto x:nums){
            if(x==1){
                ++cnt;
            }
            else if(x!=1&&cnt!=0){
                max1=max(max1,cnt);
                cnt=0;
            }
        }
        
        max1=max(max1,cnt);
        
        if(max1==0 && cnt ==0){
            return 0;
        }
        return max1;
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
