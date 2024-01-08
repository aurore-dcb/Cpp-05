#include "../includes/Intern.hpp"

Intern::Intern( void ) {}

Intern::~Intern( void ) {}

Intern::Intern( const Intern& cpy ) {

    *this = cpy;
}

Intern& Intern::operator=(const Intern& rhs) {

    (void)rhs;
    return *this;
}

AForm* Intern::makeShrubberyCreationForm( std::string target) {
    return ( new ShrubberyCreationForm(target) );
}

AForm* Intern::makeRobotomyRequestForm( std::string target) {
    return ( new RobotomyRequestForm(target) );
}

AForm* Intern::makePresidentialPardonForm( std::string target) {
    return ( new PresidentialPardonForm(target) );
}

AForm* Intern::makeForm( std::string name , std::string target) {

    std::string formNames[3];
    makeFormFct tab[3];

    formNames[0] = "shrubbery creation";
    formNames[1] = "robotomy request";
    formNames[2] = "presidential pardon";

    tab[0] = &Intern::makeShrubberyCreationForm;
    tab[1] = &Intern::makeRobotomyRequestForm;
    tab[2] = &Intern::makePresidentialPardonForm;

    for (int i = 0 ; i < 3 ; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*tab[i])(target));
        }
    }
    throw Intern::FormNotFound();
}
