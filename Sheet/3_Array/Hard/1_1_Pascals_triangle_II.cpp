//Print nth row;
#include<iostream>
#include<vector>
using namespace std;

// ========================= BRUTE FORCE =========================
// Time Complexity: O(n^2)
// Space Complexity: O(1) excluding output
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

vector<int> generateNthRowBrute(int row){
    vector<int> ans;
    for(int col = 0; col <= row; col++){
        ans.push_back(nCrBrute(row, col));
    }
    return ans;
}

// ========================= BETTER APPROACH =========================
// Using Pascal Triangle construction
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
vector<int> generateNthRowBetter(int row){
    vector<vector<int>> triangle(row + 1);
    for(int i = 0; i <= row; i++){
        triangle[i].resize(i + 1);
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; j++){
            triangle[i][j] =
                triangle[i-1][j-1] +
                triangle[i-1][j];
        }
    }
    return triangle[row];
}

// ========================= OPTIMAL APPROACH =========================
// Time Complexity: O(n)
// Space Complexity: O(1) excluding output

vector<int> generateNthRowOptimal(int row){
    vector<int> ans;
    long long value = 1;
    ans.push_back(value);
    for(int col = 1; col <= row; col++){
        value = value * (row - col + 1);
        value = value / col;
        ans.push_back(value);
    }
    return ans;
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
