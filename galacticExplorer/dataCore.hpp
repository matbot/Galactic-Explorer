#ifndef MMCD_DATACORE_HPP
#define MMCD_DATACORE_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:20:44 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"

class DataCore: public DataNode
{
public:
	DataCore(DataNode*);
	~DataCore();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode();
};
#endif

