/*
        #include <iostream>

        int main() {
           int size;

         std::cout << "Enter the size of the array: ";
         std::cin >> size;

          // Dynamic allocation of array in heap
         int* arr = new int[size];  // allocate memory

          // Taking input
          std::cout << "Enter " << size << " elements:\n";
          for (int i = 0; i < size; ++i) {
              std::cout << "Element " << i << ": ";
              std::cin >> arr[i];
          }

          // Displaying the array
          std::cout << "You entered:\n";
           for (int i = 0; i < size; ++i) {
               std::cout << arr[i] << " ";
           }
           std::cout << std::endl;


            //Changing the size of array 
            //cannot change the size of array after input later if in       allocatted in stack but in heap we can
            std::cout<<"Enter new size:";
            std::cin>>size;
            arr=new int[size];

            // Freeing the allocated memory
            delete[] arr;

            return 0;
        }


there's a major issue in the part where you're changing the array size using new again without freeing the previously allocated memory first.

Here’s a line-by-line review and correction:

✅ Your original logic (first half):
This part is correct:

int* arr = new int[size];
...
for (int i = 0; i < size; ++i)
    std::cin >> arr[i];
👍 You're dynamically allocating and using a heap array correctly.

⚠️ Issue with Resizing:
This part:
arr = new int[size];
overwrites the previous pointer without delete[] — this causes a memory leak.

✅ Correct Way to Resize (with deletion):

delete[] arr;  // Free the original array
std::cout << "Enter new size: ";
std::cin >> size;
arr = new int[size];  // Allocate new memory

💡 Optionally: Copy old data before resizing
If you want to retain previous values when resizing:

int* newArr = new int[newSize];
for (int i = 0; i < std::min(oldSize, newSize); ++i)
    newArr[i] = arr[i];

delete[] arr;
arr = newArr;
✅ Final Correct Version:
*/
#include <iostream>

int main() {
    int size;

    // Ask user for the initial size of the array
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    // Dynamically allocate memory for the array in the heap
    int* arr = new int[size];

    // Take input for each element of the array
    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": ";
        std::cin >> arr[i];
    }

    // Display the entered elements
    std::cout << "You entered:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 🔁 We now want to change the size of the array
    // 🧹 First, deallocate previously allocated memory to avoid memory leaks
    delete[] arr;

    // Ask user for the new size of the array
    std::cout << "Enter new size: ";
    std::cin >> size;

    // Allocate a new array of the new size
    arr = new int[size];

    // Take input again for the new array
    std::cout << "Enter " << size << " new elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i << ": ";
        std::cin >> arr[i];
    }

    // Display the new elements
    std::cout << "New elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Final cleanup: deallocate memory to avoid memory leak
    delete[] arr;

    return 0;
}
/*
🧠 Summary:
 - ✅ Always delete[] before reassigning new memory to avoid memory leaks.
 - ✅ In heap, you can "resize" an array by allocating a new one.
 - ❌ You cannot do this with stack arrays.
*/
