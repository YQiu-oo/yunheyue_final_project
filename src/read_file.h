#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

typedef vector<vector<string>> V2D;

V2D read_airports(const string & filename);

V2D read_routes(const string & filename);