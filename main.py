import subprocess

executable_path = "C:\\Users\\Admin\\Desktop\\Graphs\\cmake-build-release\\Graph_algorithms.exe"
output_file = "dijkstra_List.txt"


arguments = [
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


with open(output_file, "w") as f:
    for arg in arguments:
        for v in vertices:
            command = [executable_path, v, arg]
            result = subprocess.run(command, capture_output=True, text=True)
            output = result.stdout
            print(result)
            f.write(f"Command: {' '.join(command)}\n")
            f.write(f"Output:\n{output}\n\n")
