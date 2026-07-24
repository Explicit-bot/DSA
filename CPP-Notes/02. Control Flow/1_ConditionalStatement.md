# Conditional Statements in C++

Decision-making in C++ is done using **Conditional Statements**.

A condition always evaluates to either:  true or false

Based on the result, different blocks of code are executed.

---

# Types of Conditional Statements

```
Conditional Statements
│
├── if
├── if-else
├── else-if Ladder
├── Nested if
├── switch
└── Ternary Operator
```

---

# 1. if Statement

The simplest decision-making statement.

The block executes **only if the condition is true**.

Syntax

```cpp
if(condition)
{
    // statements
}
```

If the condition becomes false,

nothing is executed.

---

# 2. if-else Statement

Used when exactly **one of two blocks** should execute.

Syntax

```cpp
if(condition)
{
    // True Block
}
else
{
    // False Block
}
```

---

# 3. else-if Ladder

Used when multiple mutually exclusive conditions exist.

The compiler checks conditions from **top to bottom**.

The **first true condition** executes.

Remaining conditions are skipped.

Syntax

```cpp
if(condition1)
{

}
else if(condition2)
{

}
else if(condition3)
{

}
else
{

}
```

The first condition that becomes true stops further checking.We can have any number of else if in-between.

# Order Matters

Consider:

```cpp
int marks = 95;

if(marks >= 40)
{
    cout << "Pass";
}
else if(marks >= 90)
{
    cout << "Grade A";
}
```

Output

```
Pass
```

Although the student scored 95,

the first condition already became true.

Always write conditions from **most specific to least specific**.

---

# 4. Nested if

An `if` statement inside another `if` statement.

Used when one decision depends on another.

Syntax

```cpp
if(condition1)
{
    if(condition2)
    {

    }
}
```

---

# else-if vs Nested if

## else-if

Used when **only one case** should execute.

Example

```cpp
if(x > 0)

else if(x < 0)

else
```

---

## Nested if

Used when one condition depends on another.

Example

```cpp
if(age >= 18)
{
    if(hasID)
    {

    }
}
```

---

# Multiple if Statements

Sometimes multiple conditions should all be checked independently.

Example

```cpp
int x = 10;

if(x > 0)
    cout << "Positive ";

if(x % 2 == 0)
    cout << "Even";
```

Output

```
Positive Even
```

Both conditions execute.

---

# Multiple if vs else-if

### Multiple if

Every condition is checked.

```
if

if

if
```

All may execute.

---

### else-if

Only the first true condition executes.

```
if

else if

else if

else
```

Only one executes.

---

# Logical Operators with Conditions

Conditions can be combined using:

| Operator | Meaning |
|----------|---------|
| && | AND |
| \|\| | OR |
| ! | NOT |

---

# Logical AND

Returns true only if **both** conditions are true.

Example

```cpp
if(age >= 18 && age <= 60)
{
    cout << "Eligible";
}
```

---

# Logical OR

Returns true if **at least one** condition is true.

Example

```cpp
if(day == 6 || day == 7)
{
    cout << "Weekend";
}
```

---

# Logical NOT

Reverses the result.

Example

```cpp
if(!(age < 18))
{
    cout << "Adult";
}
```

---
