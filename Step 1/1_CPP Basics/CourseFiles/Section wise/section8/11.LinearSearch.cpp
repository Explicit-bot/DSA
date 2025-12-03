/*
 What is Linear Search?
Linear Search is the simplest searching algorithm that checks each element one by one from start to end until the desired element is found or the array ends.

✅ Use Cases
 - Searching in unsorted arrays
 - First-time learners
 - Suitable for small datasets
 - When ease of implementation > performance

 💡 Code Example — Basic Form

		#include <iostream>
		using namespace std;

		int linearSearch(int arr[], int n, int key) {
    		for (int i = 0; i < n; ++i) {
        		if (arr[i] == key) {
           		 return i;  // Return index where found
       		 	}
    		}
    		return -1;  // Not found
		}

		int main() {
    		int arr[] = {4, 2, 9, 7, 1};
    		int key = 9;
    		int size = sizeof(arr) / sizeof(arr[0]);

    		int index = linearSearch(arr, size, key);
    		if (index != -1)
    		    cout << "Found at index: " << index << endl;
    		else
     		   cout << "Element not found.\n";
		}
			   
🔁 Range-Based for Loop Version

		#include <iostream>
		using namespace std;

		int main() {
    		int arr[] = {10, 20, 30, 40};
    		int key = 30;
    		int idx = 0;
    		bool found = false;

		    for (int x : arr) {
        		if (x == key) {
            		found = true;
            		break;
        		}
        		++idx;
    		}

		    if (found)
        		cout << "Element found at index: " << idx << endl;
    		else
        		cout << "Element not found.\n";
		}


🧮 Find All Occurrences

		#include <iostream>
		#include <vector>
		using namespace std;

		int main() {
		    int arr[] = {5, 3, 7, 3, 9, 3};
		    vector<int> indices;
		    int key = 3;

 		    for (int i = 0; i < 6; ++i) {
 		        if (arr[i] == key) {
  		          indices.push_back(i);
 		        }
  		    }

   		 	if (indices.empty()) {
   		     	cout << "Not found\n";
   		 	} 
			else {
   		     	cout << "Found at indices: ";
   		     	for (int i : indices) cout << i << " ";
   		 		}
		}

🧪 Edge Cases
Input Case					Expected Output
Empty array					Not found (-1)
Single element match		Found at index 0
Multiple matches			Return all or first
Not found					Return -1

🧵 Can You Use on Other Types?
Yes!
Works on:
 - strings (find a char or substring)
 - std::vector
 - 2D arrays (loop row/col)

Example with string:

		#include <iostream>
		using namespace std;

		int main() {
		    string str = "linearsearch";
		    char target = 'e';

		    for (int i = 0; i < str.length(); ++i) {
		        if (str[i] == target) {
		            cout << "Found at position: " << i << endl;
		            break;
 		       }
		    }
		}

❌ Disadvantages
 - Inefficient on large datasets
 - Should not be used when:
 		The array is sorted
		Frequent lookups are needed (use hashing or binary search instead)

🔄 Linear Search vs Binary Search
Feature					Linear Search				Binary Search
Works on Sorted?		❌ Not required			   ✅ Must be sorted
Time (Worst)			O(n)						O(log n)
Simpler to code			✅ Yes					   ❌ More logic
Use for CP				❌ Slow					   ✅ Fast

📘 Best Practices (for CP & Real Use)
 - Use only for small or unsorted inputs
 - Always return -1 or a flag if not found
 - Use functions for reuse
 - For multiple queries → use map/set instead

🔍 Competitive Programming Tips
 - Most problems require logarithmic time
 - You’ll often lose time/points using linear search where binary search or hashing was expected
 - For strings, use find() or std::search()
*/

//program for linear search of array element

# include<iostream>
using namespace std;
    


int main()
{
 	int a[10]{};
	int n{10};
	int key;
	
	cout<<"enter numbers:";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	cout<<"enter key";
	cin>>key;
	for(int i=0;i<n;i++)
	{
		if(key==a[i])
		{
			cout<<"found at"<<i;
			return 0;
		}
	}	
	cout<<"not found";
	return 0;
}		



/*
		#include <iostream>
		using namespace std;

		int linearSearch(int arr[], int n, int key) {
    		for (int i = 0; i < n; ++i) {
        		if (arr[i] == key) {
           		 return i;  // Return index where found
       		 	}
    		}
    		return -1;  // Not found
		}

		int main() {
    		int arr[] = {4, 2, 9, 7, 1};
    		int key = 9;
    		int size = sizeof(arr) / sizeof(arr[0]);

    		int index = linearSearch(arr, size, key);
    		if (index != -1)
    		    cout << "Found at index: " << index << endl;
    		else
     		   cout << "Element not found.\n";
		}

🔎 Code Example:(Line 196)

		int arr[] = {10, 20, 30, 40, 50};
		int size = sizeof(arr) / sizeof(arr[0]);

🧠 What happens in memory:
Assume you are on a system where:
	int is 4 bytes
	arr[] has 5 integers

1. sizeof(arr)
Total memory occupied by entire array:
	5 elements × 4 bytes each = 20 bytes
	So sizeof(arr) = 20
2. sizeof(arr[0])
This is the size of the first element of the array
	arr[0] = 10 → which is an int → 4 bytes
	So sizeof(arr[0]) = 4

🔢 Final Calculation:

		size = sizeof(arr) / sizeof(arr[0]) 
     		 = 20 / 4 
     		 = 5

✔️ So size becomes 5, which is the number of elements in the array.

⚠️ Why this only works in the same function?
If you pass arr to a function, it decays to a pointer:

		void myFunc(int arr[]) {
    		sizeof(arr);  // ❌ This is now size of pointer (usually 8 bytes)
		}

So use this technique only in the scope where the array is defined.

✅ Tip for Dynamic Arrays (e.g., vectors):
For a vector, just use:

		std::vector<int> v = {10, 20, 30};
		std::cout << v.size();  // Outputs 3

*/
