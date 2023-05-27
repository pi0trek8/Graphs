import subprocess
import sys
import plot

executable_path = "C:\\Users\\Admin\\Desktop\\Graphs\\cmake-build-release\\Graph_algorithms.exe"
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
    "25",
    "50",
    "75",
    "100"
]

for den in density:
    for v in vertices:
        command = [executable_path, v, den]
        result = subprocess.run(command, capture_output=True, text=True)
        output = result.stdout
        print(result)
        file = open(f"{output_file}_{den}.csv", 'a')
        file.write(f"{v};{output}")

files = plot.get_csv_files()
print(files)

for file in files:
    plot.plot(file)
