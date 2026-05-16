/*
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute force Approach
vector<int> alldivisors(int n){
    vector <int> res{};
    for(int i{1};i<=n;++i){
        if(n%i==0){
            res.push_back(i);
        }
   }
   return res;
}

//Optimal Approach
vector<int> AllDivisors(int n){
    vector <int> res{};
    for(int i{1};i*i<=n;++i){   //do not initialize i with zero coz division by i 
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i){
                res.push_back(n/i);
            }
        }
    }

    sort(res.begin(), res.end());
    return res;
}

//Ultra-Optimized Version (No Sorting)
vector<int> ALLDivisors(int n){
    vector<int> small, large;
    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            small.push_back(i);
            if(i != n / i){
                large.push_back(n / i);
            }
        }
    }

    reverse(large.begin(), large.end());
    small.insert(small.end(), large.begin(), large.end());

    return small;
}

int main(){
    int num{};

    cout<<"Enter the number:";
    cin>>num;

    vector <int> div=alldivisors(num);
    vector <int> Div=AllDivisors(num);

    cout<<"Brute Force Approach"<<"\n";
    for(auto x:div){
        cout<<x<<" ";
    }

    cout<<"\n"<<"Optimal Approach"<<"\n";
    for(auto x:Div){
        cout<<x<<" ";
    }
    return 0;
}


/*
1️⃣ Brute Force Approach
⏱️ Time Complexity
O(n)

💾 Space Complexity
O(n)   // storing divisors

⚠️ Drawbacks
* Very slow for large `n`
* Checks unnecessary numbers



2️⃣ Optimal Approach (√n Method)
📐 Time Complexity Calculation
🔁 Loop
Runs from 1 → √n
 O(√n)

🔃 Sorting
* At most 2√n divisors
* Sorting cost:
O(√n log √n) ≈ O(√n log n)

🏁 Final Time Complexity
O(√n log n)

💾 Space Complexity
O(√n)

🚀 Ultra-Optimized Version (No Sorting)

⏱️ Time Complexity
O(√n)

🧪 Edge Cases

| Case           | Input | Output     |
| -------------- | ----- | ---------- |
| n = 1          | 1     | 1          |
| Prime          | 7     | 1 7        |
| Perfect Square | 16    | 1 2 4 8 16 |


 ✅ Summary
| Approach          | Time        | Sorted | Recommended |
| ----------------- | ----------- | ------ | ----------- |
| Brute Force       | O(n)        | ✔      | ❌           |
| Optimal + sort    | O(√n log n) | ✔      | ✔           |
| Optimal (no sort) | O(√n)       | ✔      | ⭐ BEST      |

*/
