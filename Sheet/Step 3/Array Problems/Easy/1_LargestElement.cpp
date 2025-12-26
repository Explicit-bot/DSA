#include <iostream>
using namespace std;

//Brute force
void largestelement(int arr[],int n){
    sort(arr,arr+n);
    cout<<arr[n-1]<<"\n";
}

//Better approach
void Largestelement(int arr[],int n){
    int max=arr[0];
    for(int i{};i<n;++i){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max<<"\n";
} 

//Optimal approach
void LargestElement(int arr[],int n){
    cout<< *max_element(arr,arr+n)<<"\n";
}

int main(){
    int n{};
    cin>>n;

    int arr[n];
    for(int i{};i<n;++i){
        cin>>arr[i];
    }

    //cout<<"Brute: ";
    //largestelement(arr,n);

    //cout<<"Better: ";
    //Largestelement(arr,n);

    cout<<"Optimal: ";
    LargestElement(arr,n);
}
