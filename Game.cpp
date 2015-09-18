//
// Created by smart on 9/18/2015.
//

#include <c++/iostream>
#include "Game.h"

Game::Game() : mWindow(sf::VideoMode(640, 480), "CATRPG"), mPlayer(), mTexture() {
    if(!mTexture.loadFromFile("resources/Textures/Eagle.png")) {
        std::cout << "KANKER TEXTURE WERKT NIET" << std::endl;
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
    playerSpeed = 100.f;
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}


void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp) {
        movement.y -= playerSpeed;
    }
    if(mIsMovingDown) {
        movement.y += playerSpeed;
    }
    if(mIsMovingLeft) {
        movement.x -= playerSpeed;
    }
    if(mIsMovingRight) {
        movement.x += playerSpeed;
    }
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render() {
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    switch(key) {
        case sf::Keyboard::W:
            mIsMovingUp = isPressed;
            break;
        case sf::Keyboard::S:
            mIsMovingDown = isPressed;
            break;
        case sf::Keyboard::A:
            mIsMovingLeft = isPressed;
            break;
        case sf::Keyboard::D:
            mIsMovingRight = isPressed;
            break;
        default: break;
    }
}
