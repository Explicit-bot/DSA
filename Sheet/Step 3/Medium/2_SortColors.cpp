#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//brute would be like to just sort the algo 

void SortColorsBetter(vector<int>& nums){
    int cnt0{},cnt1{},cnt2{};

    for(auto x:nums){       //O(N)
        if(x==0)++cnt0;
        else if(x==1)++cnt1;
        else ++cnt2;
    }
    for(int i{};i<cnt0;++i){    //O(cnt0)
        nums[i]=0;
    }
    for(int i{cnt0};i<cnt0+cnt1;++i){   //O(cnt1)
        nums[i]=1;
    }
    for(int i{cnt0+cnt1};i<cnt0+cnt1+cnt2;++i){     //O(cnt2)
        nums[i]=2;
    }
}

//Dutch National Flag algorithm
void SortColorOptimal(vector<int>& nums ){
    int n=nums.size();
    int low{};
    int high{n-1};
    int mid{};

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            ++low;
            ++mid;
        }
        else if(nums[mid]==1){
            ++mid;
        }
        else{
            swap(nums[mid],nums[high]);
            --high;       
        }
    }
}

int main(){
    int n{};
    cin>>n;
    int temp{};
    vector<int> nums{};
    for(int i{};i<n;++i){
        cin>>temp;
        nums.push_back(temp);
    }

    //SortColorsBetter(nums);
    SortColorOptimal(nums);
    for(auto x:nums){
        cout<<x<<"\n";
    }
}
