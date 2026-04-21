# 📅 C++ Calendar and Date Management System

## 📌 Project Overview
This project simulates the development of a core backend system for managing dates and events. The primary objective is to implement a robust, Object-Oriented architecture using C++ while maintaining strict control over system memory and data validity.

The system consists of two primary modules: a `MyDate` class that handles complex time logic and dynamic string allocation, and a `Calendar` class that acts as a manager (Aggregation) for a collection of date objects. 

## 🏗️ System Architecture & Files
The codebase enforces strict separation of interface and implementation:

* **`MyDate.h` / `MyDate.cpp`:** The core date entity. It encapsulates Day, Month, Year, and a dynamically allocated `char*` comment. It handles its own validation and memory lifecycle.
* **`Calendar.h` / `Calendar.cpp`:** The management layer. It maintains a static array of pointers to `MyDate` objects, handling insertion, deletion, capacity checks, and deep cleanup.
* **`main.cpp`:** The driver program executing integration tests and demonstrating system capabilities.

## 💡 Key Engineering Features Demonstrated
* **Dynamic Memory Management:** Safe allocation and deallocation of dynamic strings (`char*`) and object pointers, ensuring zero memory leaks via custom Destructors.
* **Deep Copy Semantics:** Implemented custom Copy Constructors to safely duplicate objects containing dynamic memory (avoiding shallow copy crashes).
* **Exception Handling:** Utilized `try-catch-throw` blocks to gracefully handle invalid inputs (e.g., impossible calendar dates or out-of-bounds operations).
* **`Const` Correctness & References:** Passed variables by reference (`&`) and used `const` keywords extensively to optimize performance and prevent accidental data mutation.
* **Data Validation:** Built-in business logic to verify leap years, correct days-per-month, and fallback logic for invalid user inputs.

## 🛠️ How To Build And Run

**Using Command Line (g++):**
Navigate to the project directory and compile the source files:
```bash
g++ main.cpp MyDate.cpp Calendar.cpp -o calendar_app
./calendar_app