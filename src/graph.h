#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

typedef vector<vector<string>> V2D;
typedef vector<vector<bool>> Adjacency_Matrix;

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
};

class Graph {
    public:
        Graph(V2D airports_datas, V2D routes_datas);
        void graph_connect();
        int get_index(int id);
        int get_vertex_number();
        void get_airport_ids();
        void get_adjacency_matrix();
        int get_edge_number();

        void DFS ();
        void DFS_helper (int i);

    private:
        int vertex_number;
        int edge_number;

        vector<int> airport_ids; //可以通过这个vector得到制定id的下标
        map<int, vertex> airports; //key is airport_id
        Adjacency_Matrix adjacency_matrix;
};