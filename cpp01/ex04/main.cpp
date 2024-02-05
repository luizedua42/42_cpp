/**======================
 * ?        ABOUT
 * @file      : main.cpp
 * @author    : luizedua
 * @createdOn : 05/02/2024
 *========================**/

#include <iostream>
#include <fstream>

int main(int argc, char **argv){
	if (argc < 3 || argc > 4)
		return 1;
	std::string filename = argv[1];
	std::ifstream filein(filename.c_str());
	std::ofstream fileout((filename  + ".replace").c_str());
	char ch;
	while(filein){
		filein.get(ch);
		fileout << ch;
	}
	fileout.close();
	filein.close();
	return 0;
}
