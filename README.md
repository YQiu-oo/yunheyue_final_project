# yunheyue_final_project ✈️ 🛩️ ✈️

<img src="https://user-images.githubusercontent.com/86536290/206965520-c34a9a50-580b-44f2-b54e-139305bcf820.png" alt="worldmap3" style="zoom:10%" />

# Presentations Video:
* Link: 

# Github files structures
```
|--data 
|------data_project (Store input airport files and routes files)
|--entry
|------main.cpp (file for user to execute the program )
|--data--
        |
        --data_project (Store input airport files and routes files)
|--entry--
         |
         --main.cpp (file for user to execute the program )
|--lib (store cs255 and lodepeng that are copied from mp_maze)
|--src (file to store all function declaratons and defintions[code])
|--tests (store test suites)
|--result (store the output(result) )
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
execute the program with `make` first or `make main`, there are two required data file for user to input: <br>
1. the location of data file for airports.
2. the location of data file for routes.

*****Notice** : All input data files should put into the `data --> data_project` folders, the format will look like this: `../data/data_project/airports.dat`***

```
make | make main
./main [your airport data file path] [your routes data file path]
```
Then it will pop up all options for user to select :<br>
![image](https://user-images.githubusercontent.com/86536290/206976385-b8fe35c8-d8cf-4d56-8273-1fc7459502b7.png)


# Description of Test Suites
All test suites are in the tests folder, there are two testing file: <br>
1. test_graph.cpp, there are 8 test cases for the follwing:
* BFS (bread first search)
* Floyd Warshall Algorithm 
* Adjacency Matrix <br>

2. test_data.cpp, there are 4 test cases for the follwing:
* read_airports_file
* read_routes_file


# Description of Test Suites
### Command to run the test suites

```
make test
./test
```


# Project Demo
