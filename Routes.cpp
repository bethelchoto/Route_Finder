/**
 * @author Ruvimbo Joy Sithole
 * @author Bethel Panashe Choto
 */

#include "main.h"
using namespace std;

/**
 * Function fetches the relevant information from routes.csv
 * @returns a map containing airport codes as keys with their connected airport codes and respective airline codes as values in a vector
 */
unordered_map<string, vector<vector<string>>> Routes::Route()
{
    unordered_map<string, vector<vector<string>>> routes;
    vector<vector<string>> temp;
    vector<string> temp1;

    vector<string> row;
    string line, word;

    string start_code;
    string destination_code;
    string number_of_stops;
    string airline_code;

    fstream location("routes.csv", ios::in);
    if (location.is_open())
    {
        while (getline(location, line))
        {
            row.clear();
            temp1.clear();

            stringstream str(line);
            // reads through line using the , delimeter
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }
            start_code = row[2];       // start code
            destination_code = row[4]; // destination
            number_of_stops = row[7];  // number of stops
            airline_code = row[0];     // airline code

            // create a vector for each destination airport that hold the relevant information for that route
            temp1.push_back(number_of_stops);
            temp1.push_back(airline_code);
            temp1.push_back(destination_code);

            // using find() to search for code if found, "it" has address of key value pair.
            auto it = routes.find(start_code);
            if (it == routes.end()) // if code was not found it is == routes.end()
            {
                temp.push_back(temp1);
                routes.insert({start_code, temp});
            }
            else
            {
                temp = it->second;
                temp.push_back(temp1);
                routes.insert({start_code, temp});
            }
        }
        location.close();
    }
    return routes;
}
