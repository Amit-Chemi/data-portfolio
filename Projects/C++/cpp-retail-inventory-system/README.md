# 🛒 C++ Retail Inventory Management System

## 📌 Project Overview
This project is a robust, Object-Oriented inventory and pricing engine developed for a supermarket chain. It simulates a real-world retail backend where different product categories require entirely different business logic for pricing, storage, and tracking.

The core objective of this project is to demonstrate advanced C++ Object-Oriented design, specifically focusing on **Deep Inheritance Hierarchies**, **Polymorphism**, and managing heterogeneous collections of objects in memory.

## 🏗️ System Architecture & Class Hierarchy
The system uses a multi-level inheritance tree to model the store's inventory, ensuring high cohesion and code reusability:

* **Manager Class (`Store`):** Acts as the central database. It manages a dynamic array of polymorphic pointers to the base `Product` class, handling global parameters like the "Store Advertising Factor."
* **Base Class (`Product`):** Encapsulates shared attributes like SKU (Serial Number), shelf location, base quantity, and exposure level. Defines virtual interfaces for printing and pricing.
* **Level 1 Derived Classes:** * `AgriculturalProduct`: Adds seasonal logic and supplier counts.
  * `DairyProduct`: Adds fat percentages, packaging details, and dairy-specific types.
  * `PackageProduct`: An aggregated product containing multiple sub-items.
* **Level 2 Derived Classes:**
  * `Fruit` / `Vegetable` (inherit from `AgriculturalProduct`): Add specific nutritional data (sugar content, vitamins) that directly impact dynamic pricing.
  * `Cheese` / `OtherDairy` (inherit from `DairyProduct`): Handle add-ons and non-dairy dietary components (e.g., Kosher Pareve logic).

## 💡 Key Engineering Features
* **Polymorphic Pricing Engine:** Implemented virtual `calculatePrice()` functions. Each derived class overrides this method to calculate its final price dynamically based on complex formulas (e.g., base weight $\times$ exposure factor $\times$ product-specific traits).
* **Heterogeneous Data Structures:** The `Store` class maintains a single array of `Product*` pointers, allowing the system to iterate through fruits, cheeses, and packages seamlessly using late binding (Polymorphism).
* **Strict Encapsulation & Const Correctness:** Variables are strictly private. Data access is controlled via getters/setters, using pass-by-reference and `const` modifiers to ensure memory safety and prevent unauthorized mutations.
* **Complex Data Parsing:** Capable of instantiating the correct objects dynamically by parsing complex, space-separated string formats representing diverse product configurations.

## 🛠️ Tech Stack & Skills Demonstrated
* **Language:** C++
* **OOP Concepts:** Inheritance, Polymorphism (Virtual Functions), Aggregation, Encapsulation.
* **Memory Management:** Safe handling of dynamic arrays of pointers, ensuring proper cleanup via Virtual Destructors to prevent memory leaks.