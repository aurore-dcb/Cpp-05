#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

#define RED         "\033[31m"
#define GRAY        "\033[90m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLACK       "\033[30m"
#define RESET_COLOR "\033[0m"
#define UNDERLINE   "\033[4m"

class Bureaucrat ;

class Form {

    public :

        Form( std::string name , const int toSign , const int toExec );
        ~Form( void );
        Form( const Form& cpy );
        Form& operator=( const Form& cpy );

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

        std::string getName( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExec( void ) const;
        bool getSigned( void ) const;

        void beSigned( const Bureaucrat& bureaucrat );

    private :

        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, Form& other);

#endif