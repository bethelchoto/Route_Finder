/**
 * @author Bethel Panashe Choto 
 * @author Ruvimbo Joy Sithole
 *
 */
#include "main.h"

using namespace std;

int main()
{
    writeInput win;
    Start st;
    cout << st.getStart() << "\n";
    Destination ds;
    cout << ds.getDestination() << "\n";
    ReadAirport rd;
    ReadAirport();
    Routes RT;
    RT.Route();
    ReadRoutes RD;
    cout << RD.displayRoutes() << "\n";

    Search SN;
    SN.searchAlgorithm(rd.readAirport()[0], rd.readAirport()[1]);
}