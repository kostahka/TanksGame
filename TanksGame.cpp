#include <SFML/Graphics.hpp>
#include <iostream>

#include "Configurations/Configure.h"
#include "Managers/IOManager.h"
#include "Scenes/GameScene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tanks");

    Configure::Init();
    IOManager* ioManager = IOManager::getCurrent();
    GameScene* gameScene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
    if (!gameScene) {
        std::cout << "Couldn't create scene";
        return -1;
    }
    gameScene->StartOnePlayer();


    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                ioManager->KeyboardEvent(event);
            }
        }
        ioManager->InputLoop();

        window.clear();
        gameScene->Draw(window, elapsed.asMilliseconds());
        window.display();
    }

    return 0;
}