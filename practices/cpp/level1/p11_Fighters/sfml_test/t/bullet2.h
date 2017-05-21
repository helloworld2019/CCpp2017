/*
 * bullet2.h
 *
 *  Created on: 2017年5月18日
 *      Author: mark
 */

#ifndef BULLET2_H_
#define BULLET2_H_
#include"bullet.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std ;


class ArrayBullet
{
public:
	void add_m(int x , int y){
		bullet a(1);
		a.set(x,y);
		A.push_back(a);
	}
	void add_e(int x , int y){
		bullet a('a');
		a.set(x,y);
		A.push_back(a);
	}

void control_bullet(){
	sf::Mutex mutex;
	while(1){
		mutex.lock();
		if(A.size()!=0){
			for(int i = 0;i < A.size();i++){
				if(A[i].getb()==1){
					int j = A[i].fly2();
					if( j == 0){A.erase(A.begin() + i );}
				}
				if(A[i].getb()==0){
					int j = A[i].fly1();
					if( j == 0){A.erase(A.begin() + i );}
				}
		   }
			mutex.unlock();
			sf::sleep(sf::milliseconds(10));
		}
	}
}
	vector <bullet>A ;


};

#endif /* BULLET2_H_ */
