/**======================
*            42sp
* @file      : ShrubberyCreationForm.cpp
* @author    : luizedua
* @email     : luizedua@student.42sp.org.br
* @createdOn : 06/03/2024
*========================**/

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm", 145, 137), _target("default"){
	std::cout << MAGENTA << "Default Shrubbery constructor called" << RESET << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << MAGENTA << "Param Shrubbery constructor called" << RESET << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : 
AForm("ShrubberyCreationForm", 145, 137), _target(rhs._target) {
	std::cout << MAGENTA << "Copy Shrubbery constructor called" << RESET << std::endl;
	*this = rhs;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << RED << " Shrubbery Destructor called" << RESET << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if(this != &rhs) {
		AForm::operator=(rhs);
		const_cast<std::string&>(_target) = rhs._target;
	}
	return *this;
};

//Methods========================================================================


void draw_trees(std::string const& filename)
throw(std::ios_base::failure){
	std::ofstream out(filename.c_str(), std::ios::out | std::ios::trunc);

	if(!out.is_open() || out.fail()){
		throw(std::ios_base::failure("Error: could not open file"));
	}
	out << "                                                     . "<< "                                                     . "<< std::endl;
	out << "                                      .         ;      "<< "                                      .         ;      "<< std::endl;
	out << "         .              .              ;%     ;;       "<< "         .              .              ;%     ;;       "<< std::endl;
	out << "           ,           ,                :;%  %;        "<< "           ,           ,                :;%  %;        "<< std::endl;
	out << "            :         ;                   :;%;'     ., "<< "            :         ;                   :;%;'     ., "<< std::endl;
	out << "   ,.        %;     %;            ;        %;'    ,;   "<< "   ,.        %;     %;            ;        %;'    ,;"   << std::endl;
	out << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'    "<< "     ;       ;%;  %%;        ,     %;    ;%;    ,%'"    << std::endl;
	out << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'     "<< "      %;       %;%;      ,  ;       %;  ;%;   ,%;' "    << std::endl;
	out << "       ;%;      %;        ;%;        % ;%;  ,%;'       "<< "       ;%;      %;        ;%;        % ;%;  ,%;'"       << std::endl;
	out << "        `%;.     ;%;     %;'         `;%%;.%;'         "<< "        `%;.     ;%;     %;'         `;%%;.%;'"         << std::endl;
	out << "         `:;%.    ;%%. %@;        %; ;@%;%'            "<< "         `:;%.    ;%%. %@;        %; ;@%;%'"            << std::endl;
	out << "            `:%;.  :;bd%;          %;@%;'              "<< "            `:%;.  :;bd%;          %;@%;'"              << std::endl;
	out << "              `@%:.  :;%.         ;@@%;'               "<< "              `@%:.  :;%.         ;@@%;'   "            << std::endl;
	out << "                `@%.  `;@%.      ;@@%;                 "<< "                `@%.  `;@%.      ;@@%;         "        << std::endl;
	out << "                  `@%%. `@%%    ;@@%;                  "<< "                  `@%%. `@%%    ;@@%;        "          << std::endl;
	out << "                    ;@%. :@%%  %@@%;                   "<< "                    ;@%. :@%%  %@@%;       "            << std::endl;
	out << "                      %@bd%%%bd%%:;                    "<< "                      %@bd%%%bd%%:;     "               << std::endl;
	out << "                        #@%%%%%:;;                     "<< "                        #@%%%%%:;;"                     << std::endl;
	out << "                        %@@%%%::;                      "<< "                        %@@%%%::;"                      << std::endl;
	out << "                        %@@@%(o);  . '                 "<< "                        %@@@%(o);  . '         "        << std::endl;
	out << "                        %@@@o%;:(.,'                   "<< "                        %@@@o%;:(.,'         "          << std::endl;
	out << "                    `.. %@@@o%::;                      "<< "                    `.. %@@@o%::;         "             << std::endl;
	out << "                       `)@@@o%::;                      "<< "                       `)@@@o%::;         "             << std::endl;
	out << "                        %@@(o)::;                      "<< "                        %@@(o)::;        "              << std::endl;
	out << "                       .%@@@@%::;                      "<< "                       .%@@@@%::;         "             << std::endl;
	out << "                       ;%@@@@%::;.                     "<< "                       ;%@@@@%::;.          "           << std::endl;
	out << "                      ;%@@@@%%:;;;.                    "<< "                      ;%@@@@%%:;;;. "                   << std::endl;
	out << "                  ...;%@@@@@%%:;;;;,..                 "<< "                  ...;%@@@@@%%:;;;;,.."                 << std::endl;

	if(out.fail())
		throw(std::ios_base::failure("Error: could not write to file"));
	out.close();
	if(out.fail()){
		throw(std::ios_base::failure("Error: could not close file"));
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, NotSignedException) {
	AForm::execute(executor);
	draw_trees(_target + "_shrubbery");
};
