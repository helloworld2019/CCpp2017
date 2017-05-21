/*
 * bullet.h
 *
 *  Created on: 2017年5月18日
 *      Author: mark
 */

#ifndef BULLET_H_
#define BULLET_H_
#include <SFML/Graphics.hpp>
class bullet
{
public:
	bullet(char a){
		texture.loadFromFile("bullet.jpg");
		sprite.setTexture(texture);
		sprite.scale(0.1,0.1);
		sprite.setRotation(145);
		b = 1 ;
	}
	bullet(int a){
		texture.loadFromFile("bullet.jpg");
		sprite.setTexture(texture);
		sprite.scale(0.1,0.1);
		sprite.setRotation(-45);
		b = 0 ;
	}

	int fly1(){
		if(sprite.getPosition().y<1000){
			sprite.move(0,-1);
			return 1 ;
		}
		else return 0;
	}
	int fly2(){
		if(sprite.getPosition().y>0){
			sprite.move(0,1);
			return 1 ;
		}
		else return 0;
	}

	int getb(){
		return b ;
	}
	void set(int x , int y){
			sprite.setPosition(x,y);
	}

	sf::Sprite getsprite(){
		return sprite;
	}

private:
	sf::Texture texture;
	sf::Sprite sprite;
	int b ;
};




#endif /* BULLET_H_ */
