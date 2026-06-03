#include<iostream>
#include<vector>
using namespace std;

void ShuffleArrayBrute(vector<int>& nums,int n){
    vector<int> x{};
    vector<int> y{};
    for(int i{};i<n;++i){
        x.push_back(nums[i]);
    }
    for(int i{n};i<2*n;++i){
        y.push_back(nums[i]);
    }

    for(int i{};i<n;++i){
        nums[2*i]=x[i];
        nums[2*i+1]=y[i];
    }

}

vector<int> ShuffleArrayBetter(vector<int>& nums,int n){
    vector<int> ans(2*n,0);
    
    for(int i{};i<n;++i){
        ans[2*i]=nums[i];
        ans[2*i+1]=nums[i+n];
    }
    return ans;
}

vector<int> ShuffleArrayOptimal(vector<int>& nums,int n){
    vector<int> ans;
    int i{};
    int j{n};

    while(i<n && j<2*n){
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        ++i;
        ++j;
    }
    return ans;
}
int main(){
    int n{};
    cin>>n;

    vector<int> nums(2*n,0);

    for(int i{};i<2*n;++i){
        cin>>nums[i];
    }

    //vector <int> Shuffled=ShuffleArrayBetter(nums,n);
    vector <int> Shuffled=ShuffleArrayOptimal(nums,n);
    
    for(auto x:Shuffled){
        cout<<x<<" ";
    }
    
    cout<<"\n";

    ShuffleArrayBrute(nums,n);
    
    for(auto x:nums){
        cout<<x<<" ";
    }

}
