#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5), _target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& cpy ) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()) {

    *this = cpy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    
    _target = rhs._target;
    return *this;
}

void PresidentialPardonForm::formAction() const {

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
