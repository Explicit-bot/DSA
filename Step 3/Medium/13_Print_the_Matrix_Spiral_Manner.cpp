#include<iostream>
#include<vector>
using namespace std;

void PrintSpiralManner(vector<vector<int>> matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    int left{};
    int top{};
    int right{n-1};
    int bottom{m-1};

    while(left<=right && top<=bottom){
        for(int i{left};i<=right;++i){
            cout<<matrix[top][i]<<" ";
        }
        ++top;

        for(int i{top};i<=bottom;++i){
            cout<<matrix[i][right]<<" ";
        }
        --right;
        if(top<=bottom){
            for(int i{right};i>=left;--i){
                cout<<matrix[bottom][i]<<" ";
            }
            --bottom;
        }
        
        if(left<=right){
            for(int i{bottom};i>=top;--i){
                cout<<matrix[i][left]<<" ";
            }
            ++left;
        }
        
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
    
    PrintSpiralManner(matrix);
}

