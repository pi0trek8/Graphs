import sys
import os
import pandas as pd
import matplotlib.pyplot as plt

plt.style.use('seaborn-v0_8-whitegrid')


def plot(file, directory=''):
    file_path = (file if directory == '' else f'{directory}/{file}')

    df = pd.read_csv(file_path, header=None, names=['num_elements', 'time'], delimiter=';')
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
    if not os.path.exists('img'):
        os.mkdir('img')

    fig.savefig(f'img/{file.removesuffix(".csv")}.png', bbox_inches='tight')


def get_csv_files(directory=''):
    # if not os.path.exists(directory):
    #     print(f"Directory {directory} does not exist")
    #     return []
    return [f for f in os.listdir() if f.endswith('.csv')]
