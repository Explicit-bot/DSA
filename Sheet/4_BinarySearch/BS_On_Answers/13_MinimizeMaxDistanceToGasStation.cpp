//********
#include<iostream>
#include<vector>
#include <queue>
#include <utility>
using namespace std;

long double minMaxDistanceBrute(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);

    for(int i{1};i<=k;++i){
        long double maxsection{-1};
        int maxidx{-1};
        for(int j{};j<n-1;++j){
            long double diff=arr[j+1]-arr[j];
            long double sectionlen=diff/(howMany[j]+1.0);

            if(sectionlen>maxsection){
                maxsection=sectionlen;
                maxidx=j;
            }
        }
        ++howMany[maxidx];
    }

    long double maxans{-1};
    for(int i{};i<n-1;++i){
        long double diff=arr[i+1]-arr[i];
        long double sectionlen=diff/(howMany[i]+1.0);

        maxans=max(maxans,sectionlen);
    }
    return maxans;
}

long double minMaxDistanceBetter(vector<int>& arr,int k){
    int n=arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double,int>> pq;
    for(int i{};i<n-1;++i){
        long double len=arr[i+1]-arr[i];
        pq.push({len,i});
    }

    for(int i{1};i<=k;++i){
        auto top=pq.top();
        pq.pop();
        int segmentidx=top.second;

        ++howMany[segmentidx];
        long double totaldist=arr[segmentidx+1]-arr[segmentidx];
        long double newlen=totaldist/(howMany[segmentidx]+1.0);
        pq.push({newlen,segmentidx});
    }

    return pq.top().first;
}

//Optimal
int cntGasStations(vector<int>& arr,long double dist){
    int cnt{};
    for(int i{1};i<arr.size();++i){
        int numinbetween=((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist==numinbetween*dist){
            --numinbetween;
        }
        cnt+=numinbetween;
    }
    return cnt;
}

long double minMaxDistanceOptimal(vector<int>& arr,int k){
    int n=arr.size();
    long double low{};
    long double high{};
    for(int i {};i<n-1;++i){
        high=max(high,(long double)(arr[i+1]-arr[i]));
    }

    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(high+low)/(2.0);
        int cnt=cntGasStations(arr,mid);
        if(cnt>k){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return high;
}

int main(){
    int n{};
    cin>>n;
    
    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int k{};
    cin>>k;

    cout<<minMaxDistanceBrute(nums,k)<<"\n";
    cout<<minMaxDistanceBetter(nums,k)<<"\n";
    cout<<minMaxDistanceOptimal(nums,k)<<"\n";

}
