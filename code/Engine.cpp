#include "Engine.h"

void Engine::input()
{
    
}
void Engine::update(float dtAsSeconds)
{

}
void Engine::draw()
{

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