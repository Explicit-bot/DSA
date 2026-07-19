#include <iostream>
#include <vector>
using namespace std;

double medianTwoSortedArraysBrute(vector<int>& arr1,vector<int>& arr2){
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

    int p{m+n};

    if(p%2==1){
        return arr3[p/2];
    }

    return ((double)arr3[p/2]+(double)arr3[(p/2)-1])/2.0;      
}

double medianTwoSortedArraysBetter(vector<int>& arr1,vector<int>& arr2){
    int m=arr1.size();
    int n=arr2.size();
    
    if(m+n==0){
        return -1;
    }

    int l{};
    int r{};
    int p{m+n};
    int idx2{p/2};  
    int idx1{(p/2)-1};
    int cnt{};
    int idxelm2{-1};
    int idxelm1{-1};

    while(l<m && r<n && cnt<=idx2){
        if(arr1[l]<arr2[r]){
            if(cnt==idx1){
                idxelm1=arr1[l];
            }
            if(cnt==idx2){
                idxelm2=arr1[l];
            }
            ++cnt;
            ++l;
        }
        else{
            if(cnt==idx1){
                idxelm1=arr2[r];
            }
            if(cnt==idx2){
                idxelm2=arr2[r];
            }
            ++cnt;
            ++r;
        }
    }

    while(l<m && cnt<=idx2){
        if(cnt==idx1){
            idxelm1=arr1[l];
        }
        if(cnt==idx2){
            idxelm2=arr1[l];
        }
        ++cnt;
        ++l;
    }
    while(r<n && cnt<=idx2){
        if(cnt==idx1){
                idxelm1=arr2[r];
        }
        if(cnt==idx2){
            idxelm2=arr2[r];
        }
        ++cnt;
        ++r;
    }

    if(p%2==1){
        return idxelm2;
    }

    return ((double)idxelm1 + (double)idxelm2)/2.0;
}

double medianTwoSortedArraysOptimal(vector<int>& arr1,vector<int>& arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    
    //to take smaller array as main
    if(n1>n2){
        return medianTwoSortedArraysOptimal(arr2,arr1);
    }

    int l{};
    int h{n1};
    int left=(n1+n2+1)/2;
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
            if(n%2==1){
                return max(l1,l2);
            }
            return ((double)max(l1,l2)+(double)min(r1,r2))/2.0;
        }
        else if (l1>r2){
            h=mid1-1;
        }
        else{
            l=mid1+1;
        }
    }
    return 0;
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

    cout<<medianTwoSortedArraysBrute(nums1,nums2)<<"\n";
    cout<<medianTwoSortedArraysBetter(nums1,nums2)<<"\n";
    cout<<medianTwoSortedArraysOptimal(nums1,nums2)<<"\n";
}
