#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//Brute force
void slargestelement(int arr[],int n){
    if(n < 2){
    cout << "No Second Largest\n";
    return;
    }
    
    sort(arr,arr+n);
    for(int i=n-2;i>=0;--i){
        if(arr[i]!=arr[n-1]){
            cout<<arr[i];
            return;
        }
    }
    cout<<"All are equal"<<"\n";
}

//Better approach
void SLargestelement(int arr[],int n){
    int maxx=arr[0];
    for(int i{};i<n;++i){
        if(arr[i]>maxx){
            maxx=arr[i];
        }
    }
    bool flag=false;
    int slargest=INT_MIN;
    for(int i{1};i<n;++i){
        if(arr[i]>slargest && arr[i]!=maxx){
            slargest=arr[i];
            flag=true;
        }
    }

    if(flag){
        cout<<slargest<<"\n";
    }
    else{
        cout<<"All are equal"<<"\n";
    }
} 

//Optimal approach
void SLargestElement(int arr[],int n){
    if(n<2){
        cout<<"No Second Largest."<<"\n";
        return;
    }

    int l=arr[0];
    int sl=INT_MIN;
    bool flag=false;
    for(int i{1};i<n;++i){
        if(arr[i]>l){
            sl=l;
            l=arr[i];
            flag=true;
        }
        else if(arr[i]<l &&arr[i]>sl){
            sl=arr[i];
            flag=true;
        }
    }

    if(flag){
        cout<<sl<<"\n";  
    }
    else{
        cout<<"All are equal."<<"\n";
    }
}

int main(){
    int n{};
    cin>>n;

    int arr[n];
    for(int i{};i<n;++i){
        cin>>arr[i];
    }

    //cout<<"Brute: ";
    //slargestelement(arr,n);

    cout<<"Better: ";
    SLargestelement(arr,n);

    //cout<<"Optimal: ";
    //SLargestElement(arr,n);
}
