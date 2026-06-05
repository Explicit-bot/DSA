/*
# C++ cerr and clog Complete Detailed Notes

# =========================================================

# 1. INTRODUCTION TO STREAMS

# =========================================================

Before understanding:

* `cerr`
* `clog`

you must first understand:

# What is a stream?

A stream is:

```text
A flow of data between a program and an input/output device.
```

Examples:

* keyboard → input stream
* monitor → output stream
* file → file stream

C++ uses streams for:

* input
* output
* logging
* error handling

---

# Standard Streams in C++

| Stream | Purpose        |
| ------ | -------------- |
| cin    | standard input |
| cout   | normal output  |
| cerr   | error output   |
| clog   | logging output |

Wide versions:

| Normal | Wide Version |
| ------ | ------------ |
| cin    | wcin         |
| cout   | wcout        |
| cerr   | wcerr        |
| clog   | wclog        |

# =========================================================

# 2. WHAT IS cerr?

# =========================================================

`cerr` means:

```text
character error stream
```

It is used for:

```text
URGENT ERROR OUTPUT
```

Examples:

* file open failure
* invalid input
* runtime problems
* crash information
* critical warnings
* debugging urgent issues

---

# Basic Syntax

```cpp
cerr << "Error occurred";
```

---

# Example Program

```cpp
#include <iostream>
using namespace std;

int main(){

    cerr << "File not found";
}
```

Output:

```text
File not found
```

# =========================================================

# 3. WHY cerr EXISTS

# =========================================================

You may think:

```text
Why not just use cout?
```

Because:

* normal output
* errors

are conceptually different.

Example:

```cpp
cout << "Answer = 42";
cerr << "Database connection failed";
```

These messages serve DIFFERENT purposes.

---

# cout

Used for:

```text
normal program output
```

Shown intentionally to user.

---

# cerr

Used for:

```text
urgent problems/errors
```

Mostly for:

* developers
* debugging
* monitoring
* diagnostics

# =========================================================

# 4. cerr IS UNBUFFERED

# =========================================================

This is one of the MOST IMPORTANT properties.

# What is buffering?

A buffer is:

```text
temporary memory storage
```

Normally output is:

1. stored temporarily
2. printed later

This improves performance.

---

# Example of Buffered Output

```cpp
cout << "Hello";
```

May not immediately appear.

---

# cerr Behavior

`cerr` is:

```text
UNBUFFERED
```

Meaning:

* output appears immediately

Example:

```cpp
cerr << "Fatal Error";
```

prints instantly.

# =========================================================

# 5. WHY cerr IS UNBUFFERED

# =========================================================

Because errors are urgent.

Suppose program crashes.

If error messages stayed in buffer:

* they might never appear.

Example:

```cpp
cerr << "Memory corruption detected";
```

must appear IMMEDIATELY before crash.

That is why:

* `cerr` flushes instantly.

# =========================================================

# 6. REAL USE CASES OF cerr

# =========================================================

# Example 1 : File Opening Error

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream file("data.txt");

    if(!file){
        cerr << "Cannot open file";
    }
}
```

---

# Example 2 : Invalid Input

```cpp
int age;

cin >> age;

if(age < 0){
    cerr << "Invalid age";
}
```

---

# Example 3 : Null Pointer

```cpp
if(ptr == nullptr){
    cerr << "Null pointer error";
}
```

---

# Example 4 : Debugging

```cpp
cerr << "x = " << x;
```

# =========================================================

# 7. stderr

# =========================================================

Internally:

| Stream | Connected To |
| ------ | ------------ |
| cout   | stdout       |
| cerr   | stderr       |

These are operating-system-level streams.

Even if both appear on terminal:

* they are DIFFERENT internally.

This is VERY important in:

* Linux
* shells
* scripting
* servers
* system programming

# =========================================================

# 8. REDIRECTION OF cerr

# =========================================================

Linux example:

```bash
./program 2> errors.txt
```

This redirects:

* stderr
* therefore cerr output

into:

```text
errors.txt
```

while normal output still stays on terminal.

This separation is one major reason `cerr` exists.

# =========================================================

# 9. WHAT IS clog?

# =========================================================

`clog` means:

```text
character log stream
```

Used for:

```text
LOGGING INFORMATION
```

This is one of the most important concepts in software engineering.

# =========================================================

# 10. WHAT IS LOGGING?

# =========================================================

Logging means:

```text
Recording information about program execution.
```

Logs help developers:

* track program behavior
* debug problems
* monitor systems
* analyze crashes
* inspect execution flow
* keep history of events

---

# Real Life Analogy

Think of logs like:

* CCTV recordings
* airplane black box
* hospital records
* school attendance register

They keep a HISTORY of what happened.

# =========================================================

# 11. EXAMPLES OF LOGS

# =========================================================

```text
Program Started
Database Connected
User Logged In
Cache Refreshed
API Request Received
```

These are NOT necessarily errors.

They are informational records.

# =========================================================

# 12. WHY clog EXISTS

# =========================================================

Programs need:

* user output
* errors
* logs

separately.

---

# Example

```cpp
cout << "Welcome User";
clog << "Database connected";
cerr << "Database failure";
```

Each stream has DIFFERENT purpose.

# =========================================================

# 13. clog IS BUFFERED

# =========================================================

Unlike `cerr`:

```text
clog is BUFFERED
```

Meaning:

* messages may stay temporarily in memory
* printed later

# =========================================================

# 14. WHY clog IS BUFFERED

# =========================================================

Because logs are:

* frequent
* large
* not urgent

Imagine a web server printing:

```text
Request received
```

millions of times.

Immediate printing every time would slow program heavily.

Buffering improves performance.

# =========================================================

# 15. REAL USE CASES OF clog

# =========================================================

# Example 1 : Program Start

```cpp
clog << "Program started";
```

---

# Example 2 : User Login

```cpp
clog << "User authenticated";
```

---

# Example 3 : Database Events

```cpp
clog << "Database connected";
```

---

# Example 4 : Debugging Flow

```cpp
clog << "Reached function A";
```

---

# Example 5 : Performance Monitoring

```cpp
clog << "Execution time = " << time;
```

# =========================================================

# 16. REAL SOFTWARE LOGGING

# =========================================================

Large applications generate:

* millions
* billions

of log messages.

Examples:

* banking systems
* operating systems
* browsers
* cloud servers
* games

Logs are extremely important.

# =========================================================

# 17. WHERE LOGS GO

# =========================================================

Beginner programs:

* print logs on terminal

Professional software:

* saves logs to files
* sends logs to servers
* stores logs in cloud systems

Examples:

* app.log
* server.log
* monitoring systems

# =========================================================

# 18. PROFESSIONAL LOGGING

# =========================================================

Real logging systems add:

* timestamps
* severity levels
* thread ids
* file names
* function names

Example:

```text
[INFO] Server Started
[WARNING] High Memory Usage
[ERROR] Database Failed
```

# =========================================================

# 19. LOG LEVELS

# =========================================================

| Level   | Meaning            |
| ------- | ------------------ |
| INFO    | normal information |
| DEBUG   | debugging info     |
| WARNING | suspicious issue   |
| ERROR   | serious issue      |
| FATAL   | crash-level issue  |

# =========================================================

# 20. DIFFERENCE BETWEEN clog AND cerr

# =========================================================

| Feature   | clog               | cerr            |
| --------- | ------------------ | --------------- |
| Meaning   | logging stream     | error stream    |
| Purpose   | execution records  | urgent problems |
| Buffered? | Yes                | No              |
| Urgent?   | No                 | Yes             |
| Main Use  | tracking/debugging | failures/errors |

---

# Simple Analogy

## clog

```text
Diary / black box / records
```

## cerr

```text
Emergency alarm
```

# =========================================================

# 21. FULL EXAMPLE

# =========================================================

```cpp
#include <iostream>
using namespace std;

int main(){

    clog << "Program Started\n";

    int x = 10;

    clog << "x initialized\n";

    if(x == 10){
        clog << "Condition True\n";
    }

    if(x < 0){
        cerr << "Negative value detected\n";
    }

    cout << "Program Finished\n";
}
```

Possible Output:

```text
Program Started
x initialized
Condition True
Program Finished
```

If error occurs:

```text
Negative value detected
```

appears IMMEDIATELY.

# =========================================================

# 22. IMPORTANT BUFFERING DIFFERENCE

# =========================================================

| Stream | Buffered? |
| ------ | --------- |
| cout   | Yes       |
| clog   | Yes       |
| cerr   | No        |

---

# Buffered Means

```text
Store temporarily before printing
```

---

# Unbuffered Means

```text
Print immediately
```

# =========================================================

# 23. FINAL CORE UNDERSTANDING

# =========================================================

# cout

```text
Normal communication with USER
```

---

# clog

```text
Internal program records/history/logs
```

Used for:

* monitoring
* debugging
* tracking execution

---

# cerr

```text
Urgent error reporting
```

Used for:

* crashes
* failures
* critical problems

---

# Most Important Distinction

The difference is NOT:

```text
"Which one prints?"
```

because:

* all can print

The real difference is:

```text
WHY the information is being printed.
```

*/
