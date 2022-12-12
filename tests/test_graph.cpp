#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "read_file.h"
#include "graph.h"
#include "draw.h"

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
/*
    Graph for small size of data:
    EDGE(airport id)     Weight(kilometer)
    1->2                  106.714
    1->3                  124.481
    1->4                  157.102
    2->3                  179.036
    2->4                  193.578
    3->1                  124.481
    3->4                  281.037
    4->5                  324.124
    5->1                  424.593


*/
//Test adjacency matrix
TEST_CASE("Matrix Test1", "[weight=5]")
{   //load airport data file
    V2D airports = read_airports("../data/data_project/airport1.dat");
    //load route data file
    V2D routes = read_routes("../data/data_project/route1.dat");
    //initialize graph
    Graph graph(airports, routes);
    //get adjacency matrix
    Adjacency_Matrix realoutput = graph.get_adjacency_matrix();
    //expected output
    const Adjacency_Matrix correct_matrix = {{0, 1, 1, 1, 0},
                                             {0, 0, 1, 1, 0},
                                             {1, 0, 0, 1, 0},
                                             {0, 0, 0, 0, 1},
                                             {1, 0, 1, 0, 0}};

    REQUIRE(realoutput == correct_matrix);
}
TEST_CASE("Floyd small test", "[weight=5]")
{   
    //load airport data file
    V2D airports = read_airports("../data/data_project/airport1.dat");
    //load routes data file
    V2D routes = read_routes("../data/data_project/route1.dat");

    //initilaize graph
    Graph graph(airports, routes);
    //output for testing
    vector<string> output;
    vector<vertex> my_ = graph.floyd_warshall(3, 4);
    for (unsigned int i = 0; i < my_.size(); i++)
    {
        output.push_back(my_[i].city);
    }
    //expected output
    vector<string> expectresult;
    expectresult.push_back("Mount Hagen");
    expectresult.push_back("Nadzab");
    REQUIRE(output == expectresult);
}
TEST_CASE("BFS small TEST", "[weight=5]")
{
    //load airport data file
    V2D airports = read_airports("../data/data_project/airport1.dat");
    //load route data file
    V2D routes = read_routes("../data/data_project/route1.dat");
    vector<string> output;
    Graph graph(airports, routes);
    vector<vertex> my_ = graph.bfs(3, 4);
    for (unsigned int i = 0; i < my_.size(); i++)
    {
        output.push_back(my_[i].city);
    }
    vector<string> expectresult;
    expectresult.push_back("Mount Hagen");
    expectresult.push_back("Nadzab");
}
TEST_CASE("Visualization Test for Floyd small", "[weight=5]")
{
      //load airport data file
    V2D airports = read_airports("../data/data_project/airport1.dat");
    //load route data file
    V2D routes = read_routes("../data/data_project/route1.dat");

    Graph graph(airports, routes);
    //output for testing
    vector<vertex> my_ = graph.floyd_warshall(3, 4);
    Draw dd("../data/data_project/worldmap3.png");
    //draw the graph on the map
    dd.drawtheline(my_);

    PNG *p = dd.getPng();
    //output the result to see if it is correct
    p->writeToFile("../result/Floyd small.png");
}
TEST_CASE("Visualization Test for BFS small", "[weight=5]")
{
     //load airport data file
    V2D airports = read_airports("../data/data_project/airport1.dat");
    //load route data file
    V2D routes = read_routes("../data/data_project/route1.dat");

    Graph graph(airports, routes);
    //execute bfs to get the result for testing if correct
    vector<vertex> my_ = graph.bfs(3, 4);
    Draw dd("../data/data_project/worldmap3.png");
    dd.drawtheline(my_);
    PNG *p = dd.getPng();
    //output the result to see if it is correct
    p->writeToFile("../result/BFS small.png");
}

/*
    Graph for mid size of data
    EDGE(airport id)     Weight(kilometer)
    1->2                  106.714
    1->3                  124.481
    1->4                  157.102
    2->3                  179.036
    2->4                  193.578
    3->1                  124.481
    3->4                  281.037
    4->5                  324.124
    5->1                  424.593
    6->7                  3335
    7->10                 13343
    10->9                 2223
    6->8                  12949
    8->9                  6270
    1->9                  7359
    1->7                  11548
    3->10                 9548

*/
//In order to test the difference output between bfs and floyd, I modified some airports' latitude and longitude to make sure two airport
//have different path between shortest distance path and shortest stop path.
TEST_CASE("Matrix Test2", "[weight=5]")
{
      //load airport data file
    V2D airports = read_airports("../data/data_project/airportmidsize.dat");
      //load routes data file
    V2D routes = read_routes("../data/data_project/routemidsize.dat");

    Graph graph(airports, routes);
    //get the adjacency matrix
    Adjacency_Matrix realoutput = graph.get_adjacency_matrix();
    //expected output
    const Adjacency_Matrix correct_matrix = {{0, 1, 1, 1, 0, 0, 1, 0, 1, 0},
                                             {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                             {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                             {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                             {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                             {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

    REQUIRE(realoutput == correct_matrix);
}
TEST_CASE("Floyd mid test", "[weight=5]")
{
     //load airport data file
    V2D airports = read_airports("../data/data_project/airportmidsize.dat");
      //load routes data file
    V2D routes = read_routes("../data/data_project/routemidsize.dat");

    Graph graph(airports, routes);
    //execute floyd warshall to get the result for testing if correct
    vector<string> output;
    vector<vertex> my_ = graph.floyd_warshall(6, 9);
    for (unsigned int i = 0; i < my_.size(); i++)
    {
        output.push_back(my_[i].city);
    }
    //expected output
    vector<string> expectresult;
    expectresult.push_back("Wewak");
    expectresult.push_back("Narssarssuaq");
    expectresult.push_back("Thule");
    expectresult.push_back("Sondrestrom");
    REQUIRE(output == expectresult);
}
TEST_CASE("BFS MID TEST", "[weight=5]")
{
    //load airport data file
    V2D airports = read_airports("../data/data_project/airportmidsize.dat");
      //load routes data file
    V2D routes = read_routes("../data/data_project/routemidsize.dat");
    vector<string> output;
    Graph graph(airports, routes);
     //execute bfs to get the result for testing if correct
    vector<vertex> my_ = graph.bfs(6, 9);
    for (unsigned int i = 0; i < my_.size(); i++)
    {
        output.push_back(my_[i].city);
    }
    //expected output
    vector<string> expectresult;
    expectresult.push_back("Wewak");
    expectresult.push_back("Godthaab");
    expectresult.push_back("Sondrestrom");
    REQUIRE(output == expectresult);
}
TEST_CASE("Visualization Test for Floyd", "[weight=5]")
{
    //load airport data file
    V2D airports = read_airports("../data/data_project/airportmidsize.dat");
      //load routes data file
    V2D routes = read_routes("../data/data_project/routemidsize.dat");

    Graph graph(airports, routes);

    //execute floyd warshall to get the result for testing if correct
    vector<vertex> my_ = graph.floyd_warshall(6, 9);
    //draw line on the map
    Draw dd("../data/data_project/worldmap3.png");
    dd.drawtheline(my_);
    PNG *p = dd.getPng();
    //output the result to see if it is correct
    p->writeToFile("../result/Floyd mid.png");
}
TEST_CASE("Visualization Test for BFS", "[weight=5]")
{
    //load airport data file
    V2D airports = read_airports("../data/data_project/airportmidsize.dat");
    //load routes data file
    V2D routes = read_routes("../data/data_project/routemidsize.dat");

    Graph graph(airports, routes);
    //execute bfs to get the result for testing if correct
    vector<vertex> my_ = graph.bfs(6, 9);
    // vector<vertex> sb = graph.bfs(3, 4);
    //draw line on the map
    Draw dd("../data/data_project/worldmap3.png");
    dd.drawtheline(my_);
    PNG *p = dd.getPng();
    //output the result to see if it is correct
    p->writeToFile("../result/BFS mid.png");
}
