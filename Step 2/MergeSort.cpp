#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums,int l,int mid,int h){          //Pass by reference not by value
    vector<int> temp;
    int left=l;
    int right=mid+1;
    
    while(left<=mid&&right<=h){
        if(nums[left]<nums[right]){
            temp.push_back(nums[left]);
            ++left;
        }
        else{
            temp.push_back(nums[right]);
            ++right;
        }
    }

    while(left<=mid){
        temp.push_back(nums[left]);
        ++left;
    }

    while(right<=h){
        temp.push_back(nums[right]);
        ++right;
    }

    for (int i = l; i <= h; i++) {
        nums[i] = temp[i - l];
    }
}

void mergesort(vector<int>& nums,int l,int h){
    if(l>=h){
        return;
    }

    int mid=(l+h)/2;
    mergesort(nums,l,mid);
    mergesort(nums,mid+1,h);
    if(nums[mid]<nums[mid+1]){
        return;
    }
    merge(nums,l,mid,h);
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

    mergesort(nums,0,n-1);
   

    cout << "Sorted array:\n";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;

}
