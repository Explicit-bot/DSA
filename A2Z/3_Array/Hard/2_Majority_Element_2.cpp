#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

vector<int> MajorityElementBrute(vector<int>& nums){
    int n=nums.size();
    vector<int> ans{};

    for(int i{};i<n;++i){
        if(ans.size()==0 || ans[0]!=nums[i]){
            int cnt{0};
            for(int j{};j<n;++j){
                if(nums[j]==nums[i]){
                ++cnt;
                }
            }
            if(cnt>(n/3)){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2){
                return ans;
            }
        }
    }
    return ans;
}

//Assuming no collisons
void MajorityElementBetter(vector<int>& nums){
    int n=nums.size();
    unordered_map<int,int> mp{};
    int cnt{};
    for(int i{};i<n;++i){
        ++mp[nums[i]];

        if((mp[nums[i]])==(((n/3)+1))){
            cout<<nums[i]<<" ";
            ++cnt;
        }
        if(cnt==2){
            return;
        }
    }
}


void MajorityElementOptimal(vector<int>& nums){
    int n=nums.size();
    int cnt1{}; int cnt2{};
    int curelm1{INT_MIN};   int curelm2{INT_MIN};
    for(int i{};i<n;++i){
        if(cnt1==0 && curelm2!=nums[i]){    //*Why currelm1
            cnt1=1;
            curelm1=nums[i];
        }
        else if(cnt2==0 && curelm1!=nums[i]){   //*Why currelm1
            cnt2=1;
            curelm2=nums[i];
        }
        else if(curelm1==nums[i]){
            ++cnt1;
        }
        else if(curelm2==nums[i]){
            ++cnt2;
        }
        else{
            --cnt1; --cnt2;
        }
    }

    cnt1=0;     cnt1=0;
    for(int i{};i<n;++i){
        if(nums[i]==curelm1){
            ++cnt1;
        }
        else if(nums[i]==curelm2){
            ++cnt2;
        }
    }

    if(cnt1>(n/3)){
        cout<<curelm1<<" ";
    }
    if(cnt2>(n/3)){
        cout<<curelm2<<" ";
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    cout<<"\n";

    vector<int> ansBr=MajorityElementBrute(nums);
    for(auto x:ansBr){
        cout<<x<<" ";
    }

    cout<<"\n";

    MajorityElementBetter(nums);
    
    cout<<"\n";

    MajorityElementOptimal(nums);
}

/*
Core Intuition
The algorithm performs “group cancellation.”
Whenever we see 3 DIFFERENT elements:
A B C
we can safely remove them together.

Why?
Because none of them can dominate the others in that group.
This is the heart of the proof.

Why Triple Cancellation Works
Suppose:
x occurs > n/3 times

Even if we repeatedly remove triples of distinct elements:
x, y, z

the true majority element cannot disappear completely.

Because:
every cancellation removes at most ONE copy of x
but removes TWO non-x elements too
So x loses slower than the rest.

Eventually:
majority elements survive
minority elements die

This is the deep invariant.
*/
