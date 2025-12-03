/*
int A[]; is correct because in C and C++, when declaring an array without specifying its size, you must initialize it with values. Without a size or initialization, the declaration is considered invalid.

✅ 1. Array Declaration Without Initialization
#include <iostream>
int main() {
    int A[5];  // Declared but not initialized — contains garbage values

    for (int i = 0; i < 5; ++i)
        std::cout << "A[" << i << "] = " << A[i] << '\n';

    return 0;
}

✅ 2. Array Declaration With Partial Initialization
#include <iostream>
int main() {
    int A[5] = {2, 4};  // First 2 values set, rest are 0

    for (int i = 0; i < 5; ++i)
        std::cout << "A[" << i << "] = " << A[i] << '\n';

    return 0;
}
🧠 Output: 2 4 0 0 0 — because unspecified values get 0.


✅ 3. Array Declaration With Complete Initialization
#include <iostream>
int main() {
    int A[5] = {2, 4, 6, 8, 10};

    for (int i = 0; i < 5; ++i)
        std::cout << "A[" << i << "] = " << A[i] << '\n';

    return 0;
}

✅ 4. Compiler-Sized Array Declaration

#include <iostream>
int main() {
    int A[] = {10, 20, 30, 40};  // Compiler sets size to 4

    for (int i = 0; i < 4; ++i)
        std::cout << A[i] << '\n';

    return 0;
}
🧠 This is useful when you're just initializing and don't want to count manually.


✅ 5. Accessing Array Elements via Index
#include <iostream>
int main() {
    int A[5] = {1, 2, 3, 4, 5};

    std::cout << "First element: " << A[0] << '\n';
    std::cout << "Third element: " << A[2] << '\n';
    std::cout << "Last element: " << A[4] << '\n';

    return 0;
}

✅ 6. Modify Array Elements
#include <iostream>
int main() {
    int A[5] = {1, 2, 3, 4, 5};

    A[2] = 10;  // Modify 3rd element

    for (int i = 0; i < 5; ++i)
        std::cout << A[i] << ' ';

    return 0;
}

✅ 7. Input Values From User
#include <iostream>
int main() {
    int A[5];

    std::cout << "Enter 5 numbers:\n";
    for (int i = 0; i < 5; ++i)
        std::cin >> A[i];

    std::cout << "You entered:\n";
    for (int i = 0; i < 5; ++i)
        std::cout << A[i] << ' ';

    return 0;
}

✅ 8. Print in Reverse Order
#include <iostream>
int main() {
    int A[5] = {10, 20, 30, 40, 50};

    std::cout << "Reverse: ";
    for (int i = 4; i >= 0; --i)
        std::cout << A[i] << ' ';

    return 0;
}

✅ 9. Invalid Index Access (Avoid This)
#include <iostream>
int main() {
    int A[5] = {1, 2, 3, 4, 5};

    std::cout << A[10];  // ❌ Undefined behavior!

    return 0;
}

🔴 Important: C++ has no bounds checking. Accessing A[10] will lead to undefined behavior.

⚠️ Best Practices for CP:

Always initialize arrays: int A[1000] = {};
Prefer std::vector<int> for dynamic size
Avoid out-of-bounds access: 0 <= index < size
*/
