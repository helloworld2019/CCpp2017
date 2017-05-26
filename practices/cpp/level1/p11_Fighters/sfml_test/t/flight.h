/*
 * flight.h
 *
 *  Created on: 2017年5月16日
 *      Author: mark
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdlib.h>
#include<iostream>
class Flight
{
public:
	Flight(const char* filename){
		life = 3 ;
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
		sprite.scale(1,1);
		sprite.setPosition(500,500);
	}
	Flight(){
		life = 1 ;
		texture.loadFromFile("2.png");
		sprite.setTexture(texture);
		srand(time(0));
		sprite.scale(1,1);
		sprite.setRotation(180);
		int x = rand() % 1200;
		sprite.setPosition(x,0);
	}

	int control();

	void control2();

	sf::Sprite &GetSprite(){
		return sprite ;
	}

	void restore(){
		life++;
	}
	void subtract(){
		life--;
	}

	bool ifdeath(){
		if(life<=0){
			return 0;
		}
		return 1 ;
	}
	int getx(){
		return  sprite.getPosition().x;
	}
	int gety(){
		return  sprite.getPosition().y ;
	}
	int s  = 0 ;

private:
	int life ;
	sf::Texture texture;
	sf::Sprite sprite;
};




#endif /* FLIGHT_H_ */