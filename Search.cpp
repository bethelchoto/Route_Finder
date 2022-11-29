/**
 * @author Ruvimbo Joy Sithole
 * @author Bethel Panashe Choto
 */
#include "main.h"
using namespace std;

/**
 * Function checks if given code is the desired destination
 *@returns true if the code is the same as a the destination code
 * */
bool goal_test(string start, string destination)
{
    if (start.compare(destination) == 0)
    {
        return true;
    }
    return false;
}

/**
 * Function obtains destination codes from the unorded_map using the given code as a key
 * @return all destinations from given airportcode
 */
vector<vector<string>> actions(string airportcode)
{
    Routes RT;                                                // Route object
    unordered_map<string, vector<vector<string>>> all_routes; // obtain all routes from the routes.csv file
    all_routes = RT.Route();

    // returns key and all destinations from given key
    auto it = all_routes.find(airportcode);
    vector<vector<string>> temp1;

    if (it == all_routes.end())
    {
        return it->second;
    }
    return temp1;
}

/**
 * @param code the found Node that is equivalent to the desired destination
 * @returns the solution path by recursively printing out the child parent
 * */
vector<Node> solution_path(Node *code)
{
    vector<Node> routes_path;
    int overrall_stops = 0;
    vector<Node> sequence_of_action;

    while (code->parent != nullptr)
    {
        routes_path.push_back(*code);
        overrall_stops += 1;
        code = code->parent;
    }
    writeTofile(routes_path);
    return routes_path;
}

/**
 * Function outputs the solution to a new .txt file
 * @param result is the vector that contains sequential Nodes from start to destination airport
 */
void writeTofile(vector<Node> result)
{
    int count = result.size() - 1;
    int total_stops;
    fstream myFile;
    myFile.open("output.txt", ios::out); // write

    if (myFile.is_open())
    {
        // writes out a line in the file for each airline route used
        while (0 <= count)
        {
            myFile << (result.size() - count) + ". " +
                          result[count].airline + " From " +
                          result[count].parent->code + " To " +
                          result[count].code + " " + to_string(result[count].stops) +
                          " " + "stops";
            total_stops += result[count].stops;
            count--;
        }
    }
    // adds a simple summary at the end
    myFile << "Total Flights: " << result.size() << "\n";
    myFile << "Total additional stops: " << total_stops << "\n"
           << "Optimality Criteria: flights \n";
    myFile.close();
}

/**
 * Performs search for route from given start to desired destination
 * @param start_city is the airport code at the user's origin
 * @param destination is an airport code for the destination airport
 * @return vector<Node> of the connected airports in a sequence
 */
vector<Node> Search::searchAlgorithm(string start_city, string destination)
{
    // create node for the start airport
    Node *node = new Node(start_city, nullptr, 0, NULL);
    deque<Node> frontier;
    unordered_set<string> explored;

    if (goal_test(node->code, destination))
    {
        return solution_path(node);
    }

    frontier.push_back(*node);

    // continue to explore airport nodes till the destination is found
    while (!frontier.empty())
    {
        Node *removed_node = new Node(frontier.front().code, frontier.front().parent, frontier.front().stops, frontier.front().airline);
        frontier.pop_front();
        vector<vector<string>> child_nodes = actions(removed_node->code); // get all destinations

        for (vector<string> child_str : child_nodes)
        {
            Node *child = new Node(child_str[0], removed_node, stoi(child_str[1]), child_str[2]);
            if (goal_test(child->code, destination))
            {
                return solution_path(child);
            }
            // if child is not the goal, add to frontier
            deque<Node>::iterator front;
            front = find(frontier.begin(), frontier.end(), &child);

            if (front == frontier.end() && explored.find(child->code) == explored.end())
            {
                frontier.push_back(*child);
            }
        }
        // append the explored parent to the explored set
        explored.insert(removed_node->code);
    }
}
