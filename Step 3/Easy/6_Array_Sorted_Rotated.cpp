#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsSorted(vector<int>& nums){
    for(int i{1};i<nums.size();++i){
        if(nums[i]<nums[i-1]){
            return false;
        }
    }
    return true;
}

//Brute force(O(n^2),O(n))
/*
Loop → n
Rotate → n
Check sorted → n
👉 n × (n + n) = n²
*/
bool check(vector<int>& nums){
    int n=nums.size();
    
    if(n<2) {
        return true;
    }

    vector<int> temp(nums.begin(),nums.end());
    for(int k{0};k<n;++k){
        rotate(temp.begin(),temp.begin()+1,temp.end());
        if(IsSorted(temp)){
            return true;
        }
    }
    return false;
}

//Using min element approach(O(n),O(1))
bool Check(vector<int>& nums){
    int n=nums.size();
    if(n<2){
        return true;
    }
    int minIndex{};
    for(int i{};i<n;++i){
        if(nums[i]<nums[minIndex]){
            minIndex=i;
        }
    }
    if(minIndex==0){
        return true;
    }

    //Left check
    for(int i{1};i<minIndex;++i){
        if(nums[i-1]>nums[i]){
            return false;
        }
    }
    //Right check
    for(int i=minIndex+1;i<n-1;++i){
        if(nums[i]>nums[i+1]){
            return false;
        }
    }
    //Boundary check
    if(minIndex>0 && nums[0]<nums[n-1]){
        return false;
    }

    return true;;
}

//Optimal   (O(n),O(1))
bool CHECK(vector<int>& nums) {
    int n=nums.size();

    if (n<2){
        return true;
    }

    int cnt{};
    for(int i{};i<n-1;++i){
        if(nums[i+1]<nums[i]){
            ++cnt;
        }
    }
    if(nums[0]<nums[n-1]){
        ++cnt;
    }

    if(cnt==0||cnt==1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<check(nums)<<"\n";
    cout<<Check(nums)<<"\n";
    //cout<<CHECK(nums)<<"\n";
    
}
