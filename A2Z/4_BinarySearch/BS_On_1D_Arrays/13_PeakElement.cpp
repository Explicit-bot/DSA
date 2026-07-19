#include<iostream>
#include<vector>
using namespace std;

int peakElementOptimal(vector<int>& arr){
    int n=arr.size();
    
    if(n==1){
        return 0;
    }

    if(arr[0]>arr[1]){
        return 0;
    }
    if(arr[n-1]>arr[n-2]){
        return n-1;
    }

    int l{1};
    int h{n-2};

    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }

        if(arr[mid]<arr[mid+1]){
            l=mid+1;
        }
        else {
            h=mid-1;
        }
    }
    return 0;
}

int main(){
    int n{};
    cin>>n;
    
    vector<int> nums(n,0);
    for(auto& x:nums){
        cin>>x;
    }

    cout<<peakElementOptimal(nums);
}
