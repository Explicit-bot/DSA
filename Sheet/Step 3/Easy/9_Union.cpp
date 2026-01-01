#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
//Brute(Maps)   (O((n1 + n2) log(n1 + n2)),O(n1 + n2))
vector<int> UniMap(vector<int>& nums1,vector<int>& nums2){
    int n1=nums1.size();
    int n2=nums2.size();

    map<int,int> mp;
    vector<int> uni;

    for(int i{};i<n1;++i){
        mp[nums1[i]]++;
    }
    for(int i{};i<n2;++i){
        mp[nums2[i]]++;
    }

    for(auto x:mp){
        uni.push_back(x.first);
    }
    return uni;
}

//Brute(Sets)
vector<int> UniSet(vector<int>& nums1,vector<int>& nums2){
    int n1=nums1.size();
    int n2=nums2.size();

    set<int> st;
    vector<int> uni;

    for(auto x:nums1){
        st.insert(x);
    }
     for(auto x:nums2){
        st.insert(x);
    }

    for(auto x:st){
        uni.push_back(x);
    }
    return uni;
}

//Optimal(Two pointer) (O(n1+n2),O(n1+n2))
vector<int> UnionOptimal(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0;
    vector<int> uni;

    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] == nums2[j]){
            if(uni.empty() || uni.back() != nums1[i])
                uni.push_back(nums1[i]);
            i++; j++;
        }
        else if(nums1[i] < nums2[j]){
            if(uni.empty() || uni.back() != nums1[i])
                uni.push_back(nums1[i]);
            i++;
        }
        else{
            if(uni.empty() || uni.back() != nums2[j])
                uni.push_back(nums2[j]);
            j++;
        }
    }

    while(i < nums1.size()){
        if(uni.empty() || uni.back() != nums1[i])
            uni.push_back(nums1[i]);
        i++;
    }

    while(j < nums2.size()){
        if(uni.empty() || uni.back() != nums2[j])
            uni.push_back(nums2[j]);
        j++;
    }

    return uni;
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
    //vector<int> uni=UniOptimal(nums1,nums2);
    for(auto x:uni){
        cout<<x<<" ";
    }
}
