/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:20:55 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "dataCore.hpp"
#include "engines.hpp"
#include "utils.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

/******************************
 * dataCore Constructor
 * ****************************/
DataCore::DataCore(DataNode* dN)
{
	nodeName = "Data Core";
	player = NULL;

	uNode = dN;
	dNode = new Engine(this);
	lNode = NULL;
	rNode = NULL;
}

/**************
 * Destructor
 * **********/
DataCore::~DataCore()
{
	delete dNode;
} //gosh I hope these destructors work.

/***************
 * nodeScript()
 * ************/
void DataCore::nodeScript()
{
	if(player->checkDataLink(4) || player->checkDataLink(5))
	{
		cout << endl << "You have already captured the hostile AI." << endl;
		sleep(1);
		cout << "Automation is returning the Data Core to full function." << endl << endl;
		sleep(1);
		return;
	}
	cout << "You are now in the Data Storage Core." << endl << endl;
	sleep(1);
	cout << "The Data Core is your primary data storage center." << endl;
	sleep(1);
	cout << "You keep all of your valuable exploration data here." << endl;
	sleep(1);
	cout << "But..." << endl;
	sleep(1);
	cout << "This place is a mess. It looks like the unknown process is" << endl
		<< "converting the core to an auxillary command terminal!" << endl << endl;
	sleep(1);
	cout << "The AI is using the Data Core to grow and gain control of the ship's systems." << endl;
	sleep(1);
	cout << "It might be possible to capture the AI by using the Core's link interface, but"
		<< endl << " you should be very careful. Capturing the AI before linking the"
		<< endl << " sensor array may have unintended consequences." << endl << endl;
	sleep(1);
	}

/*************
 * moveMenu()
 * **********/
void DataCore::moveMenu()
{
	cout << endl << "Would you like to move:" << endl << endl;
	cout << "1. Up to the Transit Hub." << endl;
	cout << "2. Down to the Engine." << endl;

	int moveChoice = getInt(1,2);
	switch(moveChoice){
		case 1: player->setCurrentNode(uNode);
			   player = NULL;
			   break;
		case 2: player->setCurrentNode(dNode);
			   player = NULL;
			   break;}
}

/*****************
 * nodeFunction()
 * **************/
bool DataCore::nodeFunction()
{
	cout << endl << "Binding hostile AI." << endl;
	sleep(2);
	cout << "..." << endl;
	sleep(2);
	cout << "Hostile AI linked!" << endl << endl;
	return true;
}

/***************************************************
 * linkNode(): adds a pointer to the current node
 * to the player's dataBank array.
 * ************************************************/
void DataCore::linkNode()
{
	if(player->checkKnowledge())
		player->addDataLink(this,4);
	else
		player->addDataLink(this,5);
	return;
}
