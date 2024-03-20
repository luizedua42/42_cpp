/**======================
*            42sp
* @file      : PmergeMe.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#include "../include/PmergeMe.hpp"
#include <sstream>

namespace utils {

	std::deque< std::pair<int, int> > pairDeq(std::deque<int> &deq) {
		std::deque<int>::iterator it = deq.begin();
		std::deque<int>::iterator ite = deq.end();
		std::deque< std::pair<int, int> > pair;
		for(int i = 0; it != ite; i++, it++) {
			pair[i] = std::make_pair(*it, *(it + 1));
		}
		return pair;
	}

	std::deque< std::pair<int, int> > pairVec(std::vector<int> &vec) {
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator ite = vec.end();
		std::deque< std::pair<int, int> > pair;
		for(int i = 0; it != ite; i++, it++) {
			pair[i] = std::make_pair(*it, *(it + 1));
		}
		return pair;
	}

	
}
PmergeMe::PmergeMe() : _intD(), _intV(){};

PmergeMe::PmergeMe(const PmergeMe& rhs){
	*this = rhs;
}

PmergeMe::~PmergeMe(void){}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if(this != &rhs) {
		_intD = rhs._intD;
		_intV = rhs._intV;
	}
	return *this;
}

void PmergeMe::validateInput(void) {
	for (size_t i = 0; i < _intV.size(); i++) {
		for (size_t j = i + 1; j < _intV.size(); j++) {
			if (_intV[i] == _intV[j]) {
				std::cout << "Error: duplicated input" << std::endl;
				exit(1);
			}
		}
	}
}

void PmergeMe::processInput(char **argv) {
	std::istringstream iss;
	int num = 0;

	iss.exceptions(std::ios::failbit);
	for (size_t i = 1; argv[i]; i++) {
		iss.str(argv[i]);
		try{
			iss >> num;
		} catch (std::exception &e) {
			std::cout << "Error: invalid input: it must be int" << std::endl;
			exit(1);
		}
		if (num < 1) {
			std::cout << "Error: invalid input: it must be greater than 0" << std::endl;
			exit(1);
		}
		_intV.push_back(num); 
		iss.clear();
	}
	PmergeMe::validateInput();
}

void PmergeMe::sortDeque(void) {

}