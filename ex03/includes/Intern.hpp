#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <string>

class Intern {

    public :
        Intern( void );
        ~Intern( void );
        Intern( const Intern& cpy );
        Intern& operator=( const Intern& rhs);

        AForm* makeShrubberyCreationForm( std::string target );
        AForm* makeRobotomyRequestForm( std::string target );
        AForm* makePresidentialPardonForm( std::string target );
        typedef AForm* (Intern::*makeFormFct)(std::string target);
        AForm* makeForm( std::string name , std::string target );

        class FormNotFound {
            public:
            virtual const char* what() const throw() {
                return "Type of form not found !";
            }
        };

    private :


};

#endif