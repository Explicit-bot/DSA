#include <iostream>
#include <vector>
using namespace std;

//Brute (O(n),O(n))
void moveZeroesBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;

    for(int i = 0; i < n; ++i){
        if(nums[i] != 0){
            temp.push_back(nums[i]);
        }
    }

    int zeros = n - temp.size();
    while(zeros--){
        temp.push_back(0);
    }

    nums = temp;
}

//Better (O(n),O(1))
void moveZeroesBetter(vector<int>& nums) {
    int n = nums.size();
    int k = 0;

    for(int i = 0; i < n; ++i){
        if(nums[i] != 0){
            nums[k++] = nums[i];    //overwriting the values from 0 -> n with non-Zero no.s only 
        }
    }

    while(k < n){
        nums[k++] = 0;
    }
}


//Optimal (O(n),O(1))
void moveZeroesFaltuOptimal(vector<int>& nums) {
    int n=nums.size();
    if(n<2){
    return;
    } 

    int i{};
    for(int j{1};j<n;++j){
        if(nums[i]!=0){
            ++i;
        }
        if(nums[j]!=0&&nums[i]==0){
            swap(nums[j],nums[i]);
            ++i;
        }        
   }
}

//Optimal (No faltu ke check)
void moveZeroesOptimal(vector<int>& nums) {
    int n = nums.size();
    
    int i = 0;
    for(int j = 0; j < n; ++j){
        if(nums[j] != 0){
            swap(nums[i], nums[j]);
            ++i;
        }
    }
}



int main(){
    int n{};
    cin>>n;

    vector <int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    moveZeroesBrute(nums);
    moveZeroesBetter(nums);
    //moveZeroesFaltuOptimal(nums);
    //moveZeroesOptimal(nums);

    for(auto x:nums){
        cout<<x<<" ";
    }
    cout<<"\n";
}
