/*
 * EnemyFlight.h
 *
 *  Created on: 2017年5月21日
 *      Author: chen
 */

#ifndef ENEMYFLIGHT_H_
#define ENEMYFLIGHT_H_
#include"flight.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<vector>

class EnemyFlight
{
public:
	EnemyFlight():Flight(){
		srand(time(0));
		number = rand()%5;
		for(int i = 0 ; i<number; i++){
			Flight flight;
			E.push_back(flight);
		}
	}
private:
	std::vector<Flight> E;
	int number ;
};




#endif /* ENEMYFLIGHT_H_ */