#include <iostream>
#include <vector>
using namespace std;

int KthElementTwoSortedArraysBrute(vector<int>& arr1,vector<int>& arr2,int k){
    int m=arr1.size();
    int n=arr2.size();
    
    if(m+n==0){
        return -1;
    }
    vector<int> arr3;
    int l{};
    int r{};
    while(l<m && r<n){
        if(arr1[l]<arr2[r]){
            arr3.push_back(arr1[l]);
            ++l;
        }
        else{
            arr3.push_back(arr2[r]);
            ++r;
        }
    }

    while(l<m){
        arr3.push_back(arr1[l]);
        ++l;
    }
    while(r<n){
        arr3.push_back(arr2[r]);
        ++r;
    }

    return arr3[k-1]; 
}

int KthElementTwoSortedArraysBetter(vector<int>& arr1,vector<int>& arr2,int k){
    int m=arr1.size();
    int n=arr2.size();
    
    if(m+n==0){
        return -1;
    }

    int l{};
    int r{};
    int cnt{};

    while(l<m && r<n){
        if(arr1[l]<arr2[r]){
            if(cnt==k-1){
                return arr1[l];
            }
            ++cnt;
            ++l;
        }
        else{
            if(cnt==k-1){
                return arr2[r];
            }
            ++cnt;
            ++r;
        }
    }

    while(l<m){
        if(cnt==k-1){
            return arr1[l];
        }
        ++cnt;
        ++l;
    }

    while(r<n){
        if(cnt==k-1){
            return arr2[r];
        }
        ++cnt;
        ++r;
    }
    return -1;
}

int KthElementTwoSortedArraysOptimal(vector<int>& arr1,vector<int>& arr2,int k){
    int n1=arr1.size();
    int n2=arr2.size();
    
    //to take smaller array as main
    if(n1>n2){
        return KthElementTwoSortedArraysOptimal(arr2,arr1,k);
    }

    int l=max(k-n2,0);  //WHYYy??
    int h=min(k,n1);
    int left=k;
    int n{n1+n2};

    while(l<=h){
        int mid1=l+(h-l)/2;
        int mid2=left-mid1;
        int l1{INT_MIN};
        int l2{INT_MIN};
        int r1{INT_MAX};
        int r2{INT_MAX};

        if(mid1<n1){
            r1=arr1[mid1];
        }
        if(mid2<n2){
            r2=arr2[mid2];
        }
        if(mid1-1>=0){
            l1=arr1[mid1-1];
        }
        if(mid2-1>=0){
            l2=arr2[mid2-1];
        }
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if (l1>r2){
            h=mid1-1;
        }
        else{
            l=mid1+1;
        }
    }
    return -1;
}

int main(){
    int n1{},n2{};
    cin>>n1>>n2;
    
    vector<int> nums1(n1);
    for (auto& x : nums1){
        cin >> x;
    }

    vector<int> nums2(n2);
    for (auto& x : nums2){
        cin >> x;
    }

    int k{};
    cin>>k;

    cout<<KthElementTwoSortedArraysBrute(nums1,nums2,k)<<"\n";
    cout<<KthElementTwoSortedArraysBetter(nums1,nums2,k)<<"\n";
    cout<<KthElementTwoSortedArraysOptimal(nums1,nums2,k)<<"\n";
}
