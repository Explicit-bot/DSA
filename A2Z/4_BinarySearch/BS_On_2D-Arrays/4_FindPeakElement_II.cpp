#include<iostream>
#include<vector>
using namespace std;

//Brute
vector<int> findPeakGridBrute(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            int up = (i > 0) ? mat[i-1][j] : -1;
            int down = (i < m-1) ? mat[i+1][j] : -1;
            int left = (j > 0) ? mat[i][j-1] : -1;
            int right = (j < n-1) ? mat[i][j+1] : -1;

            if(mat[i][j] > up && mat[i][j] > down && 
               mat[i][j] > left && mat[i][j] > right) {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

//Optimal
int findmax(vector<vector<int>>& mat,int col){
    int m=mat.size();
    int ans{INT_MIN};
    int idx{};
    for(int i{};i<m;++i){
        if(mat[i][col]>ans){
            ans=mat[i][col];
            idx=i;
        }
    }
    return idx;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    
    int l{};
    int h{n-1};
    
    while(l<=h){
        int mid=(l+h)/2;
        int idx=findmax(mat,mid);
        int left = mid - 1 >= 0 ? mat[idx][mid - 1] : INT_MIN;
        int right = mid + 1 < n ? mat[idx][mid + 1] : INT_MIN;
        if(mat[idx][mid]>right && mat[idx][mid]>left){
            return {idx,mid};
        }
        else if(mat[idx][mid]<right){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return {-1,-1};
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

    //vector<int> ans=findPeakGridBrute(mat);
    vector<int> ans=findPeakGrid(mat);
    cout<<ans[0]<<" "<<ans[1]<<" ";

}
