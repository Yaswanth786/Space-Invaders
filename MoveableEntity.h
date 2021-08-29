#pragma once
//#include <SFML/Graphics.hpp>
class MoveableEntity:public sf::Sprite{
	//int xPosition,yPosition,life,xVelocity,yVelocity;
	protected:
		sf::Texture texture;
	public:
		void Texture(const char* fileName,float xFactor=1,float yFactor=1){
			texture.loadFromFile(fileName);
			this->setTexture(texture);
			this->setScale(xFactor,yFactor);
		}
		void Position(int x,int y){
			this->setPosition(x,y);
		}
		void Move(float offsetX=0.45,float offsetY=0){
			this->move(offsetX,offsetY);
		}
};

