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
    //load the route file
    V2D routes = read_routes("../data/data_project/routes_small1.dat");
    //expected output
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
    //load the route file
    V2D routes = read_routes("../data/data_project/routes_small2.dat");
    //expected output
    const V2D correct_routes = {{"4029", "6160"},\
                                {"2966", "2990"}};

    REQUIRE(routes == correct_routes);


}


TEST_CASE("read_airport_file Test1", "[weight=5]"){
    //load the airport data file
    V2D routes = read_airports("../data/data_project/airports_small1.dat");
    //expected output
    const V2D correct_routes = {{"1","Goroka Airport","Goroka","Papua New Guinea","-6.081689834590001","145.391998291"},\
                                {"2","Madang Airport","Madang","Papua New Guinea","-5.20707988739","145.789001465"}, \
                                {"3","Mount Hagen Kagamuga Airport","Mount Hagen","Papua New Guinea","-5.826789855957031","144.29600524902344"}, \
                                {"4","Nadzab Airport","Nadzab","Papua New Guinea","-6.569803","146.725977"}, \
                                {"5","Port Moresby Jacksons International Airport","Port Moresby","Papua New Guinea","-9.443380355834961","147.22000122070312"}};

    REQUIRE(routes == correct_routes);


}
TEST_CASE("read_airport_file Test2", "[weight=5]"){
    //load the airport data file
    V2D routes = read_airports("../data/data_project/airports_small2.dat");
    //expected output
    const V2D correct_routes = {{"1","Goroka Airport","Goroka","Papua New Guinea","-6.081689834590001","145.391998291"}};

    REQUIRE(routes == correct_routes);
}




