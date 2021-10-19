#include "GrayIm.hpp"

int main(){

	
	std::ifstream f("chat.pgm", ios::binary);
	GrayImage *i = GrayImage::readPGM(f);
	
	
	delete i;
	
	return 0;
}
