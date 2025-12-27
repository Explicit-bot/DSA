#include <iostream>
using namespace std;

//Brute force
void largestelement(int arr[],int n){
    sort(arr,arr+n);
    cout<<arr[n-1]<<"\n";
}

//Optimal approach
void Largestelement(int arr[],int n){
    int max=arr[0];
    for(int i{};i<n;++i){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max<<"\n";
} 

//Using STL Algo
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

    //cout<<"//Optimal: ";
    //Largestelement(arr,n);

    cout<<"Using STL: ";
    LargestElement(arr,n);
}
