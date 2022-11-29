/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */

#include "main.h"

using namespace std;

/**
 * getStart method
 * @brief return the String start_city_destination location
 * @return start_city_destination
 *
 */
string Start::getStart()
{

    /**
     * Instatiating the readInput class
     */

    readInput inputs;
    string start_city_destination;

    for (int i = 0; i < inputs.Input().size(); i++)
    {
        start_city_destination = inputs.Input()[i];
        return start_city_destination;
        // AFTER RUNNING THIS CLASS IT SHOULD RETURN A
        // STRING OF THE START CITY AND START COUNTRY
    }
    return "0";
}