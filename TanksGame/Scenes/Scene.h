#pragma once

#include "SFML/Graphics.hpp"

class Scene {
public:
	static Scene* getCurrentScene() {
		if (!current)
			current = new Scene();
		return current;
	}

	virtual void Draw(sf::RenderWindow& window, int deltaTime);

private:
	
protected:
	Scene();
	static Scene* current;

	
};