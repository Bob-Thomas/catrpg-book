//
// Created by smart on 9/18/2015.
//

#ifndef CATRPG_GAME_H
#define CATRPG_GAME_H

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();
    private:
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
        const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

        sf::RenderWindow mWindow;
        sf::Texture mTexture;
        sf::Sprite mPlayer;
        bool mIsMovingRight = false;
        bool mIsMovingLeft = false;
        bool mIsMovingDown = false;
        bool mIsMovingUp = false;
        float playerSpeed;
};


#endif //CATRPG_GAME_H
