#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> SetMatrixZeroesBrute(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();

    for(int i{};i<m;++i){
        for(int j{};j<n;++j){
            if(matrix[i][j]==0){
                for(int k{};k<m;++k){
                    if(matrix[k][j]!=0){
                        matrix[k][j]=-1;
                    }
                }
                for(int k{};k<n;++k){
                    if(matrix[i][k]!=0){
                        matrix[i][k]=-1;
                    }
                }
            }
        }
    }

    for(auto& row:matrix){
        for(auto& x:row){
            if(x==-1){
                x=0;
            }
        }

    }

    return matrix;
}

vector<vector<int>> SetMatrixZeroesBetter(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> row(m,0);
    vector<int> col(n,0);

    for(int i{};i<m;++i){
        for(int j{};j<m;++j){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i{};i<m;++i){
        for(int j{};j<m;++j){
            if(row[i]==1||col[j]==1){
                matrix[i][j]=0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> SetMatrixZeroesOptimal(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    int row0=1;
    for(int i{};i<m;++i){
        for(int j{};j<n;++j){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                if(i!=0){
                    matrix[i][0]=0;
                }
                else{
                    row0=0;
                }
            }
        }
    }

    for(int i{1};i<m;++i){
        for(int j{1};j<n;++j){
            if(matrix[0][j]==0||matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }

    if(matrix[0][0]==0){
        for(int i{};i<n;++i){
            matrix[0][i]=0;
        }
    }
    if(row0==0){
        for(int i{};i<m;++i){
            matrix[i][0]=0;
        }
    }

    return matrix;
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
    SetMatrixZeroesBrute(matrix);
    //SetMatrixZeroesBetter(matrix);
    //SetMatrixZeroesOptimal(matrix);

    for(auto row:matrix){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
}
