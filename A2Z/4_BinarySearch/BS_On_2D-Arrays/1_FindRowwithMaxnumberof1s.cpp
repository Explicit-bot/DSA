#include<iostream>
#include<vector>
using namespace std;

//Brute
int rowWithMax1sBrute(vector<vector<int>>& mat){
    int m=mat.size();
    int n=mat[0].size();
    int cntmax{};
    int idx{-1};
    for(int i{};i<m;++i){
        int cnt1s{};
        for(int j{};j<n;++j){
            if(mat[i][j]==1){
                ++cnt1s;
            }
        }
        if(cnt1s>cntmax){
            cntmax=cnt1s;
            idx=i;
        }
    }
    return idx;
}

//Better
int LowerBound(vector<int>& nums,int k){
    int n=nums.size();
    int l{0};
    int h{n-1};
    int ans{n};
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>=k){
            h=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int rowWithMax1sBetter(vector<vector<int>>& mat){
    int m=mat.size();
    int n=mat[0].size();
    int cntmax{};
    int idx{-1};
    for(int i{};i<m;++i){
       int cnt1s=n-LowerBound(mat[i],1);
       if(cnt1s>cntmax){
        cntmax=cnt1s;
        idx=i;
       }
    }
    return idx;
}

//Optimal
int rowWithMax1sOptimal(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int row = -1;
    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
        if (mat[i][j] == 1) {
            row = i;  // current row has more 1s than previous answer
            j--;      // try to find an even earlier 1
        }
        else {
            i++;      // move to next row
        }
    }

    return row;
}

int main(){
    int m{},n{};
    cin>>m>>n;

    vector<vector<int>> mat(m,vector<int> (n,0));
    for(auto& row:mat){
        for(auto& val:row){
            cin>>val;
        }
    }

    cout<<rowWithMax1sBrute(mat)<<"\n";
    cout<<rowWithMax1sBetter(mat)<<"\n";
    cout<<rowWithMax1sOptimal(mat)<<"\n";
}
