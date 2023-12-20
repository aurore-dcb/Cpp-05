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

class AForm {

    public :

        AForm( std::string name , const int toSign , const int toExec );
        ~AForm( void );
        AForm( const AForm& cpy );
        AForm& operator=( const AForm& cpy );

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

        void beSigned( Bureaucrat bureaucrat );

        virtual void execute(Bureaucrat const & executor) const;

    private :

        const std::string   _name;
        bool                _signed;
        const int           _gradeToSign;
        const int           _gradeToExecute;

        virtual void formAction() const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm& other);

#endif