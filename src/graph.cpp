#include "graph.h"
#include <cmath>
#include<queue>
#include<algorithm>


//copy from website: https://verytoolz.com/blog/844d2a795f/
double Graph::haversine(double lat1, double lon1, double lat2, double lon2){
    // distance between latitudes and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formula
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

Graph::Graph(V2D airports_datas, V2D routes_datas) {
    //Store all airport numbers in vector<int> airport_ids
    /*
        Store all airport numbers as keys(int) in map<int, vertex> airports
        Store all name, city, country, latitude, and longitude as values(vertex) in map<int, vertex> airports
    */
    for (size_t i = 0; i < airports_datas.size(); i++) {
        vertex vertex;
        vertex.name = airports_datas[i][1];
        airport_names.push_back(airports_datas[i][1]);
        vertex.city = airports_datas[i][2];
        cities.push_back(airports_datas[i][2]);
        vertex.country = airports_datas[i][3];
        vertex.latitude = stod(airports_datas[i][4]);
        vertex.longitude = stod(airports_datas[i][5]);

        int airport_id = stoi(airports_datas[i][0]);
        airports.insert(make_pair(airport_id, vertex));
        airport_ids.push_back(airport_id);
    }

    vertex_number = airport_ids.size(); //total number of vertex

    //Initialize adjacency_matrix
    //The element inside the container defaults to false
    adjacency_matrix.resize(vertex_number);
    for (int i = 0; i < vertex_number; i++) {
        adjacency_matrix[i].resize(vertex_number);
    }
    
    //Third transition invalid data
    //Delete the non-existent airport based on vector<int> airport_ids.
    for (size_t i = 0; i < routes_datas.size(); i++) {
        bool flag = false;
        for (size_t j = 0; j < routes_datas[i].size(); j++) {
            if (get_index(stoi(routes_datas[i][j])) == -1) {
                flag = true;
            }
        }

        if (flag == true) {
            routes_datas.erase(routes_datas.begin() + i);
            i--;
        }
    }

    //According to the routes_datas, mark the route relations in the adjacency_matrix 
    //(give the points of the graph to be connected)
    for (size_t i = 0; i < routes_datas.size(); i++) {
        adjacency_matrix[get_index(stoi(routes_datas[i][0]))][get_index(stoi(routes_datas[i][1]))] = true;
    }

    //After filtering the invalid data, we get 66771 routes from routes.dat
    //However, the total number of routes marked in adjacency_matrix is 36907
    /*
        This is because there are routes that start and end at the same point, 
        but they are on different airlines. We consider this situation as one route.
    */

    //Calculate the number of edges in the graph;
    int count_edge = 0;
    for (size_t i = 0; i < adjacency_matrix.size(); i++) {
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j] == true) {
                count_edge++;
            }
        }
    }
    edge_number = count_edge / 2;

    routes.resize(routes_datas.size());
    for (size_t i = 0; i < routes.size(); i++) {
        routes[i].resize(2);
    }

    for (size_t i = 0; i < routes.size(); i++) {
        routes[i][0] = stoi(routes_datas[i][0]);
        routes[i][1] = stoi(routes_datas[i][1]);
    }
}

int Graph::get_index(int id) {
    for (size_t i = 0; i < airport_ids.size(); i++) {
        if (airport_ids[i] == id) {
            return i;
        }
    }
    return -1;
}

int Graph::get_vertex_number() {
    return vertex_number;
}

int Graph::get_edge_number() {
    return edge_number;
}

vector<int> Graph::get_airport_ids() {
    return airport_ids;
}


Adjacency_Matrix Graph::get_adjacency_matrix() {
    return adjacency_matrix;
}


vector<vector<int> > Graph::get_routes() {
    return routes;
}


vector<vertex> Graph::floyd_warshall(int start_id, int end_id) {
    All_distances all_distance;//store distance from one airport to another airport
    All_path all_path;//store the path from one airport to another airport
    all_distance.resize(vertex_number);
    all_path.resize(vertex_number);
    
    for (int i = 0; i < vertex_number; i++) {
        all_distance[i].resize(vertex_number);
        all_path[i].resize(vertex_number);

    }
    //initialize all_path and all_distance with the haversine function and adjacency_matrix,
    //if two airports have connection , then intializes all_distance with the distance and all_path with the index
    //of the current traverse index. Otherwise, INF and -1.
    for (size_t i = 0; i < adjacency_matrix.size(); i++) { 
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++) {
            
            if(i == j) { 
                all_distance[i][j] = 0;
                all_path[i][j] = -1;
                continue;
            }
            all_path[i][j] = j;
            if (adjacency_matrix[i][j] == true) {
                double i_dis = haversine(airports[airport_ids[i]].latitude, airports[airport_ids[i]].longitude,
                airports[airport_ids[j]].latitude, airports[airport_ids[j]].longitude);
                
                int dis = (int) i_dis;
                all_distance[i][j] = dis;
            }else if(adjacency_matrix[i][j] == false) {
                all_distance[i][j] = INF;
            }
        }
    }
  
    //The core stuff of the Floyd_warshall algorithm: update the value in all_path and all_distance
    //The shortest path between j and j with k as the transfer point: i -> k -> j
    int num_of_vertex = get_vertex_number();
    for(int k = 0; k < num_of_vertex; k++ ) {
        for(int i = 0; i <  num_of_vertex; i++) {
            if(all_distance[i][k] != INF) {
                 for(int j = 0; j < num_of_vertex; j++) {
                    if(all_distance[k][j] != INF) {
                        if(all_distance[i][j] == INF || all_distance[i][k] + all_distance[k][j] < all_distance[i][j]) {
                            all_distance[i][j] = all_distance[i][k] + all_distance[k][j];
                            all_path[i][j] = all_path[i][k];
                         }


                    }
                 }   
            }
            

            
            
            
        }
    }
    
   /*
    Now we have correct path and given the start_id and end_id, find the shortest path 
    in all_path.
   */
    vector<vertex> path;
    int start_idx = get_index(start_id);
    int end_idx = get_index(end_id);
   
    if(start_idx == end_idx) {
        return path;
    }
    
    vertex v = airports[start_id];
    path.push_back(v);
    while(start_idx != end_idx) {
        
        start_idx = all_path[start_idx][end_idx] ;
        path.push_back(airports[airport_ids[start_idx]]);
    }
    // for(unsigned int i= 0; i < path.size();i++) {
    //     cout << path[i].city << endl;

    // }


    
   return path;
 }
 
//  vector<vertex> Graph::shortest_Path(int start_id, int end_id){

//     int start_idx = get_index(start_id);
//     int end_idx = get_index(end_id);
//     vector<vertex> shortest_path;
//     shortest_Path_helper(start_idx,end_idx, shortest_path);
//     return shortest_path;
// }

// void Graph::shortest_Path_helper(int start_idx, int end_idx, vector<vertex>& path) {
//     if(all_path[start_idx][end_idx] == end_idx) {
//         path.push_back(airports[get_index(end_idx)]);
//         return;
//     }
//     path.push_back(airports[get_index(start_idx)]);
//     shortest_Path_helper(all_path[start_idx][end_idx] ,end_idx , path);
// }


vector<vertex> Graph::bfs(int start_id, int end_id){

    vector<int> visited;
    queue<int> q;
   
   
    q.push(start_id);
    visited.push_back(start_id);
    std::map<int, int> parent;
    
    /*
    BFS to traverse all points and record each points 
    */
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == end_id) {
            //now is the endpoint
            break;
        }
        //To check all neighbors of the "now" vertex, if it has not visited yet, we mark it as visited and store the parent(now) 
        // of current neighbor
        for(int i = 0; i < vertex_number; i++) {
            if(adjacency_matrix[get_index(now)][i]) {
                if(find(visited.begin(), visited.end(), airport_ids[i]) == visited.end()) {
                    q.push(airport_ids[i]);
                    visited.push_back(airport_ids[i]);
                    parent[airport_ids[i]] = now;
                }
            }

        }
    }
   
    /*
    Find the route from the end point and push each point to the vector called path,
    stop until we meet the start point
    */
    std::vector<vertex> path;
    int current = end_id;
  while (current != start_id) {
    path.push_back(airports[current]);
    current = parent[current];
  }
  path.push_back(airports[start_id]);


  // reverse the path to get the correct order
  std::reverse(path.begin(), path.end());

  return path;
}


vector<string> Graph::get_airport_names() {
    return airport_names;
}

vector<string> Graph::get_cities() {
    return cities;
}


int Graph::get_index(string airport_name) {
    for (size_t i = 0; i < airport_names.size(); i++) {
        if (airport_names[i] == airport_name) {
            return i;
        }
    }
    return -1;
}

vector<int> Graph::get_airports_index(string city) {
    vector<int> temp;
    for (size_t i = 0; i < cities.size(); i++) {
        if (cities[i] == city) {
            temp.push_back(i);
        }
    }
    return temp;
}