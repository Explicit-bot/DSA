/*First study Pointer_1.cpp
============================================================
🔹 Dynamic Allocation on STACK (VLAs)
============================================================
❓ Is dynamic allocation on stack possible?
❌ NOT in standard C++
⚠️ Possible only via compiler extensions (VLAs)

------------------------------------------------------------
🧠 What is a Variable Length Array (VLA)?
------------------------------------------------------------
A Variable Length Array (VLA) is an array whose size is decided
at runtime BUT allocated on the STACK.

➡️ It allocates the array on the stack, but size is taken at runtime — so it's "dynamic" in that sense.

Example (GCC / Clang extension only):

    int n;
    cin >> n;
    int arr[n];   // ❌ Not standard C++

------------------------------------------------------------
📜 C++ Standard Rule
------------------------------------------------------------
According to the C++ standard:
- Array size MUST be a constant expression
- Runtime-sized stack arrays are NOT allowed

So this is illegal in standard C++:

    int n;
    cin >> n;
    int arr[n];   // ❌ non-standard

------------------------------------------------------------
🖥️ Compiler Support
------------------------------------------------------------
GCC / Clang (Linux, Mac):
    ✅ Works (extension)

MSVC (Windows / Visual Studio):
    ❌ Compilation ERROR

⚠️ Hence: NOT portable

------------------------------------------------------------
🧠 Key Properties of VLAs
------------------------------------------------------------
✔ Allocated on stack
✔ Size decided at runtime
✔ Fast access
❌ Cannot resize
❌ Lifetime limited to scope
❌ Stack size is limited (~1MB–8MB)
❌ NOT standard C++

------------------------------------------------------------
⚠️ Why VLAs Are Dangerous
------------------------------------------------------------
- Large VLAs → stack overflow
- No resizing
- No manual memory control
- Compiler-dependent behavior

============================================================
🔹 Dynamic Allocation on HEAP
============================================================

📦 What is a Dynamic Array?
------------------------------------------------------------
A dynamic array is allocated on the HEAP using `new`.

Example:

    int n;
    cin >> n;
    int* arr = new int[n];

------------------------------------------------------------
🧠 Properties of Heap Allocation
------------------------------------------------------------
✔ Size decided at runtime
✔ Much larger memory than stack
✔ Memory lives until manually deleted
✔ Portable & standard C++
❌ Must manually free memory

------------------------------------------------------------
🔁 Resizing a Heap Array (IMPORTANT)
------------------------------------------------------------
❌ WRONG WAY (causes MEMORY LEAK):
    arr = new int[newSize];

Reason:
- Old memory is lost
- delete[] was never called

✅Correct Way:
    int* A = new int[n];
        // use A
    delete[] A;             // free old memory
    A = new int[2*n];       // resize by creating a new one

------------------------------------------------------------
✅ Best Practice (Modern C++)
------------------------------------------------------------
Prefer:

    vector<int> v(n);

✔ Automatic memory management
✔ Resizable
✔ Safe
✔ Standard C++

🔥 Final Verdict:
VLAs = compiler hacks ❌  
Heap / vector = real C++ ✅
============================================================
*/
