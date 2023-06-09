import subprocess
import sys
import plot
import csv
import os
import time


def create_file():
    file = f"{output_file}.csv"
    if os.path.exists(file):
        os.remove(file)
    f = open(file, 'a+')
    # f.write("num\n")
    # for vertex in vertices:
    #     f.write(f'{vertex}\n')


def add_column_to_csv(csv_file, new_column_name, new_column_data):
    rows = []
    with open(csv_file, 'r') as file:
        reader = csv.reader(file)
        rows = list(reader)
        # Add the new column header to the first row
        print(rows)
    rows[0].append(new_column_name)

    for i in range(1, len(rows)):
        # Add the new column data to the remaining rows
        rows[i].append(new_column_data[i - 1])

    with open(csv_file, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(rows)


def main():
    for alg in algorithms:
        for den in density:
            output = []
            header = f'{alg}_{den}'
            for v in vertices:
                command = [executable_path, alg, 'List', v, den]
                result = subprocess.run(command, capture_output=True, text=True)
                output.append(result.stdout)
                print(result)
            add_column_to_csv(f"{output_file}.csv", header, output)


def single_plot():
    file = f"{output_file}.csv"
    f = open(file, "a+")
    alg = "Kruskal"
    den = "0.99"
    for v in vertices:
        command = [executable_path, alg, 'List', v, den]
        result = subprocess.run(command, capture_output=True, text=True)
        print(result)
        f.write(f"{v};{result.stdout}\n")


def single_density(den):
    for graph in graphs:
        for alg in algorithms:
            output = []
            header = f'{alg}_{graph}_{den}'
            for v in vertices:
                command = [executable_path, alg, graph, v, den]
                result = subprocess.run(command, capture_output=True, text=True)
                output.append(result.stdout)
                print(result)
            add_column_to_csv(f"{output_file}.csv", header, output)


# executable_path = "C:\\Users\\Admin\\Desktop\\Graphs\\cmake-build-release\\Graph_algorithms.exe"
executable_path = R"C:\Users\Admin\Desktop\Graphs\cmake-build-release\Graph_algorithms.exe"
output_file = sys.argv[1]
# {algorithmName}_{GraphImplementation}

density = [
    "0.25",
    "0.5",
    "0.75",
    "0.99"
]

vertices = [
    "10",
    "15",
    "25",
    "35",
    "50",
]

# algorithms = ['Dijkstra', 'FordBellman']
algorithms = ['Prim', 'Kruskal']

graphs = ['Matrix', 'List']

if '__main__' == '__main__':
    print("a")
    create_file()
    # main()
    single_plot()
    plot.plot(f"{output_file}.csv")
    # single_density('0.99')
    # plot.plot_multiline(f"{output_file}.csv")
