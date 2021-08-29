#include <SFML/Audio.hpp>
//#include <SFML/SoundStream.hpp>
class MusicStream:public sf::Music{
	public:
		//music_stream(){
			/*this->openFromFile("shoot.wav");
			this->setVolume(10);  */
		//}
		void Set_Music(const char* fileName,int Volume){
			this->openFromFile(fileName);
			this->setVolume(Volume);  
		}
		~MusicStream(){
			//this->~SoundStream();
			//this->~Music();
			this->setVolume(0);
		}
		void Play(){
			//this->play();
		}
		/*void Move(float offsetX=0.45,float offsetY=0){
			this->move(offsetX,offsetY);
		}*/
};
