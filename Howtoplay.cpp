#include "Howtoplay.h"
#include "Global.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

Howtoplay::Howtoplay() : h_window(sf::VideoMode(672, 704), "How to Play") {
    //sf::View view(sf::FloatRect(0, 0, 672, 704)); // Initial view
    //h_window.setView(view);
    if (!h_texture.loadFromFile("htp1.png")) {
        
    }
    h_sprite.setTexture(h_texture);

    if (!h_soundBuffer.loadFromFile("pacman_eatfruit.wav")) {
        std::cout << "Error loading sound" << std::endl;
    }
    h_sound.setBuffer(h_soundBuffer);
}

int Howtoplay::show()
{
    sf::View view(sf::FloatRect(0, 0, 672, 704)); // Initial view
    h_window.setView(view);
    while (h_window.isOpen()) {
        sf::Event event;
        while (h_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                h_window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                h_window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                view.move(-5, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                view.move(5, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                view.move(0, -5);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                view.move(0, 5);

            h_window.setView(view);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(h_window);

                   
                    if (mousePosition.x > 8 && mousePosition.x < 57 && mousePosition.y > 7 && mousePosition.y < 25) {
                        // Perform a specific task for clicks in the specified area
                        std::cout << "option 2 how to play" << std::endl;
                        h_sound.play();
                        return 1;


                    }
                    

                }
            }
        }
        h_window.clear();
        h_window.draw(h_sprite);
        h_window.display();

    }
    return 0;
}