#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "read_file.h"
#include "graph.h"
#include "draw.h"

TEST_CASE("read_route_file Test1", "[weight=5]"){
    V2D routes = read_routes("../tests/data_project/routes_small1.dat");

    const V2D correct_routes = {{"2965", "2990"},\
                                {"2966", "2990"}, \
                                {"2966", "2962"}, \
                                {"2968", "2990"}, \
                                {"2968", "4078"}, \
                                {"4029", "2990"}, \
                                {"4029", "6969"}, \
                                {"4029", "6160"}, \
                                {"6156", "2952"}
                                };

    REQUIRE(routes == correct_routes);


}

TEST_CASE("read_route_file Test2", "[weight=5]"){
    V2D routes = read_routes("../tests/data_project/routes_small2.dat");

    const V2D correct_routes = {{"4029", "6160"},\
                                {"2966", "2990"}};

    REQUIRE(routes == correct_routes);


}


TEST_CASE("read_airport_file Test1", "[weight=5]"){
    V2D routes = read_airports("../tests/data_project/airports_small1.dat");

    const V2D correct_routes = {{"1","Goroka Airport","Goroka","Papua New Guinea","-6.081689834590001","145.391998291"},\
                                {"2","Madang Airport","Madang","Papua New Guinea","-5.20707988739","145.789001465"}, \
                                {"3","Mount Hagen Kagamuga Airport","Mount Hagen","Papua New Guinea","-5.826789855957031","144.29600524902344"}, \
                                {"4","Nadzab Airport","Nadzab","Papua New Guinea","-6.569803","146.725977"}, \
                                {"5","Port Moresby Jacksons International Airport","Port Moresby","Papua New Guinea","-9.443380355834961","147.22000122070312"}};

    REQUIRE(routes == correct_routes);


}
TEST_CASE("read_airport_file Test2", "[weight=5]"){
    V2D routes = read_airports("../tests/data_project/airports_small2.dat");

    const V2D correct_routes = {{"1","Goroka Airport","Goroka","Papua New Guinea","-6.081689834590001","145.391998291"}};

    REQUIRE(routes == correct_routes);
}

/*
Example:
    vector<int> airport_ids {10, 20, 30, 40};
    V2D routes: {{10, 20}
                 {20, 30}
                 {40, 30}
                 {20, 10}};
    
    Adjacency_Matrix adjacency_matrix {{0, 1, 0, 0}
                                       {0, 0, 1, 0}};
                                       {1, 0, 0, 0}};
                                       {0, 0, 1, 0}};

*/
TEST_CASE("Matrix Test1", "[weight=5]"){
    V2D airports = read_airports("/workspaces/yunheyue/yunheyue_final_project/tests/data_project/airport1.dat");
    V2D routes = read_routes("/workspaces/yunheyue/yunheyue_final_project/tests/data_project/route1.dat");

    Graph graph(airports, routes);
    Adjacency_Matrix realoutput = graph.get_adjacency_matrix();
    const Adjacency_Matrix correct_matrix = {{0,1,1,1,0},\
                                             {0,0,1,1,0},\
                                             {1,0,0,1,0},\
                                             {0,0,0,0,1},\
                                             {1,0,1,0,0}};
    vector<vertex> my_ = graph.floyd_warshall(4, 3);
    // vector<vertex> sb = graph.bfs(3, 4);
    for(unsigned int i  = 0; i < my_.size(); i++) {
        cout << my_[i].city << endl;

    }
    Draw dd("/workspaces/yunheyue/yunheyue_final_project/worldmap2.png");
    dd.drawtheline(my_);

    PNG* p = dd.getPng();
  
    p->writeToFile("sbjjy.png");
    

    REQUIRE(realoutput == correct_matrix);
}
