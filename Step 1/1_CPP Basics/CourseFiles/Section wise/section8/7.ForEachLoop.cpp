/*
✅ What is a For-Each Loop?
A for-each loop allows you to iterate directly over elements of a collection without using indices.
works on the basis of size of an array and nit on no. of elements initialized with

📌 Syntax:
for (datatype element : collection) {
    // use element
}
✅ Example 1: Basic For-Each with Array
#include <iostream>
int main() {
    int A[5] = {10, 20, 30, 40, 50};

    std::cout << "Array elements:\n";
    for (int x : A) {
        std::cout << x << " ";
    }

    return 0;
}
🧾 Output: 10 20 30 40 50

⚠️ Note: For-Each is Read-Only by Default

int A[5] = {1, 2, 3, 4, 5};

for (int x : A) {
    cout<<++x;  // ❌ This does NOT change the actual array
}
If you want to modify elements, you must pass by reference:

✅ Example 2: Modifying Elements with Reference
#include <iostream>
int main() {
    int A[5] = {1, 2, 3, 4, 5};

    for (int& x : A) {
        cout<<++x;  // ✅ Now modifies original array
    }

    for (int x : A) {
        std::cout << x << " ";
    }

    return 0;
}
🧾 Output: 2 4 6 8 10

✅ Example 3: Using with std::vector
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {100, 200, 300};

    for (int x : v) {
        std::cout << x << " ";
    }

    return 0;
}

⚡ When to Use For-Each
✅ Use For-Each When…	        ❌ Avoid When…
You don’t need the index	    You need the position/index
You just want to read items	    You need to modify non-references
You work with STL containers	You need custom step size in loop

💡 CP Tip:
Great for reading or printing values.
Not useful if you need to compare current with previous element or do prefix sums.
*/


/*
For-each loop programs

1.Display all Elements using For Each loop when size not given

        #include<iostream>
        using namespace std;

        int main(){
            int A[]={2,4,6,8,10};
    
            for(int x:A){
                cout<<x<<" ";
            }   
        }


2.Display all Elements using For Each loop when partial initialized

        #include<iostream>
        using namespace std;

        int main(){
            int A[6]={2,4,6};
    
            for(int x:A){
                cout<<x<<" ";
            }   
        }
  output:2 4 6 0 0 0
  **As we can see it works on the basis of size of an array and nit on no. of elements initialized with

4.Display all Elements using For Each loop when float type 

        #include<iostream>
        using namespace std;

        int main(){
            float A[]={2.5f,5.6f,9,8,7};
    
            for(int x:A){
                cout<<x<<" ";
            }   
        }
    output:2,5,9,8,7

->when float x

        #include<iostream>
        using namespace std;

        int main(){
            float A[]={2.5f,5.6f,9,8,7};
    
            for(float x:A){
                cout<<x<<" ";
            }   
        }
    output:2.5,5.6,9,8,7

9, 8, and 7 are treated as floats implicitly, because:
	•	You declared the array as float A[].
	•	When you write 9, 8, or 7 in an initializer list for a float array, the compiler implicitly converts them to float.

⸻

⚠️ Behind the Scenes:

These values are integers by default, but:
	•	C++ sees they’re being used to initialize a float, so it converts them to 9.0f, 8.0f, and 7.0f.

✅ So why doesn’t it print 9.0, 8.0, 7.0?

Because:
	•	std::cout prints only the digits it needs to represent the number.
	•	Even though the values are floats internally, std::cout prints them like 9 or 8 if there’s no decimal part.
	•	This is purely a formatting thing, not a type issue.


instead of using int or float we can also write auto
-> When auto

        #include<iostream>
        using namespace std;

        int main(){
            float A[]={2.5f,5.6f,9,8,7};
    
            for(auto x:A){
                cout<<x<<" ";
            }   
        }
    output:2.5,5.6,9,8,7

5.Display all Elements using For Each loop when char type 

  #include<iostream>
        using namespace std;

        int main(){
            char A[]={'A',66,'C',68};
    
            for(auto x:A){
                cout<<x<<" ";
            }   
        }
    output:A B C D

-> for int

 #include<iostream>
        using namespace std;

        int main(){
            char A[]={'A',66,'C',68};
    
            for(int x:A){
                cout<<x<<" ";
            }   
        }
    output:65 66 67 68
*/

 #include<iostream>
        using namespace std;

        int main(){
            int A[]={2,4,6,8,10};
    
            for(int x:A){
                cout<<x<<" ";
            }   
        }
