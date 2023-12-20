#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45), _target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& cpy ) : AForm(cpy.getName(), cpy.getGradeToSign(), cpy.getGradeToExec()) {

    *this = cpy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    
    _target = rhs._target;
    return *this;
}

void RobotomyRequestForm::formAction() const {

    time_t currentTime = time(0);
    clock_t clockTime = clock();
    unsigned int value = static_cast<unsigned int>(currentTime) ^ static_cast<unsigned int>(clockTime);

    if (value % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "the robotomy failed." << std::endl;
    return;
}
