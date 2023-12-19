#include "Form.hpp"

Form::~Form( void ) {}

Form::Form( const Form& cpy ) : _name(cpy._name), _signed(false), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute) {

    *this = cpy;
}

Form& Form::operator=(const Form& rhs) {

    _signed = rhs._signed;
    return *this;
}

Form::Form( std::string name , const int toSign , const int toExec ) : _name(name), _signed(0), _gradeToSign(toSign) , _gradeToExecute(toExec) {

    if (toSign < 1 || toExec < 1)
        throw Form::GradeTooHighException();
    else if (toSign > 150 || toExec > 150)
        throw Form::GradeTooLowException();
    return;
}

int Form::getGradeToSign( void ) const {

    return _gradeToSign;
}

int Form::getGradeToExec( void ) const {

    return _gradeToExecute;
}

std::string Form::getName( void ) const {

    return _name;
}

bool Form::getSigned( void ) const {

    return _signed;
}

void Form::beSigned( Bureaucrat bureaucrat ) {

	if (bureaucrat.getGrade() <= _gradeToSign) {
        _signed = true;
    }
    else {
        throw Form::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, Form &other) {

    os << other.getName() << "'s informations :" << std::endl;
    os << "	- grade required to sign : " << other.getGradeToSign() << std::endl;
	os << "	- grade required to execute : " << other.getGradeToExec() << std::endl;
	if (other.getSigned())
		os << "	- status : " << GREEN << "signed" << RESET_COLOR << std::endl;
	else
		os << "	- status : " << RED << "not signed" << RESET_COLOR << std::endl;
    return os;
}