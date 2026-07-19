#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& nums, int l, int mid, int h){   //Pass by reference not by value
    int left{l};
    int right{mid+1};
    vector<int> ans;

    while(left<=mid && right<=h){
        if(nums[left]<=nums[right]){
            ans.push_back(nums[left]);
            ++left;
        }
        else{
            ans.push_back(nums[right]);
            ++right;
        }
    }

    while(left<=mid){
        ans.push_back(nums[left]);
        ++left;
    }
    while(right<=h){
        ans.push_back(nums[right]);
        ++right;
    }

    for(int i{l};i<=h;++i){
        nums[i]=ans[i-l];
    }
}

void MergeSort(vector<int>& nums ,int l,int h){
    if(l>=h) return;
    
    
    int mid=(l+h)/2;

    MergeSort(nums,l,mid);
    MergeSort(nums,mid+1,h);
    Merge(nums,l,mid,h);
}
int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements:";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Original array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    MergeSort(nums,0,n-1);
   

    cout << "Sorted array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;

}

