#include<iostream>
#include<vector>
using namespace std;

//O(NlogN)+O(2N)
vector<vector<int>> mergeoverlapintervalsBrute(vector<vector<int>>& arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i{};i<n;++i){
        int start{arr[i][0]};
        int end{arr[i][1]};
        //ans.back()[1] gives the second element of the latest array of ans array.
        //As ans.back() gives the latest array of ans array
        if(!ans.empty() && end<= ans.back()[1]){    
            continue;
        }
        for(int j{i+1};j<n;++j){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

vector<vector<int>> mergeoverlapintervalsOptimal(vector<vector<int>>& arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    int start{arr[0][0]};
    int end{arr[0][1]};
    for(int i{1};i<n;++i){
        if(arr[i][0]<=end){
            end=max(end,arr[i][1]);
        }
        else{
            ans.push_back({start,end});
            start=arr[i][0];
            end=arr[i][1];
        }
    }
    ans.push_back({start,end});
    return ans;
}

//Cleaner version
vector<vector<int>> mergeoverlapintervals(vector<vector<int>>& arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
   
    for(int i{0};i<n;++i){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<vector<int>> nums(n,vector<int>(2,0));
    for(auto& x:nums){
        for(auto& y:x){
            cin>>y;
        }
    }

    vector<vector<int>> ansBr=mergeoverlapintervalsBrute(nums);
    for(auto x:ansBr){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\t";
    }
    cout<<"\n";

    vector<vector<int>> ansOp=mergeoverlapintervalsOptimal(nums);
    for(auto x:ansOp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\t";
    }
    cout<<"\n";

    vector<vector<int>> ans=mergeoverlapintervals(nums);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\t";
    }
    cout<<"\n";
}
