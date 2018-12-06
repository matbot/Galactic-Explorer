/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:21:19 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"
#include "player.hpp"
#include "utils.hpp"

#include <iostream>
using namespace std;

/*********************
 * Empty Constructor
 * ******************/
DataNode::DataNode()
{
}

/*********************
 * Virtual Destructor
 * ******************/
DataNode::~DataNode()
{
}

/*****************
 * getNodeName()
 * **************/
string DataNode::getNodeName()
{
	return nodeName;
}

/*************
 * nodeMenu()
 * **********/
int DataNode::nodeMenu()
{
	cout << "Would you like to:" << endl << endl;
	cout << "1. Interface with this node's control terminal." << endl;
	cout << "2. Transit to an adjacent terminal." << endl;
	cout << "3. Exit system. !!You will be deleted!!" << endl;
	int choice = getInt(1,3);
	return choice;
}
