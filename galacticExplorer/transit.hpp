#ifndef MMCD_TRANSIT_HPP
#define MMCD_TRANSIT_HPP
/****************************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:23:17 PST 2016
 * *Description: I had a good time thinking about
 * the transit hub idea. It reminded me of a
 * computer science puzzle I read somewhere that
 * asked what the fastest way to transfer a file
 * of asymptotic size. The answer is that it is
 * eventually faster to put the physical file
 * on a plane and fly it to its destination, as
 * opposed to online transfer. I imagine the
 * transit hub as something that physically picks
 * up the captain's physical container and carries
 * it a vast distance to the next node.
 * ************************************************/
#include "dataNode.hpp"

class Transit: public DataNode
{
private:
	bool unlocked;
public:
	Transit(DataNode*);
	~Transit();

	virtual void nodeScript();
	virtual void moveMenu();
	virtual bool nodeFunction();
	virtual void linkNode(){};
};
#endif

