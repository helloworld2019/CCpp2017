/*
 * control.cpp
 *
 *  Created on: 2017年5月16日
 *      Author: mark
 */
#include <SFML/Graphics.hpp>
#include"flight.h"

int Flight::control()
{

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&sprite.getPosition().x>0){
    		sprite.move(-1,0);
		}

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&sprite.getPosition().x<1225){
    		sprite.move(1,0);
    	}

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&sprite.getPosition().y>0){
    		sprite.move(0,-1);
    	}

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&sprite.getPosition().y<666){
    		sprite.move(0,1);
    	}

    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    		return 1 ;
    	}
    	return 0;
}



