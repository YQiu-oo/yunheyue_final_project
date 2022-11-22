#include "graph.h"

Graph::Graph(V2D airports_datas, V2D routes_datas) {
    for (size_t i = 0; i < airports_datas.size(); i++) { //这个forloop将所有的airports存进map容器里
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

    adjacency_matrix.resize(vertex_number); //初始化整个矩阵(全部为false)
    for (int i = 0; i < vertex_number; i++) {
        adjacency_matrix[i].resize(vertex_number);
    }

    vector<vector<int>> relation; //将routes_datas转成index
    for (size_t i = 0; i < routes_datas.size(); i++) {
        relation.push_back(vector<int>());
    }
    for (size_t i = 0; i < routes_datas.size(); i++) {
        for (size_t j = 0; j < routes_datas[i].size(); j++) {
            relation[i].push_back(get_index(stoi(routes_datas[i][j])));
        }
    }

    //目前有bug
    // for (size_t i = 0; i < relation.size(); i++) { //根据relation 给adjacency_matrix 填充上关系(给图的点连线)
    //     adjacency_matrix[relation[i][0]][relation[i][1]] = true;
    // }

}

int Graph::get_index(int id) {
    for (size_t i = 0; i < airport_ids.size(); i++) {
        if (airport_ids[i] == id) {
            return i;
        }
    }
    return -1;
}