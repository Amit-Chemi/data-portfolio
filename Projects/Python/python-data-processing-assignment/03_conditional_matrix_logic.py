import numpy as np
import pandas as pd

table = np.random.randint(1000, size=(3,3))
table = pd.DataFrame(table, columns=['A','B','C'])
table['row_sum'] = table.apply(lambda row: row.sum() if any(x%2==0 for x in row) else 0, axis=1)

print(table)
print(f"Total of row_sum = {table['row_sum'].sum()}")
