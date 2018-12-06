/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:23:27 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "controlTerminal.hpp"
#include "transit.hpp"
#include "shields.hpp"
#include "sensors.hpp"
#include "dataCore.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

/******************************
 * Transit Constructor
 * ****************************/
Transit::Transit(DataNode* dN)
{
	nodeName = "Transit Hub";
	unlocked = false;
	player = NULL;

	uNode = dN;
	dNode = new DataCore(this);
	lNode = new Shield(this);
	rNode = new Sensor(this);
}

/**************
 * Destructor
 * **********/
Transit::~Transit()
{
	delete lNode;
	delete rNode;
	delete dNode;
} //will hopefully descend to parent destructor.

/***************
 * nodeScript()
 * ************/
void Transit::nodeScript()
{
	if(!unlocked)
	{
		cout << "You are now in the Rapid Data Transit Hub, or DTH." << endl;
		sleep(1);
		cout << "The DTH allows you to quickly access the rest of the ship." << endl;
		sleep(1);
		cout << "These massive data transfers would normally take days to complete," << endl
			<< "but can be done nearly instantaneously via the Transit Hub." << endl;
		sleep(1);
		cout << "But..." << endl << endl;
		sleep(1);
		cout << "The Hub is currently locked!" << endl;
		cout << "All incoming and outgoing data streams are dark." << endl << endl;
		cout << "It appears you have been trapped here!" << endl << endl;
	}
	else if(unlocked)
		cout << "The Transit Hub is fully functional! Please select your destination." << endl << endl;
}

/*************
 * moveMenu()
 * **********/
void Transit::moveMenu()
{
	if(!unlocked)
		cout << "The Hub is locked! You're trapped and losing RAM!" << endl << endl;
	else if(unlocked)
	{
		cout << endl << endl << "Would you like to transit:" << endl << endl;
		cout << "1. Up to the Control Terminal." << endl;
		cout << "2. Left to the Shield Terminal." << endl;
		cout << "3. Right to the Sensor Array." << endl;
		cout << "4. Down to the Data Core." << endl;

		int moveChoice = getInt(1,4);
		switch(moveChoice){
			case 1: player->setCurrentNode(uNode);
				   player = NULL;
				   break;
			case 2: player->setCurrentNode(lNode);
				   player = NULL;
				   break;
			case 3: player->setCurrentNode(rNode);
				   player = NULL;
				   break;
			case 4: player->setCurrentNode(dNode);
				   player = NULL;
				   break;}
	}
}

/*****************
 * nodeFunction()
 * **************/
bool Transit::nodeFunction()
{
	if(!unlocked)
	{
		cout << endl << "You've located a logic bypass in the lock! But it's encrypted..." << endl << endl;
		cout << "Do you want to try to decrypt it?" << endl << endl;
		cout << "1. Yes           2. No" << endl;
		int choice = getInt(1,2);
		if(choice==1)
		{
			cout << endl << "Attempting to decrypt logic bypass..." << endl;
			sleep(3);
			cout << "..." << endl;
			sleep(3);
			int chance = randInt(100);
			if(chance>25)
			{
				cout << "Decryption successful! Transit Hub unlocked and online!" << endl << endl;
				unlocked = true;
			}
			else if(chance<=25)
				cout << "The unknown process has detected your decryption attempt and reset"
					<< " the logic bypass." << endl << "I don't think it likes you." << endl << endl << endl;
		}
	}
	else if(unlocked)
		cout << "You have already unlocked the Transit Hub. Good job." << endl << endl;
	return false;
}

