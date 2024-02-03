/**==============================================
 * ?                    ABOUT
 * @file        : PhoneBook.hpp
 * @author      : luizedua
 * @email       : luizedua@student.42sp.org.br
 * @createdOn   : 01/02/2024
 *=============================================**/


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contacts.hpp"

class PhoneBook {
	private:
		Contacts		_contacts[8];
		static size_t	_nbrOfContacts;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(void);
		void	searchContact(void);
		void	help(void);
};		

#endif 	