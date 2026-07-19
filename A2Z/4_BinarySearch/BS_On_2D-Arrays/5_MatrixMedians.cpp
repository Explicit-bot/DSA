#include<iostream>
#include<vector>
using namespace std;

int medianOfRowWiseSortedMatrixBrute(vector<vector<int>>& mat){
    int m=mat.size();
    int n=mat[0].size();
    vector<int> mat1d;
    mat1d.reserve(m*n);
    for(auto x:mat){
        for(auto val:x){
            mat1d.push_back(val);
        }
    }
    sort(mat1d.begin(),mat1d.end());

    return mat1d[m*n/2];
}


int medianOfRowWiseSortedMatrixOptimal(vector<vector<int>>& mat){
    return 0;
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

    cout<<medianOfRowWiseSortedMatrixBrute(mat)<<"\n";
    cout<<medianOfRowWiseSortedMatrixOptimal(mat)<<"\n";

}
