//program for displaying day name using switch case 

#include <iostream>

enum Day {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

int main() {
    int input;
    std::cout << "Enter the day number (1-7): ";
    std::cin >> input;

    switch (input) {
        using enum Day; // ✅ works directly since Day is unscoped
        case Monday:
            std::cout << "Monday\n";
            break;
        case Tuesday:
            std::cout << "Tuesday\n";
            break;
        case Wednesday:
            std::cout << "Wednesday\n";
            break;
        case Thursday:
            std::cout << "Thursday\n";
            break;
        case Friday:
            std::cout << "Friday\n";
            break;
        case Saturday:
            std::cout << "Saturday\n";
            break;
        case Sunday:
            std::cout << "Sunday\n";
            break;
        default:
            std::cout << "Invalid day number\n";
    }

    return 0;
}

