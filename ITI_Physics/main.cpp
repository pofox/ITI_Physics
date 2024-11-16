#include <SFML/Graphics.hpp>
#include "PhysicsWorld.h"
#include "Renderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    //sf::RectangleShape shape(Vector2f(50,50)),shape2(Vector2f(20,100));
    sf::ConvexShape shape(4), shape2(4),dshape(4),dshape2(4);
    shape.setPoint(0, Vector2f(-25, -25));
    shape.setPoint(1, Vector2f(25, -25));
    shape.setPoint(2, Vector2f(25, 25));
    shape.setPoint(3, Vector2f(-25, 25));
    shape2.setPoint(0, Vector2f(-10, -50));
    shape2.setPoint(1, Vector2f(10, -50));
    shape2.setPoint(2, Vector2f(10, 50));
    shape2.setPoint(3, Vector2f(-10, 50));
    //shape.setOrigin(Vector2d(25, 25));
    //shape2.setOrigin(Vector2d(10, 50));
    shape.setFillColor(sf::Color::Green);
    shape2.setFillColor(sf::Color::Yellow);
    //dshape.setFillColor(sf::Color::Color(255, 0, 0, 100));
    //dshape2.setFillColor(sf::Color::Color(255, 0, 0, 100));
    shape2.setPosition(sf::Vector2f(300, 300));

    Renderer renderer;
    renderer.AddDrawable(&shape);
    renderer.AddDrawable(&shape2);
    //renderer.AddDrawable(&dshape);
    //renderer.AddDrawable(&dshape2);

    PhysicsWorld world;

    //Particle p(Vector2d(shape.getPosition().x, shape.getPosition().y), Vector2d(shape.getPosition().x - shape.getSize().x / 2, shape.getPosition().y - shape.getSize().y / 2), Vector2d(shape.getPosition().x + shape.getSize().x / 2, shape.getPosition().y + shape.getSize().y / 2), 1, 0.1);
    //Particle p1(Vector2d(shape2.getPosition().x,shape2.getPosition().y), Vector2d(shape2.getPosition().x - shape2.getSize().x / 2, shape2.getPosition().y - shape2.getSize().y / 2), Vector2d(shape2.getPosition().x + shape2.getSize().x / 2, shape2.getPosition().y + shape2.getSize().y / 2), 1, 0.1);
    Particle p(shape, 1, 0.1);
    Particle p1(shape2, 1, 0.1);
    p.addForce(Vector2d(1000, 1000));
    p1.addForce(Vector2d(-1000, -1000));
    world.addParticle(&p);
    world.addParticle(&p1);

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

        if (Keyboard::isKeyPressed(Keyboard::Up)) p.addForce(Vector2d(0, -1000));
        if (Keyboard::isKeyPressed(Keyboard::Down)) p.addForce(Vector2d(0, 1000));
        if (Keyboard::isKeyPressed(Keyboard::Right)) p.addForce(Vector2d(1000, 0));
        if (Keyboard::isKeyPressed(Keyboard::Left)) p.addForce(Vector2d(-1000, 0));

        dt = clock.getElapsedTime().asSeconds() - time;
        time += dt;

        /*for (int i = 0; i < p.satCollider.points.size(); i++)
        {
            dshape.setPoint(i, p.satCollider.points[i]);
        }
        for (int i = 0; i < p1.satCollider.points.size(); i++)
        {
            dshape2.setPoint(i, p1.satCollider.points[i]);
        }*/

        world.Update(dt);

        shape.setPosition((Vector2f)p.position);
        shape2.setPosition((Vector2f)p1.position);

        renderer.Render(&window);
    }

    return 0;
}