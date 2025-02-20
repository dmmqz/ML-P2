from sklearn.datasets import load_iris
import pandas as pd

# import data
df = pd.read_csv("Iris.csv")

# Make 2 datasets
df1 = df[df["Species"] != "Iris-virginica"]
df1["Species"] = df1["Species"].replace({"Iris-setosa": 0, "Iris-versicolor": 1})
df2 = df[df["Species"] != "Iris-setosa"]
df2["Species"] = df2["Species"].replace({"Iris-virginica": 0, "Iris-versicolor": 1})

# Delete unneeded info and export
cols = ["Id"]

df1.drop(columns=cols).to_csv("test_data.csv", index=False, header=False)
df2.drop(columns=cols).to_csv("test_data2.csv", index=False, header=False)
