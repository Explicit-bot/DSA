#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//Maps 
vector<int> UniMap(vector<int>& nums,vector<int>& nums1){
    vector<int> temp{};
    map<int,int> mp;
    for(auto x:nums){
        mp[x]++;    //O(log(n)) for an element
    }
    for(auto x:nums1){
        mp[x]++;    //O(log(m)) for an element
    }
    for(auto x:mp){
        temp.push_back(x.first);
    }

    return temp;
}

//Sets
vector<int> UniSet(vector<int>& nums,vector<int>& nums1){
    set<int> st;
    vector<int> temp{};
    for(auto x:nums){
        st.insert(x);   //O(logn)
    }
    for(auto x:nums1){
        st.insert(x);   //O(logm)
    }

    for(auto x:st){
        temp.push_back(x);
    }

    return temp;
}

//Optimal(Two pointer)
vector<int> UniOpt(vector<int>& nums,vector<int>& nums1){
    int n{nums.size()};
    int n1{nums1.size()};
    vector<int> temp{};
    int i{};
    int j{};

    while(i<n && j<n1){
        if(nums[i]<nums1[j]){
            if(temp.empty()||temp.back()!=nums[i]){
                temp.push_back(nums[i]);
            }
            ++i;
        }
        else if(nums1[j]<nums[i]){
            if(temp.empty()||temp.back()!=nums1[j]){
                temp.push_back(nums[j]);
            }
            ++j;
        }
        else{
            if(temp.empty()||temp.back()!=nums[i]){
                temp.push_back(nums[i]);
            }
            ++i;
            ++j;
        }
    }
    
    while(i<n){
        if(temp.empty()||temp.back()!=nums[i]){
                temp.push_back(nums[i]);
        }
        ++i;
    }
    while(j<n1){
        if(temp.empty()||temp.back()!=nums[j]){
                temp.push_back(nums[j]);
        }
        ++j;
    }
    return temp;
}

int main(){
    int n1{},n2{};
    cin>>n1>>n2;
    
    vector<int> nums1(n1);
    for (auto& x : nums1){
        cin >> x;
    }

    vector<int> nums2(n2);
    for (auto& x : nums2){
        cin >> x;
    }

    vector<int> uni=UniMap(nums1,nums2);
    //vector<int> uni=UniSet(nums1,nums2);
    //vector<int> uni=UniOpt(nums1,nums2);
    for(auto x:uni){
        cout<<x<<" ";
    }
}
