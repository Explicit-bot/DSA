/*
1. INTRODUCTION TO STREAMS
A stream is: A flow of data between a program and an input/output device.

Examples:
* keyboard → input stream
* monitor → output stream
* file → file stream

Standard Streams in C++:
| Stream |Wide Version | Purpose        |
| ------ |------------ | -------------- |
| cin    | wcin        | standard input |
| cout   | wcout       | normal output  |
| cerr   | wcerr       | error output   |
| clog   | wclog       | logging output |

-----------------------------------------------------------------------------------------

2.cerr
cerr means: character error stream
It is used for Urgent error reporting
Examples:
* file open failure
* invalid input
* runtime problems
* crash information
* critical warnings
* debugging urgent issues

Used for:
* crashes
* failures
* critical problems



Basic Syntax:
    cerr << "Error occurred";

# WHY cerr EXISTS
Because:
* normal output
* errors
are conceptually different.

Example:
    cout << "Answer = 42";
    cerr << "Database connection failed";
These messages serve DIFFERENT purposes.

# cerr is used for urgent problems/errors mostly for:
* developers
* debugging
* monitoring
* diagnostics

# cerr IS UNBUFFERED, meaning: output appears immediately
 Example:
    cerr << "Fatal Error";      //prints instantly.

# A buffer is temporary memory storage
Normally output is:
1. stored temporarily
2. printed later
This improves performance.

# WHY cerr IS UNBUFFERED?
Because errors are urgent.
Suppose program crashes.
If error messages stayed in buffer they might never appear.

Example:
    cerr << "Memory corruption detected";
must appear IMMEDIATELY before crash.
That is why cerr flushes instantly.

# REAL USE CASES OF cerr
Example 1 : File Opening Error
    #include <iostream>
    #include <fstream>
    using namespace std;

    int main(){

        ifstream file("data.txt");

        if(!file){
            cerr << "Cannot open file";
        }
    }

Example 2 : Invalid Input
    int age;

    cin >> age;

    if(age < 0){
        cerr << "Invalid age";
    }

Example 3 : Null Pointer
    if(ptr == nullptr){
        cerr << "Null pointer error";
    }

Example 4 : Debugging
    cerr << "x = " << x;

# stderr
Internally:
| Stream | Connected To |
| ------ | ------------ |
| cout   | stdout       |
| cerr   | stderr       |
These are operating-system-level streams.
Even if both appear on terminal they are DIFFERENT internally.

# REDIRECTION OF cerr

Linux example:
    ./program 2> errors.txt
This redirects:
* stderr
* therefore cerr output into errors.txt while normal output still stays on terminal.
This separation is one major reason cerr exists.

-----------------------------------------------------------------------------------------

3. clog
clog means: character log stream
Used for : 
* Internal program records/history/logs
* monitoring
* debugging
* tracking execution

# WHAT IS LOGGING?
Logging means: Recording information about program execution.
Logs help developers:
* track program behavior
* debug problems
* monitor systems
* analyze crashes
* inspect execution flow
* keep history of events

# Real Life Analogy
Think of logs like:
* CCTV recordings
* airplane black box
* hospital records
* school attendance register
They keep a HISTORY of what happened.

# EXAMPLES OF LOGS
    Program Started
    Database Connected
    User Logged In
    Cache Refreshed
    API Request Received

These are NOT necessarily errors.
They are informational records.

# WHY clog EXISTS
Programs need:
* user output
* errors
* logs
separately.

Example:-
    cout << "Welcome User";
    clog << "Database connected";
    cerr << "Database failure";

Each stream has DIFFERENT purpose.

# clog IS BUFFERED
Unlike cerr clog is BUFFERED
Meaning:
* messages may stay temporarily in memory
* printed later

# WHY clog IS BUFFERED
Because logs are:
* frequent
* large
* not urgent

Imagine a web server printing:
    Request received
    millions of times.

Immediate printing every time would slow program heavily.
Buffering improves performance.

# REAL USE CASES OF clog
Example 1 : Program Start
    clog << "Program started";

Example 2 : User Login
    clog << "User authenticated";

Example 3 : Database Events
    clog << "Database connected";

Example 4 : Debugging Flow
    clog << "Reached function A";

Example 5 : Performance Monitoring
    clog << "Execution time = " << time;

# WHERE LOGS GO
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

# PROFESSIONAL LOGGING
Real logging systems add:
* timestamps
* severity levels
* thread ids
* file names
* function names

Example:
    [INFO] Server Started
    [WARNING] High Memory Usage
    [ERROR] Database Failed

# LOG LEVELS
| Level   | Meaning            |
| ------- | ------------------ |
| INFO    | normal information |
| DEBUG   | debugging info     |
| WARNING | suspicious issue   |
| ERROR   | serious issue      |
| FATAL   | crash-level issue  |
*/
