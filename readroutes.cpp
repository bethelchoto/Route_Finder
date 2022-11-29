/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */
#include "main.h"

using namespace std;
/**
 * @brief return a unordered map of routes that
 * can be accessible from each start position
 * @return string of the key node
 */
string ReadRoutes::displayRoutes()
{
    Routes rt;
    ReadAirport RA;
    unordered_map<string, vector<vector<string>>> routes_2 = rt.Route();
    auto it = routes_2.find(RA.readAirport()[1]);

    if (it != routes_2.end())
    {
        cout << it->first;
        vector<vector<string>> temp;
        temp = it->second;
    }
    return it->first;
}