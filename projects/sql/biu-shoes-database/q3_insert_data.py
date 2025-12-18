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
    cursor.execute ("""
    # Inserting data into shoe table.
    INSERT INTO shoe (shoe_id, shoe_name, price) VALUES (1, 'Air CS 0/1', 150), (2, 'Yeezy Gauss 360', 220),
    (3, '1BAll Star', 60), (4, 'Jordan 1 Engineering', 170), (5, 'BIU Superstar',90), 
    (6, 'Lunar Glow', 200), (7, 'HyperFlux', 180), (8, 'NebulaRunner', 140), (9, 'Quantum Charge', 250), (10, 'Echo Boost',160), 
    (11, 'Storm Runner', 130), (12, 'Apex Boost', 190), (13, 'Velocity Wave', 170), (14, 'Stride Master', 100), (15, 'TrailBlazer', 200), 
    (16, 'Infinity Glide', 180), (17, 'Solar Charge', 150), (18, 'Pace Leader', 120), (19, 'Canyon Racer', 250), (20, 'Sky High', 210);
    """)

    # Inserting data into size table.
    cursor.execute ("""
    INSERT INTO size (size_id, european_number, us_number) VALUES (1, 38, 6), (2, 39, 7), (3, 40, 8), (4, 41, 9), (5, 42, 10),
    (6, 43, 11), (7, 44, 12), (8, 45, 13), (9, 46, 14), (10, 47, 15), 
    (11, 36, 4), (12, 37, 5), (13, 48, 16), (14, 49, 17), (15, 50, 18);
    """)

    # Mapping the shoes to the sizes.
    cursor.execute ("""
    INSERT INTO shoe_size (shoe_id, size_id) VALUES (1, 1), (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), (2,5), 
    (2, 6), (2, 7), (3, 4), (3, 5), (3, 6), (3, 7), (3, 8),
    (4, 6), (4, 7), (4, 8), (4, 9), (4, 10), (5, 5), (5, 6), (5,7), 
    (5, 8), (5, 9), (6, 4), (6, 5), (6, 6), (6, 7), (6, 8),
    (7, 5), (7, 6), (7, 7), (7, 8), (7, 9), (8, 6), (8, 7), (8,8),
    (8, 9), (8, 10), (9, 7), (9, 8), (9, 9), (9, 10), (9, 11),
    (10, 8), (10, 9), (10, 10), (10, 11), (10, 12);
    """)

    # Inserting data into release table.
    cursor.execute ("""
    INSERT INTO upcoming (special_id, shoe_id, collection_name, release_date) VALUES (1, 1, 'Air Max Day 2025', '2025-03-26 10:00:00'), (2, 1, 'Spring Breeze Collection', '2025-05-15 12:00:00'), 
    (3, 2, 'Yeezy Glow Pack', '2025-06-15 09:00:00'), (4, 2, 'Summer Neon Edition', '2025-08-10 11:00:00'), 
    (5, 4, 'Jordan Anniversary', '2025-08-22 12:00:00'), (6, 4, 'Jordan Lunar Collection', '2025-10-05 14:00:00'),
    (7, 6, 'Lunar Bright Collection', '2025-09-30 08:00:00'), (8, 7, 'HyperFlux Supreme', '2025-10-10 15:00:00'), (9, 9, 'Quantum Special Edition', '2025-11-05 18:00:00'), 
    (10, 9, 'Winter Starlight Pack', '2025-12-20 20:00:00'), (11, 10, 'Echo Runner Series', '2025-01-18 09:00:00'), (12, 10, 'Trail Explorer Edition', '2025-07-25 17:00:00');
    """)

    # Inserting data into countries table.
    cursor.execute ("""
    INSERT INTO country (country_id, country_name) VALUES (1, 'Israel'), (2, 'Canada'), (3, 'United States'), (4, 'Germany'),
    (5, 'France'), (6, 'Japan'), (7, 'Australia'), (8, 'Italy'),
    (9, 'Spain'), (10, 'Brazil');
    """)

    # Inserting data into countries table.
    cursor.execute ("""
    INSERT INTO city (city_id, city_name, country_id) VALUES (1, 'Jerusalem', 1), (2, 'Tel Aviv', 1), (3, 'Haifa', 1), (4, 'Toronto', 2), 
    (5, 'Vancouver', 2), (6, 'Montreal', 2), (7, 'Los Angeles', 3), (8, 'New York', 3), (9, 'Chicago', 3), (10, 'Houston', 3), 
    (11, 'Berlin', 4), (12, 'Munich', 4), (13, 'Frankfurt', 4), 
    (14, 'Hamburg', 4), (15, 'Paris', 5), (16, 'Lyon', 5), (17, 'Marseille', 5), 
    (18, 'Tokyo', 6), (19, 'Osaka', 6), (20, 'Kyoto', 6), 
    (21, 'Sydney', 7), (22, 'Melbourne', 7), (23, 'Brisbane', 7),
    (24, 'Rome', 8), (25, 'Milan', 8), (26, 'Naples', 8), (27, 'Madrid', 9), 
    (28, 'Barcelona', 9), (29, 'Seville', 9), (30, 'Rio de Janeiro', 10), (31, 'S~ao Paulo', 10), (32, 'Brasilia', 10);
    """)  

    # Inserting data into customer table.
    cursor.execute ("""
    INSERT INTO customer (customer_id, first_name, last_name, email, city_id) VALUES ('123456789', 'John', 'Doe', 'john.doe@example.com', 1), ('987654321', 'Jane', 'Smith', 'jane.smith@example.com', 2), 
    ('112233445', 'Alice', 'Brown', 'alice.brown@example.com', 3), ('223344556', 'Bob', 'White', 'bob.white@example.com', 4), 
    ('334455667', 'Eve', 'Green', 'eve.green@example.com', 5), ('445566778', 'Chris', 'Black', 'chris.black@example.com', 6), 
    ('556677889', 'Anna', 'Taylor', 'anna.taylor@example.com', 7), ('667788990', 'Max', 'Johnson', 'max.johnson@example.com', 8), 
    ('778899001', 'Lily', 'Adams', 'lily.adams@example.com', 9), ('889900112', 'Oscar', 'Hill', 'oscar.hill@example.com', 10);
    """)  

    # Inserting data into company orders table.
    cursor.execute ("""
    INSERT INTO company_order (order_id, order_date) VALUES (1, '2025-01-15 14:30:00'), (2, '2025-02-10 10:15:00'), (3, '2025-03-05 16:45:00'), 
    (4, '2025-04-12 09:00:00'), (5, '2025-05-20 11:00:00'), (6, '2025-06-01 13:30:00'), (7, '2025-07-10 15:45:00'),
    (8, '2025-08-15 17:00:00'), (9, '2025-09-05 19:30:00'), (10, '2025-10-22 08:15:00'), (11, '2025-11-01 12:30:00'), (12, '2025-12-10 14:45:00'), 
    (13, '2025-02-18 10:00:00'), (14, '2025-03-20 08:15:00'),
    (15, '2025-04-22 16:30:00');
    """)
  
    # Mapping orders to shoes.
    cursor.execute ("""
    INSERT INTO order_shoe (order_id, shoe_id) VALUES (1, 1), (1, 2), (2, 3), (3, 4), (4, 5), (5, 6), (6, 7), 
    (7, 8), (8, 9), (9, 10);
    """)

    # Mapping orders to customers.
    cursor.execute ("""
    INSERT INTO order_customer (order_id, customer_id) VALUES (1, '123456789'), (2, '987654321'), (3, '112233445'), (4, '223344556'),
    (5, '334455667'), (6, '445566778'), (7, '556677889'), (8, '667788990'),
    (9, '778899001'), (10, '889900112');
    """)

    mydb.commit ()
    cursor.close ()
    mydb.close ()
