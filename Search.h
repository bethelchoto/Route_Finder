/**
 * @author Bethel Panashe Choto 
 * @author Ruvimbo Joy Sithole
 *
 */
#ifndef SEARCH_H
#define SEARCH_H

#include "main.h"

using namespace std;

class Search
{
public:
    Search();
    vector<Node> searchAlgorithm(string start_city, string destination);
};

bool goal_test(string start, string destination);
vector<vector<string>> actions(string airportcode);
vector<Node> solution_path(Node code);
void writeTofile(vector<Node> result);

#endif // SEARCH_H
