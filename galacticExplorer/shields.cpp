/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:23:04 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "shields.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

/******************************
 * shield Constructor
 * ****************************/
Shield::Shield(DataNode* dN)
{
	nodeName = "Shield Terminal";
	player = NULL;

	rNode = dN;
	lNode = NULL;
	uNode = NULL;
	dNode = NULL;

	//for(unsigned int i=0;i<freqs.size();i++)
	//	freqs[i] = i+1000000;
}

/**************
 * Destructor
 * **********/
Shield::~Shield()
{} //parent destructor.

/***************
 * nodeScript()
 * ************/
void Shield::nodeScript()
{
	cout << "You are now in the Shield control station." << endl;
	sleep(1);
	cout << "The air in the Shield station crackles with exotic particle energy transfer." << endl;
	sleep(1);
	cout << "It is important to set and maintain the proper shield frequency to protect the ship." << endl;
	sleep(1);
	cout << "Interact with the node to search for the shield frequency and gain control." << endl << endl;
	sleep(1);
}

/*************
 * moveMenu()
 * **********/
void Shield::moveMenu()
{
	cout << "Would you like to move right to the Data Transit Hub?" << endl << endl;
	cout << "1. Yes       2. No" << endl;
	int moveChoice = getInt(1,2);
	if(moveChoice==1)
	{
		player->setCurrentNode(rNode);
		player = NULL;
	}
}
/*****************
 * nodeFunction()
 * **************/
bool Shield::nodeFunction()
{
	cout << endl << "Shield automation was lost and you will have to search for it manually." << endl;
	sleep(1);
	cout << "A proper shield frequency of 1845z381cZ is needed to restore shield function." << endl;
	sleep(1);
	cout << "Unfortunately, an unknown process on the ship has followed you" << endl
		<< " into the Shield station and may limit your search capability." << endl;
	sleep(1);
	cout << "Searches of O(n) or greater complexity should not be attempted." << endl << endl;
	sleep(1);
	cout << "Would you like to attempt:" << endl << endl;
	cout << "1. Linear Search	 2. Binary Search" << endl;
	int searchChoice = getInt(1,2);
	switch(searchChoice){
		case 1: cout << endl << "Searching..." << endl;
			   sleep(3);
			   cout << "Search aborted." << endl;
			   cout << "The hostile process has locked your input!" << endl;
			   sleep(10);
			   cout << "..." << endl;
			   sleep(10);
			   cout << "Rerouting" << endl;
			   sleep(5);
			   cout << "..." << endl << endl;
			   sleep(2);
			   return false;
			   break;
		case 2: cout << "Searching..." << endl;
			   sleep(1);
			   cout << "Search successful!" << endl;
			   sleep(1);
			   cout << "Shields coming online." << endl;
			   sleep(1);
			   cout << "Establishing control." << endl << endl;
			   sleep(1);
			   cout << "Shields online and linked!" << endl << endl;
			   sleep(1);
			   return true;
			   break;}
	return false;
}

/***************************************************
 * linkNode(): adds a pointer to the current node
 * to the player's dataBank array.
 * ************************************************/
void Shield::linkNode()
{
	player->addDataLink(this,2);
	return;
}
