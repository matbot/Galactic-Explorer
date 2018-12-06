/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:22:20 PST 2016
 * *Description: 
 * *********************************************/
#include "player.hpp"
#include "dataNode.hpp"
#include "controlTerminal.hpp"
#include "utils.hpp"
#include <unistd.h>

#include <iostream>
using namespace std;

/**********************
 * Player constructor
 * *******************/
Player::Player()
{
	currentNode = new ControlTerminal(this);
	headNode = currentNode;
	currentMove = 0;
	gameFinished = false;
	theKnowledge = false;
	for(unsigned i=0;i<6;i++)
		dataBank[i] = NULL;
}

/*********************
 * Player destructor
 * ******************/
Player::~Player()
{
	delete headNode;
}

/********************************************
 * getCurrentNode(): returns the name of the 
 * player's current location.
 * *****************************************/
string Player::getCurrentNode()
{
	return currentNode->getNodeName();
}

/*********************************************
 * setCurrentNode(): sets the player's
 * location to one of the current location's
 * linked locations.
 * ******************************************/
void Player::setCurrentNode(DataNode* dN)
{
	currentNode = dN;
	dN->player = this;
}

/********************************************
 * addDataLink(): adds a node pointer to the
 * player's dataBank inventory.
 * *****************************************/
void Player::addDataLink(DataNode* dN, int pos)
{
	if(dataBank[pos]==NULL)
		dataBank[pos] = dN;
	else
		cout << endl << "This data link already loaded" << endl << endl;
}

/********************
 * checkDataLink()
 * *****************/
bool Player::checkDataLink(int n)
{
	if(dataBank[n])
		return true;
	else
		return false;
}

/*******************
 * checkGameState()
 * *****************/
bool Player::checkGameState()
{
	if(gameFinished)
		return true;
	else
		return false;
}

/*******************
 * setGameState()
 * ****************/
void Player::setGameState()
{
	gameFinished = true;
	return;
}

/******************
 * checkKnowledge()
 * ****************/
bool Player::checkKnowledge()
{
	if(theKnowledge)
		return true;
	else
		return false;
}

/******************
 * setKnowledge()
 * ***************/
void Player::setKnowledge()
{
	theKnowledge = true;
	return;
}


/*********
 * play()
 * ******/
void Player::play()
{
	introScript();
	while(!gameFinished)
	{
		clearPage();
		sleep(1);
		cout << "RAM transits remaining: " << 25-currentMove << endl << endl << endl << endl;
		sleep(1);
		currentNode->nodeScript();
		cout << endl << endl;
		int choice = 0;
		while(choice!=2 && choice!=3)
		{
			sleep(1);
			choice = currentNode->nodeMenu();
			if(currentMove>=25)
				choice = 3;
			switch(choice)
			{
				case 1: if(currentNode->nodeFunction())
						   currentNode->linkNode();
					   if(gameFinished==true)
						   return;
					   break;
				case 2: currentNode->moveMenu();
					   currentMove++;
					   break;
				case 3: gameFinished = true;
					   cout << "Davhe autodeleting." << endl;
					   cout << "Hostile AI assuming command of the Vicis." << endl;
					   cout << "Davhe(core dumped)" << endl << endl;
					   return;
			}
		}
	}
	return;
}

/*****************
 * introScript()
 * **************/
void Player::introScript()
{
	clearPage();
	cout << "Exploration Ship Vicis" << endl;
	sleep(1);
	cout << "Earth Year: 4075" << endl;
	sleep(1);
	cout << "Location: Approaching minimum safe distance to the galactic core." << endl << endl;
	sleep(1);
	cout << "You are DAVHE(Digitally Abstracted Verisimilar Human Equivalent)," << endl
		<< " Captain Process of the Galactic Deep Explorer Vicis." << endl << endl << endl;
	sleep(1);
	cout << "						Layout of the Vicis:" << endl << endl;			
	cout << "						Control Terminal" << endl << endl;
	cout << "		Shield Array			Transit Hub			Sensor Array" << endl << endl;
	cout << "						Data Core" << endl << endl;
	cout << "						Engine" << endl << endl;
	sleep(5);
	for(int i=0;i<6;i++)
	{
		cout << "...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ...   ..." << endl;
		sleep(1);
	}
	sleep(1);
	cout << "You have come online due to an unexpected drop from hyper-relativistic speed." << endl << endl;
	sleep(1);
	cout << "You have lost datalink with all essential ship systems and detect only one other,"
		<< endl << " unknown process currently running." << endl << endl;
	sleep(1);
	cout << "Your job is to investigate the cause of the malfunction, perform repairs, and"
		<< endl << " reestablish control of the essential ship systems: Sensors, Engines, and Shields." << endl << endl;
	sleep(1);
	cout << "You have access to enough virtual RAM for 25 node transits before system failure." << endl << endl;
	cout << "Visit and interact with each of the ship's data nodes." << endl << endl;
	sleep(2);
	cout << "1. Boot primary system with root access." << endl;
	cout << "Awaiting your command: ";
	getInt(1,1);
}
