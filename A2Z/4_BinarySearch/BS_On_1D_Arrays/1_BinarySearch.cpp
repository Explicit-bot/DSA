//Array must be sorted.
#include<iostream>
#include<vector>
using namespace std;

int BinarySearchIterative(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]==k){
            return mid;
        }
        else if(nums[mid]>k){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int BinarySearchRecursive(vector<int>& nums,int k,int l,int h){
    if(l>h){
        return -1;
    }
    int mid=l+(h-l)/2;      //Overflow case is handled
    
    if(nums[mid]==k){
        return mid;
    }
    else if(nums[mid]>k){
        return BinarySearchRecursive(nums,k,l,mid-1);
    }

    return BinarySearchRecursive(nums,k,mid+1,h);
}

int main(){
    int n{};
    cin>>n;
    int k{};
    cin>>k;

    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    //int idxi=BinarySearchIterative(nums,k);
    int idxr=BinarySearchRecursive(nums,k,0,n-1);
    if(idxr!=-1){
        cout<<idxr;
    }
    else{
        cout<<"Element not found.";
    }
}

