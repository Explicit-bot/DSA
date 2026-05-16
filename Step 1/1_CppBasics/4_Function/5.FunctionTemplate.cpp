/*
🔷 1. What is a Function Template?
A function template is a feature in C++ that lets you create a single function to work with multiple data types.

🔑 Instead of writing multiple functions for int, float, double, etc., a function template allows you to write it once, and the compiler generates the correct version at compile-time for each type used.

🔶 2. Syntax of Function Template
	template <typename T>
	T functionName(T arg1, T arg2) {
    	// Function logic
	}

✅ You can use class instead of typename — both are equivalent:
	template <class T>  // also valid

🔁 You can have multiple type parameters:
	template <typename T, typename U>
	void display(T a, U b);

🔷 3. Simple Example
*/
#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maximum(3, 7) << endl;         // int
    cout << maximum(4.5, 2.3) << endl;     // double
    cout << maximum('a', 'z') << endl;     // char
}
/*
🧾 Output:
7
4.5
z

🔶 4. How Does It Work?
When you call maximum(3, 7), the compiler sees that T is used with int, so it generates a version of the function like:
	int maximum(int a, int b) {
    	return (a > b) ? a : b;
	}
✅ This happens for every different type you use.

🔷 5. Function Template — Key Concepts
Feature						Description
Type Deduction				Compiler detects type of T automatically
Explicit Instantiation		You can force the type: maximum<int>(a, b)
Multiple Type Parameters	Use more than one type if needed
Overloading Support			You can overload template and non-template functions

🔷 6. Advanced Usage
✅ Template with Multiple Types:
	template <typename T1, typename T2>
	void printBoth(T1 a, T2 b) {
    	cout << a << " " << b << endl;
	}

🔷 7. Function Template Overloading
You can write multiple versions of a function, including templated and non-templated ones:
	template <typename T>
	T add(T a, T b) {
	    return a + b;
	}

	int add(int a, int b, int c) {
    	return a + b + c;
	}
🧠 The compiler chooses the best match based on function parameters.

🔷 8. Edge Cases & Pitfalls
Case									Explanation
max() gives error						It’s a macro in many systems; 
										rename to maximum()
Using different types in same call		Not allowed unless both are converted 
										to a common type
Overloading by return type				❌ Not possible 
										(return type is not part of signature)
Complex types (like class)				Initialization like T x = 0 fails 
										if T is not numeric

🔷 9. Default Arguments in Function Templates
✅ You can use default values in function parameters, but
❌ not in template type parameters (before C++20)

✅ Valid:
template <typename T>
void display(T value, int count = 1) {
    for (int i = 0; i < count; ++i)
        cout << value << endl;
}

🔷 10. class vs typename
Both are exactly the same in templates:
	template <class T>
	template <typename T>   // ✅ Both are valid
✅ typename is preferred in modern C++ because it’s more descriptive when referring to types.

🔷 11. Can We Initialize Template Variables?
Yes — but only if the type supports the value.
	template <typename T>
T sumArray(T arr[], int n) {
    T sum = 0;  // works for int, float, double
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    return sum;
}
⚠️ Fails for types like std::string, MyClass, etc.
✅ Use {} to safely initialize:
	T sum{}; // Default constructor initialization

🔷 12. STL Functions That Use Function Templates
STL uses templates heavily to work with any type:

Function			Purpose
std::swap<T>()		Swaps any two variables
std::sort<T>()		Sorts any type of container
std::max<T>()		Returns maximum element
🧠 STL functions are function templates under the hood!
*/

