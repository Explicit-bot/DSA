#include<iostream>
#include<vector>
using namespace std;

vector<int> RepeatingMissingBrute(const vector<int>& nums){
    int n=nums.size();
    int repeating{};
    int missing{};
    for(int i{1};i<=n;++i){
        int cnt{};
        for(int j{};j<n;++j){
            if(i==nums[j]){
                ++cnt;
            }
        }
        if(cnt==2){
            repeating=nums[i];
        }
        else if(cnt==0){
            missing=nums[i];
        }

        if(missing!=0 && repeating!=0){
            break;
        }
    }
    return {repeating,missing};
}

vector<int> RepeatingMissingBetter(const vector<int>& nums){
    int n=nums.size();
    vector<int> hash(n+1,0);
    int repeating{};
    int missing{};
    for(auto x:nums){
        ++hash[x];
    }

    for(int i{1};i<=n;++i){
        if(hash[i]==2){
            repeating=i;
        }
        else if(hash[i]==0){
            missing=i;
        }
        if(missing!=0 && repeating!=0){
            break;
        }
    }
    return {repeating,missing};
}

vector<int> RepeatingMissingOptimalMath(const vector<int>& nums){
    int n=nums.size();
    int S2n=(n*(n+1)*(2*n+1)/6);
    int Sn=(n*(n+1)/2);
    int Sa{};
    int S2a{};
    for(auto x:nums){
        Sa+=x;
        S2a+=x*x;
    }

    int val1=Sa-Sn;
    int val2=S2a-S2n;

    val2=val2/val1;

    int repeating=(val2+val1)/2;
    int missing=val2-repeating;

    return {repeating,missing};
}

vector<int> RepeatingMissingOptimalXor(vector<int>& nums) {
    int n = nums.size(); 
    int xr = 0;
    for (int i = 0; i < n; i++) {
        // XOR of all elements in nums
        xr = xr ^ nums[i]; 
            
        // XOR of numbers from 1 to n
        xr = xr ^ (i + 1);  
    }

    // Get the rightmost set bit in xr
    int number = (xr & ~(xr - 1));

    //Group the numbers based on the differentiating bit
    // Number that falls into the 0 group
    int zero = 0; 
        
    // Number that falls into the 1 group
    int one = 0;  

    for (int i = 0; i < n; i++) {
        /* Check if nums[i] belongs to the 1 group
        based on the differentiating bit*/
        if ((nums[i] & number) != 0) {                
            // XOR operation to find numbers in the 1 group
            one = one ^ nums[i];        
        } 
        else {
            // XOR operation to find numbers in the 0 group
             zero = zero ^ nums[i]; 
        }
    }

    // Group numbers from 1 to n based on differentiating bit
    for (int i = 1; i <= n; i++) {            
        /* Check if i belongs to the 1 group 
        based on the differentiating bit*/
        if ((i & number) != 0) {   
            // XOR operation to find numbers in the 1 group
            one = one ^ i; 
        } 
        else {
            // XOR operation to find numbers in the 0 group
            zero = zero ^ i; 
        }
    }

    // Count occurrences of zero in nums
    int cnt = 0; 

    for (int i = 0; i < n; i++) {
        if (nums[i] == zero) {
            cnt++;
        }
    }

    if (cnt == 2) {
        /*zero is the repeating number,
        one is the missing number*/
        return {zero, one}; 
    }
        
    /* one is the repeating number, 
    zero is the missing number*/
    return {one, zero}; 
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    // vector<int> ans=RepeatingMissingBrute(nums);
    // vector<int> ans=RepeatingMissingBetter(nums);
     vector<int> ans=RepeatingMissingOptimalMath(nums);
    // vector<int> ans=RepeatingMissingOptimalXor(nums);
    cout<<"Repeating:"<<ans[0]<<"\n";
    cout<<"Missing:"<<ans[1]<<"\n";
}


/*
vector<int> RepeatingMissingBetter(const vector<int>& nums){
    int n=nums.size();
    unordered_map<int,int> mp;
    int repeating{};
    int missing{};
    for(auto x:nums){
        ++mp[x];
    }

    for(int i{1};i<=n;++i){
        if(mp[i]==2){
            repeating=i;
        }

        // You are wondering:
        // “Shouldn’t this give an error because missing number does not exist in map?”
        // The answer is:
        // No, because operator[] in unordered_map automatically creates the key if it does not exist
        
        else if(mp[i]==0){
            missing=i;
        }
        if(missing!=0 && repeating!=0){
            break;
        }
    }
    return {repeating,missing};
}
*/
