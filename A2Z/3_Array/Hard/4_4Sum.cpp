#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int>> FourSumBrute(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> st;
    for(int i{};i<n-3;++i){
        for(int j{i+1};j<n-2;++j){
            for(int k{j+1};k<n-1;++k){
                for(int l{k+1};l<n;++l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==0){
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(),st.end());
}

vector<vector<int>> FourSumBetter(vector<int>& nums){
    int n=nums.size();
    set<vector<int>> ans;
    for(int i{};i<n-2;++i){
        for(int j{i+1};j<n-1;++j){
            set<int> hashset;
            for(int k{j+1};k<n;++k){
                long long rem=-(1LL*nums[i]+nums[j]+nums[k]);
                //The 1LL* forces entire expression into long long.
                if(hashset.find(rem)!=hashset.end()){
                    vector<int> temp={nums[i],nums[j],nums[k],(int)rem};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>> (ans.begin(),ans.end());
}

vector<vector<int>> FourSumOptimal(vector<int>& nums){
    int n=nums.size();
    vector<vector<int>> ans{};
    sort(nums.begin(),nums.end());
    for(int i{};i<n-3;++i){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }

        for(int j{i+1};j<n-2;++j){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int k{j+1};
            int l{n-1};
            while(k<l){
                long long sum=1ll*nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    ++k;
                    --l;

                    while(k<l && nums[k]==nums[k-1]){
                        ++k;
                    }
                    while(k<l && nums[l]==nums[l+1]){
                        --l;
                    }
                }
                else if(sum<0){
                    ++k;
                }
                else{
                    --l;
                }
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

    vector<vector<int>> ansBr=FourSumBrute(nums);
    cout<<"Answer Brute:"<<"\n";
    for(auto x:ansBr){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    vector<vector<int>> ansBe=FourSumBetter(nums);
    cout<<"Answer Better:"<<"\n";
    for(auto x:ansBe){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    vector<vector<int>> ansOp=FourSumOptimal(nums);
    cout<<"Answer Optimal:"<<"\n";
    for(auto x:ansOp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
}
