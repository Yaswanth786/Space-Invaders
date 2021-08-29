#pragma once
class Laser:public MoveableEntity{
	
	public:
		//static Laser allLaser[10];
		//static allLaser;
		//static vector<Laser> allLaser;
		Laser(){
			//Texture("Missile.png",0.10,0.100);
			Texture("Laser.png",0.11,0.12);
			Position(500,400);
			
		}
		void Move1(){
			this->move(0,-0.01);
			//int i=0;
			//cout<<this->getPosition().y;
			//while(this->getPosition().y>0){

				//Sleep(0.5);
				//i++;
			//}
		}
		
};
