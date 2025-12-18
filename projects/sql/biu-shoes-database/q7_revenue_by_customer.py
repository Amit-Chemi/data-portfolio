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
    # Finds out which customer generate the most for the company.
    cursor.execute ("""
    SELECT cu.first_name, cu.last_name, SUM(sh.price) AS total_revenue
    FROM customer AS cu
        JOIN order_customer AS oc ON cu.customer_id = oc.customer_id
        JOIN company_order AS co ON oc.order_id = co.order_id
        JOIN order_shoe AS os ON co.order_id = os.order_id
        JOIN shoe AS sh ON os.shoe_id = sh.shoe_id
    GROUP BY cu.customer_id
    ORDER BY total_revenue DESC; 
    """)
    print (', '. join (str( row ) for row in cursor . fetchall ()
    ))
