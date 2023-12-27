#pragma once

#include "SFML/Graphics.hpp"
#include"EntityManger.hpp"
#include"Entity.h"





class Game {


	sf::RenderWindow window;

	EntityManger   entities;

	sf::Font        font;
	sf::Text        test;
	int score = 0;

	int currentFrame = 0;

	int lastEnemySpawnTime = 0;
	bool paused = false;
	bool running = true;

	Entity* player;


	void init()const {

	};

	void setPaused(bool paused);

	void sMovement();

	void sUserInput();
		
	void sLifespan();

	void sRender();

	void sEnemySpawner();

	void sCollision();

	void swanPlayer();

	void spawnEnemy();

	void spawnSmallEnemies(Entity* entity);

	void spawnBullet(Entity* entity,const Vec2 & mousePos);
	void spawnSpecialWeapon(Entity* entity,const Vec2 & mousePos);














public:

	Game() {

	};

	void run();



















};
