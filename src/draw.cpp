#include "draw.h"
using namespace std;
#include <math.h>

Draw::Draw(const string input_file)
{
    png = new PNG();
    png->readFromFile(input_file);
}

Draw::~Draw()
{
    delete png;
}

pair<int, int> Draw::converttoindex(double latitude, double longitude)
{   
    //convert aiport's latitude and longtitude to index in the graph
    int x = (int)((map_width / 360) * (180 + longitude));
    int y = (int)((map_height / 180) * (90 - latitude));
    //120 and 175 are the difference in different size of map, we move the index of airport to it real place.
    return {x + 120, y + 175};
}

void Draw::drawtheline(vector<vertex> v)
{   
    //get height and wide of our world map
    int high = png->height();
    int wide = png->width();
    // v are the vector contain the shortest path of two vertex of airport,traverse the vector to get each vertex
    for (size_t i = 0; i < v.size(); i++)
    {   
        if (i + 1 < v.size())
        {   
            //first index, which is the start airport
            pair<int, int> index1 = converttoindex(v[i].latitude, v[i].longitude);
            //next index, which is the next stop or destination airport
            pair<int, int> index2 = converttoindex(v[i + 1].latitude, v[i + 1].longitude);
            //draw the line are from left to right, so if fist index's x are larger than second, then swap
            if (index1.first > index2.first)
            {
                swap(index1, index2);
            }
            //draw the airport, color 4 pixel around the airport
            png->getPixel(index1.first, index1.second).h = 150;
            png->getPixel(index1.first, index1.second).s = 1; 
            png->getPixel(index1.first, index1.second).l = 0.5;
            png->getPixel(index1.first + 1, index1.second).h = 150;
            png->getPixel(index1.first+1, index1.second).s = 1; 
            png->getPixel(index1.first+1, index1.second).l = 0.5;
            png->getPixel(index1.first-1, index1.second).h = 150;
            png->getPixel(index1.first-1, index1.second).s = 1; 
            png->getPixel(index1.first-1, index1.second).l = 0.5;
            png->getPixel(index1.first, index1.second+1).h = 150;
            png->getPixel(index1.first, index1.second+1).s = 1; 
            png->getPixel(index1.first, index1.second+1).l = 0.5;
            png->getPixel(index1.first, index1.second-1).h = 150;
            png->getPixel(index1.first, index1.second-1).s = 1; 
            png->getPixel(index1.first, index1.second-1).l = 0.5;
            // //draw the second airport, color 4 pixel around the airport
            png->getPixel(index2.first, index2.second).h = 150;
            png->getPixel(index2.first, index2.second).s = 1; 
            png->getPixel(index2.first, index2.second).l = 0.5;
            png->getPixel(index2.first + 1, index2.second).h = 150;
            png->getPixel(index2.first+1, index2.second).s = 1; 
            png->getPixel(index2.first+1, index2.second).l = 0.5;
            png->getPixel(index2.first-1, index2.second).h = 150;
            png->getPixel(index2.first-1, index2.second).s = 1; 
            png->getPixel(index2.first-1, index2.second).l = 0.5;
            png->getPixel(index2.first, index2.second+1).h = 150;
            png->getPixel(index2.first, index2.second+1).s = 1; 
            png->getPixel(index2.first, index2.second+1).l = 0.5;
            png->getPixel(index2.first, index2.second-1).h = 150;
            png->getPixel(index2.first, index2.second-1).s = 1; 
            png->getPixel(index2.first, index2.second-1).l = 0.5;
            //use dy/dx formula to get slope of line that connect two airport
            double slope = (index2.second - index1.second) / (index2.first - index1.first);
            //use c = y - slope*x to get the value of constant
            double constant = index2.second - slope * (index2.first);
            //use y = ax+b to draw the line, the line are start with first index'x, and draw a points when every time x increase. 
            for (double x = index1.first; x < index2.first; x++)
            {
                //y - axis of point, are using y = ax+b
                double y = slope * x + constant;
                //color red for each point
                png->getPixel(x, y).h = 0;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
            }
            //to complement the y-axis, we use x = (y-c)/slope, to color a points when everytime y increase.
            for (double y = index1.second; y < index2.second; y++)
            {
                double x = (y - constant) / slope;
                //color red for each point.
                png->getPixel(x, y).h = 0;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
            }
        }
    }
}

PNG *Draw::getPng()
{
    return this->png;
}