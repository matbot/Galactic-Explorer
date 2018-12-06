/*********************************************
 * *Author: Mathew McDade
 * *Date: Mon Dec  5 22:19:36 PST 2016
 * *Description: The main method.
 * *********************************************/
#include "player.hpp"
#include "game.hpp"
#include "controlTerminal.hpp"
#include "transit.hpp"
#include "shields.hpp"
#include "sensors.hpp"
#include "dataCore.hpp"
#include "engines.hpp"
#include "utils.hpp"

using namespace std;

int main()
{
	srand(time(NULL));

	Player davhe;

	davhe.play();

	return 0;
}
