-- ==========================================================
-- E-Commerce Business Analysis & Product Insights
-- This script contains queries designed to extract actionable 
-- insights regarding customer behavior, inventory health, and revenue.
-- ==========================================================

-- ----------------------------------------------------------
-- 1. Customer Lifetime Value (LTV) & Revenue Generation
-- Identifies top spending customers to support targeted marketing campaigns.
-- ----------------------------------------------------------
SELECT 
    cu.first_name, 
    cu.last_name, 
    SUM(sh.price) AS total_revenue
FROM customer AS cu
JOIN order_customer AS oc ON cu.customer_id = oc.customer_id
JOIN company_order AS co ON oc.order_id = co.order_id
JOIN order_shoe AS os ON co.order_id = os.order_id
JOIN shoe AS sh ON os.shoe_id = sh.shoe_id
GROUP BY cu.customer_id
ORDER BY total_revenue DESC; 

-- ----------------------------------------------------------
-- 2. Price Distribution by Size Category
-- Analyzes whether specific size demographics correlate with higher-priced inventory.
-- ----------------------------------------------------------
SELECT 
    sz.european_number, 
    sz.us_number, 
    AVG(sh.price) AS average_price
FROM size AS sz
JOIN shoe_size AS ss ON sz.size_id = ss.size_id
JOIN shoe AS sh ON ss.shoe_id = sh.shoe_id
GROUP BY sz.european_number, sz.us_number
ORDER BY average_price DESC;

-- ----------------------------------------------------------
-- 3. Stock Availability Health
-- Tracks the count of size options available per product model to identify supply bottlenecks.
-- LEFT JOIN ensures visibility of zero-stock items.
-- ----------------------------------------------------------
SELECT 
    sh.shoe_name, 
    COUNT(ss.size_id) AS size_count
FROM shoe AS sh
LEFT JOIN shoe_size AS ss ON sh.shoe_id = ss.shoe_id
GROUP BY sh.shoe_id
ORDER BY size_count ASC;

-- ----------------------------------------------------------
-- 4. Unified Promotional Catalog
-- Consolidates live inventory with upcoming collections for marketing materials.
-- ----------------------------------------------------------
SELECT 
    shoe_name AS name, 
    'Inventory' AS source
FROM shoe       
UNION ALL           
SELECT 
    collection_name AS name, 
    'Upcoming Release' AS source
FROM upcoming;

-- ----------------------------------------------------------
-- 5. Financial Performance View
-- Creates a reusable view summarizing total historical revenue per product.
-- ----------------------------------------------------------
CREATE OR REPLACE VIEW total_sales_per_shoe AS
SELECT 
    sh.shoe_name, 
    sh.shoe_id, 
    SUM(sh.price) AS total_revenue
FROM shoe AS sh
JOIN order_shoe AS os ON sh.shoe_id = os.shoe_id
GROUP BY sh.shoe_id, sh.shoe_name;
        
SELECT * FROM total_sales_per_shoe;

-- ----------------------------------------------------------
-- 6. Dead Stock Identification
-- Flags inventory that has never been ordered to optimize warehouse storage.
-- ----------------------------------------------------------
SELECT DISTINCT sh.shoe_name
FROM shoe AS sh
WHERE NOT EXISTS (
    SELECT 1
    FROM order_shoe AS os
    WHERE os.shoe_id = sh.shoe_id
);