#pragma once

#ifndef mainmenu_h
#define mainmenu_h

#include <sfml/graphics.hpp>
#include <sfml/audio.hpp>
#include <iostream>
#include"Howtoplay.h"



class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    void run();
    int draw();

private:
    void handleEvents();
    void update();
    void render();


    sf::RenderWindow& m_window;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::SoundBuffer m_soundBuffer;
    sf::Sound m_sound;

    bool m_showingRules;

};

#endif // MAINMENU_H