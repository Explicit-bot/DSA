/*
🔹 Heap Memory Allocation in C++
In C++, heap memory (also called dynamic memory) is memory that you allocate manually at runtime using the new operator, and deallocate with delete.
This is different from stack memory, where variables are automatically managed and destroyed when they go out of scope.

🧠 When to Use Heap Memory?
 - Use heap memory when:
 - You don’t know the size of data in advance
 - You want to allocate large memory
 - You need the data to persist beyond the current scope

✅ Syntax: Allocation & Deallocation
1. For Single Variable
    int *p = new int;      // allocate memory for one int
    *p = 10;               // assign value
    delete p;              // deallocate memory
2. For Array

    int *arr = new int[5];     // allocate array of 5 integers
    arr[0] = 1;
    arr[1] = 2;
    // ...
    delete[] arr;              // deallocate array memory
❗ Always use delete[] when using new[].

📊 Stack vs Heap Comparison
Feature	      Stack	                   Heap
Size Limit	  Limited	               Large (depends on system)
Allocation	  Automatically (static)   Manually (new)
Deallocation  Automatic	               Manual (delete)
Speed	      Faster	               Slower
Scope	      Ends with function/block Until delete or program ends

💡 Example: Dynamic Array

    #include <iostream>
    using namespace std;

    int main() {
        int n;
        cout << "Enter size: ";
        cin >> n;

        int* arr = new int[n];  // heap allocation

        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        delete[] arr;  // deallocation
        return 0;
    }

🛑 Common Mistakes to Avoid
 - Forgetting to delete → Memory leak
 - Using delete on stack memory → Undefined behavior
 - Using delete[] for memory created with new (without []) → Also undefined behavior

🔁 Smart Pointers (Modern C++)
In modern C++, it's better to use smart pointers like std::unique_ptr or std::shared_ptr to automatically manage heap memory.

Example:

    #include <memory>
    std::unique_ptr<int> p = std::make_unique<int>(10);

✅ Summary:
Task	            Code
Allocate	        int *p = new int;
Assign	            *p = 5;
Deallocate	        delete p;
Allocate array	    new int[n];
Deallocate arr	    delete[] p;


🔍 What is a Memory Leak?
A memory leak happens when:
 - You allocate memory on the heap using new (or malloc in C)
 - But forget to deallocate it using delete (or free)
This causes unused memory to remain occupied — your program loses access to it, but the system doesn’t reclaim it until the program exits.

❗ Example of a Memory Leak

        void leak() {
            int* p = new int(10);  // memory allocated
            // no delete -> memory leak!
        }

Every time leak() runs, it allocates memory without freeing it.

✅ How to Fix a Heap Memory Leak
🔸 1. Use delete / delete[] properly
Always deallocate any memory you've allocated manually.

        int* p = new int;
        *p = 5;
        delete p;  // FIXED

For arrays:

        int* arr = new int[10];
        // ...
        delete[] arr;  // FIXED

🔸 2. Use Smart Pointers (Modern C++)
Use std::unique_ptr or std::shared_ptr from <memory> to automatically manage memory.

✅ Example:

    #include <memory>

    std::unique_ptr<int> ptr = std::make_unique<int>(42);  
    // no need to delete

Smart pointers automatically delete the object when it goes out of scope. No leaks.

🔸 3. Use Tools to Detect and Fix Leaks
 - Valgrind (Linux/macOS)
 - Visual Studio Diagnostic Tools (Windows)
 - AddressSanitizer (Clang/GCC)
These tools show you exactly where memory is leaked and how much is lost.

🧠 Best Practices to Avoid Leaks
Practice	                    Why it Helps
Use smart pointers	            Auto memory management
Avoid raw new unless necessary	Prevents manual deallocation issues
Match every new with delete	    Manual fix
Use RAII                    	Cleanup tied to scope
(Resource Acquisition Is 
Initialization)

❌ Once a leak occurs...
You cannot recover that memory during program runtime unless you:
 - Still have a pointer to it → then you can delete it
 - Otherwise, it's lost until the program exits

✅ Final Verdict
Question	                        Answer
Can memory leaks be fixed?	      -  Yes, by proper deallocation
Can leaked memory be recovered?	-Only if pointer is stillaccessible
Best way to avoid leaks?	- Use smart pointers or delete properly

👉 If you set p = nullptr before calling delete p,
then the memory is leaked permanently — because the original address is lost, and you can no longer delete it.

🔍 Why?
Suppose you do this:

    int *p = new int(10);  // heap memory allocated
    p = nullptr;           // address is lost! 🔥

At this point:
 - The memory is still allocated on the heap
 - But the only pointer (p) that could free it is now nullptr
 - So you can’t delete it anymore
 - ✅ The program continues to run
 - ❌ But you've created a memory leak

🔥 Wrong Way — Causes Memory Leak

        int* p = new int(10);
        p = nullptr;       // leak! memory is lost forever
        // delete p;       // now does nothing, it's null

✅ Correct Way — No Leak

        int* p = new int(10);
        delete p;          // free memory first
        p = nullptr;       
        // optional but safe (avoids dangling pointer)

Setting p = nullptr after deleting is good practice:
 - Prevents dangling pointer
 - Avoids accidental re-use or double-delete

🔍 What happens to heap memory after the program ends?
Even if you leak heap memory (i.e., forget to delete it),
➡️ The operating system reclaims all memory when your program exits.

✅ So, no — leaked memory is not permanently lost to the system.
 - It's only unreachable during the program's lifetime.
 - After the program ends, the OS frees everything, including leaked memory.

🧠 So why are memory leaks still bad?
🔁 Long-running programs	
 - If your program runs for hours/days (like servers, games),leaks pile up and eat RAM.

📉 Performance
 - Leaks reduce available memory and can slow or crash your app.
❌ Lost control	
 - Memory leaks mean you lost control of what your program allocated.
🛠️ Debugging hell	
 - Hard to trace where leaks happen without tools.
*/
