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
    
    # Updating the UK matket size values.
    cursor.execute ("UPDATE size SET uk_number = 5 WHERE european_number = 38;")
    cursor.execute ("UPDATE size SET uk_number = 6 WHERE european_number = 39;")
    cursor.execute ("UPDATE size SET uk_number = 7 WHERE european_number = 41;")
    cursor.execute ("UPDATE size SET uk_number = 8 WHERE european_number = 42;") 
    cursor.execute ("UPDATE size SET uk_number = 9 WHERE european_number = 43;") 
                    
    mydb.commit ()
    cursor.close ()
    mydb.close ()
