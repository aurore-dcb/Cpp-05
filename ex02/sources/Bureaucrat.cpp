#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {}

Bureaucrat::~Bureaucrat( void ) {

    // std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& cpy ) {

    *this = cpy;
    // std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {

    _grade = rhs._grade;
    return *this;
}

Bureaucrat::Bureaucrat( std::string name , int grade ) : _name(name) {

    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

int Bureaucrat::getGrade( void ) const {

    return _grade;
}

std::string Bureaucrat::getName( void ) const {

    return _name;
}

void Bureaucrat::incrementGrade( void ) {

    // std::cout << "Incrementing " << _name << " grade ..."  << std::endl;
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else {
        _grade--;
    }
}

void Bureaucrat::decrementGrade( void ) {

    // std::cout << "Decrementing " << _name << " grade ..."  << std::endl;
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else {
        _grade++;
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &other) {

    os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
    return os;
}

void Bureaucrat::signForm( AForm &form ) {
    
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << _name << " couldn't sign " << form.getName() << " because grade is too low." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {

    try {
        // fonction qui execute le bon form
        // (peut throw une erreur)
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "" << std::endl;
    }
}