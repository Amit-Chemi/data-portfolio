import mysql.connector

if __name__ == '__main__':
    mydb=mysql.connector.connect (
        host="localhost",
        user="root",
        password="root",
        database="biu_shoes",
        port='3307',
    )
    cursor=mydb.cursor ()
    # Finds shoes availability by name and size in stock
    cursor.execute ("""
    SELECT sh.shoe_name, COUNT(ss.size_id) AS size_count
    FROM shoe AS sh
        LEFT JOIN shoe_size AS ss ON sh.shoe_id = ss.shoe_id
        -- Left join because we also need all shoes include those without size.
    GROUP BY sh.shoe_id
    ORDER BY size_count ASC;
    """)
    print (', '. join (str( row ) for row in cursor . fetchall ()
    ))
