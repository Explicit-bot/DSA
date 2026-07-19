#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> RotateMatrixBrute(vector<vector<int>>& matrix){
    int n=matrix.size();
    vector<vector<int>> ans(n,vector<int> (n,0));
    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    
    return ans;
}

void RotateMatrixOptimal(vector<vector<int>>& matrix){
    int n=matrix.size();
    for(int i{};i<n;++i){
        for(int j{i+1};j<n;++j){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int i{};i<n;++i){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    int m{},n{};
    cin>>m>>n;

    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int i{};i<m;++i){
        for(int j{};j<n;++j){
            cin>>matrix[i][j];
        }
    }

    cout<<"\n";
    
    vector<vector<int>> ans=RotateMatrixBrute(matrix);
    for(auto row:ans){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n";

    RotateMatrixOptimal(matrix);
    for(auto row:matrix){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<"\n";
    }

    
}

