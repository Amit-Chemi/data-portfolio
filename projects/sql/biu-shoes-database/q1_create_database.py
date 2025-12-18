import mysql.connector

if __name__ == '__main__':
    mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root",
    port=3307,
)
    cursor=mydb.cursor ()
    cursor.execute ("""
    # Creation of the db.
    CREATE DATABASE 'biu_shoes';
    """)
    # !!! Commit the transaction to save the changes to the database !!!
    mydb.commit ()
    cursor.close ()
    mydb.close ()
