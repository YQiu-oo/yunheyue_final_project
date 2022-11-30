#include "draw.h"
using namespace std;
pair<double,double> Draw::converttoindex(double lon, double lat,double wide, double high) {
    double x;
    double y;
    double nw = wide / 2;
    double nh = high / 2;
    if (lon >= 0)
    {   
        x = ((90/nw)*lon) + nw;
    } else {
        x = ((90/nw)*lon) + nw;
    }

    if (lat >= 0)
    {
        y = ((190/nh) * lat) + nh;
    }else {
        y = ((190/nh) * lat) + nh;
    }
    return {x,y};
    
    
}

PNG Draw::drawtheline(vector<vertex> v) {
    PNG map;
    map.readFromFile("/workspaces/final project/yunheyue_final_project-main/worldmap.png");
    double high = map.height();
    double wide = map.width();
    //get two point's lontitude and latitude and convert it to the index
    pair<double,double> index1 = converttoindex(1,1,1,1);
    pair<double,double> index2 = converttoindex(2,2,2,2);
    double slope = (index2.second - index1.second) / (index2.first - index2.first);
    double constant = index2.second - slope*(index2.first);
    for (double x = index1.first; x < index2.first; x++)
    {
        double y = slope*x + constant;
        map.getPixel(x,y).l = 111;
    }
    return map;
       
}