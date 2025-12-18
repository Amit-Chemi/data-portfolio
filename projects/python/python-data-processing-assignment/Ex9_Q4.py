import pandas as pd


try:
    data = pd.read_csv("students.csv")
except FileNotFoundError as e:
    print(f"Error: {e}")

else:
    non_numeric_cols = data.drop(columns=["student_id"]).select_dtypes(exclude='number').columns
    if not non_numeric_cols.empty:
        print(f"The next columns are non numeric: {', '.join(non_numeric_cols)}")
    
    else:
        grade_cols = [col for col in data.columns if col!='student_id']
        data['average'] = data[grade_cols].mean(axis=1)
        top_student = data.loc[data['average'].idxmax()]

        print(f"Top student (s):\n{top_student.to_frame().T}")

        data.to_csv("student_with_avg.csv", index=False)
