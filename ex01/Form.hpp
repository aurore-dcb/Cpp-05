#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form {

    public :

        Form( std::string name , const int toSign , const int toExec );
        ~Form( void );
        Form( const Form& cpy );
        Form& operator=( const Form& cpy );

        class GradeTooHighException {
            public:
            virtual const char* what() const throw() {
                return "Grade is too high !";
            }
        };

        class GradeTooLowException {
            public:
            virtual const char* what() const throw() {
                return "Grade is too low !";
            }
        };

        std::string getName( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExec( void ) const;
        bool getSigned( void ) const;

        void beSigned( Bureaucrat Bureaucrat )

    private :

        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, Form& other);

#endif