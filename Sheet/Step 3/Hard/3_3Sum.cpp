#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> ThreeSumBrute(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> st;
    vector<vector<int>> ans{};
    for(int i{};i<n-2;++i){
        for(int j{i+1};j<n-1;++j){
            for(int k{j+1};k<n;++k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
     ans.assign(st.begin(),st.end());
     return ans;
}

vector<vector<int>> ThreeSumBetter(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> ans;
    for(int i{};i<n;++i){
        set<int> hashset;
        for(int j{i+1};j<n;++j){
            int rem=-(nums[i]+nums[j]);
            if(hashset.find(rem)!=hashset.end()){
                vector<int> temp={nums[i],nums[j],rem};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>> (ans.begin(),ans.end());
}

vector<vector<int>> ThreeSumOptimal(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> ans{};
    sort(nums.begin(),nums.end());
    for(int i{};i<n;++i){
        if(i>0 && (nums[i]==nums[i-1])){
            continue;
        }
        int j{i+1};
        int k{n-1};
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                ans.push_back({nums[i],nums[j],nums[k]});
                ++j;
                --k;
                while(j<k && nums[j]==nums[j-1])++j;
                while(j<k && nums[k]==nums[k+1])--k;                
            }
            else if(sum<0){
                ++j;
            }
            else{
                --k;
            }
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }
    cout<<"Input Array:";
    for(auto x:nums){
        cout<<x<<" ";
    }

    cout<<"\n";

    vector<vector<int>> ansBr=ThreeSumBrute(nums);
    cout<<"Answer Brute:"<<"\n";
    for(auto x:ansBr){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    vector<vector<int>> ansBe=ThreeSumBetter(nums);
    cout<<"Answer Better:"<<"\n";
    for(auto x:ansBe){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    vector<vector<int>> ansOp=ThreeSumOptimal(nums);
    cout<<"Answer Optimal:"<<"\n";
    for(auto x:ansOp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}
