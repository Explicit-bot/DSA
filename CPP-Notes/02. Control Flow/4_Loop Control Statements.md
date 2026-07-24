# Loop Control Statements in C++

---

Sometimes we don't want a loop to execute normally.

We may want to:

- Stop the loop immediately.
- Skip the current iteration.
- Exit the current function.
- Terminate the entire program.

C++ provides special statements for controlling program flow.

---

# Loop Control Statements

```
Loop Control Statements
│
├── break
├── continue
├── return
└── exit()
```

Each statement affects a different level of program execution.

---

# Flow Hierarchy

```
Program
│
├── Function
│   │
│   ├── Loop
│   │   │
│   │   ├── Iteration
│   │   └── Iteration
│   │
│   └── Loop
│
└── Function
```

Each control statement exits a different level.

| Statement | Affects |
|-----------|---------|
| continue | Current Iteration |
| break | Current Loop |
| return | Current Function |
| exit() | Entire Program |

---

# 1. break Statement

The `break` statement immediately terminates the **nearest loop or switch statement**.

Once `break` executes,

control moves to the first statement after the loop.

---

# Syntax

```cpp
break;
```

---

# 2. continue Statement

The `continue` statement skips the **current iteration**.

The loop itself continues normally.

---

# Example

```cpp
for(int i = 1; i <= 5; i++)
{
    if(i == 3)
        continue;

    cout << i << " ";
}
```

Output

```
1 2 4 5
```

---

# continue with switch

`continue` **cannot** be used inside a standalone switch.

Wrong

```cpp
switch(x)
{
    case 1:
        continue;
}
```

Compilation Error.

Reason:

A switch is **not** a loop.

---

# switch Inside a Loop

```cpp
for(int i = 1; i <= 5; i++)
{
    switch(i)
    {
        case 3:
            continue;
    }

    cout << i << " ";
}
```

Output

```
1 2 4 5
```

`continue` skips the **loop iteration**, not the switch.

---

# 3. return Statement

The `return` statement immediately exits the **current function**.

It may optionally return a value.

---

# Example

```cpp
int add(int a, int b)
{
    return a + b;
}
```

The function returns

```
a + b
```

to the caller.

---

# 4. exit()

`exit()` immediately terminates the **entire program**.

Unlike `return`,

it can be called from **any function**.

---

# Header File

```cpp
#include <cstdlib>
```

---

# Exit Status

```cpp
exit(0);
```

Program terminated successfully.

---

```cpp
exit(1);
```

Program terminated due to an error.

---

| Statement | Scope |
|-----------|-------|
| continue | Current Iteration |
| break | Current Loop |
| return | Current Function |
| exit() | Entire Program |

---
