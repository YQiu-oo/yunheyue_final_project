#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "/workspaces/final project/yunheyue_final_project/lib/cs225/PNG.h"
#include "graph.h"

using namespace std;
using namespace cs225;
class Draw
{
    private:
        PNG* png;
        //wide of our worldmap in pixel which is 2000
        int map_width = 1196;
        //height of our worldmap in pixel which is 1000
        int map_height = 690; 


    public:
        //convert latitude and longtitude of airport to index in our worldmap.
        pair<int,int> converttoindex(double latitude, double longitude);
        //draw the line connect each airport
        void drawtheline(vector<vertex> v);
        /*
        Description: constructor to intialize png with the input_file
        parameters: the path of the png
        */
        Draw(const string input_file);
        /*
        Description: return the png
        return value: PNG*
        */
        PNG* getPng();
        ~Draw();
};
