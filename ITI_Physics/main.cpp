#include <SFML/Graphics.hpp>
#include "PhysicsWorld.h"
#include "Renderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    Renderer renderer;
    renderer.AddDrawable(&shape);

    PhysicsWorld world;

    Particle p(Vector2d(0, 0));
    world.addParticle(&p);

    Clock clock;

    float time = 0;
    float dt = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) p.addForce(Vector2d(0, -10000));
        if (Keyboard::isKeyPressed(Keyboard::Down)) p.addForce(Vector2d(0, 10000));
        if (Keyboard::isKeyPressed(Keyboard::Right)) p.addForce(Vector2d(10000, 0));
        if (Keyboard::isKeyPressed(Keyboard::Left)) p.addForce(Vector2d(-10000, 0));

        dt = clock.getElapsedTime().asSeconds() - time;
        time += dt;

        world.Update(dt);

        shape.setPosition((Vector2f)p.position);

        renderer.Render(&window);
    }

    return 0;
}