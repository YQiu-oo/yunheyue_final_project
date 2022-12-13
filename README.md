# yunheyue_final_project ✈️ 🛩️ ✈️

<img src="https://user-images.githubusercontent.com/86536290/206965520-c34a9a50-580b-44f2-b54e-139305bcf820.png" alt="worldmap3" style="zoom:10%" />

# Presentations Video:
* Link: https://youtu.be/-y6CJfrIplw

# Github files structures
```

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
First make main, and use ./main first.dat second.dat to input the data set you want.

![f539f2e6ea48665d0d33cbbc61193e1](https://user-images.githubusercontent.com/92742463/207180203-22708d73-4417-495b-9d5d-21658a0f50a9.png)

Input 1 to test shortest path by distance. Input Wewak as source airport, and input 0 to choose the first airport in this city.Then Input Sondrestrom as destination airport and input 0 to choose the first airport in this city.

![3bd610cc4711c72de34c50ef043d7a8](https://user-images.githubusercontent.com/92742463/207180235-c43bcf58-45ff-40dd-9e26-5aa0ef759dbc.png)

The route in word and the route in graph are generate

![436b623c20a0eaa9b8b06036b88d7ce](https://user-images.githubusercontent.com/75405352/207177186-92965a48-f107-4b1b-9fc8-d26419779692.png)

Input 2 to test shortest path by number of stops. Input Wewak as source airport, and input 0 to choose the first airport in this city.Then Input Sondrestrom as destination airport and input 0 to choose the first airport in this city.

![9e65abfa20700070d40ee0f3591e8d7](https://user-images.githubusercontent.com/92742463/207181199-1921beaf-88dc-46dd-8036-10e3b8208854.png)

The route in word and the route in graph are generate

![13c0daf7cdcb1a7e8ae23fefe6161f1](https://user-images.githubusercontent.com/75405352/207177117-51c35ca1-559e-489a-b530-13e078313300.png)

Input 0 to exist the program

![e7e67d325157f701779d517ebcfb7d3](https://user-images.githubusercontent.com/92742463/207180293-84ff7d69-6651-47de-b8c1-47e9bcd2f730.png)

