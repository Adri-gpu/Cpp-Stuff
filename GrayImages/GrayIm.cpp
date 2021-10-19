#include <iostream>
#include <cstring>
#include <stdexcept>

#include "GrayIm.hpp"

using namespace std;

GrayImage::GrayImage(uint16_t w, uint16_t h)
		: width(w), height(h),array(0)
{
	array= new char[width*height];
}

void GrayImage::writePGM(std::ostream& os) const
{
	os << "P5 \n";
	os << "#Image sauvegarder par Nico \n";
	os << width << " " <<  height << "\n";
	os << "255 \n";
	os.write((const char*)array, width*height);
}

void GrayImage::skip_line(std::istream& os)
{
	char car;
	do 
	{
		os.get(car);
	} while(car !='\n');
}

void GrayImage::skip_comments(std::istream& os)
{
	char car;
	do
	{
		os.get(car);
		skip_line(os);
	} while(car=='#');
	os.putback(car);
}

GrayImage* GrayImage::readPGM(std::istream& os)
{
	char c1,c2;
	c1 = os.get();
	c2 = os.get();
	cout << c1 << " " << c2 << endl;
	if(c1 != 'P' || c2!='5')
	throw runtime_error("Le fichier n'est pas une image PGM");
	
	skip_line(os);
	skip_comments(os);
	uint16_t w,h;
	os >> w >> h;
	skip_line(os);
	skip_comments(os);
	uint32_t u;
	os >> u;
	
	if (u != 255)
	throw runtime_error("La profondeur d'image n'est pas celle attendue");
	
	os.get();
	GrayImage* image = new GrayImage(w, h);
	os.read((char*) image->array, image->width*image->height);
	return image;
}
