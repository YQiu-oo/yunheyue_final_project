# yunheyue_final_project

<img src="https://user-images.githubusercontent.com/86536290/206965520-c34a9a50-580b-44f2-b54e-139305bcf820.png" alt="worldmap3" style="zoom:10%" />


# Github files structures
```
|--data 
|------data_project (Store input airport files and routes files)
|--entry
|------main.cpp (file for user to execute the program )
|--lib (store cs255 and lodepeng that are copied from mp_maze)
|--src (file to store all function declaratons and defintions[code])
|--tests (store test suites)
|--README.md (running instructions and program organization)
|--result.md (written report)

```

# Instructions of how to run this program

### Download project to your local with git clone command:
```
git clone https://github.com/YQiu-oo/yunheyue_final_project.git
```
### Make a build directory and let the cmake command workable before running program 
```
mkdir build
cd build
cmake ..
```
### Excute the program
execute the program with make first or make main, then there are two required arguments for user to input:
** Notice **
1. the data file for airport 
```
make | make main
```





# Description of Test Suites
### Command to run the test suites





# Overview

Airplanes are the most useful transportation for people traveling around the world. We want to make a useful tool that allows people to choose the shortest path between two countries so that people can save their time and enjoy their journey ^-^. The shortest path is one of the choices, if users want to choose their preferred paths, don't worry, our project allows users to choose different paths. Given the datasets, our code base will be able to guide its user in several aspects:

 1. Ideal Path(IP):The data structure we are using for this project is a graph. Given the source airport and destination airport, code base will return  the shortest path between two chosen airports,along with several stops. The Floyd-Warshall Algorithm is a choice to find the ideal path. For the graph, the node is the airport, the edges the route, and the weight the distance between two locations(using latitude and longitude to calculate it).

 2. All Possible Routes(APR):Users can choose their preferred route. If the user inputs the source airport and destination airport, then it will display all possible paths with their distance. To achieve this, the code base returns all possible paths using the breadth first search.


# Tools and programming language
C++,etc.

# Datasets
We will be using : OpenFlights:https://openflights.org/data.html

# Algorithm and Formula
Floyd-Warshall algorithm, Haversine formula

# Timeline
Week 1(November 11th)
Import data, and data process
 1. Write makefile

Week 2(November 18th)
 1. Implement graph to connect all airport
 2. implement BFS 


Week3(November 25th)
 1. implement Floyd-Warshall algorithm
 2. write test case for BFS and Floyd-Warshall algorithm

Week 4(December 2th)
 1. write main function, and debugging.
 2. If time allowed, present all the airports on a real map.


Week 5(December 8th)
 1. Final revision on presentation and report.
 2. Clean up code.


