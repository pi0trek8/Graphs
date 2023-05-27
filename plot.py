import sys
import os
import pandas as pd
import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8-whitegrid')


def plot(directory, file):
    df = pd.read_csv(directory + "/" + file, header=None, names=['num_elements', 'time'], delimiter=';')
    labels = file.split('_')
    label = f'{labels[0]} algorithm, {labels[1]} graph implementation, density: {labels[2].removesuffix(".csv")}'
    plt.plot(df['num_elements'], df['time'], marker='.', markersize=7, markerfacecolor='#000000',
             markeredgecolor='#000000', label=f'{labels[0]} algorithm, {labels[1]} graph')
    plt.title(label)
    plt.legend()
    plt.xlabel('Number of elements [n]')
    plt.ylabel('Time (microseconds)')
    fig = plt.gcf()
    plt.show()
    fig.savefig(f'img/{file.removesuffix(".csv")}.png', bbox_inches='tight')


def get_csv_files(directory: str):
    if not os.path.exists(directory):
        print(f"Directory {directory} does not exist")
        return []
    return [f for f in os.listdir(directory) if f.endswith('.csv')]


dire = sys.argv[1]
files = get_csv_files(dire)
print(files)

for file in files:
    plot(dire, file)
