#ifndef MMCD_PLAYER_HPP
#define MMCD_PLAYER_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:22:02 PST 2016
 * *Description: 
 * *********************************************/
#include <string>

class DataNode;

class Player
{
protected:
	DataNode* currentNode;
	DataNode* headNode;
	int currentMove;
	DataNode* dataBank[6]; 
	bool gameFinished;
	bool theKnowledge;
public:
	Player();
	~Player();

	std::string getCurrentNode();
	void setCurrentNode(DataNode*);
	void addDataLink(DataNode*,int);
	void introScript();
	bool checkDataLink(int);
	bool checkGameState();
	void setGameState();
	bool checkKnowledge();
	void setKnowledge();

	void play();

	friend class DataNode;
};
#endif
