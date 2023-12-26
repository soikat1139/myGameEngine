
// This is the main function for the last successfull sfml program with imgui:



#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include<iostream>









int main()
{
    sf::RenderWindow windows(sf::VideoMode(800, 800), "SFML Game Programming");

    //ImGui::SFML::Init(windows);

    sf::CircleShape shape(200.f, 100);
    shape.setFillColor(sf::Color::Cyan); // Color circle
    shape.setPosition(300, 300); // Center circle

    //sf::Clock deltaClock;

    while (windows.isOpen())
    {
        sf::Event event;
        while (windows.pollEvent(event))
        {

            //ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                windows.close();
        }

        ImGui::SFML::Update(windows, deltaClock.restart());

         ImGui::Begin("Title Window");
         ImGui::Text("Windows Text");

        ImGui::End();

         windows.clear(sf::Color(18, 33, 43)); // Color background
        windows.clear(sf::Color(0, 0, 0)); // Color background
        windows.draw(shape);
        ImGui::SFML::Render(windows);
        windows.display();
    }


    ImGui::SFML::Shutdown();

    return 0;
}






//This is the last successful program with sfml:





#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"
#include<iostream>
#include "Vector.h"









int main()
{

    int winHeight = 800;
    int winWidth = 800;
    //sf::RenderWindow windows(sf::VideoMode(winHeight, winWidth), "SFML Game Programming");

    sf::RenderWindow windows;

    windows.create(sf::VideoMode(winHeight, winWidth), "SFML game");


    float radius = 80.0f;



    sf::CircleShape shape(radius,100);
    shape.setFillColor(sf::Color::Cyan); // Color circle
    shape.setPosition(0,0); // Center circle

    windows.setFramerateLimit(60);


    int count = 0;

    bool countPaused = 0;

    sf::Vector2f speed = { 4,4 };








    while (windows.isOpen())
    {



        sf::Event event;
        while (windows.pollEvent(event))
        {



            if (event.type == sf::Event::Closed)
                windows.close();


            if ((event.type == sf::Event::KeyPressed)  ) {
                //(event.key.code == sf::Keyboard::Escape)
                //std::cout << "Yes Iam  escape my boy" << std::endl;
               // std::cout << (event.key.code==sf::Keyboard::P)<< std::endl;

                if ((event.key.code == sf::Keyboard::P)) {
                    countPaused = !countPaused;

                }
                if ((event.key.code == sf::Keyboard::Escape)) {
                    windows.close();
                }



            }



        }


        if (!countPaused) {



        }




        windows.clear(sf::Color(0, 0, 0)); // Color background


        windows.draw(shape);

        //Comment out this portion to run the program
          sf::Vector2f pos = shape.getPosition();

        if (pos.y+300.00>800) {
            speed.y = (-1) * speed.y;
            shape.setPosition(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
            shape.setFillColor(sf::Color::Green);

        }
        else if (pos.x+300.00>800) {
            speed.x = (-1) * speed.x;
            shape.setPosition(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
            shape.setFillColor(sf::Color::Yellow);

        }
        else if (pos.y<0) {
            speed.y = (-1) * speed.y;
            shape.setPosition(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
            shape.setFillColor(sf::Color::Red);

        }
        else if(pos.x<0) {
            speed.x = (-1) * speed.x;
            shape.setPosition(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
            shape.setFillColor(sf::Color::White);
        }
        else {
            shape.setPosition(sf::Vector2f(pos.x + speed.x, pos.y + speed.y));
        }

        //Upuntil here comment out







        windows.display();


    }



    return 0;
}



