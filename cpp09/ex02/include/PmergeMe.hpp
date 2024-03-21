/**======================
*            42sp
* @file      : PmergeMe.hpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 19/03/2024
*========================**/

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>

class PmergeMe {
	private:
		std::vector<int> _intV;
		std::deque<int> _intD;
		int _straggler;
	public:
		bool has_straggler;
		PmergeMe(void);
		PmergeMe(const PmergeMe& rhs);
		~PmergeMe(void);
		PmergeMe& operator=(const PmergeMe& rhs);
		void processInput(char **argv);
		void validateInput(void);
		void printContainers(void);
		void catchVecStraggler(std::vector<int> &vec);
		void catchDeqStraggler(std::deque<int> &deq);
		void setStraggler(int straggler);
		int getStraggler(void);
	}
;

# endif