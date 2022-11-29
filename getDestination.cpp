/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */

#include "main.h"

using namespace std;

/**
 * @brief returns the string of the destination_city_country
 * @return destination_city_country
 *
 */
string Destination::getDestination()
{

    /**
     * Instatiating the readInput class
     */
    readInput inputs;

    for (int i = 0; i < inputs.Input().size(); i++)
    {
        string destination_city_country = inputs.Input()[i + 1];
        return destination_city_country;
    }
    return "0";
}