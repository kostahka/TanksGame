#include <SFML/Graphics.hpp>
#include <iostream>

#include "Configurations/Configure.h"
#include "Managers/IOManager.h"
#include "Scenes/GameScene.h"
#include "Managers/TimeManager.h"

int main()
{
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();

    if (modes.size() <= 0) {
        std::cout << "Couldn't get fullscreen modes";
        return -1;
    }

    sf::VideoMode currentMode = modes[0];

    sf::RenderWindow window(currentMode, "Tanks", sf::Style::Fullscreen);

    Configure::Init(currentMode);
    TimeManager* timeManager = TimeManager::getCurrent();
    IOManager* ioManager = IOManager::getCurrent();
    GameScene* gameScene = dynamic_cast<GameScene*>(GameScene::getCurrentScene());
    if (!gameScene) {
        std::cout << "Couldn't create scene";
        return -1;
    }
    gameScene->StartTwoPlayers();


    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
            else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                ioManager->KeyboardEvent(event);
            }
        }
        ioManager->InputLoop();
        timeManager->TimeListen(elapsed.asMilliseconds());

        window.clear();
        gameScene->Draw(window, elapsed.asMilliseconds());
        window.display();
    }

    return 0;
}