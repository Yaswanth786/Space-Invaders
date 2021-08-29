#pragma once
#include "Aliens.h"
#include <SFML/Graphics.hpp>
#include"MusicStream.h"
#include<iostream>
//Aliens temp1;
//sf::Music PlayerShoot;
MusicStream Sound;
class Player:public MoveableEntity{
	int life,fire_laser;
	Laser temp2;
	//MusicStream Sound;//("shoot.wav",10);
	public:
		int score,outcome;
		Player(const char* str){
			//Sound("shoot.wav",10);
			//MusicStream Sound ("shoot.wav",10);
			Sound.Set_Music("shoot.wav",10);
			Texture(str,0.20,0.20);
			Position(500,400);
			life=3;
			fire_laser=0;
			score=0;
			outcome=-1;
		}
		int PlayerMovement(){
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				Move(0.45,0);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				Move(-0.45,0);
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
				/*PlayerShoot.openFromFile("shoot.wav");
				PlayerShoot.setVolume(10);*/  
				Sound.play();
				fire_laser=1;
				while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
					Sleep(0.1);
				}
			}
			return 0;
		}
		//void PlayerMovement();
		void LaserFire();
		void LivesDraw(){
			sf::Sprite life_1,life_2,life_3; // *************** Change this  ***************  
			life_1.setTexture(texture);
			life_1.setScale(0.08,0.08);
			life_2.setTexture(texture);
			life_2.setScale(0.08,0.08);
			life_3.setTexture(texture);
			life_3.setScale(0.08,0.08);
	//******************************************************************************
			if(life>=1){
				life_1.setPosition(875,20);
				window.draw(life_1);
			}
			if(life>=2){
				life_2.setPosition(915,20);
				window.draw(life_2);
			}
			if(life==3){
				life_3.setPosition(955,20);
				window.draw(life_3);
			}
				//window.display();
		}
		void injury();
};
//int Player::outcome=1;
void Player::LaserFire(){
	if(fire_laser==1){
		temp2.Move(0,-1);
		window.draw(temp2);
		if(temp2.getPosition().y<=0){
			fire_laser=0;
			
		}
		for(int i=0;i<5;i++){
			for(int j=0;j<11;j++){
					if(temp1[i][j].getGlobalBounds().intersects(temp2.getGlobalBounds())){ //******  Collision Detection  ******
						fire_laser=0; // !!!!!!!!!!!!   Problem  !!!!!!!! Same(one value ) for all the clones; 
		        		temp1[i][j].Del();
		        		score+=((i+1)*10);
				}
			}
		}
	}
	else{
		temp2.setPosition(this->getPosition().x+35,this->getPosition().y-10);
	}
}
void Player::injury(){
	if(this->getGlobalBounds().intersects(temp3.getGlobalBounds())){ 
		life--;
		temp3.setPosition(-100,0);
	}
	if(life==0){
		//exit(0);
		//PlayerShoot.openFromFile("explosion.wav");
		//PlayerShoot.play();
		//Sound.setVolume(0);
		Sound.~MusicStream();
		//Sleep(500);
		outcome=0; // *************************************************   Game END   *******************************
	}	
}
