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
    # Finds price distribution of shoes for different sizes.
    cursor.execute ("""
    SELECT sz.european_number, sz.us_number, AVG(sh.price) AS average_price
    FROM size AS sz
        JOIN shoe_size AS ss ON sz.size_id = ss.size_id
        JOIN shoe AS sh ON ss.shoe_id = sh.shoe_id
    GROUP BY sz.european_number, sz.us_number
    ORDER BY average_price DESC;
    """)
    print (', '. join (str( row ) for row in cursor . fetchall ()
    ))
