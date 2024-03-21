/**======================
*            42sp
* @file      : PmergeMe.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#include "../include/PmergeMe.hpp"
#include <sstream>
#include <algorithm>

namespace utils {
	std::deque< std::pair<int, int> > pairDeq(std::deque<int> &deq) {
		if(deq.empty()) {
			std::cout << "Error: empty deque" << std::endl;
		}
		std::deque<int>::iterator it = deq.begin();
		std::deque<int>::iterator ite = deq.end();
		std::deque< std::pair<int, int> > pairs;
		for(int i = 0; it != ite; i++, it++) {
			pairs.push_back(std::make_pair(*it++, *it));
		}
		return pairs;
	}

	std::vector< std::pair<int, int> > pairVec(std::vector<int> &vec) {
		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator ite = vec.end();
		std::vector< std::pair<int, int> > pairs;
		for(int i = 0; it != ite; i++, it++) {
			pairs.push_back(std::make_pair(*it++, *it));
			
		}
		return pairs;
	}
	void sortMaxDeque(std::deque< std::pair<int, int> > &deq) {
		for (size_t i = 0; i < deq.size(); i++) {
			if (deq[i].first < deq[i].second) {
				std::swap(deq[i].first, deq[i].second);
			}
		}
	}
	void sortMaxVec(std::vector< std::pair<int, int> > &vec) {
		for (size_t i = 0; i < vec.size(); i++) {
			if (vec[i].first < vec[i].second) {
				std::swap(vec[i].first, vec[i].second);
			}
		}
	}

	void sortVecP(std::vector< std::pair<int, int> > &vec) {
		std::vector< std::pair<int, int> > left;
		std::vector< std::pair<int, int> > right;
		if (vec.size() > 1) {
			size_t mid = vec.size() / 2;
			for (size_t i = 0; i < mid; i++) {
				left.push_back(vec[i]);
			}
			for (size_t i = mid; i < vec.size(); i++) {
				right.push_back(vec[i]);
			}
			sortVecP(left);
			sortVecP(right);
			size_t i = 0;
			size_t j = 0;
			size_t k = 0;
			while (i < left.size() && j < right.size()) {
				if (left[i].first < right[j].first) {
					vec[k] = left[i];
					i++;
				} else {
					vec[k] = right[j];
					j++;
				}
				k++;
			}
			while (i < left.size()) {
				vec[k] = left[i];
				i++;
				k++;
			}
			while (j < right.size()) {
				vec[k] = right[j];
				j++;
				k++;
			}
		}
	}

	 void insertionSortVec(std::vector<int> &Sv, std::vector<int> &Pv) {
		for (size_t i = 1; i < Pv.size(); i++) {
			std::vector<int>::iterator it = std::upper_bound(Sv.begin(), Sv.end(), Pv[i]);
			if(it != Sv.end())
				Sv.insert(it, Pv[i]);
			else
				Sv.push_back(Pv[i]);
		}
		Pv.erase(Pv.begin(), Pv.end());
	}

	std::deque<int> unpairDeque(std::deque< std::pair<int, int> > &deq, std::deque<int> &pending) {
		std::deque<int> unpaired;
		for (size_t i = 0; i < deq.size(); i++) {
			unpaired.push_back(deq[i].first);
			pending.push_back(deq[i].second);
		}
		
		return unpaired;
	}

	void unpairVector(std::vector< std::pair<int, int> > &vec, std::vector<int> &pending, std::vector<int> &unpaired) {
		for (size_t i = 0; i < vec.size(); i++) {
			unpaired.push_back(vec[i].first);
			pending.push_back(vec[i].second);
		}
		unpaired.insert(unpaired.begin(), pending[0]);
		pending.erase(pending.begin());
	}
}

PmergeMe::PmergeMe() : _intV(), _intD(), _straggler(0){};

PmergeMe::PmergeMe(const PmergeMe& rhs){
	*this = rhs;
}

PmergeMe::~PmergeMe(void){}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
	if(this != &rhs) {
		_intD = rhs._intD;
		_intV = rhs._intV;
		_straggler = rhs._straggler;
	}
	return *this;
}

void PmergeMe::validateInput(void) {
	for (size_t i = 0; i < _intV.size(); i++) {
		for (size_t j = i + 1; j < _intV.size(); j++) {
			if (_intV[i] == _intV[j]) {
				std::cout << "Error: duplicated input" << std::endl;
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
		}
		_intV.push_back(num); 
		_intD.push_back(num);
		iss.clear();
	}
	PmergeMe::validateInput();
}

void PmergeMe::setStraggler(int straggler) {
	_straggler = straggler;
}

int PmergeMe::getStraggler(void) {
	return _straggler;
}

void PmergeMe::catchVecStraggler(std::vector<int> &vec) {
	_straggler = vec[vec.size() - 1];
	vec.pop_back();
}

void PmergeMe::printContainers(void) {
	bool has_straggler = false;
	std::vector<int> Sv;
	std::cout << "VECTOR =======================" << std::endl;
	if (_intV.size() % 2 != 0) {
		PmergeMe::catchVecStraggler(_intV);
		has_straggler = _straggler != 0;
	}
	if ( has_straggler ) {
		std::cout << "Straggler: " << _straggler << std::endl;
	}
	std::vector< std::pair<int, int> > pairs = utils::pairVec(_intV);
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << pairs[i].first << ':' << pairs[i].second;
		if (i < pairs.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	utils::sortMaxVec(pairs);
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << pairs[i].first << ':' << pairs[i].second;
		if (i < pairs.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	utils::sortVecP(pairs);
	for (size_t i = 0; i < pairs.size(); i++) {
		std::cout << pairs[i].first << ':' << pairs[i].second;
		if (i < pairs.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> Vpending;
	utils::unpairVector(pairs, Vpending, Sv);
	if(has_straggler)
		Vpending.push_back(_straggler);
	std::cout << "Sv: ";
	for (size_t i = 0; i < Sv.size(); i++) {
		std::cout << Sv[i];
		if (i < Sv.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "Vpend:";
	for (size_t i = 0; i < Vpending.size(); i++) {
		std::cout << Vpending[i];
		if (i < Vpending.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;

	utils::insertionSortVec(Sv, Vpending);
	std::cout << "Sv: ";
	for (size_t i = 0; i < Sv.size() - 1; i++) {
		std::cout << Sv[i];
		if (i < Sv.size() - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
}