#include "Form.hpp"

Form::~Form( void ) {}

Form::Form( const Form& cpy ) : _name(cpy._name), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute) {

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

// void Form::incrementGrade( void ) {

//     std::cout << "Incrementing " << _name << " grade ..."  << std::endl;
//     if (_grade - 1 < 1)
//         throw Form::GradeTooHighException();
//     else {
//         _grade--;
//     }
// }

// void Form::decrementGrade( void ) {

//     std::cout << "Decrementing " << _name << " grade ..."  << std::endl;
//     if (_grade + 1 > 150)
//         throw Form::GradeTooLowException();
//     else {
//         _grade++;
//     }
// }

std::ostream &operator<<(std::ostream &os, Form &other) {

    os << "Form's informations :" << std::endl;
    os << "	- grade required to sign : " << other.getGradeToSign() << std::endl;
	os << "	- grade required to execute : " << other.getGradeToExec() << std::endl;
	if (other.getSigned())
		os << "	- status : signed" << std::endl;
	else
		os << "	- status : not signed" << std::endl;
    return os;
}