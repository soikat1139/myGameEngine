#pragma once

#include "SFML/Graphics.hpp"
#include"EntityManger.hpp"
#include"Entity.h"
#include"Vector.h"
#include "Components.h"
#include<iostream>





class Game{


	sf::RenderWindow windows;

	EntityManger   entities;

	sf::Font        font;
	sf::Text        test;
	int score = 0;

	int currentFrame = 0;

	bool startTheGame = false;

	int lastEnemySpawnTime = 0;
	bool paused = false;
	bool running = true;
	float rotationSpeed = 50.0f;

	Entity* player;

	sf::Clock clock;

	
public:


	Game() :player(nullptr) {
		


	};




	void init() {
		
		windows.create(sf::VideoMode(1280, 720), "SFML");

		windows.setFramerateLimit(60);
		spwanPlayer();

		while (windows.isOpen()) {


			

			sRender();
			rotateEntity();



			sf::Event event;
			
			currentFrame++;

			
			while (windows.pollEvent(event))
			{



				if (event.type == sf::Event::Closed)
					windows.close();


				if ((event.type == sf::Event::KeyPressed)) {
					//(event.key.code == sf::Keyboard::Escape)
					//std::cout << "Yes Iam  escape my boy" << std::endl;
				   // std::cout << (event.key.code==sf::Keyboard::P)<< std::endl;

					if ((event.key.code == sf::Keyboard::P)) {
						

					}
					if ((event.key.code == sf::Keyboard::Escape)) {
						windows.close();
					}



				}



			}
			

		}


	}

	//CShape(float radius, int points, 
	//const sf::Color& fill, const sf::Color& outline, float thickness)
	//

	void spwanPlayer() {

		auto entity = entities.addEntity("player");

		entity->cTransform = new CTransform(Vec2(640.00,400.00),Vec2(0.00,0.00),0);
		entity->cShape = new CShape(25.00f,4, sf::Color::Black,sf::Color::Red,2.0f);
		entity->cShape->circle.setPosition(entity->cTransform->pos.x, entity->cTransform->pos.y);
		
		player = entity;
	}

	void sRender() {



		windows.clear();



		for (auto e:entities.getEntities()) {


			windows.draw(e->cShape->circle);


		}


		


		windows.display();






	}

	void rotateEntity() {

		sf::Time elapsed = clock.restart();

		

		// Update rotation angle based on elapsed time
		
		float rotation = player->cShape->circle.getRotation() + (rotationSpeed * elapsed.asSeconds());

		// Ensure rotation stays within [0, 360) degrees
		if (rotation >= 360.0f) {
			rotation -= 360.0f;
		}


		for (auto e : entities.getEntities()) {


			e->cShape->circle.setRotation(rotation);


		}

		


	}








};


/*
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 

	void setPaused(bool paused);

	void init(sf::RenderWindow& window)const {



		while (window.isOpen()) {






		}




	}

	void sMovement();

	void sUserInput() {


	};

	void sLifespan() {



	};

	void sRender(sf::RenderWindow& window) {



	};

	void sEnemySpawner() {



	};

	void sCollision() {




	};

	void swanPlayer() {



	};

	void spawnEnemy() {



	};

	void spawnSmallEnemies(Entity* entity) {




	};

	void spawnBullet(Entity* entity, const Vec2& mousePos){



	};


	void spawnSpecialWeapon(Entity* entity, const Vec2& mousePos) {




	};






	void run() {
		startTheGame = true;

	};







*/
