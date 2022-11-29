/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */
#include "main.h"

using namespace std;

/**
 * @brief Reading inputs from the inputs file
 * @return vector<string> return start_destination
 **/
vector<string> readInput::Input()
{
    /**
     * @local variables
     */
    vector<string> start_destination;
    string start_destination_citycountry;
    string country;
    string city;
    vector<string> row;
    string line, word;

    /**
     * Reading from a file csv input file
     * values are stored inside vector
     * */
    fstream location("input.csv", ios::in);
    if (location.is_open())
    {
        while (getline(location, line))
        {
            row.clear();
            stringstream str(line);
            while (getline(str, word, ','))
            {
                row.push_back(word);
            }
            city = row[0];
            country = row[1];
            start_destination_citycountry = city.append(country);
            start_destination.push_back(start_destination_citycountry);
        }
    }
    return start_destination;
}
