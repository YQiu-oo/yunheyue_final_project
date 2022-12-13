#include <iostream>
#include "graph.h"
#include "read_file.h"
#include "draw.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cerr << "Please input three arguments: ./main [your airports file location] [your routes file location]" << std::endl;
        return 1;
    }
    
    //"../data/data_project/airports.dat"
    V2D airports = read_airports(argv[1]);

    //"../data/data_project/routes.dat"
    V2D routes = read_routes(argv[2]);
    
    Graph graph(airports, routes);
   
    Draw d("../data/data_project/worldmap3.png");
    cout << "Welocme to OpenFlight!!" << endl;
    cout << "Below is the instrution of how to use this system!" << endl;
    cout << "Press 1 to find shortest distance" << endl;
    cout << "Press 2 to find Least stops" << endl;
    cout << "Press 0 to exit the system" << endl;

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

            vector<int> airports_index2 = graph.get_airports_index(des_city);
            

            vector<string> airports_user_input2;
            for (size_t i = 0; i < airports_index2.size(); i++)
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
                ids2.push_back(graph.get_airport_ids()[airports_user_input_index2[i]]);
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
  
                 p->writeToFile("../result/out.png");
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
                ids2.push_back(graph.get_airport_ids()[airports_user_input_index2[i]]);
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
  
                 p->writeToFile("../result/out.png");
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