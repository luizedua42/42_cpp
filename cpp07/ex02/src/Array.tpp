/**======================
*            42sp
* @file      : Array.tpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 13/03/2024
*========================**/

template< typename T >
Array<T>::Array() {
	std::cout <<" Default constructor called "<< std::endl;
	this->_array = NULL;
	this->_size = 0;
};

template< typename T >
Array<T>::Array(unsigned int n) {
	std::cout << "Parametric constructor called" << std::endl;
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++) {
		this->_array[i] = T();
	}
	this->_size = n;
};

template< typename T >
Array<T>::Array(const Array& rhs){
	std::cout << "Copy constructor called" << std::endl;
	this->_array = NULL;
	*this = rhs;
};

template< typename T >
Array<T>::~Array(void){
	std::cout << "Destructor called" << std::endl;
	if(this->_array != NULL)
		delete [] this->_array;
};

template< typename T >
Array<T>& Array<T>::operator=(const Array& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &rhs) {
		if(this->_array != NULL)
			delete [] this->_array;
		this->_array = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++) {
			this->_array[i] = rhs._array[i];
		}
		this->_size = rhs._size;
	}
	return *this;
};

template< typename T >
unsigned int Array<T>::size(void) const {
	return this->_size;
};