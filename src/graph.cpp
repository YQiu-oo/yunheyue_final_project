#include "graph.h"

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