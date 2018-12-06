#ifndef MMCD_ENGINES_HPP
#define MMCD_ENGINES_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:21:30 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"

class Engine: public DataNode
{
public:
	Engine(DataNode*);
	~Engine();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode();
};
#endif

