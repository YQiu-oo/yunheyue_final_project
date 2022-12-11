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
    // if (longitude < -180 || longitude > 180 || latitude < -90 || latitude > 90) {
    //     std::cout << "Warning. Airport with coordinates " << latitude << ", " << longitude << " are invalid and may not print!" << std::endl;
    // }
    // int x = PRIME_MERIDIAN + ((this->map_width * longitude) / 360);
    // if (longitude < LEFT_SIDE_LONG) {
    //     x = this->map_width + x;
    // }
    // //-3 was just trial and error specific to b/w map
    // int y = EQUATOR - ((this->map_height* latitude) / 180) - 3;
    // return std::pair<int, int>(x, y);
    int x = (int)((map_width / 360) * (180 + longitude));
    int y = (int)((map_height / 180) * (90 - latitude));
    return {x + 184, y + 200};
}

void Draw::drawtheline(vector<vertex> v)
{
    int high = png->height();
    int wide = png->width();
    // get two point's lontitude and latitude and convert it to the index
    for (size_t i = 0; i < v.size(); i++)
    {
        if (i + 1 < v.size())
        {
            pair<int, int> index1 = converttoindex(v[i].latitude, v[i].longitude);
            pair<int, int> index2 = converttoindex(v[i + 1].latitude, v[i + 1].longitude);
            cout << index1.first << endl;
            cout << index1.second << endl;
            cout << index2.first << endl;
            cout << index2.second << endl;
            if (index1.first > index2.first)
            {
                swap(index1, index2);
            }
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

            double slope = (index2.second - index1.second) / (index2.first - index1.first);
            double constant = index2.second - slope * (index2.first);
            for (double x = index1.first; x < index2.first; x++)
            {
                double y = slope * x + constant;
                png->getPixel(x, y).h = 0;
                png->getPixel(x, y).s = 1;
                png->getPixel(x, y).l = 0.5;
            }
            for (double y = index1.second; y < index2.second; y++)
            {
                double x = (y - constant) / slope;
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