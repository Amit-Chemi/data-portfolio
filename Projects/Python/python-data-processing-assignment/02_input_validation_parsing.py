import pandas as pd

def numtable(lst):
    try:
        int_lst = list(map(int, lst))
        table = pd.DataFrame({'Values':int_lst})
        print(table)
    except ValueError as e:
            print(f"Error: {e}")

nums = list(input("Enter a comma-seperated values: ").split(','))  
numtable(nums)          
