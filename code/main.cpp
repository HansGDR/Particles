#include "Engine.h"
#include <cstdlib>
#include <ctime>
using namespace std;



int main()
{
	// Random seed
	srand(static_cast<unsigned int>(time(0)));
	// Declare an instance of Engine
	Engine engine;
	// Start the engine
	engine.run();
	// Quit in the usual way when the engine is stopped
	return 0;
}