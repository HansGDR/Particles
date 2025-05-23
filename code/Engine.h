#pragma once
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "TextureHolder.h"
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class Engine
{
private:
	// A regular RenderWindow
	RenderWindow m_Window;
	TextureHolder th;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	SoundBuffer pingBuffer;
	Sound ping;
	Music music;
	
	


	//vector for Particles
	vector<Particle> m_particles;

	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	// The Engine constructor
	Engine();
	

	// Run will call all the private functions
	void run();
	


};