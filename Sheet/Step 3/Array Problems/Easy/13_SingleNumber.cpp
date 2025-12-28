#include <iostream>
#include <vector>
using namespace std;

//Brute     (O(n*n),O(1))
int SingleBrute(vector <int>& nums){
    int n=nums.size();
    for(int i {};i<n;++i){
        int num=nums[i];
        int cnt{};

        for(int j{};j<n;++j){
            if(nums[i]==nums[j]){
                ++cnt;
            }
        }
        if(cnt==1){
            cout<<num<<"\n";
        }
    }
}

//Better
int SingleBetter(vector<int>& nums){

}
`
