#include <iostream>
#include "graph.h"
#include "read_file.h"
#include "draw.h"

using namespace std;

int main()
{
    V2D airports = read_airports("../tests/data_project/airports.dat");
    // for (size_t i = 0; i < airports.size(); i++) {
    //     for (size_t j = 0; j < airports[i].size(); j++) {
    //         cout << airports[i][j] << ", ";
    //     }
    //     cout << endl;
    // }

    // cout << airports[6618][4] << "," << airports[6618][5] << endl;

    // stold(airports[632][4]);
    // stold(airports[632][5]);

    // for (size_t i = 0; i < airports.size(); i++) {
    //     for (size_t j = 0; j < airports[i].size(); j++) {
    //         cout << airports[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    V2D routes = read_routes("../tests/data_project/routes.dat");
    // for (size_t i = 0; i < routes.size(); i++) {
    //     cout << routes[i][0] << "," << routes[i][1] << endl;
    // }

    // int a = 0;
    // for (size_t i = 0; i < routes.size(); i++) {
    //     for (size_t j = 0; j < routes[i].size(); j++) {
    //         cout << routes[i][j] << "," << routes[i][j] << endl;
    //     }
    //     if (a == 10) {
    //         break;
    //     }
    //     a++;
    // }

    // cout << routes.size() << endl;
    Graph graph(airports, routes);
    // cout << graph.get_vertex_number() << endl;
    // cout << graph.get_edge_number() << endl;

    // graph.get_adjacency_matrix();
    // cout << graph.get_vertex_number() << endl;
    // graph.get_airport_ids();
    // for (auto i : graph.airports) {
    //     cout << i.second.latitude << "," << i.second.longitude << endl;
    // }
    Draw d("/workspaces/final project/yunheyue_final_project/worldmap2.png");
    cout << "Welocme to OpenFlight!!" << endl;
    cout << "Below is the instrution of how to use this system!" << endl;
    cout << "1.shortest distance" << endl;
    cout << "2.Least stops" << endl;
    cout << "0.exit" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "Begin to use your system: " << endl;
        cout << "1.shortest distance" << endl;
        cout << "2.Least stops" << endl;
        cout << "0.exit" << endl;

        int decision;
        cin >> decision;
        if (decision == 1)
        {
            string start_city;
            cout << "Please enter the city of your source airport:  ";
            cin >> start_city;
            // return all aiports and airport ids in this city

            vector<int> airports_index = graph.get_airports_index(start_city);

            vector<string> airports_user_input;
            for (size_t i = 0; i < airports_index.size(); i++)
            {
                airports_user_input.push_back(graph.get_airport_names()[airports_index[i]]);
            }

            vector<int> airports_user_input_index;
            for (size_t i = 0; i < airports_user_input.size(); i++)
            {
                airports_user_input_index.push_back(graph.get_index(airports_user_input[i]));
            }
            vector<int> ids;
            for (size_t i = 0; i < airports_user_input_index.size(); i++)
            {
                ids.push_back(graph.get_airport_ids()[airports_user_input_index[i]]);
            }

            for (unsigned int i = 0; i < airports_user_input.size(); i++)
            {
                cout << i << "."
                     << " Airports ID:  " << ids[i] << "  Airport's Name:  " << airports_user_input[i] << endl;
            }
            int i;
            cout << "Please chose the number of your prefer source airport: ";
            cin >> i;

            string des_city;
            cout << "Please enter the city of your destination airport:  ";
            cin >> des_city;
            // return all aiports and airport ids in this city
            //  vector<pair<int, vertex>> airport2 = de(des_city);
            //  for(unsigned int i  = 0; i < airport2.size(); i++) {
            //      cout << i << "." << " Airports ID:  " << airport2[i].first << "Airport's Name:  " << airport2[i].second.name << endl;
            //  }

            vector<int> airports_index2 = graph.get_airports_index(des_city);
            cout << airports_index2.size() << "1" << endl;

            vector<string> airports_user_input2;
            for (size_t i = 0; i < airports_index2.size(); i++)
            {
                airports_user_input2.push_back(graph.get_airport_names()[airports_index2[i]]);

            }
                        cout << airports_user_input2.size() << "2" << endl;


            vector<int> airports_user_input_index2;
            for (size_t i = 0; i < airports_user_input2.size(); i++)
            {
                airports_user_input_index2.push_back(graph.get_index(airports_user_input2[i]));
            }

                                    cout << airports_user_input_index2.size() << "3" << endl;

            vector<int> ids2;
            for (size_t i = 0; i < airports_user_input_index2.size(); i++)
            {
                ids2.push_back(graph.get_airport_ids()[airports_user_input_index2[i]]);
            }

            cout << ids2.size() << "4" << endl;

            for (unsigned int i = 0; i < airports_user_input2.size(); i++)
            {
                cout << i << "."
                     << " Airports ID:  " << ids2[i] << "  Airport's Name:  " << airports_user_input2[i] << endl;
            }
            int j;
            cout << "Please chose the number of your prefer destination airport: ";
            cin >> j;

            int start_id = ids[i]; // user's prefered source airport
            int end_id = ids2[j];  // user's prefered destination airport

            cout << "The routes: ";
            vector<vertex> draw_path = graph.floyd_warshall(start_id, end_id);
           if (draw_path.size() > 1)
            {

                for (size_t i = 0; i < draw_path.size(); i++)
                {
                    if (i != draw_path.size() - 1)
                    {
                        cout << draw_path[i].name << "-->";
                    }
                    else
                    {
                        cout << draw_path[i].name;
                    }
                }
                cout << endl;
                cout << "Loading route on the world map................" << endl;
                d.drawtheline(draw_path);
                PNG* p = d.getPng();
  
                 p->writeToFile("sbjjy.png");
                cout << "Drawing done, have a nice trip ^_^" << endl;
            }
            else
            {
                cout << "NO ROUTE, please input different airport" << endl;
            }
        }
        else if (decision == 2)
        {

            string start_city;
            cout << "Please enter the city of your source airport:  ";
            cin >> start_city;
            // return all aiports and airport ids in this city

            vector<int> airports_index = graph.get_airports_index(start_city);

            vector<string> airports_user_input;
            for (size_t i = 0; i < airports_index.size(); i++)
            {
                airports_user_input.push_back(graph.get_airport_names()[airports_index[i]]);
            }

            vector<int> airports_user_input_index;
            for (size_t i = 0; i < airports_user_input.size(); i++)
            {
                airports_user_input_index.push_back(graph.get_index(airports_user_input[i]));
            }
            vector<int> ids;
            for (size_t i = 0; i < airports_user_input_index.size(); i++)
            {
                ids.push_back(graph.get_airport_ids()[airports_user_input_index[i]]);
            }

            for (unsigned int i = 0; i < airports_user_input.size(); i++)
            {
                cout << i << "."
                     << " Airports ID:  " << ids[i] << "  Airport's Name:  " << airports_user_input[i] << endl;
            }
            int i;
            cout << "Please chose the number of your prefer source airport: ";
            cin >> i;

            string des_city;
            cout << "Please enter the city of your destination airport:  ";
            cin >> des_city;
            // return all aiports and airport ids in this city
            //  vector<pair<int, vertex>> airport2 = de(des_city);
            //  for(unsigned int i  = 0; i < airport2.size(); i++) {
            //      cout << i << "." << " Airports ID:  " << airport2[i].first << "Airport's Name:  " << airport2[i].second.name << endl;
            //  }

            vector<int> airports_index2 = graph.get_airports_index(des_city);

            vector<string> airports_user_input2;
            for (size_t i = 0; i < airports_index.size(); i++)
            {
                airports_user_input2.push_back(graph.get_airport_names()[airports_index2[i]]);
            }

            vector<int> airports_user_input_index2;
            for (size_t i = 0; i < airports_user_input2.size(); i++)
            {
                airports_user_input_index2.push_back(graph.get_index(airports_user_input2[i]));
            }
            vector<int> ids2;
            for (size_t i = 0; i < airports_user_input_index2.size(); i++)
            {
                ids.push_back(graph.get_airport_ids()[airports_user_input_index2[i]]);
            }

            for (unsigned int i = 0; i < airports_user_input2.size(); i++)
            {
                cout << i << "."
                     << " Airports ID:  " << ids2[i] << "  Airport's Name:  " << airports_user_input2[i] << endl;
            }
            int j;
            cout << "Please chose the number of your prefer destination airport: ";
            cin >> j;

            int start_id = ids[i]; // user's prefered source airport
            int end_id = ids2[j];  // user's prefered destination airport

            cout << "The routes: ";
            vector<vertex> draw_path = graph.bfs(start_id, end_id);
            if (draw_path.size() > 1)
            {

                for (size_t i = 0; i < draw_path.size(); i++)
                {
                    if (i != draw_path.size() - 1)
                    {
                        cout << draw_path[i].name << "-->";
                    }
                    else
                    {
                        cout << draw_path[i].name;
                    }
                }
                cout << endl;
                cout << "Loading route on the world map................" << endl;
                d.drawtheline(draw_path);
                PNG* p = d.getPng();
  
                 p->writeToFile("sbjjy.png");
                cout << "Drawing done, have a nice trip ^_^" << endl;
            }
            else
            {
                cout << "NO ROUTE, please input different airport" << endl;
            }
        }
        else
        {
            flag = false;
        }
    }
}