# Switch Statement and Ternary Operator in C++

---

Sometimes we need to choose **one action from many possible choices**.

Using multiple `if-else` statements can make the code long and difficult to read.

For such situations, C++ provides the **switch statement**.

For simple two-way decisions, C++ also provides the **Ternary Operator**, which is a shorter form of `if-else`.

---

# switch Statement

The `switch` statement selects one block of code from multiple choices based on the value of an expression.

Instead of checking multiple conditions one by one,

the program directly jumps to the matching case.

---

# Syntax

```cpp
switch(expression)
{
    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    default:
        // statements
}
```

The value after `case` must be a **constant expression**.

The `default` block executes if no case matches.

The `default` block is optional but recommended.

---

# break Statement

The `break` statement exits the switch immediately.

Example

```cpp
case 2:
    cout << "Tuesday";
    break;
```

Without `break`,

execution continues into the next case.

Example:

```cpp
switch(day)
{
    case 1:
        cout << "Monday";

    case 2:
        cout << "Tuesday";

    case 3:
        cout << "Wednesday";
}
```

Input

```
1
```

Output

```
Monday
Tuesday
Wednesday
```

This happens because execution continues into the next cases.

This behavior is called **Fall-through**.

---

# Data Types Allowed

The expression must evaluate to an **integral type**.

Allowed:

- int
- char
- bool
- enum

Example

```cpp
char grade = 'A';

switch(grade)
{

}
```

---

# enum with switch

`switch` works very well with enumerations.

Example

```cpp
enum Day
{
    Monday = 1,
    Tuesday,
    Wednesday
};

Day today = Tuesday;

switch(today)
{
    case Monday:
        cout << "Monday";
        break;

    case Tuesday:
        cout << "Tuesday";
        break;

    default:
        cout << "Other Day";
}
```

Using enums improves readability.

---

# Limitations of switch

- The following are **not allowed** directly:

    ```cpp
    double

    float

    string
    ```

- Every case value must be unique.
- Case labels must be known at compile time.

---

# Ternary Operator

The Ternary Operator is a shorter form of `if-else`.

It is called **ternary** because it uses **three operands**.

---

# Syntax

```cpp
condition ? expression1 : expression2;
```

Meaning

If condition is true,

execute

```
expression1
```

Otherwise,

execute

```
expression2
```

---

# Example

```cpp
int age = 20;

string status = (age >= 18)
                ? "Adult"
                : "Minor";
```

Output

```
Adult
```

---

# Equivalent if-else

```cpp
string status;

if(age >= 18)
{
    status = "Adult";
}
else
{
    status = "Minor";
}
```

Both produce the same result.

---

# Nested Ternary

Nested ternary operators are possible.

But, nested ternaries reduce readability.

Prefer `if-else` for complex logic.

---
