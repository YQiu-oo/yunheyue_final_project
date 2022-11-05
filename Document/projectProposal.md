## Leading Question 
Airplanes are the most useful transportation for people traveling around the world. We want to make a useful tool that allows people to choose the shortest path between two countries so that people can save their time and enjoy their journey ^-^. The shortest path is one of the choices, if users want to choose their preferred paths, don't worry, our project allows users to choose different paths. Given the datasets, our code base will be able to guide its user in several aspects:

 1. Ideal Path(IP):The data structure we are using for this project is a graph. Given the source airport and destination airport, code base will return  the shortest path between two chosen airports,along with several stops. The Floyd-Warshall Algorithm is a choice to find the ideal path. For the graph, the node is the airport, the edges the route, and the weight the distance between two locations(using latitude and longitude to calculate it).

 2. All Possible Routes(APR):Users can choose their preferred route. If the user inputs the source airport and destination airport, then it will display all possible paths with their distance. To achieve this, the code base returns all possible paths using the breadth first search.

 3. If time allows: Wanna see the routes on a world map? Given all possible routes, drawing a route from one airport to another airport on a world map is a challenging but interesting task. We'll achieve this by finding and coloring the location of each pixel on a world map.


## Dataset Acquisition
We will be using : OpenFlights:https://openflights.org/data.html

## Data Format
For uploading data, we will transfer the “dat” type document to “csv”. And use comma to separate different data of information. The “airports.dat” have the name, country, latitude and longitude of all the airport, which we will using as node. The “airlines.dat” have the information about each airline company, we will using this data to select which airline company are still using, which is edge. The “routes.dat” have information about source airport and destination airport, which is startpoint and endpoint of edge. The “airports.dat” is 1.08MB, the “airlines.dat” is 388 KB, and “routes.dat” 2.27MB.
## Data Correction
When we are processing the data, since we need to use distance between two countries as a weighted on edge, we will double check the data to make sure the distance is correct. If some of the nodes do not have connection with other nodes, we will ignore that node. Also since some cities may have more than two airports, and the difference between latitude and longitude is very small. We will manually check the repeat and close latitude and longitude to represent the same airport or not. 

## Data Storage
For Ideal Path and All Possible Routes need to use a graph, and all the node are from “airlines.dat” and edge are from “routes.dat” , and we are using adjacency list to represent the graph. The space complexity is `O(edges + nodes)`. We will use map to connect each airport and correspond information, the space complexity is `O(number of city)`. 
## Graph Algorithm 
### Function Inputs
In the first part of our project, we will plan to store each airport as a point object in our graphical algorithm based on the data in the data set (ex. route, longitude and latitude, etc.). We will use this as an ideal input.

In the second part of our project, we will calculate the data obtained and collated from the first part. Based on the results of the calculations, we will use the BFS algorithm to obtain all the flight distances from airport to airport in the map and use the Floyd-Warshall algorithm to obtain the shortest and easiest flight distance.

In the third part of our project, if time allows, we would like to be able to map the results we get to a world map so that we can more visually represent the results of our project.

### Function Outputs
The expected output for our project is to get the shortest distance between the airport and the airport before and to get the ideal and visual output by printing at the terminal. At the end, if we have enough time, we will choose to represent the results on a world map.

### Function Efficiency
We will use Floyd-Warshall algorithm when choosing the shortest path of two airport when there is no direct flight and the expecting Big O is `O(n^3)`.
When calculating the distance between two airport, we plan to use the haversine formula and its Big O is `O(1)`.
When finding all the paths between two airports we will use BFS with Big O is `O(V+E)` for graph.




## Timeline
Week 1(November 11th)
 1. Import data, and data process
 2. Write makefile

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
