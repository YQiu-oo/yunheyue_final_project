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
    int x,y;
    x = (int)((map_width / 360) * (180 + longitude));
    y = (int)((map_height / 180) * (90 - latitude));
    // convert aiport's latitude and longtitude to index in the graph
    //since our map have different scale, so we have to adujust it to fix the error
    if (latitude < 0)
    {
        //when latitude < 0, the expect y-axis is differnt with real y-axis about 175 coordinate.
        y = y + 175;
    }else if (latitude > 0)
    {
        //when latitude > 0, the expect y-axis is differnt with real y-axis about 5 coordinate.
        y = y + 5;
    }

    if (longitude > 0)
    {
        //when longitude > 0, the expect x-axis is differnt with real x-axis about 120 coordinate.
        x = x + 120;
    }else {
        //when longitude < 0, the expect x-axis is differnt with real x-axis about 20 coordinate.
        x = x + 20;
    }
    
    return {x,y};
}

void Draw::drawtheline(vector<vertex> v)
{
    // get height and wide of our world map
    int high = png->height();
    int wide = png->width();
    // v are the vector contain the shortest path of two vertex of airport,traverse the vector to get each vertex
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i + 1 < v.size())
        {
            // first index, which is the start airport
            pair<int, int> index1 = converttoindex(v[i].latitude, v[i].longitude);
            // next index, which is the next stop or destination airport
            pair<int, int> index2 = converttoindex(v[i + 1].latitude, v[i + 1].longitude);
            // draw the line are from left to right, so if fist index's x are larger than second, then swap
            if (index1.first > index2.first)
            {
                swap(index1, index2);
            }
            // draw the airport, color 25 pixel around the airport
            for (int i = 0; i <= 5; i++)
            {
                png->getPixel(index1.first + i, index1.second).h = 150;
                png->getPixel(index1.first + i, index1.second).s = 1;
                png->getPixel(index1.first + i, index1.second).l = 0.5;
                png->getPixel(index1.first - i, index1.second).h = 150;
                png->getPixel(index1.first - i, index1.second).s = 1;
                png->getPixel(index1.first - i, index1.second).l = 0.5;
                png->getPixel(index1.first, index1.second + i).h = 150;
                png->getPixel(index1.first, index1.second + i).s = 1;
                png->getPixel(index1.first, index1.second + i).l = 0.5;
                png->getPixel(index1.first, index1.second - i).h = 150;
                png->getPixel(index1.first, index1.second - i).s = 1;
                png->getPixel(index1.first, index1.second - i).l = 0.5;

                png->getPixel(index2.first + i, index2.second).h = 150;
                png->getPixel(index2.first + i, index2.second).s = 1;
                png->getPixel(index2.first + i, index2.second).l = 0.5;
                png->getPixel(index2.first - i, index2.second).h = 150;
                png->getPixel(index2.first - i, index2.second).s = 1;
                png->getPixel(index2.first - i, index2.second).l = 0.5;
                png->getPixel(index2.first, index2.second + i).h = 150;
                png->getPixel(index2.first, index2.second + i).s = 1;
                png->getPixel(index2.first, index2.second + i).l = 0.5;
                png->getPixel(index2.first, index2.second - i).h = 150;
                png->getPixel(index2.first, index2.second - i).s = 1;
                png->getPixel(index2.first, index2.second - i).l = 0.5;
            }
            // use dy/dx formula to get slope of line that connect two airport
            double slope = (double)(index2.second - index1.second) / (index2.first - index1.first);
            // use c = y - slope*x to get the value of constant
            double constant = index2.second - slope * (index2.first);
            // use y = ax+b to draw the line, the line are start with first index'x, and draw a points when every time x increase.
            for (double x = index1.first; x < index2.first; ++x)
            {
                // y - axis of point, are using y = ax+b
                double y = slope * x + constant;
                // color red for each point
                png->getPixel(x, y).h = 0;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
            }
            //Since the line drawing are from small coordinate to large, so it is important to reverse the index
            //when first index is larger than second.
            if (index1.second > index2.second)
            {
                swap(index1, index2);
            }
            double slope2 = (double)(index2.second - index1.second) / (index2.first - index1.first);
            // use c = y - slope*x to get the value of constant
            double constant2 = index2.second - slope * (index2.first);

            // to complement the y-axis, we use x = (y-c)/slope, to color a points when everytime y increase.
            for (double y = index1.second; y < index2.second; ++y)
            {
                double x = (y - constant2) / slope2;
                // color red for each point.
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