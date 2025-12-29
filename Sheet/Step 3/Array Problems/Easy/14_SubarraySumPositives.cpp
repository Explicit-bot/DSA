#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Worse Brute (O(N*N*N),O(1))
int SubArrayWorseBrute(vector<int>& nums,int k){
    int n = nums.size(); 
    int maxLength = 0;

    for (int startIndex = 0; startIndex < n; startIndex++) { 
        for (int endIndex = startIndex; endIndex < n; endIndex++) { 
            int currentSum = 0;
            for (int i = startIndex; i <= endIndex; i++) {
                currentSum += nums[i];
            }

            if (currentSum == k)
                maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
    return maxLength;
}


//Brute (O(N*N),O(1))
int SubArrayBrute(vector<int>& nums,int k){
    int n=nums.size();
    int maxi{};

    for(int i{};i<n;++i){
        int sum{};
        for(int j=i;j<n;++j){    
            sum+=nums[j];
            
            if(sum==k){
                maxi=max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}

//Better (Prefix Sum + Hashing) (O(N),O(N))
