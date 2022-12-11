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
    vertex() {
        name = "";
        country = "";
        city = "";
        latitude = 0.0;
        longitude = 0.0;
        visited = false;
    }
    
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
    bool visited;

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

};

class Graph {
   public:
        Graph(V2D airports_datas, V2D routes_datas);
        void graph_connect();
        int get_index(int id); //Get the subscript of the specified id
        int get_vertex_number();

        void print_airport_ids();
        vector<int> get_airport_ids();

        void print_adjacency_matrix();
        Adjacency_Matrix get_adjacency_matrix();

        void print_routes();
        vector<vector<int> > get_routes();

        int get_edge_number();

        vector<vertex> floyd_warshall(int start_id, int end_id);
        void shortest_Path_helper(int start_idx, int end_idx,vector<vertex>& path);
        vector<vertex> shortest_Path(int start_id, int end_id);

        void DFS ();
        void DFS_helper (int i);
        double haversine(double lat1, double lon1, double lat2, double lon2);
        vector<vertex> bfs(int start_id, int end_id);


        int get_index(string airport_name);
        vector<int> get_airports_index(string city);

        vector<string> get_airport_names();
        vector<string> get_cities();

    private:
        int vertex_number;
        int edge_number;

        vector<int> airport_ids; //all airport id from airports.dat
        map<int, vertex> airports; //key is airport_id
        Adjacency_Matrix adjacency_matrix;
        vector<vector<int>> routes;


        vector<string> airport_names;
        vector<string> cities;

       
        
};

