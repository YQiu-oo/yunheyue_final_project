#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

typedef vector<vector<string>> V2D;
typedef vector<vector<bool>> Adjacency_Matrix;
typedef vector<vector<int>> All_path;
typedef vector<vector<int>> All_distances;

struct vertex {
    /*
    Default constructor initialization
    */
    vertex() {
        name = "";
        country = "";
        city = "";
        latitude = 0.0;
        longitude = 0.0;
        visited = false;
    }
    /*
    Overloaded operators ==
    Comparison Vertex
    */
    bool operator==(const vertex& other) {
        if ((this -> name == other.name) and 
            (this -> city == other.city) and 
            (this -> country == other.country) and 
            (this -> latitude == other.latitude) and 
            (this -> longitude == other.longitude)) {
            return true;
        }
        return false;
    }
    
    /*
    Airport name
    */
    string name;

    /*
    The city where the airport is located
    */
    string city;

    /*
    Country where the airport is located
    */
    string country;
    
    /*
    The latitude of current airport
    */
    double latitude;

    /*
    The longitude of current airport
    */
    double longitude;

    /*
    Used to record if a vertex has been visited when traversing
    */
    bool visited;

    /*
    Each vertex has its own path to the current point.
    Mainly use in bfs,store airport id
    */
    vector<int> path;

};

class Graph {
   public:
        /*
        Converting data into an undirected weighted graph in the constructor
        */
        Graph(V2D airports_datas, V2D routes_datas);

        /*
        Get the index of the specified id
        */
        int get_index(int id);

        /*
        Get the index of the specified airport
        */
        int get_index(string airport_name);

        /*
        Get the index of the specified airport (A city may have multiple airports)
        */
        vector<int> get_airports_index(string city);

        /*
        Get total vertex number of the graph
        */
        int get_vertex_number(); 

        /*
        Get total edge number of the graph
        */
        int get_edge_number();

        /*
        return airport_ids
        */
        vector<int> get_airport_ids();

        /*
        return adjacency_matrix
        */
        Adjacency_Matrix get_adjacency_matrix();

        /*
        return routes
        */
        vector<vector<int> > get_routes();

        /*
        return airport_names
        */
        vector<string> get_airport_names();

        /*
        return cities
        */
        vector<string> get_cities();

        /*
        Description: Given start_id and end_id, find all shortest_path of each airports and then return the shortest path
        between start_id and end_id along with airports.One thing important is this is for distance.
        Parameters: int start_id and int end_id, we will convert them into vertex(airport).
        Return value: return a vector that stores each airports along with the shortest path between start_id and end_id.
        */
        vector<vertex> floyd_warshall(int start_id, int end_id);
        // void shortest_Path_helper(int start_idx, int end_idx,vector<vertex>& path);
        // vector<vertex> shortest_Path(int start_id, int end_id);

        /*
        Description: To calculate the distance between two airports with their latitude and longtitude.
        Parameters: The lat1 and lon1 of the start airport and the lat2 and lon2 of the end airport.
        Return value: return a double value that is the distance between two airports.
        */
        double haversine(double lat1, double lon1, double lat2, double lon2);

        /*
        Description: Find a route given start_id and end_id that has the least stops.
        Parameters: int start_id and int end_id, we will convert them into vertex(airport).
        Return value: return a vector that stores each airports along with the shortest path between start_id and end_id.
        */
        vector<vertex> bfs(int start_id, int end_id);

    private:
        /*
        total vertex number of graph
        */
        int vertex_number;

        /*
        total edge number of graph
        */
        int edge_number;

        /*
        all airport id from airports.dat
        */
        vector<int> airport_ids;

        /*
        all cities names from airports.dat
        */
        vector<string> cities;

        /*
        all airport names from airports.dat
        */
        vector<string> airport_names;

        /*
        key is airport_id
        velue is vertex (sush as airport name, city name, country, latitude, longitude)
        */
        map<int, vertex> airports;

        /*
        A two-dimensional vector to record the relationship between each airport
        */
        Adjacency_Matrix adjacency_matrix;

        /*
        The routes from routes.dat
        */
        vector<vector<int>> routes;        
};

