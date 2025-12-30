import mysql.connector

if __name__ == '__main__':
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="root",
        database="biu_shoes",
        port=3307,
    )
    cursor=mydb.cursor ()
   
    # Creation of shoe table.
    cursor.execute ("""
    CREATE TABLE shoe(
    shoe_id INT PRIMARY KEY,
    shoe_name VARCHAR(31) NOT NULL,
    price SMALLINT NOT NULL);
    """)
  
    # Creation of size table.
    cursor.execute ("""
    CREATE TABLE size(
    size_id INT PRIMARY KEY,
    european_number TINYINT NOT NULL,
    us_number TINYINT);
    """)
  
    # Creation connection table of shoes and sizes.
    cursor.execute ("""
    # Creation connection table of shoes and sizes.
    CREATE TABLE shoe_size(
    shoe_id INT,
    size_id INT,
    PRIMARY KEY (shoe_id, size_id),
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id),
    FOREIGN KEY (size_id) REFERENCES size(size_id));
    """)

    # Creation of special edition of upcoming sneakers releases table.  
    cursor.execute ("""
    CREATE TABLE upcoming(
    special_id INT PRIMARY KEY,
    shoe_id INT NOT NULL,
    collection_name VARCHAR(31),
    release_date DATETIME,
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id));
    """)

    # Creation of countries information table.
    cursor.execute ("""
    CREATE TABLE country(
    country_id INT PRIMARY KEY,
    country_name VARCHAR(63) NOT NULL);
    """)

    # Creation of cities information table.
    cursor.execute ("""
    CREATE TABLE city(
    city_id INT PRIMARY KEY,
    city_name VARCHAR(63) NOT NULL,
    country_id INT NOT NULL,
    FOREIGN KEY (country_id) REFERENCES country(country_id));
    """)

    # Creation of customers details table.
    cursor.execute ("""
    CREATE TABLE customer(
    customer_id VARCHAR(15) PRIMARY KEY,
    CHECK (LENGTH(customer_id) = 9),
    first_name VARCHAR(31) NOT NULL,
    last_name VARCHAR(31) NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    city_id INT NOT NULL,
    FOREIGN KEY (city_id) REFERENCES city(city_id));
    """)

    # Creation of all of the company orders table.
    cursor.execute ("""
    CREATE TABLE company_order(
    order_id INT PRIMARY KEY,
    order_date DATETIME NOT NULL);
    """)
  
    # Creation connection table of shoes and orders.
    cursor.execute ("""
    CREATE TABLE order_shoe(
    shoe_id INT,
    order_id INT,
    PRIMARY KEY (shoe_id, order_id),
    FOREIGN KEY (shoe_id) REFERENCES shoe(shoe_id),
    FOREIGN KEY (order_id) REFERENCES company_order(order_id));
    """)

    # Creation connection table of order and customer.
    cursor.execute ("""
    CREATE TABLE order_customer(
    order_id INT,
    customer_id VARCHAR(15),
    PRIMARY KEY (order_id, customer_id),
    FOREIGN KEY (order_id) REFERENCES company_order(order_id),
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id));
    """)
    
    mydb.commit ()
    cursor.close ()
    mydb.close ()
