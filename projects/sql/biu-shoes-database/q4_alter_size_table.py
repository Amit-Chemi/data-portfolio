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
    # Adding UK market into size table.
    cursor.execute ("""
    ALTER TABLE size ADD COLUMN uk_number TINYINT;
    """)
    mydb.commit ()
    cursor.close ()
    mydb.close ()
