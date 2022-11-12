## Leading Question 
Airplanes are the most useful transportation for people traveling around the world. We want to make a useful tool that allows people to choose the shortest path between two countries so that people can save their time and enjoy their journey ^-^. The shortest path is one of the choices, if users want to choose their preferred paths, don't worry, our project allows users to choose different paths. Given the datasets, our code base will be able to guide its user in several aspects:
1. Ideal Path(IP): The data structure we are using for this project is a graph. Given the source airport and destination airport, the code base will return the shortest path between two chosen airports, along with several stops. The Floyd-Warshall Algorithm is a choice to find the ideal path. For the graph, the node is the airport, the edges the route, and the weight the distance between two locations(using latitude and longitude to calculate it).

2. All Possible Routes(APR): Users can choose their preferred route. If the user inputs the source airport and destination airport, then it will display all possible paths with their distance. To achieve this, the code base returns all possible paths using the breadth-first search.

3. Route Visualization: Wanna see the routes on a world map? Given all possible routes, drawing a route from one airport to another airport on a world map is a challenging but interesting task. We are aiming to implement that by displaying the shortest route from the location to the destination. To achieve this, the Graphic Output of Graph would be an excellent choice. Given a starting node and a goal node, the Graphic Output of the Graph should reflect all the paths in the real-world map, and the shortest route will be used in another color to highlight in the graph.




## Dataset Acquisition
We will be using : OpenFlights:https://openflights.org/data.html

## Data Format
For uploading data, we will transfer the “dat” type document to “csv”. And use comma to separate different data of information. The “airports.dat” have the name, country, latitude and longitude of all the airport, which we will using as node. The “airlines.dat” have the information about each airline company, we will using this data to select which airline company are still using, which is edge. The “routes.dat” have information about source airport and destination airport, which is startpoint and endpoint of edge. The “airports.dat” is 1.08MB, the “airlines.dat” is 388 KB, and “routes.dat” 2.27MB.
## Data Correction
When we are processing the data, since we need to use distance between two countries as a weighted on edge, we will double check the data to make sure the distance is correct. If some of the nodes do not have connection with other nodes, we will ignore that node. Also since some cities may have more than two airports, and the difference between latitude and longitude is very small. We will manually check the repeat and close latitude and longitude to represent the same airport or not. 

## Data Storage
For Ideal Path and All Possible Routes need to use a graph, and all the nodes are from “airlines.dat” and edge are from “routes.dat” , and we are using adjacency list to represent the graph. The space complexity is O(edges + nodes). We will use map to connect each airport and correspond information, the space complexity is O(number of city). 
## Graph Algorithm 
### Function Inputs
In the first part of our project(Ideal path labeled in the leading question),  we will find the shortest distance between two airports. Since we already have a dataset, we need to analyze and extract the data from the dataset and put them into a file , as an input,  that stores the nodes and edges to help us build our graph for this project. Next, we implement the Floyd-Warshall Algorithm to find the shortest distance. The inputs for this function are clearly the starting node and the goal node. The second part(All possible routes mentioned in the leading question) of our project is to find all possible paths from source to destination.  The input is the source node for this part. The input of the third part(Route Visualization) should be the vector or map which stored the airport of shortest path between source and destination, and one vector which store all the path from source to destination. 

### Function Outputs 
The expected output for the first part(Ideal path labeled in the leading question) of our project is to return the shortest route between the source airport  and  destination airport, and we will use vectors to store each node of the shortest path. The expected output of the second part(All possible routes mentioned in the leading question) of the project would be a 2-d vector that store all possible paths .The output of the third part(Route Visualization) for this project is to return a PNG with all paths from source to destination, and a highlight of shortest path from source to destination. 


### Function Efficiency
We will use Floyd-Warshall algorithm when choosing the shortest path of two airport when there is no direct flight and the expecting Big O is O(n^3).
When calculating the distance between two airport, we plan to use the haversine formula and its Big O is O(1).
When finding all the paths between two airports we will use BFS with Big O O(V+E) for graph.




## Timeline
Week 1(November 11th)
Import data, and data process
Write makefile

Week 2(November 18th)
1.Implement graph to connect all airport
2.implement BFS 


Week3(November 25th)
1.implement Floyd-Warshall algorithm
2.write test case for BFS and Floyd-Warshall algorithm
Week 4(December 2th)
1.write main function, and debugging.
2.If time allowed, present all the airports on a real map.


Week 5(December 8th)
Final revision on presentation and report.
Clean up code.
