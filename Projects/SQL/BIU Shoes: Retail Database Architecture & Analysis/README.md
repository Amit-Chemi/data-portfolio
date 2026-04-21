# 👟 BIU Shoes: E-Commerce Database Architecture & Analysis

## 📌 Project Overview
This project simulates the role of a Data Analyst / BI Developer at "BIU Shoes," a rapidly growing footwear retail company. As the business scales globally, tracking inventory, regional sizing, customer lifetime value, and order fulfillment becomes increasingly complex. 

This repository contains the complete end-to-end solution: from designing the relational database architecture to executing complex SQL queries that extract actionable business insights for the Product, Marketing, and Operations teams.

## 🏗️ Architecture & Technical Implementation
I designed a robust relational database (MySQL) and automated its deployment using Python (`mysql.connector`). The schema ensures strict data integrity across 10 interconnected tables:

* **Product & Inventory:** `shoe`, `size`, `shoe_size`, `upcoming` (handling standard inventory, sizing charts, and pre-orders for special releases).
* **Global Logistics:** `country`, `city` (supporting international expansion, including dynamic updates for regional sizing like UK metrics).
* **Customer & Sales Tracking:** `customer`, `company_order`, `order_shoe`, `order_customer` (tracking the full user journey from purchase to fulfillment).
* **Data Integrity:** Implemented rigorous constraints including Primary/Foreign Keys, `UNIQUE` email enforcement, and `CHECK` constraints (e.g., precise 9-digit customer ID validation).

## 💡 Business Impact & Key Insights Extracted
The core value of this project lies in translating complex business questions into structured analytical queries:

* **Customer Lifetime Value (LTV):** Identified top-tier customers based on total revenue generated, enabling targeted retention campaigns.
* **Pricing Strategy Analysis:** Calculated the average price distribution across different size categories to identify pricing trends and anomalies.
* **Inventory Optimization (Dead Stock):** Engineered queries to identify unsold SKUs, helping operations clear warehouse space and reduce holding costs.
* **Financial Reporting (Views):** Created dynamic Database Views (e.g., `total_sales_per_shoe`) to provide the finance team with a real-time, high-level summary of product performance.
* **Cross-Functional Marketing Support:** Consolidated standard inventory with upcoming special releases into a unified dataset (`UNION ALL`) to streamline promotional campaign planning.
* **Supply Chain Health:** Tracked exact size availability per shoe model to preemptively flag out-of-stock risks.

## 🛠️ Tech Stack & Skills Demonstrated
* **Languages:** SQL (MySQL), Python (Database Integration & Automation).
* **Database Design:** Relational Schema, Normalization, Constraints (DDL).
* **Data Analysis (SQL):** Complex `JOIN` operations, Aggregations (`GROUP BY`, `SUM`, `AVG`), Subqueries, `UNION`, and `VIEW` creation.
* **Business Analysis:** Translating operational needs into data models and extracting KPIs.