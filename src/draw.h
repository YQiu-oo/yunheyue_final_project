#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "/workspaces/final project/yunheyue_final_project-main/lib/cs225/PNG.h"
#include "graph.h"

using namespace std;
using namespace cs225;
class Draw
{
public:
    pair<double,double> converttoindex(double lon, double lat,double wide, double high);
    PNG drawtheline(vector<vertex> v);
};
