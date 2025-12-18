/*
🧠 Memory Segments in C++
C++ program memory is typically divided into 5 segments:
Segment                     Stores                              Example
🔹 Stack                 Local variables, function calls        int x = 5; in main()

🔸 Heap                  Dynamically allocated memory           new int[n]

🟣 Static/Global         Static & global variables              static int a = 10;

⚫ Code/Text             Machine code (functions)               Compiled code itself

🟢 Constants             String literals, const values          const int x = 10;

🔹 1. Stack Memory
	•	Stores local variables inside functions.
	•	Automatically managed.
	•	Fast but limited size (~1MB - 8MB).
	•	Memory is freed automatically when the function returns.
✅ Example:
        void fun() {
            int x = 5;  // Stored in stack
        }
💥 Stack Overflow:
Too many or too large arrays on the stack can cause a stack overflow:
        int arr[10000000];  // ❌ Stack overflow

🔸 2. Heap Memory
	•	Used for dynamic memory allocation (new, malloc).
	•	You must manually deallocate (delete, free).
	•	Bigger size than stack (in GBs).
	•	Slower than stack.

✅ Example:
        int* arr = new int[1000000];  // Stored in heap
        delete[] arr;  // Must manually free memory

🟣 3. Static / Global Memory
	•	Stores:
	•	Global variables
	•	Static local variables
	•	Exists for entire duration of the program.
	•	Automatically initialized to 0.

✅ Example:
        int x = 10;           // Global variable → static segment
        
        void fun() {
            static int y = 5; // Static local variable → static segment
        }

⚫ 4. Code (Text) Segment
	•	Stores the actual compiled machine code of your program.
	•	Read-only.

✅ Example:
        int sum(int a, int b) {
            return a + b;  // This code is in text/code segment
        }

🟢 5. Constant Segment
	•	Stores:
	•	String literals ("hello")
	•	const global variables

✅ Example:
        const int PI = 3.14;    // Read-only memory
        std::cout << "Hello";   // "Hello" stored in constant segment

✅ Read-Only Section of Memory
 - Sometimes called the Constant Segment
 - It is marked as read-only by the OS/Compiler, but it is not actual ROM hardware
*/
