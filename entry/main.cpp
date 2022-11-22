#include <iostream>
#include "graph.h"
#include "read_file.h"

using namespace std;

int main() {
    V2D airports = read_airports("../tests/data_project/airports.dat");
    // cout << airports[6618][4] << "," << airports[6618][5] << endl;

    // stold(airports[632][4]);
    // stold(airports[632][5]);

    for (size_t i = 0; i < airports.size(); i++) {
        for (size_t j = 0; j < airports[i].size(); j++) {
            cout << airports[i][j] << " ";
        }
        cout << endl;
    }

    V2D routes = read_routes("../tests/data_project/routes.dat");
    // for (size_t i = 0; i < routes.size(); i++) {
    //     for (size_t j = 0; j < routes[i].size(); j++) {
    //         cout << routes[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Graph graph(airports, routes);
    // for (auto i : graph.airports) {
    //     cout << i.second.latitude << "," << i.second.longitude << endl;
    // }

}