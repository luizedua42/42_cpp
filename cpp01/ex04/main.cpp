/**======================
*            42sp
* @file      : main.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 05/02/2024
*========================**/

#include <iostream>	
#include <fstream>
namespace utils {

	void error(std::string err) {
		std::cout << "Error: "<< err << std::endl;

	}
	void replace(std::string& line, std::string find, std::string sub) {
		size_t idx = 0;
		size_t found = 0;

		while (true) {
			found = line.find(find, idx);
			if (found == std::string::npos)
				break;
			line.erase(found, find.size());
			line.insert(found, sub);
			idx = found + sub.size();
		}
	}

	void closeIO(std::ifstream& input, std::ofstream& output) {
		input.close();
		output.close();
	}
}

int searchSubs(std::string file, std::string find, std::string sub) {
	std::ifstream input(file.c_str(), input.in);
	
	if (input.fail() || input.is_open() == false) {
		utils::error("Opening input file");
		return (3);
	}

	std::ofstream output((file + ".replace").c_str(),output.out | output.trunc);

	if (output.fail() || output.is_open() == false) {
		utils::error("Opening output file");
		return (4);
	}

	while(input.eof() == false){
		std::string line;
		std::getline(input, line);
		if (input.eof() == false && input.fail()) {
			utils::error("Reading input file");
			utils::closeIO(input, output);
			return (5);
		}
		utils::replace(line, find, sub);
		if (input.eof() == false)
			output << line << std::endl;
		else
			output << line;
		if (output.fail()) {
			utils::error("Writing on output file");
			utils::closeIO(input, output);
			return (6);
		}
	}
	utils::closeIO(input, output);
	return 0;
}

int main(int argc, char **argv){
	int status = 0;

	if (argc < 3 || argc > 4){
		utils::error("Invalid arguments.");
		std::cout << "Try: ./replace filename s1 s2" << std::endl;
		return 1;
	}
	if(std::string(argv[2]) == "") {
		std::cout << "Oh fiddlesticks!, What are you doing?" << std::endl;
		return 2;
	}
	status = searchSubs(argv[1], argv[2], argv[3]);

	return status;
}
