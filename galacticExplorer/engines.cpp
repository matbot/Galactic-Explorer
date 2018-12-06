/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:21:39 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "engines.hpp"
#include "utils.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

/******************************
 * engines Constructor
 * ****************************/
Engine::Engine(DataNode* dN)
{
	nodeName = "Engine Room";
	player = NULL;

	uNode = dN;
	dNode = NULL;
	lNode = NULL;
	rNode = NULL;
}

/**************
 * Destructor
 * **********/
Engine::~Engine()
{}

/***************
 * nodeScript()
 * ************/
void Engine::nodeScript()
{
	cout << "You've made it all the way to the Engine Room!" << endl;
	cout << "All sensors are reading normal here." << endl;
	cout << "You just need to interface and link Engine control." << endl << endl;
}

/*************
 * moveMenu()
 * **********/
void Engine::moveMenu()
{
	cout << "Would you like to move back up to the Data Core?" << endl << endl;
	cout << "1. Yes      2. No" << endl;
	int moveChoice = getInt(1,2);
	if(moveChoice==1)
	{
		player->setCurrentNode(uNode);
		player = NULL;
	}
}

/*****************
 * nodeFunction()
 * **************/
bool Engine::nodeFunction()
{
	cout << endl << "Linking Engine control." << endl;
	sleep(1);
	cout << "..." << endl;
	sleep(1);
	cout << "Engine linked and fully operational!" << endl << endl;
	return true;
}

/***************************************************
 * linkNode(): adds a pointer to the current node
 * to the player's dataBank array.
 * ************************************************/
void Engine::linkNode()
{
	player->addDataLink(this,1);
	return;
}

