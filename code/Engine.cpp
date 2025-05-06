#include "Engine.h"
#include "TextureHolder.h"
using namespace sf;
void Engine::input()
{
    VideoMode desktop = VideoMode::getDesktopMode();
     m_BackgroundTexture = TextureHolder::GetTexture("graphics/astro.png");
     m_BackgroundSprite.setTexture(m_BackgroundTexture);
    Event event;
    while (m_Window.pollEvent(event)) 
    {
        if (event.type == Event::Closed)
            m_Window.close();

        if (event.type == Event::MouseButtonPressed) 
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                int numParticles = 5;           // Increase the numParticles
                for (int i = 0; i < numParticles; i++)
                {
                    int start = 25; int end = 50;
                    int numPoints = (rand() % (end - start + 1)) + start;
                    Vector2i mousePos = Mouse::getPosition(m_Window);
                    Particle p(m_Window, numPoints, mousePos);
                    m_particles.push_back(p);
                }
            }     
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        m_Window.close();
    }
}
void Engine::update(float dtAsSeconds)
{

    for (auto iter = m_particles.begin(); iter != m_particles.end(); )
    {
        if (iter->getTTL() > 0.0)
        {
            iter->update(dtAsSeconds);
            iter++;
        }
        else
        {
            iter = m_particles.erase(iter);
        }
    }
}
void Engine::draw()
{
    m_Window.clear();


    m_Window.draw(m_BackgroundSprite);
    for (auto p : m_particles)
    {
       
        m_Window.draw(p);
    }
    m_Window.display();
}
Engine::Engine()
{
    m_Window.create(VideoMode::getDesktopMode(), "Particles");
}
void Engine::run()
{
    // Unit Testngs
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    
    Clock clk;
    while (m_Window.isOpen())
    {
        Time dt = clk.restart();
        float dtSeconds = dt.asSeconds();
        input();
        update(dtSeconds);
        draw();   
    }
}