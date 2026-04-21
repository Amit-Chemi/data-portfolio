import pandas as pd

class GradesAnalyzer:
    def __init__(self, df):
        self.df = df.copy()

    def drop_missing(self):
        self.df = self.df.dropna().copy()
    
    def add_average_column(self):
        numeric_cols = self.df.select_dtypes(include='number').columns
        self.df["average"] = self.df[[col for col in numeric_cols if col != 'student_id']].mean(axis=1)
    
    def get_top_students(self, n):
        return self.df.sort_values(by='average', ascending=False).head(n)
    
    def get_std_subject(self):
        numeric_cols = self.df.select_dtypes(include='number').columns
        grade_cols = [col for col in numeric_cols if col not in ('student_id', 'average')]
        std_series = self.df[grade_cols].std()
        return std_series.idxmax()
    
df = pd.read_csv("students.csv")

analyzer = GradesAnalyzer(df)
analyzer.drop_missing()
analyzer.add_average_column()

top_students = analyzer.get_top_students(2)
print(top_students.to_string(index=False))

highest_std_subject = analyzer.get_std_subject()
print(f"Subject with highest std deviation: {highest_std_subject}")
