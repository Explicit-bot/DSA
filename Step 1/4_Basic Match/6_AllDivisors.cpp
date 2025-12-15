/*
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.
*/
#include <iostream>
#include <vector>
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
    return res;
}

//Optimal approach (No need of sorting)

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
# 📌 Divisors of a Number (C++) — Complete VS Code Documentation

---

## 🧠 Problem Statement

You are given an integer **n**. You need to find **all divisors of n** and return them in **sorted order**.

> A number which completely divides another number is called its **divisor**.

---

## 🧩 Example

### Input

```
n = 36
```

### Output

```
1 2 3 4 6 9 12 18 36
```

---

## 🛠️ Approaches

We will cover **two approaches**:

1. **Brute Force Approach**
2. **Optimal (√n) Approach**

---

## 1️⃣ Brute Force Approach

### 💡 Idea

Check every number from `1` to `n` and see if it divides `n`.

---

### ✅ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> allDivisors(int n){
    vector<int> res;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            res.push_back(i);
        }
    }
    return res;
}
```

---

### ⏱️ Time Complexity

```
O(n)
```

### 💾 Space Complexity

```
O(n)   // storing divisors
```

---

### ⚠️ Drawbacks

* Very slow for large `n`
* Checks unnecessary numbers

---

## 2️⃣ Optimal Approach (√n Method)

### 🧠 Key Observation

Divisors occur in **pairs**:

```
i × (n / i) = n
```

So if `i` is a divisor, then `n/i` is also a divisor.

Once `i > √n`, divisors start repeating.

---

### ✅ Code (Optimal + Sorted Output)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> AllDivisors(int n){
    vector<int> res;

    for(int i = 1; i * i <= n; ++i){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i){
                res.push_back(n / i);
            }
        }
    }

    sort(res.begin(), res.end());
    return res;
}
```

---

## 🔍 Why `i * i <= n`?

Because:

```
i <= √n
```

This ensures we only loop **√n times**, not `n` times.

---

## 📐 Time Complexity Calculation

### 🔁 Loop

```
Runs from 1 → √n
⇒ O(√n)
```

### 🔃 Sorting

* At most `2√n` divisors
* Sorting cost:

```
O(√n log √n) ≈ O(√n log n)
```

---

### 🏁 Final Time Complexity

```
O(√n log n)
```

---

### 💾 Space Complexity

```
O(√n)
```

---

## 🚀 Ultra-Optimized Version (No Sorting)

```cpp
vector<int> AllDivisors(int n){
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
```

### ⏱️ Time Complexity

```
O(√n)
```

---

## 🧪 Edge Cases

| Case           | Input | Output     |
| -------------- | ----- | ---------- |
| n = 1          | 1     | 1          |
| Prime          | 7     | 1 7        |
| Perfect Square | 16    | 1 2 4 8 16 |

---

## 🎯 Interview Ready One-Liner

> "Divisors come in pairs around √n, so iterating only till √n is sufficient, giving O(√n) time complexity."

---

## ✅ Summary

| Approach          | Time        | Sorted | Recommended |
| ----------------- | ----------- | ------ | ----------- |
| Brute Force       | O(n)        | ✔      | ❌           |
| Optimal + sort    | O(√n log n) | ✔      | ✔           |
| Optimal (no sort) | O(√n)       | ✔      | ⭐ BEST      |

---

🔥 You’re now **exam + interview + CP ready** for this topic.

*/
