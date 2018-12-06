/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:22:45 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "sensors.hpp"
#include "game.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

/******************************
 * sensors Constructor
 * ****************************/
Sensor::Sensor(DataNode* dN)
{
	nodeName = "Sensor Array";
	player = NULL;

	lNode = dN;
	rNode = NULL;
	uNode = NULL;
	dNode = NULL;
}

/**************
 * Destructor
 * **********/
Sensor::~Sensor()
{}

/***************
 * nodeScript()
 * ************/
void Sensor::nodeScript()
{
	cout << "You are in the Sensor Array Arm." << endl << endl;
	sleep(1);
	cout << "Miles of finely tuned sensors are housed here." << endl
		<< "These sensors continuously gather full spectrum data" << endl
		<< "and transmit it to the Data Storage Core during exploration." << endl << endl;
	sleep(1);
}

/*************
 * moveMenu()
 * **********/
void Sensor::moveMenu()
{
	cout << endl << "Would you like to move left to the Data Transit Hub?" << endl << endl;
	cout << "1. Yes      2. No" << endl;
	int moveChoice = getInt(1,2);
	cout << endl;
	if(moveChoice==1)
	{
		player->setCurrentNode(lNode);
		player = NULL;
	}
}

/*****************
 * nodeFunction()
 * **************/
bool Sensor::nodeFunction()
{
	cout << endl << "It looks like the Sensor Array is overloaded with some unkown type of data!" << endl << endl;
	sleep(1);
	cout << "You should inject some zero point viral predators to clear the sensor stream." << endl;
	sleep(1);
	cout << "How many predators would you like to insert?" << endl;
	int preds = getInt(25,75);
	Game g(250,20,50,500, preds);
	g.runBoard();
	sleep(1);
	cout << "Clearing sensor stream." << endl;
	sleep(2);
	cout << "..." << endl;
	sleep(2);
	cout << "Linking Sensor Array." << endl;
	sleep(1);
	cout << "Receiving backlog data." << endl;
	sleep(1);
	cout << "The sensor backlog shows that the system crash was related to a previously"
		<< endl << " undetected, novel-type black hole." << endl << endl;
	sleep(1);
	cout << "The Vicis passed dangerously close to the gravity well and was overwhelmed by"
		<< endl << " a hostile signal that overloaded the sensors and caused a shipwide shutdown." << endl;
	sleep(1);
	cout << "This is the likely source of the unknown, hostile process onboard." << endl;
	sleep(1);
	cout << "The hostile AI is hiding in the Data Core." << endl;
	sleep(1);
	cout << "You should try to capture the alien process if possible..." << endl << endl;
	sleep(1);
	player->setKnowledge();
	return true;
}

/***************************************************
 * linkNode(): adds a pointer to the current node
 * to the player's dataBank array.
 * ************************************************/
void Sensor::linkNode()
{
	player->addDataLink(this,3);
	return;
}

