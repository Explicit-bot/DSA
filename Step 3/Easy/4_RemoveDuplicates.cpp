#include <iostream>
#include <set>
#include<vector>
using namespace std;

//Brute force (O(n+nlogn))
int removeDuplicates(vector<int >& nums){
    set<int>  st;
    for(auto x:nums){
        st.insert(x);
    }
    int i{};
    for(auto x:st){
        nums[i]=x;
        ++i;
    }
    return st.size();
}

//Optimal (O(n))
int RemoveDuplicates(vector<int>& nums){
    int i{};
    for(int j{1};j<nums.size();++j){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            ++i;
        }
    }
    return i+1;
}


int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    //int k=removeDuplicates(nums);
    int k=RemoveDuplicates(nums);

    cout<<"No. of Unique Elements:"<<k<<"\n";
    return 0;
}
