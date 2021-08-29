#pragma once
//#include <SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include "Laser.h"
sf::RenderWindow window(sf::VideoMode(1000,560),"Space Invaders!!!");
float val=0.15;
Laser temp3;
class Aliens:public MoveableEntity{
	int life;
	public:
		int velocity;
		static int fire_laser1; 
		//static vector<Aliens> allAliens[10];
		Aliens();
		static void DrawCheck();
		static void StepDown();
		static void Fire();
		void MoveMovement();
		
		void Del(){
			life=0;
			this->setPosition(-100,0);
		}
		/*void static Move(){
			move(0.1,0);
		}*/
};
int Aliens::fire_laser1=0;
Aliens temp1[5][11];
MoveableEntity boader,boader1,boader2;
Aliens::Aliens(){
	//Texture("124.png",0.03125,0.03125);
	//Texture("Aliens 1.png",0.30,0.30);
	life=1;
	//fire_laser1=0;
	//velocity=0.25;
}
void Aliens::MoveMovement(){
	int yval=0;
	if(this->getGlobalBounds().intersects(boader.getGlobalBounds())){
		val=-0.15;
		StepDown();
	}
	else if(this->getGlobalBounds().intersects(boader1.getGlobalBounds())){
		val=0.15;
		StepDown();
	}
	else if(this->getGlobalBounds().intersects(boader2.getGlobalBounds())){
		//exit(0);
		//Game::win(); //****************************************************************   Game END   ****************
	}
	this->Move(val,0);
}
void Aliens::DrawCheck(){
	for(int i=0;i<5;i++){
		for(int j=0;j<11;j++){
			if(temp1[i][j].life==1){
				temp1[i][j].MoveMovement();
				window.draw(temp1[i][j]);
			}
		}
	}
}
void Aliens::StepDown(){
	for(int i=0;i<5;i++){
		for(int j=0;j<11;j++){
			temp1[i][j].Move(0,1.5);
		}
	}
}
void Aliens::Fire(){
	if(fire_laser1==0){
		int randi=((rand()%5));
		int randj=((rand()%11));
		while(temp1[randi][randj].life==0){
			randi=((rand()%5));
			randj=((rand()%11));
		}
		temp3.setPosition(temp1[randi][randj].getPosition().x+12,temp1[randi][randj].getPosition().y+15);
		//temp3.setPosition(temp1[0][0].getPosition().x+12,temp1[0][0].getPosition().y+15);
		//temp3.setPosition(100,200);
		fire_laser1=1;
	}
	else{
		temp3.Move(0,0.5);
		if(temp3.getPosition().y>=500){
			fire_laser1=0;
		}
	}
}
