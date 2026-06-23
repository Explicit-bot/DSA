#include<iostream>
#include<vector>
using namespace std;

//Brute
bool searchMatrixBrute(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i{};i<n;++i) {
        for (int j{};j<m;++j) {
            if (matrix[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

//Better
bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size();
    int low{};
    int high{n-1};
    
    while(low<=high){
        int mid=(low + high) / 2;
    
        if(nums[mid]==target){
            return true;
        }
        else if(target>nums[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i{};i<n;++i){
        if (matrix[i][0]<=target && target<=matrix[i][m - 1]){
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

//Optimal
bool searchMatrixOptimal(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low{};
    int high{m*n-1};
        
    while (low <= high) {
        int mid = (low + high) / 2;
        
        int row = mid / m;
        int col = mid % m;
        
        if (matrix[row][col] == target){
            return true;
        }
        else if (matrix[row][col] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
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

    int target{};
    cin>>target;

    cout<<searchMatrixBrute(mat,target)<<"\n";
    cout<<searchMatrixBetter(mat,target)<<"\n";
    cout<<searchMatrixOptimal(mat,target)<<"\n";
}
