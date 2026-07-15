#include<iostream>
#include<vector>
using namespace std;

int RichestCustomerWealthBrute(vector<vector<int>>& wealth){
    int m=wealth.size();
    int n=wealth[0].size();
    int maxi{};

    for(int i{};i<wealth.size();++i){
        int sum{};
        for(int j{};j<wealth[i].size();++j){
            sum+=wealth[i][j];        
        }
        maxi=max(maxi,sum);
    }
    return maxi;
}

int main(){
    int m{},n{};
    cin>>m>>n;

    vector<vector<int>> nums(m,vector<int>(n,0));

    for(int i{};i<m;++i){
        for(int j{};j<n;++j){
            cin>>nums[i][j];
        }
    }

    cout<<RichestCustomerWealthBrute(nums);
}
