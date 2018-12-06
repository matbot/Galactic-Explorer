#ifndef MMCD_SHIELDS_HPP
#define MMCD_SHIELDS_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:22:55 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"

class Shield: public DataNode
{
private:
	//unsigned long freqs[1000000];
public:
	Shield(DataNode*);
	~Shield();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode();
};
#endif

