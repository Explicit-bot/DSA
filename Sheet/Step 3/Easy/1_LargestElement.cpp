#include <iostream>
#include <vector>
using namespace std;

int largestbrute(vector<int>& nums){
    sort(nums.begin(),nums.end());  //O(NlogN)

    return *(nums.end()-1);
}

int largestOptimal(vector<int>& nums){
        int lar{INT_MIN};
        for(const int &var:nums){
            if(var>lar){
                lar=var;
            }
        }
        return lar;
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
