#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "read_file.h"
#include "graph.h"


TEST_CASE("floyd_warshall test1", "[weight=5]"){
    V2D routes = read_routes("../tests/data_project/routes_small1.dat");
    V2D airport = read_airports("../tests/data_project/airports_small1.dat");

    Graph graph(routes, airport);

    int start_id = 0;
    int end_id = 0;
    vector<vertex> my_ = graph.floyd_warshall(start_id, end_id);
    vector<vertex> correct = {};
    REQUIRE(my_ == correct);
}


TEST_CASE("floyd_warshall test2", "[weight=5]"){
    V2D routes = read_routes("../tests/data_project/routes_small1.dat");
    V2D airport = read_airports("../tests/data_project/airports_small1.dat");

    Graph graph(routes, airport);

    int start_id = 0;
    int end_id = 0;
    vector<vertex> my_ = graph.floyd_warshall(start_id, end_id);
    vector<vertex> correct = {};
    REQUIRE(my_ == correct);


}

TEST_CASE("floyd_warshall test3", "[weight=5]"){
   
    V2D routes = read_routes("../tests/data_project/routes_small1.dat");
    V2D airport = read_airports("../tests/data_project/airports_small1.dat");

    Graph graph(routes, airport);

    int start_id = 0;
    int end_id = 0;
    vector<vertex> my_ = graph.floyd_warshall(start_id, end_id);
    vector<vertex> correct = {};
    REQUIRE(my_ == correct);

}

TEST_CASE("floyd_warshall test4", "[weight=5]"){
    V2D routes = read_routes("../tests/data_project/routes_small1.dat");
    V2D airport = read_airports("../tests/data_project/airports_small1.dat");

    Graph graph(routes, airport);


    int start_id = 0;
    int end_id = 0;
    vector<vertex> my_ = graph.floyd_warshall(start_id, end_id);
    vector<vertex> correct = {};
    REQUIRE(my_ == correct);


}

