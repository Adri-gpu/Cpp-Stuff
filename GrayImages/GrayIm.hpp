#include <iostream>
#include <cstring>
#include <cstdint>
#include <fstream>

#ifndef GrayIm_hpp
#define GrayIm_hpp


using namespace std;

class GrayImage{
	private:
		uint16_t width;
		uint16_t height;
		char *array;
	
	public:
		GrayImage(uint16_t width, uint16_t height);
		GrayImage();
		~GrayImage()
		{
			delete [] array;
		};
		void writePGM(std::ostream& ) const;
		static GrayImage* readPGM(std::istream& );
		static void skip_line(std::istream& );
		static void skip_comments(std::istream& );

};
		
#endif
