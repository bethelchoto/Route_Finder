/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */
#include "main.h"

using namespace std;

/**
 * Global Variable
 */
vector<string> start_destination;

string writeInput::WritetoFile()
{
    /**
     * Local Variables
     */
    vector<string> row;
    string line, word;
    string start_city_destination;
    /**
     *
     * writing to a file input csv
     */
    fstream myFile;
    myFile.open("input.csv", ios::out); // write
    if (myFile.is_open())
    {
        myFile << "Accra,Ghana\n";
        myFile << "Winnipeg,Canada\n";
        myFile.close();
    }
    return "File Created";
}
