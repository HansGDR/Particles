#include "Engine.h"
#include <cstdlib>
#include <ctime>
using namespace std;

srand(time(0));

int main()
{
	// Declare an instance of Engine
	Engine engine;
	// Start the engine
	engine.run();
	// Quit in the usual way when the engine is stopped
	return 0;
}