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
    # Adding Pre-order Available column into upcoming table.
    cursor.execute ("""
    ALTER TABLE upcoming ADD COLUMN pre_order_available BIT(1) NOT NULL DEFAULT 0;
    """)
    mydb.commit ()
    cursor.close ()
    mydb.close ()
