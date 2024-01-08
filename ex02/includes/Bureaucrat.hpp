#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class AForm ;

class Bureaucrat
{
    public :
        
        Bureaucrat( void );
        ~Bureaucrat( void );
        Bureaucrat( const Bureaucrat& cpy );
        Bureaucrat& operator=(const Bureaucrat& copy);
        Bureaucrat( std::string name , int grade );

        class GradeTooHighException : public std::exception {
            public:
            virtual const char* what() const throw() {
                return "Grade is too high !";
            }
        };

        class GradeTooLowException : public std::exception {
            public:
            virtual const char* what() const throw() {
                return "Grade is too low !";
            }
        };

        int getGrade( void ) const;
        std::string getName( void ) const;
        void incrementGrade( void );
        void decrementGrade( void );

        void signForm( AForm &form );
        void executeForm(AForm const & form);

    private :

        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &other);

#endif