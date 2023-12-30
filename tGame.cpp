#pragma once

#include "SFML/Graphics.hpp"
#include"EntityManger.hpp"
#include"Entity.h"
#include"Vector.h"
#include "Components.h"
#include<iostream>

#include<math.h>
#define M_PI 3.14159265358979323846





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

	int winHeight = 1280;

	int winWidth = 720;
	float bulletSpeed = 10.00f;
	RandomNumber rand;
		


	
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
			inputs();
			movements();
			showEnemy();
		


			currentFrame++;




			
			

		}


	}

	//CShape(float radius, int points, 
	//const sf::Color& fill, const sf::Color& outline, float thickness)
	//

	void movements() {


		Vec2 velocity = { 0.0f,0.0f };
		
		
		if (player->cInput->right) {
			

			velocity.x = player->cTransform->velocity.x;

		}	
		if (player->cInput->down) {
			

			velocity.y = player->cTransform->velocity.y;

		}	
		if (player->cInput->up) {
			

			velocity.y = (-1)*player->cTransform->velocity.y;

		}	
		if (player->cInput->left) {
			

			velocity.x = (-1)*player->cTransform->velocity.x;

		}

		player->cTransform->pos.x += velocity.x;
		player->cTransform->pos.y += velocity.y;
		player->cShape->circle.setPosition(player->cTransform->pos.x, player->cTransform->pos.y);


		



		for (auto& e : entities.getEntities()) {

			if (e->tags== "player") {


			}
			if (e->tags=="bullet") {
				e->cTransform->pos.x += e->cTransform->velocity.x;
				e->cTransform->pos.y += e->cTransform->velocity.y;


				e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);

			}

			if (e->tags == "enemy") {
				
				e->cTransform->pos.x += e->cTransform->velocity.x;
				e->cTransform->pos.y += e->cTransform->velocity.y;
				std::cout << "Hello There " << std::endl;
				std::cout << e->cTransform->pos.x << std::endl;
				std::cout << e->cTransform->pos.y << std::endl;

				e->cShape->circle.setPosition(e->cTransform->pos.x, e->cTransform->pos.y);

			}












		}





	}


	void inputs() {

		sf::Event event;


		while (windows.pollEvent(event))
		{



			if (event.type == sf::Event::Closed)
				windows.close();


			if ((event.type == sf::Event::KeyPressed)) {
				//(event.key.code == sf::Keyboard::Escape)
				//std::cout << "Yes Iam  escape my boy" << std::endl;
			   std::cout << (event.key.code)<< std::endl;

				if ((event.key.code == sf::Keyboard::P)) {

					std::cout << "You Presssed p " << std::endl;
				}


				if ((event.key.code == sf::Keyboard::Right)) {

					std::cout << "You Presssed Right " << std::endl;
					player->cInput->right = true;
				}


				if ((event.key.code == sf::Keyboard::Left)) {

					std::cout << "You Presssed Left " << std::endl;
					player->cInput->left = true;
				}


				if ((event.key.code == sf::Keyboard::Up)) {

					std::cout << "You Presssed Up " << std::endl;
					player->cInput->up = true;
				}	



				if ((event.key.code == sf::Keyboard::Down)) {

					std::cout << "You Presssed Down " << std::endl;
					player->cInput->down = true;
				}



				if ((event.key.code == sf::Keyboard::Escape)) {
					windows.close();
				}

			}

			if (event.type == sf::Event::KeyReleased) {


				


				if ((event.key.code == sf::Keyboard::Right)) {

					std::cout << "You Released Right " << std::endl;
					player->cInput->right = false;
				}


				if ((event.key.code == sf::Keyboard::Left)) {

					std::cout << "You Released Left " << std::endl;
					player->cInput->left = false;

				}


				if ((event.key.code == sf::Keyboard::Up)) {

					std::cout << "You Released Up " << std::endl;
					player->cInput->up= false;


				}



				if ((event.key.code == sf::Keyboard::Down)) {

					std::cout << "You Released Down " << std::endl;
					player->cInput->down = false;
				}








			}


			if (event.type == sf::Event::MouseButtonPressed) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					// Get the mouse click position
					sf::Vector2i mousePosition = sf::Mouse::getPosition(windows);

					// Print the mouse click position
					std::cout << "Mouse Clicked at: (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
					Entity* bullet=spawnBullet();
					Vec2 v= { player->cTransform->pos.x,player->cTransform->pos.y };
					Vec2 diff = { mousePosition.x - v.x,mousePosition.y - v.y };

				


					float result = atan2f(diff.y,diff.x);
					//float result = atanf(diff.x/diff.y);

					

					float diffy = sin(result) * bulletSpeed;
					float diffx = cos(result) * bulletSpeed;
					bullet->cTransform->velocity.x = diffx;
					bullet->cTransform->velocity.y = diffy;



					




				}	if (event.mouseButton.button == sf::Mouse::Right) {
					// Get the mouse click position
					sf::Vector2i mousePosition = sf::Mouse::getPosition(windows);

					// Print the mouse click position
					std::cout << "Mouse Clicked at: (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
				}





			}





		}



	}


	void spwanPlayer() {

		auto entity = entities.addEntity("player");

		entity->cTransform = new CTransform(Vec2(640.00,400.00),Vec2(4.0f,4.0f),0);
		entity->cShape = new CShape(25.00f,4, sf::Color::Black,sf::Color::Red,2.0f);
		
		entity->cInput = new CInput();
		
		player = entity;
	}





	Entity* spawnBullet() {

		auto entity = entities.addEntity("bullet");
		Vec2 bulletPosition = { player->cTransform->pos.x,player->cTransform->pos.y};

		entity->cTransform = new CTransform(bulletPosition, Vec2(5.0f, 5.0f), 0);
		entity->cShape = new CShape(10.00f, 100, sf::Color(255,255,255,1000), sf::Color::White, 2.0f);

		entity->cInput = new CInput();

		return entity;;

	}

	void spawnEnemy() {
		auto entity = entities.addEntity("enemy");


		entity->cTransform = new CTransform(Vec2(rand.getRandom(100.0f,1280.0f), rand.getRandom(50.0f, 720.0f)), Vec2(2.0f, 1.0f), 0);

		entity->cShape = new CShape(25.00f, rand.getRandom(3,10), sf::Color::Black, sf::Color::Red, 2.0f);

		entity->cInput = new CInput();

	}


	void showEnemy() {

		if (currentFrame - lastEnemySpawnTime == 50) {
			spawnEnemy();
			lastEnemySpawnTime = currentFrame;

		}





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
