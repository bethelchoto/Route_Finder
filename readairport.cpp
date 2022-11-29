/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */
#include "main.h"

using namespace std;

/**
 * @brief read airport data
 * @return vector<string> start_destination
 **/
vector<string> ReadAirport::readAirport()
{
    /**
     * local variables
     */
    vector<string> city_country;
    vector<string> key_airport;
    vector<string> start_destination;
    string key_start;
    string key_destination;
    vector<string> content;
    vector<string> row;
    string line, word;

    /**
     * Instatiating the readInput class
     */
    readInput inputs;

    fstream location("airports.csv", ios::in);
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
            string city = row[2];
            string country = row[3];
            string key_elemmt = row[4];
            string citycountry = city.append(country);
            key_airport.push_back(key_elemmt);
            city_country.push_back(citycountry);
        }
        for (int i = 0; i < city_country.size(); i++)
        {
            /**
             * Instatiating the Start class
             * Instatiating the Destination class
             *
             */
            Start st;
            Destination Dest;

            /**
             * getStart and getDestination are used
             * to search for key in the airport csv
             */
            if (city_country[i].compare(st.getStart()) == 0)
            {
                key_start = key_airport[i];
                start_destination.push_back(key_start);
            }

            if (city_country[i].compare(Dest.getDestination()) == 0)
            {
                key_destination = key_airport[i];
                start_destination.push_back(key_destination);
            }
        }
        location.close();
    }
    return start_destination;
}
