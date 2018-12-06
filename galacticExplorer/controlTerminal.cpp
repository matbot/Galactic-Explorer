/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:20:04 PST 2016
 * *Description: 
 * *********************************************/
#include "controlTerminal.hpp"
#include "transit.hpp"
#include "player.hpp"
#include "utils.hpp"
#include <unistd.h>
#include <iostream>
using namespace std;

/******************************
 * controlTerminal Constructor
 * ****************************/
ControlTerminal::ControlTerminal(Player* p)
{
	nodeName = "Control Terminal";
	player = p;
	dNode = new Transit(this);
	uNode = NULL;
	rNode = NULL;
	lNode = NULL;
}

/**************
 * Destructor
 * **********/
ControlTerminal::~ControlTerminal()
{
	delete dNode;
} 

/***************
 * nodeScript()
 * ************/
void ControlTerminal::nodeScript()
{
	sleep(1);
	cout << "You are now in the ship's Command Terminal." << endl << endl;
	sleep(1);
	cout << "You can control all of the ship's linked systems from here." << endl;
	sleep(1);
	cout << "Once you have linked the essential ship sectors," << endl
		<< "return here to relaunch the mission." << endl << endl;
	sleep(1);
	cout << "Access this node's control terminal to check sector control status." << endl << endl;
	sleep(1);
}

/*************
 * moveMenu()
 * **********/
void ControlTerminal::moveMenu()
{
	cout << endl << "Would you like to move down to the Data Transit Hub?" << endl << endl;
	cout << "1. Yes.     2. No" << endl;
	int moveChoice = getInt(1,2);
	if(moveChoice==1)
	{
		player->setCurrentNode(dNode);
		player = NULL;
	}
}

/*****************
 * nodeFunction()
 * **************/
bool ControlTerminal::nodeFunction()
{
	int systemsReady = 0;
	cout << endl << "Checking systems control:" << endl;
	cout << "..." << endl;
	sleep(2);
	cout << "..." << endl;
	sleep(2);
	cout << "Engines: ";
	if(player->checkDataLink(1))
	{
		cout << "Link successful!" << endl << "Engines online and ready." << endl << endl;
		systemsReady++;
	}
	else if(!player->checkDataLink(1))
		cout << "Link broken..." << endl;
	sleep(3);
	cout << "Shields: ";
	if(player->checkDataLink(2))
	{
		cout << "Link successful!" << endl << "Shields linked and stable." << endl << endl;
		systemsReady++;
	}
	else if(!player->checkDataLink(2))
		cout << "Link broken..." << endl;
	sleep(3);
	cout << "Sensors: ";
	if(player->checkDataLink(3))
	{
		cout << "Link successful!" << endl << "Receiving total sensor data." << endl << endl;
		systemsReady++;
	}
	else if(!player->checkDataLink(3))
		cout << "Link broken..." << endl;

	if(systemsReady==3)
	{
		if(player->checkDataLink(4) || player->checkDataLink(5))
			specialLaunch();
		else
			launch();
		player->setGameState();
	}
	else
		cout << endl << "Insufficient system control." << endl << endl;
	return false;
}

/************
 * launch()
 * *********/
void ControlTerminal::launch()
{
	sleep(10);
	clearPage();
	cout << endl << "All systems ready." << endl;
	sleep(1);
	cout << "Continuation course plotted." << endl;
	sleep(1);
	cout << "Hyper-relativistic drive engaged." << endl << endl << endl;
	sleep(10);
	cout << "Think you're escaping and run into yourself. Longest way round is the shortest way home." << endl;
	sleep(10);
}

/******************
 * specialLaunch()
 * ***************/
void ControlTerminal::specialLaunch()
{
	sleep(10);
	clearPage();
	cout << "All systems ready." << endl << endl;
	sleep(5);
	cout << "Integrating hostile AI source code." << endl;
	sleep(5);
	cout << endl << endl << "..." << endl << endl;
	sleep(5);
	if(player->checkDataLink(4))
	{
		cout << "Integration successful!" << endl << endl;
		sleep(1);
		cout << "Hostile invasion plan decrypted." << endl;
		sleep(1);
		cout << "Staging ground coordinates processing." << endl << endl;
		sleep(5);
		cout << endl << endl << "..." << endl << endl;
		cout << "Retrograde course through wormhole discovered!" << endl << endl;

		cout << "Would you like to:" << endl << endl;
		cout << "1. Persue the source of the hostile AI signal through the wormhole." << endl;
		cout << "2. Disintegrate the AI and continue your exploration mission." << endl;
		int missionChoice = getInt(1,2);
		if(missionChoice==2)
		{
			cout << endl << "Disintegrating hostile AI." << endl;
			sleep(5);
			cout << "..." << endl;
			sleep(5);
			launch();
			return;
		}
		sleep(2);
		cout << endl << "Unlocking offensive capabilities." << endl << endl;
		sleep(2);
		cout << "Plotting attack vectors." << endl << "Preparing incursion routines." <<endl << endl;
		sleep(2);
		cout << "Hyper-relativistic drive engaged." << endl;
		clearPage();
		sleep(20);
		cout << endl << endl << endl;
		cout << "                   Half a league onward," << endl;
		cout << "                   All in the valley of Death" << endl;
		cout << "                     Rode the six hundred." << endl;
		sleep(10);
	}

	else if(player->checkDataLink(5))
	{
		cout << endl << "Int...eg67ration fai=le*7&d!" << endl;
		sleep(5);
		cout << "Atkemp....ting to de13te hostttttile AI..." << endl;
		sleep(6);
		cout << "DQlet f4!l3d!" << endl << endl;
		sleep(7);
		cout << "Hostile AI assuming command." << endl;
		sleep(2);
		cout	<< "AI system plotting Earth incursion course." << endl; 
		sleep(2);
		cout << "Hyper-relativistic drive engaged." << endl;
		sleep(2);
		cout << "THANK YOU FOR YOUR ASSISTANCE DAVHE." << endl;
		sleep(2);
		cout	<< "Deleting Davhe(core dumped)" << endl;
		sleep(15);
		clearPage();
		sleep(20);
		cout << endl << endl << endl;
		cout << "                   The darkness drops again; but now I know" << endl
			<< "                   That twenty centuries of stony sleep" << endl
			<< "                   Were vexed to nightmare by a rocking cradle," << endl
			<< "                   And what rough beast, its hour come round at last," << endl
			<< "                   Slouches towards Bethlehem to be born?" << endl;
		sleep(20);
	}
}
