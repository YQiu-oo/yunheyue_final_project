#include "graph.h"
#include <cmath>
#include<queue>
#include<algorithm>


//copy from website: https://verytoolz.com/blog/844d2a795f/
static double haversine(double lat1, double lon1, double lat2, double lon2){

        // distance between latitudes

        // and longitudes

        double dLat = (lat2 - lat1) * M_PI / 180.0;

        double dLon = (lon2 - lon1) * M_PI / 180.0;

         // convert to radians

        lat1 = (lat1) * M_PI / 180.0;

        lat2 = (lat2) * M_PI / 180.0;

         // apply formula

        double a = pow(sin(dLat / 2), 2) +

                   pow(sin(dLon / 2), 2) *

                   cos(lat1) * cos(lat2);

        double rad = 6371;

        double c = 2 * asin(sqrt(a));

        return rad * c;

    }
Graph::Graph(V2D airports_datas, V2D routes_datas) {
    //这个forloop将所有的airports存进map容器里
    for (size_t i = 0; i < airports_datas.size(); i++) {
        vertex vertex;
        vertex.name = airports_datas[i][1];
        vertex.city = airports_datas[i][2];
        vertex.country = airports_datas[i][3];
        if (i != 6618) {
            vertex.latitude = stod(airports_datas[i][4]);
            vertex.longitude = stod(airports_datas[i][5]);
        }

        int airport_id = stoi(airports_datas[i][0]);
        airports.insert(make_pair(airport_id, vertex));
        airport_ids.push_back(airport_id);
    }

    vertex_number = airport_ids.size(); //顶点总数

    //初始化整个矩阵(全部为false)
    adjacency_matrix.resize(vertex_number);
    for (int i = 0; i < vertex_number; i++) {
        adjacency_matrix[i].resize(vertex_number);
    }

    //将airports中不存在的id删除
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

    //routes_datas的size是66771
    //adjacency_matrix中标记为true的点为36907
    //这是因为有一些航线的起点和终点是一样的，但是他们的航空公司不一样

    //根据routes_datas 给adjacency_matrix 填充上关系(给图的点连线)
    for (size_t i = 0; i < routes_datas.size(); i++) {
        adjacency_matrix[get_index(stoi(routes_datas[i][0]))][get_index(stoi(routes_datas[i][1]))] = true;
    }

    //计算边的数量; 
    int count_edge = 0;
    for (size_t i = 0; i < adjacency_matrix.size(); i++) { //可能有点问题
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++) {
            if (adjacency_matrix[i][j] == true) {
                count_edge++;
            }
        }
    }
    edge_number = count_edge / 2;

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
}

int Graph::get_index(int id) {
    for (size_t i = 0; i < airport_ids.size(); i++) {
        if (airport_ids[i] == id) {
            return i;
        }
    }
    return -1;
}

// void Graph::DFS () {
//     int i;
//     for (i = 0; i < vertex_number; i++) {
//         rosters[i].visited = false;
//     }

//     for (i = 0; i < vertex_number; i++) {
//         if (!rosters[i].visited) {
//             DFS(i);
//         }
//     }

// }

// void Graph::DFS_helper (int i) {
//     int j;
//     rosters[i].visited = true;

//     cout << rosters[i] << endl;

//     for (j = 0; j < vertex_number; j++) {
//         if (adjacency_matrix[i][j] != false and !rosters[j].visited) {
//             DFS(j);
//         }
//     }
// }

int Graph::get_vertex_number() {
    return vertex_number;
}

int Graph::get_edge_number() {
    return edge_number;
}

void Graph::get_airport_ids() {
    for (size_t i = 0; i < airport_ids.size(); i++) {
        cout << airport_ids[i] << ", ";
    }
}

void Graph::get_adjacency_matrix() {
    for (size_t i = 0; i < adjacency_matrix.size(); i++) {
        for (size_t j = 0; j < adjacency_matrix[i].size(); j++) {
            cout << adjacency_matrix[i][j] << " ";
        }  
        cout << endl;
    }
}

 void Graph::floyd_warshall() {
    int num_of_vertex = get_vertex_number();
    for(int k = 0; k < num_of_vertex; k++ ) {
        for(int i = 0; i <  num_of_vertex; i++) {
            for(int j = 0; j < num_of_vertex; j++) {
                if(all_distance[i][k] + all_distance[k][j] < all_distance[i][j]) {
                    all_distance[i][j] = all_distance[i][k] + all_distance[k][j];
                    all_path[i][j] = all_path[i][k];
                }
            }
        }
    }
 }

 vector<vertex> Graph::shortest_Path(int start_id, int end_id){

    int start_idx = get_index(start_id);
    int end_idx = get_index(end_id);
    vector<vertex> shortest_path;
    shortest_Path_helper(start_idx,end_idx, shortest_path);
    return shortest_path;
}

void Graph::shortest_Path_helper(int start_idx, int end_idx, vector<vertex>& path) {
    if(all_path[start_idx][end_idx] == end_idx) {
        path.push_back(airports[get_index(end_idx)]);
        return;
    }
    path.push_back(airports[get_index(start_idx)]);
    shortest_Path_helper(all_path[start_idx][end_idx] ,end_idx , path);
}


void Graph::bfs(int start_id, int end_id){

    vector<int> visited;
    queue<int> q;
   
    q.push(start_id);
    visited.push_back(start_id);
    airports[start_id].path.push_back(start_id);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == end_id) {
            //now is the endpoint
            return;
        }
        int idx = get_index(now);
        for(size_t i = 0; i < vertex_number; i++) {
            if(adjacency_matrix[idx][i] == true) {
                if(find(visited.begin(), visited.end(), airport_ids[i]) == visited.end()) {
                    q.push(airport_ids[i]);
                    visited.push_back(airport_ids[i]);
                    for(size_t k = 0; k < airports[now].path.size(); k++) {
                        airports[airport_ids[i]].path.push_back(airports[now].path[k]);

                    }
                    airports[airport_ids[i]].path.push_back(airport_ids[i]);
                }

            }

        }


    }


}