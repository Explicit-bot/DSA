/*
Modular Programming and Object-Oriented Programming (OOP) 

🔹 1. Definition
Modular Programming	
Object-Oriented Programming (OOP)

1.What it is
•A design technique that breaks down a program into independent modules (functions/procedures).	
•A paradigm based on the concept of objects that encapsulate data and behavior.

2.Structure unit
•Modules (functions, procedures, files)	
•Classes and objects

3.Focus
Decomposition based on functionality/tasks	
Decomposition based on real-world entities

🔹 2. Core Concepts
✅ Modular Programming
•Modules: Independent units with specific functionality.
•Procedures/Functions: Key building blocks.
•Code Reusability: Through function reuse.
•Top-down approach.

✅ OOP
•Class & Object: Blueprint and instance of data+behavior.
•Encapsulation: Hides internal details.
•Inheritance: Share behavior among classes.
•Polymorphism: Same interface, different behavior.
•Abstraction: Hides complex details from user.

🔹 3. Example (C++ comparison)
🔸 Modular Programming (C-style)
    #include <iostream>
    using namespace std;

    int add(int a, int b) {
        return a + b;
    }

    int main() {
        cout << "Sum: " << add(3, 5);
    }

🔸 Object-Oriented Programming (C++ style)
    #include <iostream>
    using namespace std;

    class Calculator {
    public:
        int add(int a, int b) {
            return a + b;
        }
    };

    int main() {
        Calculator calc;
        cout << "Sum: " << calc.add(3, 5);
    }

🔹 4. Key Differences
Feature	            Modular Programming	                    OOP
Basic Unit	        Module / Function	                    Class / Object
Data Handling	    Data is global or passed explicitly	    Data is encapsulated 
                                                            within objects
Reusability	        By copying/modifying functions	        Through inheritance
                                                             & polymorphism
Scalability	        Suitable for smaller/medium apps	    Best for large, scalable 
                                                            systems
Maintainability	    Harder with growing code	            Easier due to encapsulation

Code organization	Organized around functions	            Organized around real-world 
                                                            entities
Security	        Less secure, no data hiding	            Strong encapsulation 
                                                            ensures security

🔹 5. Advantages
✅ Modular Programming
•Simpler to understand for beginners
•Encourages separation of concerns
•Functions are reusable

✅ Object-Oriented Programming
•Better modeling of real-world scenarios
•Encourages code reuse (inheritance, polymorphism)
•Easier to maintain and extend

🔹 6. When to Use
Situation	                            Use
Small scripts or tools	                Modular Programming
Large software systems	                Object-Oriented Programming
Performance-critical tasks	            Modular, low-overhead
Projects needing real-world modeling	OOP is ideal
*/
