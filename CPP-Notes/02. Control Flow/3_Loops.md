# Loops in C++

A **Loop** is a control structure that repeatedly executes a block of code until a specified condition becomes false.
Instead of writing the same code multiple times, loops allow us to automate repetitive tasks.

Example:

Without Loop

```cpp
cout << 1;
cout << 2;
cout << 3;
cout << 4;
cout << 5;
```

Using Loop

```cpp
for(int i = 1; i <= 5; i++)
{
    cout << i;
}
```

Both produce the same output.

---

# Types of Loops

```
Loops
│
├── while
├── do-while
├── for
└── Range-based for (for-each)
```

---

# Choosing the Right Loop

| Loop | Best Used When |
|------|----------------|
| while | Number of iterations is unknown |
| do-while | Body must execute at least once |
| for | Number of iterations is known |
| Range-based for | Traversing arrays or containers |

---

# 1. while Loop

The **while** loop is a **pre-tested loop**.

The condition is checked **before** the loop body executes.

If the condition is false initially, the loop body never executes.

---

# Syntax

```cpp
while(condition)
{
    // loop body
}
```

---

# 2. do-while Loop

The **do-while** loop is a **post-tested loop**.

The loop body executes first.

The condition is checked afterward.

Therefore,

the body executes **at least once**.

---

# Syntax

```cpp
do
{
    // loop body
}
while(condition);
```

Notice the semicolon after `while`.

---

# 3. for Loop

The **for** loop is the most commonly used loop.

Used when the number of iterations is known.

---

# Syntax

```cpp
for(initialization; condition; update)
{
    // body
}
```

---

# Flow

```
Initialization

↓

Condition

↓

Body

↓

Update

↓

Condition
```

Initialization executes only once.

Condition executes before every iteration.

Update executes after every iteration.

---

# Initialization and Update is Optional 

```cpp
int i = 1;

for(; i <= 5; )
{
    cout << i;

    i++;
}
```

Still works correctly.

---

# Multiple Initializations and Multiple Updates are allowed

Example

```cpp
for(int i = 0, j = 10; i < j; i++, j--)
{

}
```

---

# Multiple Conditions

Use logical operators.

Correct

```cpp
for(int i = 0, j = 5; i < 5 && j > 0; i++, j--)
{

}
```

---

# Comma in Condition

Avoid

```cpp
for(int i = 0, j = 5;
    i < 5, j > 0;
    i++, j--)
{

}
```

Only the **last expression** becomes the actual condition.

Prefer using

```
&&

or

||
```

instead.

---

# 4. Range-based for Loop

Introduced in **C++11**.

Also called the **for-each loop**.

Used for traversing arrays and containers.

---

# Syntax

```cpp
for(datatype variable : collection)
{

}
```

---

# Example

```cpp
int arr[] = {10,20,30,40};

for(int x : arr)
{
    cout << x << " ";
}
```

Output

```
10 20 30 40
```

---

# Advantages

- Cleaner syntax.
- No indexing required.
- Less chance of going out of bounds.
- Ideal for STL containers.

---
