import pandas as pd

data = pd.DataFrame ({'Name': ['Alice', 'Bob', 'Charlie', 'David'],
                      'Age': [25, 30, None, 22],
                      'City': ['Tel Aviv', 'Haifa', 'Jerusalem', 'Beer Sheva']})

missing_values = data.isnull().sum()
age_avg = data['Age'].mean()
data['Age'] = data['Age'].fillna(age_avg)

print(missing_values)
print(data)
