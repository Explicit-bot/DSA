#include<iostream>
#include<vector>
using namespace std;

int main() {
    int T{};
    cin>>T;
    
    while(T--){
        int N{};
        cin>>N;
        
        vector<int> arr(N);
        for(auto &x:arr){
            cin>>x;
        }
        
        vector<int> cost(N);
        for(auto &x:cost){
            cin>>x;
        }
        
        int sum{};
        while(!arr.empty()){
            auto minarr=min_element(arr.begin(),arr.end());
            auto mincost=min_element(arr.begin(),arr.end());
            if(*minarr>*mincost){
                int idx = mincost - cost.begin();
                sum += cost[idx] * arr[idx];
                arr.erase(mincost);
                cost.pop_back();
            }
            else{
                int idx = minarr - arr.begin();
                sum += cost[idx] * arr[idx];
                arr.erase(minarr);
                cost.pop_back();
            }
        }
        cout<<sum<<"\n";
    }

}
