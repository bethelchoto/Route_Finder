/**
 *@author Ruvimbo Sithole
 *@author Bethel Choto
 */

#include "main.h"
using namespace std;

/*
 *constructor
 */
Node::Node(string code, Node *parent, int stops, string airline)
{
    this->code = code;
    this->parent = parent;
    this->stops = stops;
    this->airline = airline;
}