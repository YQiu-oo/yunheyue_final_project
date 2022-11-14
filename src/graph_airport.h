#include <iosteram>
#include <string>
#include <set>
#include <map>

using namespace std;

class Graph_airport {
    public:
        Graph_airport();
        ~Graph_airport();
       
        //读airport.dat，存到graph里
        void read_airport();
        //读routes，建立点和点之间的联系
        void read_routes();
        
    private:
        struct Node {
            double longitude;
            double latitude;
            string city;
            vector<Node> neighbors_node;
            vector<Edge> neighbors_edge;
        };

        struct Edge {
            double distance;
            Node* start;
            Node* end;
        }
        set<Edge> edge_set;
        map<string, Node> nodes_graph;

};
