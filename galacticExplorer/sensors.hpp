#ifndef MMCD_SENSORS_HPP
#define MMCD_SENSORS_HPP
/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:22:33 PST 2016
 * *Description: 
 * *********************************************/
#include "dataNode.hpp"

class Sensor: public DataNode
{
public:
	Sensor(DataNode*);
	~Sensor();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode();
};
#endif

