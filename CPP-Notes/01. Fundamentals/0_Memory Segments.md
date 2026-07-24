# Memory Segments in C++

---

# Introduction

When a C++ program runs, the Operating System loads it into **RAM (Main Memory)**.

The memory used by the program is **not one large block**. Instead, it is divided into multiple sections called **Memory Segments**.

Each segment stores a specific type of data and has its own purpose.

> **Note:** The exact layout and ordering of these memory regions are **implementation-dependent** and may vary between operating systems, compilers, and executable formats. The diagram below is a **conceptual representation** used to understand how program memory is organized.

---

# Typical Memory Layout

```
                 High Memory
+-----------------------------+
|            Stack            |
|             ↓(grow)         |
|                             |
|                             |
|             ↑ (grow)        |
|             Heap            |
+-----------------------------+
|   Uninitialized Data (BSS)  |
+-----------------------------+
|     Initialized Data        |
+-----------------------------+
|     Read-Only Data (.rodata)|
+-----------------------------+
|      Code / Text (.text)    |
+-----------------------------+
                 Low Memory
```

> **Note:** The Stack typically grows downward toward lower memory addresses, while the Heap typically grows upward toward higher memory addresses. If both continue growing, they may eventually collide, resulting in memory allocation failure.

---

# Storage Duration vs Memory Segment

A **Memory Segment** describes **where** an object is typically stored in memory.

A **Storage Duration** describes **how long** that object exists during program execution.

These are related concepts but are **not the same**.

Examples:

- Local variables usually have **automatic storage duration** and are typically stored on the Stack.
- Global and static variables have **static storage duration** and are typically stored in the Data or BSS segments.
- Dynamically allocated objects have **dynamic storage duration** and are stored in the Heap.

---

# Main Memory Segments

A C++ program is commonly divided into the following memory segments:

| Segment | Stores |
|----------|--------|
| Code (Text) | Executable machine instructions |
| Initialized Data (.data) | Initialized global and static variables |
| BSS (.bss) | Uninitialized or zero-initialized global and static variables |
| Read-Only Data (.rodata) | String literals and other read-only data |
| Heap | Dynamically allocated memory |
| Stack | Function call frames and local variables |

---

# 1. Code (Text) Segment

The Code Segment stores the **compiled machine instructions** of the program.

Everything that represents executable code is stored here.

Example:

```cpp
int add(int a, int b)
{
    return a + b;
}
```

The compiled instructions of `add()` are stored in the Code Segment.

### Properties

- Read-only
- Can often be shared between multiple processes running the same executable (implementation-dependent)
- Exists throughout program execution

---

# 2. Initialized Data Segment (.data)

Stores:

- Initialized global variables
- Initialized static variables

Example:

```cpp
int x = 10;

static int y = 20;
```

Both variables are typically stored in the **Initialized Data Segment**.

### Properties

- Memory allocated before `main()` starts
- Exists until program terminates

---

# 3. BSS Segment (.bss)

**BSS** stands for:

```
Block Started by Symbol
```

Stores:

- Uninitialized global variables
- Uninitialized static variables
- Zero-initialized global/static variables

Example:

```cpp
int count;

static int total;
```

Although no explicit value is assigned, both variables are **zero-initialized before `main()` begins execution**.

---

# Initialized Data vs BSS

```cpp
int x = 5;     // Initialized Data (.data)

int y;         // BSS (.bss)
```

---

# 4. Read-Only Data Segment (.rodata)

Stores read-only program data.

Typically includes:

- String literals
- Many read-only global or static objects
- Many `const` global or static variables

Example:

```cpp
const int MAX = 100;

std::cout << "Hello";
```

On many implementations:

```
MAX
"Hello"
```

are placed in the **Read-Only Data Segment**.

> **Important:** Not every `const` variable is stored here.
>
> Local `const` variables usually reside on the Stack, and some constants may be optimized away entirely by the compiler.

### Properties

- Read-only
- Attempting to modify read-only memory results in **Undefined Behavior**

---

# String Literals

Example:

```cpp
const char* str = "Hello";
```

The string literal

```
"Hello"
```

is typically stored in the **Read-Only Data Segment**.

Attempting to modify it through a non-const pointer results in **Undefined Behavior**.

---

# 5. Stack Memory

The Stack typically stores:

- Function call frames
- Local variables with automatic storage duration
- Function parameters
- Return addresses
- Saved CPU registers

Example:

```cpp
void fun()
{
    int x = 10;
}
```

`x` is **typically** stored on the Stack.

---

# Stack Characteristics

- Automatically managed
- Very fast
- Limited size
- Memory released automatically when functions return

Typical stack size:

```
1 MB – 8 MB
```

(depends on the Operating System and compiler settings)

---

# Stack Example

```cpp
void display()
{
    int a = 5;
    int b = 10;
}
```

Conceptually:

```
Stack

+------+
|  b   |
+------+
|  a   |
+------+
```

> **Note:** The actual arrangement of variables inside a stack frame is implementation-dependent. The diagram is only conceptual.

When the function returns, both variables are destroyed automatically.

---

# Function Calls

Every function call creates a **Stack Frame**.

A stack frame typically contains:

- Local variables
- Function parameters
- Return address
- Saved registers

Example:

```cpp
int main()
{
    fun();
}
```

Conceptually:

```
Stack

+-----------+
|  fun()    |
+-----------+
|  main()   |
+-----------+
```

After `fun()` returns, its stack frame is removed automatically.

---

# Stack Overflow

The Stack has limited size.

Using too much stack memory causes a **Stack Overflow**.

Example:

```cpp
int arr[10000000];
```

or

```cpp
void fun()
{
    fun();
}
```

The recursive example keeps creating new stack frames until the Stack becomes full.

---

# 6. Heap Memory

The Heap stores **dynamically allocated memory**.

Memory is allocated at runtime using allocation functions such as `new` (or `malloc()` in C).

Example:

```cpp
int* ptr = new int;
```

or

```cpp
int* arr = new int[100];
```

The allocated objects are stored in the Heap.

---

# Heap Characteristics

- Large memory area
- Slower than the Stack
- Dynamically allocated at runtime
- Objects remain alive until explicitly deallocated (or until program termination)

---

# Releasing Heap Memory

```cpp
int* ptr = new int;

delete ptr;
```

Array:

```cpp
int* arr = new int[100];

delete[] arr;
```

Failure to release dynamically allocated memory can result in **Memory Leaks**.

> **Modern C++:** Smart pointers such as `std::unique_ptr` and `std::shared_ptr` are commonly used to automate memory management and reduce memory leaks.

---

# Stack vs Heap

| Stack | Heap |
|--------|------|
| Automatic management | Manual or smart-pointer management |
| Very fast | Generally slower |
| Smaller memory | Much larger memory |
| Stores function call frames | Stores dynamically allocated objects |
| Automatically released | Must be explicitly released (unless managed automatically) |

---

# Memory Leak

A **Memory Leak** occurs when dynamically allocated memory becomes unreachable by the program while still remaining allocated.

Example:

```cpp
int* ptr = new int;
```

If

```cpp
delete ptr;
```

is never called, the allocated memory cannot be reused during program execution.

The Operating System reclaims the memory when the process terminates, but until then, the program wastes memory.

---

# Lifetime of Variables

```cpp
int global = 5;
```

Exists:

```
Program Starts
       │
       ▼
Program Ends
```

---

```cpp
void fun()
{
    int x = 10;
}
```

Exists:

```
Function Starts
       │
       ▼
Function Ends
```

---

```cpp
int* ptr = new int;
```

Exists:

```
new
 │
 ▼
delete
```

---

# Memory Allocation Summary

| Variable Type | Typical Memory Segment |
|---------------|------------------------|
| Local Variable | Stack (typically) |
| Function Parameter | Stack (typically) |
| Global Variable | Initialized Data / BSS |
| Static Variable | Initialized Data / BSS |
| String Literal | Read-Only Data |
| `const` Global Variable | Usually Read-Only Data (implementation-dependent) |
| Dynamic Memory (`new`) | Heap |
| Functions | Code (Text) Segment |

---

# Important Points

- Every running C++ program uses multiple memory segments.
- Local variables with automatic storage duration are **typically** stored on the Stack.
- Dynamic memory is allocated on the Heap.
- Global and static variables are **not** stored on the Stack.
- Initialized global/static variables are stored in the **Initialized Data (.data)** segment.
- Uninitialized or zero-initialized global/static variables are stored in the **BSS (.bss)** segment.
- String literals are typically stored in the **Read-Only Data (.rodata)** segment.
- Executable machine instructions are stored in the **Code (Text)** segment.
- The Stack is automatically managed, while dynamically allocated Heap memory must be managed manually or through smart pointers.
- Memory leaks occur when dynamically allocated memory is never properly released.

---

# Note on Compiler Optimizations

The descriptions in these notes represent the **typical memory organization** of a C++ program.

Modern compilers are free to optimize storage locations whenever doing so does not change the observable behavior of the program.

For example:

- Some local variables may be stored in CPU registers instead of on the Stack.
- Some constant values may be embedded directly into machine instructions instead of occupying memory.
- Some objects may be optimized away entirely.
- The exact placement of objects in memory is implementation-dependent.

Therefore, these memory segments should be viewed as the conceptual model used by most modern systems rather than rigid rules that apply in every implementation.

---
