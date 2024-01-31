#include <iostream>


int main(int argc, char **argv){
	std::string str = "";
	
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for(int i=1; argv[i]; i++){
		for(int j=0; argv[i][j]; j++){
			str += std::toupper(argv[i][j]);
		}
	}
	std::cout << str << std::endl;
	return 0;
}
