#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137) {

}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& cpy ) : AForm("default", 145, 137) {

    *this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {


}