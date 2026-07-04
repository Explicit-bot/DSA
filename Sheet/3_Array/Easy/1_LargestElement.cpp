#include <iostream>
#include <vector>
using namespace std;

int largestbrute(vector<int>& nums){
    sort(nums.begin(),nums.end());  //O(NlogN)

    return *(nums.end()-1);
}

int largestOptimal(vector<int>& nums){
    int var{INT_MIN};
    for(const auto& x:nums){
        if(x>var){
            var=x;
        }
    }
    return var;
}

int main(){
    int n{};

    cout<<"Number of elements:";
    cin>>n;

    vector<int> nums{};
    for(int i{};i<n;++i){
        int temp{};
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<largestbrute(nums)<<"\n";
    cout<<largestOptimal(nums)<<"\n";


}
