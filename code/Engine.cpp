#include "Engine.h"

void Engine::input()
{
    VideoMode desktop = VideoMode::getDesktopMode();
    unsigned int width = desktop.width / 2;
    unsigned int height = desktop.height / 2;

    RenderWindow m_Window(VideoMode(width, height), "Particles");
    while (m_Window.isOpen()) 
    {
        Event event;
        while (m_Window.pollEvent(event)) 
        {
            if (event.type == Event::Closed)
                m_Window.close();

            if (event.type == Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int numParticles = 5;
                    for (int i = 0; i < numParticles; i++)
                    {
                        int start = 25; int end = 50;
                        int numPoints = (rand() % (start + end - 1)) + start;
                        Vector2i mousePos = Mouse::getPosition(m_Window);
                        Particle p(RenderTarget(), numPoints, mousePos);
                        m_particles.push_back();
                    }
                }
                    
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            m_Window.close();
    }
}
void Engine::update(float dtAsSeconds)
{
    Clock clk;
    Time dt = clk.restart();
    for (auto iter = m_particles.begin(); iter != m_particles.end(); )
    {
        if (iter.getTTL() > 0.0)
        {
            iter.update(dt);
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
    for (auto p : m_particles)
    {
        m_window.draw(p);
    }
    m_window.display();
}
Engine::Engine()
{
    m_Window.create(VideoMode::getDesktopMode());
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