#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string.h>
#include"MoveableEntity.h"
#include "Player.h"
sf::Font font;
sf::Text LivesText("LIVES", font);
sf::Text ScoreText("SCORE", font);
MoveableEntity BackgroundImage;
//sf::Sprite Backgroundimage;
class Game{
		static void run(Player);
		static void music();//************
		static void intro();
		static const char* menu();
		static void options();//**********
		static void info();//************
		static void level();//**********
		static void win();
		static void lose();
		static void text();
		static void themes();
		static bool check_status(int);
	public:
		static void init(int );
		/*Game(int a){
			//init(a);
			//run();
			//exit(0);
		}
		/*~Game(){
			//return 0;

		}*/
};
void Game::init(int a){
	intro();
	const char* SpaceShip_skin=menu();
	Player temp(SpaceShip_skin);
	themes();
	text();
	run(temp);
	return ;
}
void Game::themes(){
	const char* filename[5];
	filename[0]="Aliens 1.png";
	filename[1]="Aliens 2.png";
	filename[2]="Aliens 3.png";
	filename[3]="Aliens 4.png";
	filename[4]="Aliens 5.png";
	for(int j=0;j<11;j++){
		temp1[0][j].Texture(filename[0],0.30,0.30);
	}
	for(int j=0;j<11;j++){
		temp1[1][j].Texture(filename[1],0.30,0.30);
	}
	for(int j=0;j<11;j++){
		temp1[2][j].Texture(filename[2],0.03125,0.03125);
	}
	for(int j=0;j<11;j++){
		temp1[3][j].Texture(filename[3],0.30,0.30);
	}
	for(int j=0;j<11;j++){
		temp1[4][j].Texture(filename[4],0.30,0.30);
	}
	int ypos=70;
	for(int i=0;i<5;i++){
		int xpos=55;
		for(int j=0;j<11;j++){
			temp1[i][j].Position(xpos*(j+1),(ypos));
		}
		ypos+=60;
	}
}
void Game::text(){
	font.loadFromFile("PressStart2P-Regular.ttf");
	LivesText.setCharacterSize(22);
	ScoreText.setCharacterSize(22);
	LivesText.setPosition(765,32);
	ScoreText.setPosition(20,32);
	boader.Texture("white background.png",0.01,0.8);
	boader.Position(750,20);
	boader1.Texture("white background.png",0.01,0.8);
	boader1.Position(25,20);
	boader2.Texture("white background.png",0.8,0.01);
	boader2.Position(20,380);
	BackgroundImage.Texture("invaders.png",1.3,1);
}
const char* Game::menu(){
	font.loadFromFile("PressStart2P-Regular.ttf");
	sf::Text select("Select Space Ship Skin", font);
	sf::Text key("Press '1','2','3' key ", font);
	select.setCharacterSize(22);
	select.setPosition(100,100);
	key.setCharacterSize(20);
	key.setPosition(100,200);
	while(1){
			window.clear();
			window.draw(select);
			window.draw(key);
			info();
			window.display();
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)){
				return "SpaceShip.png";
				//break;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)){
				return "SpaceShip1.png";
				//break;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)){
				return "SpaceShip2.png";
				//break;
			}
	}
	Sleep(500);
}
void Game::info(){
	//font.loadFromFile("PressStart2P-Regular.ttf");
	sf::Text info123("Space Invaders is a video game made by the Taito Corporation.\nSpace Invaders is one of the most famous early video games.\nThe game is about defending the Earth from Space Invaders (aliens) by\nshooting them down before they can land. ", font);
	info123.setCharacterSize(13);
	info123.setPosition(50,350);
	window.draw(info123);
}
void Game::run(Player temp){
	//music123.openFromFile("spaceinvaders1.mpeg");
	//music123.openFromFile("shoot.wav");
	//music123.play();
    while (window.isOpen())
    {
        sf::Event event;
        temp.PlayerMovement();
        while (window.pollEvent(event))
        {   if (event.type == sf::Event::Closed)
                window.close();
        }
        if(check_status(temp.outcome)){
        	//window.close();
        	//continue;
        	return ;
        	//break;
		}
		//std::cout<<"12333333333333333333333\n";
		std::string str = std::to_string(temp.score);
		sf::Text Score(str, font);
		Score.setPosition(140,32);
		Score.setCharacterSize(21);
		window.clear();
		window.draw(BackgroundImage);
		temp.LivesDraw();
		temp.LaserFire();
        window.draw(temp);
        Aliens::DrawCheck();
        Aliens::Fire();
        window.draw(temp3);
        window.draw(LivesText);
        window.draw(ScoreText);
        window.draw(Score);
        temp.injury();
        window.display();
    }
}
void Game::intro(){
	sf::Sprite Background;
	sf::Texture texture;
	texture.loadFromFile("Intro.jpg");
	Background.setTexture(texture);
	Background.setScale(0.65,0.65);
	for(long long i=0;i<40;i++){
		for(long long j=0;j<10;j++){
			window.clear();
			window.draw(Background);
			window.display();
		}
	}
	Sleep(1000);
	window.clear();
}
bool Game::check_status(int verdict){
	if(verdict==0){
            lose();
            return true;
		}
	return false;
}
void Game::win(){
	//std::cout<<"dskhfkdjdkjdkjdkjdflkdjldfjdlfldlfjdljdldjldjdl\n";
}
void Game::lose(){
	//PlayerShoot.pause();
	//PlayerShoot.~PlayerShoot();
	window.clear();
	//window.display();
	//window.close();
	//Sleep(1000);
	//exit(0);
}
