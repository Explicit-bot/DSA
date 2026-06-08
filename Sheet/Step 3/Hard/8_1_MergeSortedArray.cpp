//Size of first array is m+n with m useful elements rest zero
#include<iostream>
#include<vector>
using namespace std;

void MergeSortedArrayBrute(vector<int>& nums1,int m,vector<int>& nums2,int n){
    for(int i{};i<n;++i){
        nums1[i+m]=nums2[i];
    }
    sort(nums1.begin(),nums1.end());
}

void MergeSortedArrayOptimal(vector<int>& nums1,int m,vector<int>& nums2,int n){
    int i{m-1};
    int j{n-1};
    int k{n+m-1};
    while(i>=0 && j>=0){
        if(nums2[j]>nums1[i]){
            nums1[k]=nums2[j];
            --j;
        }
        else{
            nums1[k]=nums1[i];
            --i;
        }
        --k;
    }
    while(j>=0){
        nums1[k]=nums2[j];
        --k;
    }
}

int main(){
    int m{};
    int n{};
    cin>>m>>n;

    vector<int> nums1(m+n,0);
    for(int i{};i<m;++i){
        cin>>nums1[i];
    }

    vector<int> nums2(n,0);
    for(int i{};i<n;++i){
        cin>>nums2[i];
    }

    //MergeSortedArrayBrute(nums1,m,nums2,n);
    MergeSortedArrayOptimal(nums1,m,nums2,n);

    for(auto x:nums1){
        cout<<x<<"\n";
    }
}
