"""
This file loads the Iris dataset and modifies it to the needs of this assignment. The output is
two new files in the `data/` directory.
"""

import pandas as pd
from pathlib import Path

# import data
data_dir = Path(__file__).parent / "data"
df = pd.read_csv(data_dir / "Iris.csv")

# Make 2 datasets
df1 = df[df["Species"] != "Iris-virginica"]
df1["Species"] = df1["Species"].replace({"Iris-setosa": 0, "Iris-versicolor": 1})
df2 = df[df["Species"] != "Iris-setosa"]
df2["Species"] = df2["Species"].replace({"Iris-virginica": 0, "Iris-versicolor": 1})

# Delete unneeded info and export
cols = ["Id"]

df1.drop(columns=cols).to_csv(data_dir / "no_virginica.csv", index=False, header=False)
df2.drop(columns=cols).to_csv(data_dir / "no_setosa.csv", index=False, header=False)
