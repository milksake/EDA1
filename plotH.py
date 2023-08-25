import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('distances.csv')

df.hist(bins=20)

for ax in plt.gcf().axes:
   ax.set_title(ax.get_title() + "D")

plt.show()