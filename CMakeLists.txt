cmake_minimum_required(VERSION 3.25)
project(Graph_algorithms)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(Graph_algorithms main.cpp graph/list/node/Node.cpp graph/list/node/Node.h collections/Array.h collections/Iterator.h collections/DoubleList.h graph/matrix/MatrixGraph.cpp graph/matrix/MatrixGraph.h graph/list/ListGraph.cpp graph/list/ListGraph.h algorithms/dijkstra/Dijkstra.cpp algorithms/dijkstra/Dijkstra.h algorithms/fordBellman/FordBellman.cpp algorithms/fordBellman/FordBellman.h algorithms/kruskal/Kruskal.cpp algorithms/kruskal/Kruskal.h algorithms/prim/Prim.cpp algorithms/prim/Prim.h collections/BinaryHeap/BinaryHeap.h collections/BinaryHeap/BinaryHeap.cpp collections/BinaryHeap/node/PriorityQueueNode.cpp collections/BinaryHeap/node/PriorityQueueNode.h to/edge/Edge.cpp to/edge/Edge.h sorter/Sorter.h collections/BinaryHeap/MinBinaryHeap.cpp collections/BinaryHeap/MinBinaryHeap.h FileReader/FileReader.h FileReader/FileReader.cpp graph/RandomDataGenerator.cpp timer/Timer.h timer/Timer.cpp Gui/MainMenu.cpp Gui/MainMenu.h Gui/MainMenu.h Gui/ShortestPathMenu.cpp Gui/ShortestPathMenu.h Gui/MinimumSpanningMenu.cpp Gui/MinimumSpanningMenu.h Gui/Utils/Utils.cpp)
