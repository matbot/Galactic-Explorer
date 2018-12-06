#ifndef MMCD_DATANODE_HPP
#define MMCD_DATANODE_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:21:10 PST 2016
 * *Description: 
 * *********************************************/
#include <string>

class Player;

class DataNode
{
protected:
	std::string nodeName;
	
	Player* player;

	DataNode* uNode;
	DataNode* dNode;
	DataNode* lNode;
	DataNode* rNode;
public:
	DataNode();
	virtual ~DataNode();

	std::string getNodeName();
	virtual void nodeScript() = 0;
	int nodeMenu();
	virtual void moveMenu() = 0;
	virtual bool nodeFunction() = 0;
	virtual void linkNode() = 0;

	friend class Player;
};
#endif
