/*
 * t.cpp
 *
 *  Created on: 2017年5月5日
 *      Author: mark
 */
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include"advanced.h"
#include"flight.h"
#include"map.h"
#include"bullet2.h"
#include"bullet.h"
#define WIDE 1300
#define HIGH 1000

int main()
{
	sf::Mutex mutex;
    sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "Fly to Dream");
    bullet A(1) ;
    Flight MyFlight("Flight.png");
    Flight EnemeyFlight;
    Map map("map.jpg");

    ArrayBullet Bullet;
    Bullet.texture1.loadFromFile("bullet1.png");
    Bullet.texture2.loadFromFile("bullet1.png");
    sf::Thread BulletControl(&ArrayBullet::control_bullet,&Bullet);
    sf::Thread EnemeyControl(&Flight::control2,&EnemeyFlight);

    BulletControl.launch();
    EnemeyControl.launch();
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            	window.close();
        }
        int b=MyFlight.control();

        mutex.lock();
        if(b)Bullet.add_m(MyFlight.getx(),MyFlight.gety());

        if(EnemeyFlight.s == 1 &&clock.getElapsedTime()>sf::milliseconds(1000)){
        	Bullet.add_e(EnemeyFlight.getx(),EnemeyFlight.gety());
        	clock.restart();
        }
        A.set(MyFlight.getx(),MyFlight.gety());
        mutex.unlock();

        mutex.lock();

        window.clear(sf::Color::Black);
        window.draw(map.Getsprite());
        window.draw(MyFlight.GetSprite());
        window.draw(EnemeyFlight.GetSprite());
        window.draw(A.getsprite());
        for(int i= 0 ; i < Bullet.A.size();i++){
        	window.draw(Bullet.A[i].getsprite());
        }
        window.display();
        mutex.unlock();
    }

    return 0;

}