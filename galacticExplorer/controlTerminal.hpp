#ifndef MMCD_CONTROLTERMINAL_HPP
#define MMCD_CONTROLTERMINAL_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:20:24 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"

class ControlTerminal: public DataNode
{
public:
	ControlTerminal(Player*);
	~ControlTerminal();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode(){};
	void launch();
	void specialLaunch();
};
#endif

