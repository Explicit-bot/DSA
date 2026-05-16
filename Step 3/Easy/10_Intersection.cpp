#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

//Brute (Map)   (O((n1 + n2) log n1), O(n1))
vector<int> IntersectMap(vector<int>& nums1, vector<int>& nums2){
    map<int,int> mp;
    vector<int> inter;

    // store frequency of nums1
    for(auto x : nums1){
        mp[x]++;
    }

    // check nums2
    for(auto x : nums2){
        if(mp[x] > 0){
            inter.push_back(x);
            mp[x] = 0;   // avoid duplicates in result
        }
    }

    return inter;
}


//Brute (Set)   (O((n1 + n2) log n1), O(n1))
vector<int> IntersectSet(vector<int>& nums1, vector<int>& nums2){
    set<int> st;
    vector<int> inter;

    for(auto x : nums1){
        st.insert(x);
    }

    for(auto x : nums2){
        if(st.find(x) != st.end()){
            inter.push_back(x);
            st.erase(x);   // avoid duplicates
        }
    }

    return inter;
}


//Optimal (Two Pointer)   (O(n1 + n2), O(n1 + n2))
vector<int> IntersectOptimal(vector<int>& nums1, vector<int>& nums2){
    int i = 0, j = 0;
    vector<int> inter;

    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] == nums2[j]){
            if(inter.empty() || inter.back() != nums1[i])
                inter.push_back(nums1[i]);
            i++; j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return inter;
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

    vector<int> inter = IntersectMap(nums1, nums2);
    // vector<int> inter = IntersectSet(nums1, nums2);
    // vector<int> inter = IntersectOptimal(nums1, nums2);

    for(auto x:inter){
        cout<<x<<" ";
    }
}
