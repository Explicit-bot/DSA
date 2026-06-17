#include<iostream>
#include<vector>
using namespace std;



int kthMissingBrute(vector<int>& arr , int k){
    int num{1};
    int i{};

    while(true){
        if(i<arr.size() && num==arr[i]){
            ++i;
        }
        else{
            --k;
            if(k==0){
                return num;
            }
        }
        ++num;
    }
}

int kthMissingBetter(vector<int>& arr , int k){
    for(auto x:arr){
        if(x<=k){
            ++k;
        }
        else{
            break;
        }
    }
    return k;
}

int kthMissingOptimal(vector<int>& arr , int k){
    int l{};
    int h=arr.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return k+h+1;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int k{};
    cin>>k;

    cout<<kthMissingBrute(nums,k)<<"\n";
    cout<<kthMissingBetter(nums,k)<<"\n";
    cout<<kthMissingOptimal(nums,k)<<"\n";
}

/*
The "generate numbers one by one" solution
1 -> missing
2 -> present
3 -> present
...
Time complexity is: O(answer) not O(n).
The answer can be much larger than n so it is brute.

Better - O(N)
Optimal - O(logN)

Explanation:
k = 5
Think like this:
If there were NO numbers present in the array, the 5th missing positive number would be 5.

The statement
    if(arr[i] <= k)
        k++;
means:
This number exists in the array, so it is not missing anymore. Therefore my kth missing number moves one position to the right.
*/
