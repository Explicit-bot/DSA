#include<iostream>
#include<vector>
using namespace std;

//Brute (O(n),O(k))
void LeftRotateBrute(vector<int>& nums,int k){
    int n=nums.size();
    k = k % n;               // IMPORTANT for k > n
    vector <int> temp(k);

    //storing in temp
    for(int i{};i<k;++i){
        temp[i]=nums[i];
    }

    //shifting
    for(int i=k;i<n;++i){
        nums[i-k]=nums[i];
    }

    //putting back
    for(int i=n-k;i<n;++i){
        nums[i]=temp[i-(n-k)];
    }
}

//Using STL (O(n),O(k))
void LeftRotateSTL(vector<int>& nums,int k){
    int n=nums.size();
    k = k % n; 

    //Storing in temp
    vector<int> temp(nums.begin(), nums.begin() + k); 
    /*
    for(int i{};i<n;++i){
        temp[i]=nums[i];
    }
    */

    //Erasing till k from nums
    nums.erase(nums.begin(),nums.begin()+k);

    //Adding in the end of vector 
    nums.insert(nums.end(), temp.begin(), temp.end());
    // for(int i=0;i<k;++i){
    //     nums.push_back(temp[i]);
    // }
}

//Optimal   (O(n),O(1))
void LeftRotateOptimal(vector<int>& nums, int k) {
       int n = nums.size();
       if(k == 0) return;
        k = k % n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int k{};
    cin>>k;

    //LeftRotateBrute(nums,k);
    //LeftRotateSTL(nums,k);
    LeftRotateOptimal(nums,k);

    for(auto x:nums){
        cout<<x<<" ";
    }

    
    return 0;
}
