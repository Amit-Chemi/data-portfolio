-- ==========================================================
-- E-Commerce Database Architecture Setup
-- This script creates the relational schema, implements constraints,
-- and handles dynamic schema modifications for market expansion.
-- ==========================================================

CREATE DATABASE biu_shoes;
USE biu_shoes;

-- 1. Product & Sizing Architecture
CREATE TABLE shoe (
    shoe_id INT PRIMARY KEY,
    shoe_name VARCHAR(31) NOT NULL,
    price SMALLINT NOT NULL
);

CREATE TABLE size (
    size_id INT PRIMARY KEY,
    european_number TINYINT NOT NULL,
    us_number TINYINT
);

CREATE TABLE shoe_size (
    shoe_id INT,
    size_id INT,
    PRIMARY KEY (shoe_id, size_id),
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id),
    FOREIGN KEY (size_id) REFERENCES size(size_id)
);

CREATE TABLE upcoming (
    special_id INT PRIMARY KEY,
    shoe_id INT NOT NULL,
    collection_name VARCHAR(31),
    release_date DATETIME,
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id)
);

-- 2. Global Logistics & Customers
CREATE TABLE country (
    country_id INT PRIMARY KEY,
    country_name VARCHAR(63) NOT NULL
);

CREATE TABLE city (
    city_id INT PRIMARY KEY,
    city_name VARCHAR(63) NOT NULL,
    country_id INT NOT NULL,
    FOREIGN KEY (country_id) REFERENCES country(country_id)
);

CREATE TABLE customer (
    customer_id VARCHAR(15) PRIMARY KEY,
    CHECK (LENGTH(customer_id) = 9),
    first_name VARCHAR(31) NOT NULL,
    last_name VARCHAR(31) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    city_id INT NOT NULL,
    FOREIGN KEY (city_id) REFERENCES city(city_id)
);

-- 3. Order Management System
CREATE TABLE company_order (
    order_id INT PRIMARY KEY,
    order_date DATETIME NOT NULL
);

CREATE TABLE order_shoe (
    shoe_id INT,
    order_id INT,
    PRIMARY KEY (shoe_id, order_id),
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id),
    FOREIGN KEY (order_id) REFERENCES company_order(order_id)
);

CREATE TABLE order_customer (
    order_id INT,
    customer_id VARCHAR(15),
    PRIMARY KEY (order_id, customer_id),
    FOREIGN KEY (order_id) REFERENCES company_order(order_id),
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id)
);

-- ==========================================================
-- Schema Modifications & Updates
-- Adapting the database to new business requirements.
-- ==========================================================

-- Adding support for pre-orders on special edition releases
ALTER TABLE upcoming ADD COLUMN pre_order_available BIT(1) NOT NULL DEFAULT 0;

-- Expanding to the UK Market: Adding UK sizing standard
ALTER TABLE size ADD COLUMN uk_number TINYINT;

-- Note: In a production environment, the database would now be populated 
-- using standard INSERT INTO statements for products, users, and locations.

UPDATE size SET uk_number = 5 WHERE european_number = 38;
UPDATE size SET uk_number = 6 WHERE european_number = 39;
UPDATE size SET uk_number = 7 WHERE european_number = 41;
UPDATE size SET uk_number = 8 WHERE european_number = 42;
UPDATE size SET uk_number = 9 WHERE european_number = 43;