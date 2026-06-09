#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> RearrBySignBrute(vector<int>& nums){
    int n=nums.size();
    vector<int> pos{};
    vector<int> neg{};
    vector<int> total(n,0);
    for(auto x:nums){
        if(x<0){
            neg.push_back(x);
        }
        else if(x>0){
            pos.push_back(x);
        }
    }
    for(int i{};i<n/2;++i){
        total[2*i]=pos[i];
        total[2*i+1]=neg[i];
    }
    return total;
}

vector<int> RearrBySignOptimal(vector<int>& nums){
    int n=nums.size();
    vector<int> total(n,0);
    int pidx{};
    int nidx{1};
    for(int i{};i<n;++i){
        if(nums[i]>=0){
            total[pidx]=nums[i];
            pidx+=2;
        }
        else{
            total[nidx]=nums[i];
            nidx+=2;
        }
    }
    return total;
}


//What if the number of positives and negatives are different
