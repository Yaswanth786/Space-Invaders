#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include<windows.h>
#include"Game.h"
using namespace std;
//sf::Thread thread(&Laser::Move1,&temp2);
int main(){
	unsigned int seedval;
	time_t t;
	seedval=(unsigned)time(&t);
	srand(seedval);
	int skin=3;
	//std::cin>>skin;
	//Game game(skin);
	//exit(0);
	Game game;
	game.init(skin);
	cout<<"sdjdkjkdddlldfjdjlaljljfnvdskjddjldjldsls";
	//exit(0);
	return 0;
}
