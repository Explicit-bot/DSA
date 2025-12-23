#include<iostream>
#include<cmath>
using namespace std;

int main() {
    //For Test case 
    int T{};
    cin>>T;
    //For test cases input
    while(T>0){
        --T;    //For looping T times
        
        //For length of array
        int N{};
        cin>>N;
        
        //Array declaration
        int arr[N];
        for(int i{};i<N;++i){
            cin>>arr[i];
        }
        
        int sum{};
        for(int i{};i<N;++i){
            sum+=arr[i];
        }
        
        if(sum>=0){
            cout<<0<<"\n";
        }
        else{
            int X=ceil((double)(-sum)/N);         //ceil(a / b) = (a + b - 1) / b
            cout<<X<<"\n";
        }
    }

    return 0;
}

