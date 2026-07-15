//2535
#include<iostream>
using namespace std;

int differenceOfSum(vector<int>& nums){
    int n=nums.size();
    int elementsum{};
    int digitsum{};

    for(int i{};i<n;++i){
        elementsum+=nums[i];
        int temp{nums[i]};
        while(temp){
            digitsum+=temp%10;
            temp/=10;
        }
    }
    return abs(elementsum-digitsum);
}
