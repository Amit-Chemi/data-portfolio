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
    # List of shoes that have not yet been ordered by any customer.
    cursor.execute ("""
    SELECT DISTINCT sh.shoe_name
    FROM shoe AS sh
    WHERE NOT EXISTS (SELECT 1
                      FROM order_shoe AS os
                      WHERE os.shoe_id = sh.shoe_id);
    """)
    print (', '. join (str( row ) for row in cursor . fetchall ()
    ))
