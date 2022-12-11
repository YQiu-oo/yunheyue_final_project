#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "/workspaces/yunheyue/yunheyue_final_project/lib/cs225/PNG.h"
#include "graph.h"

using namespace std;
using namespace cs225;
class Draw
{
    private:
        PNG* png;

        int map_width = 2000;
        int map_height = 1000; 

        //These are pixel parameters, because equator wasn't exactly middle and prime meridian were also not.
        //If not using empty_map.png this needs to be recalibrated along with map_width and map_height
        // int PRIME_MERIDIAN = 2000/2 - 2000/28; //This was done by trial and error 
        // int LEFT_SIDE_LONG = -167; 
        // int EQUATOR = 337;

    public:
        pair<int,int> converttoindex(double latitude, double longitude);
        void drawtheline(vector<vertex> v);
        Draw(const string input_file);
        PNG* getPng();
        ~Draw();
};
