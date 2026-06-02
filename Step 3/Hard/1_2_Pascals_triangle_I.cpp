//Print complete pacals triangle till nth row
#include<iostream>
#include<vector>
using namespace std;


//r th row and c th column element
int PascalTriangleelm(int r,int c){
    int pte{1};
    for(int i{};i<c-1;++i){
        pte=pte*(r-1-i);
        pte/=i+1;
    }
    return pte;
}

// ========================= BRUTE FORCE =========================
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
long long factorial(int n){

    long long ans = 1;

    for(int i = 1; i <= n; i++){
        ans *= i;
    }

    return ans;
}

long long nCrBrute(int n, int r){
    return factorial(n) / (factorial(r) * factorial(n-r));
}

vector<vector<int>> generateBrute(int numRows){
    vector<vector<int>> ans;
    for(int i = 0; i < numRows; i++){
        vector<int> row;
        for(int j = 0; j <= i; j++){
            row.push_back(nCrBrute(i, j));
        }
        ans.push_back(row);
    }
    return ans;
}

// ========================= BETTER APPROACH =========================
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

vector<vector<int>> generateBetter(int numRows){
    vector<vector<int>> triangle(numRows);
    for(int i = 0; i < numRows; i++){
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; j++){
            triangle[i][j] =triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}

// ========================= OPTIMAL APPROACH =========================
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

vector<int> generateRowOptimal(int row){
    long long ans = 1;
    vector<int> res;
    res.push_back(1);
    for(int col = 1; col <= row; col++){
        ans = ans * (row - col + 1);
        ans = ans / col;
        res.push_back(ans);
    }
    return res;
}

vector<vector<int>> generateOptimal(int numRows){
    vector<vector<int>> triangle;
    for(int row = 0; row < numRows; row++){
        triangle.push_back(generateRowOptimal(row));
    }
    return triangle;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    

    for(auto x:nums){
        cout<<x<<" ";
    }

}
