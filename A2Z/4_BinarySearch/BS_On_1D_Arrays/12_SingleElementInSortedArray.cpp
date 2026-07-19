#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicateBrute1(vector<int>& arr) {
    int n = arr.size();

    if (n==1){
        return arr[0];
    }

    for(int i{};i<n;++i){
        if(i==0){
            if (arr[i] != arr[i + 1]){
               return arr[i];
            }
        }
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1]){
                return arr[i];
            }
        }
        else{
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1]){
                return arr[i];
            }
        }
    }
    return -1;
}

int singleNonDuplicateBrute2(vector<int>& arr) {
    int n = arr.size();
    int ans{};

    for (int i{}; i<n;++i){
        ans = ans^arr[i];
    }

    return ans;
}

int singleNonDuplicateOptimal(vector<int>& arr){
    int n=arr.size();
    
    if(n==1){
        return arr[0];
    }

    if(arr[0]!=arr[1]){
        return arr[0];
    }
    if(arr[n-1]!=arr[n-2]){
        return arr[n-1];
    }

    int l{1};
    int h{n-2};

    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }

        if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid+1]==arr[mid])){
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

    cout<<singleNonDuplicateOptimal(nums);
}
