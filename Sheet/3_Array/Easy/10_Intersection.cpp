#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//Map
vector <int> InterMap(vector<int> nums1,vector<int> nums2){
    int n1{nums1.size()};
    int n1{nums2.size()};
    vector<int> temp{};
    map<int,int> mp;
    for(auto x:nums1){
        mp[x]++;
    }
    for(auto x:nums2){
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second>2){
            temp.push_back(x.first);
        }
    }
    return temp;
}

//Set
vector<int> InterSet(vector<int> nums1,vector<int> nums2){
    vector<int> temp{};
    set<int> st{};

    for(auto x:nums1){
        st.insert(x);
    }
    for(auto x:nums2){
        if(st.find(x)!=st.end()){
            temp.push_back(x);
            st.erase(x);
        }
    }
    return temp;
}

//Two pointer
vector<int> InterOpt(vector<int> nums1,vector<int> nums2){
    int n1{nums1.size()};
    int n2{nums2.size()};
    int i{};
    int j{};
    vector<int> temp{};

    while(i<n1 && j<n2){
        if(nums1[i]==nums2[j]){
            if(temp.empty()||temp.back()!=nums1[i]){
                temp.push_back(nums1[i]);
            }
            ++i;
            ++j;
        }
        else if(nums1[i]<nums2[j]){
            ++i;
        }
        else{
            ++j;
        }
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

    vector<int> inter = InterMap(nums1, nums2);
    // vector<int> inter = InterSet(nums1, nums2);
    // vector<int> inter = InterOpt(nums1, nums2);

    for(auto x:inter){
        cout<<x<<" ";
    }
}
