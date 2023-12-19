#include "../includes/Form.hpp"

AForm::~AForm( void ) {}

AForm::AForm( const AForm& cpy ) : _name(cpy._name), _signed(false), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute) {

    *this = cpy;
}

AForm& AForm::operator=(const AForm& rhs) {

    _signed = rhs._signed;
    return *this;
}

AForm::AForm( std::string name , const int toSign , const int toExec ) : _name(name), _signed(0), _gradeToSign(toSign) , _gradeToExecute(toExec) {

    if (toSign < 1 || toExec < 1)
        throw AForm::GradeTooHighException();
    else if (toSign > 150 || toExec > 150)
        throw AForm::GradeTooLowException();
    return;
}

int AForm::getGradeToSign( void ) const {

    return _gradeToSign;
}

int AForm::getGradeToExec( void ) const {

    return _gradeToExecute;
}

std::string AForm::getName( void ) const {

    return _name;
}

bool AForm::getSigned( void ) const {

    return _signed;
}

void AForm::beSigned( Bureaucrat bureaucrat ) {

	if (bureaucrat.getGrade() <= _gradeToSign) {
        _signed = true;
    }
    else {
        throw AForm::GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &os, AForm &other) {

    os << other.getName() << "'s informations :" << std::endl;
    os << "	- grade required to sign : " << other.getGradeToSign() << std::endl;
	os << "	- grade required to execute : " << other.getGradeToExec() << std::endl;
	if (other.getSigned())
		os << "	- status : " << GREEN << "signed" << RESET_COLOR << std::endl;
	else
		os << "	- status : " << RED << "not signed" << RESET_COLOR << std::endl;
    return os;
}

void AForm::execute(Bureaucrat const & executor) const {

        
}