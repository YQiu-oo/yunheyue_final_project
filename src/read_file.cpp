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
                    if(current == "\"") { // 因为文件中city有空string
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
                    break; // 减少运行时间
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

    for (size_t i = 0; i < routes.size(); i++) { //删除 \N
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