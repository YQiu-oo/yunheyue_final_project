#include "read_file.h"

V2D read_airports(const string & filename){
    V2D airports;
    string current;

    vector<string> temp;

    ifstream ifs{filename};
    for(string line; getline(ifs, line); line = "") {
        int index = 0;

        if (line.empty()) {
            continue;
        }

        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == ',' and line[i + 1] != ' ' and line[i + 2] != ',') {
                if (index == 0) {
                    temp.push_back(current);
                } else if (index == 1) {
                    current.erase(current.begin());
                    current.pop_back();
                    temp.push_back(current);
                } else if (index == 2) {
                    if(current == "\"") { //First transition invalid data
                                          //City has an empty string in the data
                                          //Example from airports.dat
                                          /*
                                            12025,"Gunnedah Airport","","Australia", .....
                                            12026,"Hay Airport","","Australia", .....
                                            12027,"Hopetoun Airport","","Australia", .....
                                            12028,"Kerang Airport","","Australia", .....
                                          */
                        current.clear();
                    } else {
                        current.erase(current.begin());
                        current.pop_back();
                    }
                    temp.push_back(current);
                } else if (index == 3) {
                    current.erase(current.begin());
                    current.pop_back();
                    temp.push_back(current);
                } else if (index == 6) {
                    temp.push_back(current);
                } else if (index == 7) {
                    temp.push_back(current);
                    break;
                }

                current.clear();
                index++;
            } else {
                current += line[i];
            }
        }
        airports.push_back(temp);
        temp.clear();
        current.clear();
    }

    return airports;
}

V2D read_routes(const string & filename) {
    V2D routes;
    string current;

    vector<string> temp;

    ifstream ifs{filename};
    for(string line; getline(ifs, line); line = "") {
        int index = 0;

        if (line.empty()) {
            continue;
        }

        for (size_t i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                if (index == 3) {
                    temp.push_back(current);
                } else if (index == 5) {
                    temp.push_back(current);
                    break; // saved running time
                }

                current.clear();
                index++;
            } else {
                current += line[i];
            }
        }
        routes.push_back(temp);
        temp.clear();
        current.clear();
    }

    //Second transition invalid data
    //Some datas may start or end with "\N"
    //Example from routes.dat
    /*
        EP,2923,THR,2131,DEF,\N,,0,AT7 100
        EP,2923,THR,2131,GCH,\N,,0,AT7
        EP,2923,THR,2131,KHY,\N,,0,AT7
    */
    for (size_t i = 0; i < routes.size(); i++) {
        bool flag = false;
        for (size_t j = 0; j < routes[i].size(); j++) {
            if (routes[i][j] == "\\N") {
                flag = true;
            }
        }
        if (flag == true) {
            routes.erase(routes.begin() + i);
            i--;
        }
    }

    return routes;
}