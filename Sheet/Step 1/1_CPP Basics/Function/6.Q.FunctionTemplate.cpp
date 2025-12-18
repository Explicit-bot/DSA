/*
Q1-In C++, the keywords class and typename are mostly interchangeable in the context of templates, but they do have some differences in specific scenarios.
Answer-
✅ In Template Parameter Lists: Both Are the Same
    template <class T>
    void func1(T arg) { }

    template <typename T>
    void func2(T arg) { }

🔸 Meaning:
•Both define a template with a type parameter T.
•There is no difference in meaning or behavior.
•You can use either class or typename — it’s a matter of style or convention.

✅ Both are equivalent.
✅ Both work with types (like int, std::string, user-defined classes, etc.).

🧠 So Why Two Keywords?
Originally:
class was used in templates since C++98.
Later, C++ introduced typename to clarify dependent types (more on this next).

⚠️ Key Difference: Inside Template Definitions with Dependent Types
When referring to a nested dependent type, only typename can be used.
template <typename T>
void func() {
    typename T::value_type x; // ✅ MUST use 'typename' here
}

❌ This is a compile-time error:
    template <typename T>
    void func() {
        class T::value_type x; // ❌ Error!
    }

🧠 Why?
The compiler doesn’t know whether T::value_type is a type or a static variable until template instantiation.
You must use typename to tell the compiler it’s a type.

✅ Example Showing Both
    template <class T, typename U>
    class MyClass {
        typename T::value_type val;  // ✅ Required when accessing nested type
        U data;
    };

🧠 Best Practice:
Use typename when accessing nested types inside templates.
Either class or typename for template parameters — just stay consistent in your codebase or team.

❓ Q2. Why is max() function giving an error?
Because max is a macro in some libraries. It can interfere with your template.
✅ Solution: Rename it to something like maximum().

❓ Q3. Can we use default arguments with function templates? ***
Yes ✅ — but only in function parameters, not in template types (before C++20).
template <typename T>
void show(T val, int count = 1) {
    for (int i = 0; i < count; ++i)
        cout << val << endl;
}

❓ Q4. What's the difference between typename and class?
None — both are identical when declaring templates.
template <class T>      // valid
template <typename T>   // also valid
✅ Use typename to make it clearer you are declaring a type.

❓ Q5. Can we initialize template variables?
Yes — if the type supports that value.
	T sum = 0;   // Works if T can be assigned 0
	T sum{};     // Safe default for all types
✅ Prefer T x{} to avoid errors with non-numeric types.
*/
