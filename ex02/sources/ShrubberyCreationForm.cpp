#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm(target, 145, 137), _target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& cpy ) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()) {

    *this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    
    _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::formAction() const {

    std::ofstream file(std::string(_target + "_shrubbery").c_str());
    if (file) {
        file << "    ^        ^        ^ " << std::endl;
        file << "   ^^^      ^^^      ^^^ " << std::endl;
        file << "  ^^^^^    ^^^^^    ^^^^^ " << std::endl;
        file << " ^^^^^^^  ^^^^^^^  ^^^^^^^ " << std::endl;
        file << "    |        |        | " << std::endl;
    } else {
        throw std::ios_base::failure("Error opening file");
    }
}
