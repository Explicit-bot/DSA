/*
🔹 Dynamic Allocation on Stack — Is It Possible?
In standard C++, stack memory is not dynamically resizable.
However, Variable Length Arrays (VLAs), which allow stack arrays with runtime sizes, are supported in C99 (standard C) and by some C++ compilers as an extension, but not in standard C++.

✅ Example: Variable Length Array (VLA) in Some Compilers

        int n;
        std::cin >> n;
        int arr[n];  // ❌ Not standard C++, but allowed in GCC/Clang with extensions
In GCC or Clang, this might work depending on compiler flags.
In MSVC (Microsoft Visual C++), this gives a compilation error.

➡️ It allocates the array on the stack, but size is taken at runtime — so it's "dynamic" in that sense.

❌ Not Standard C++
According to the C++ Standard:
 - Arrays must have a constant expression size (i.e., known at compile time).
 - So this is not portable or safe for production C++ code.

🔒 Why It’s Dangerous or Limited:
 - Stack has limited memory (usually 1MB–8MB), so large VLAs risk stack overflow.
 - You can’t resize it later anyway — it’s still fixed after creation.
 - You have no control over when memory is released (it ends when the function ends).

✅ Recommended: Use Heap for Dynamic Sizes
        int n;
        std::cin >> n;
        int* arr = new int[n];  // Allocated on heap

Now you can:
 - Resize (by creating new array)
 - Keep memory beyond the function (if needed)
 - Avoid platform/compiler dependence

*/

//program for dynamic allocation in stack

# include<iostream>
using namespace std;
    

int main(){

	int size;
	cout<<"enter no of element";
	cin>>size;
    //cannot change the size of array after input later unlike in heap
	int a[size];
	cout<<sizeof a<<endl;
    	return 0;
}        

