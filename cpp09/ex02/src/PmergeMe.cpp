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
#include <ctime>
#include <iomanip>
#include <exception>

#define CLOCKS_PER_MS 1000000
namespace utils {
	std::deque< std::pair<int, int> > pairDeq(std::deque<int> &deq) {
		if(deq.empty()) {
			throw std::invalid_argument("Error: empty deque");
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
		if(vec.empty()) {
			throw std::invalid_argument("Error: empty vector");
		}
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

	void mergeSortVec(std::vector< std::pair<int, int> > &vec) {
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
			mergeSortVec(left);
			mergeSortVec(right);
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

	void mergeSortDeq(std::deque< std::pair<int, int> > &deq) {
	std::deque< std::pair<int, int> > left;
	std::deque< std::pair<int, int> > right;
	if (deq.size() > 1) {
		size_t mid = deq.size() / 2;
		for (size_t i = 0; i < mid; i++) {
			left.push_back(deq[i]);
		}
		for (size_t i = mid; i < deq.size(); i++) {
			right.push_back(deq[i]);
		}
		mergeSortDeq(left);
		mergeSortDeq(right);
		size_t i = 0;
		size_t j = 0;
		size_t k = 0;
		while (i < left.size() && j < right.size()) {
			if (left[i].first < right[j].first) {
				deq[k] = left[i];
				i++;
			} else {
				deq[k] = right[j];
				j++;
			}
			k++;
		}
		while (i < left.size()) {
			deq[k] = left[i];
			i++;
			k++;
		}
		while (j < right.size()) {
			deq[k] = right[j];
			j++;
			k++;
		}
	}
	}

	 void insertionSortVec(std::vector<int> &Sv, std::vector<int> &Pv) {
		for (size_t i = 0; i < Pv.size(); i++) {
			std::vector<int>::iterator it = std::upper_bound(Sv.begin(), Sv.end(), Pv[i]);
			if(it != Sv.end())
				Sv.insert(it, Pv[i]);
			else
				Sv.push_back(Pv[i]);
		}
		Pv.erase(Pv.begin(), Pv.end());
	}

	 void insertionSortDeq(std::deque<int> &Sv, std::deque<int> &Pv) {
		for (size_t i = 0; i < Pv.size(); i++) {
			std::deque<int>::iterator it = std::upper_bound(Sv.begin(), Sv.end(), Pv[i]);
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
		unpaired.insert(unpaired.begin(), pending[0]);
		pending.erase(pending.begin());
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
	bool isSorted(std::vector<int>& arr)
	{
		for (std::vector<int>::iterator it = arr.begin() + 1; it != arr.end(); ++it) {
			if (*it < *(it - 1))
				return (false);
		}
		return (true);
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

bool PmergeMe::validateInput(void) {
	//validate for negative values for intV and intD
	for (size_t i = 0; i < _intV.size(); i++) {
		if (_intV[i] < 0) {
			throw std::invalid_argument("Error: negative values");
			return false;
		}
	}
	for (size_t i = 0; i < _intV.size(); i++) {
		for (size_t j = i + 1; j < _intV.size(); j++) {
			if (_intV[i] == _intV[j]) {
				throw std::invalid_argument("Error: duplicated values");
				return false;
			}
		}
	}
	return true;
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
			throw std::invalid_argument("Error: invalid input: it must be int");
		}
		_intV.push_back(num); 
		_intD.push_back(num);
		iss.clear();
	}
	if(PmergeMe::validateInput() == false)
		throw std::invalid_argument("Error: invalid input");
}


int PmergeMe::catchVecStraggler(std::vector<int> &vec) {
	_straggler = vec.back();
	vec.pop_back();
	return _straggler;
}

int  PmergeMe::catchDeqStraggler(std::deque<int> &deq) {
	_straggler = deq.back();
	deq.pop_back();
	return _straggler;
}

std::vector<int> PmergeMe::fordSortVec(void) {
	bool has_straggler = false;
	std::vector<int> Sv;
	std::vector<int> Vpending;

	if (_intV.size() % 2 != 0) {
		PmergeMe::catchVecStraggler(_intV);
		has_straggler = true;
	}
	std::vector< std::pair<int, int> > pairs = utils::pairVec(_intV);
	utils::sortMaxVec(pairs);
	utils::mergeSortVec(pairs);
	utils::unpairVector(pairs, Vpending, Sv);
	if(has_straggler){
		Vpending.push_back(_straggler);
	}
	utils::insertionSortVec(Sv, Vpending);
	return Sv;
}

std::deque<int> PmergeMe::fordSortDeq(void) {
	bool has_straggler = false;
	std::deque<int> Sd;
	std::deque<int> Dpending;

	if (_intD.size() % 2 != 0) {
		_straggler = PmergeMe::catchDeqStraggler(_intD);
		has_straggler = _straggler != 0;
	}
	std::deque< std::pair<int, int> > pairs = utils::pairDeq(_intD);
	utils::sortMaxDeque(pairs);
	utils::mergeSortDeq(pairs);
	utils::unpairDeque(pairs, Dpending);
	Sd.insert(Sd.begin(), Dpending[0]);
	if(has_straggler)
		Dpending.push_back(_straggler);
	utils::insertionSortDeq(Sd, Dpending);
	return Sd;
}

void PmergeMe::printContainers(void) {
	std::cout << "Before: ";
	for (size_t i = 0; i < _intV.size(); i++) {
		std::cout << _intV[i] << " ";
	}
	std::cout << std::endl;
	clock_t begin = clock();
	_intV = PmergeMe::fordSortVec();
	clock_t end = clock();
	std::cout << "After: ";
	for (size_t i = 0; i < _intV.size(); i++) {
		std::cout << _intV[i] << " ";
	}
	std::cout << std::endl;
	double time = static_cast<double>(end - begin) / CLOCKS_PER_MS;
	std::cout << "Time to process a range of " << _intV.size() << " elements with std::vector : " << std::fixed << std::setprecision(6)<< (float)time << " us" << std::endl;

	if(utils::isSorted(_intV)) {
		std::cout << "Sorted" << std::endl;
	} else {
		std::cout << "Not sorted" << std::endl;
	}
}