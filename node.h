/**
 * @author Bethel Panashe Choto
 * @author Ruvimbo Joy Sithole
 *
 */
#ifndef NODE_H
#define NODE_H

#include "main.h"
using namespace std;

class Node
{

public:
    string code;
    Node *parent;
    int stops;
    string airline;
    Node(string code, Node *parent, int stops, string airline);
    // friend std::ostream &operator==(const Node &one, const Node &two);

    bool operator==(const Node &one) const
    {
        return this->code == one.code;
    }
};

#endif // NODE_H