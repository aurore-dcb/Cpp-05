#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public AForm {

    public :
        RobotomyRequestForm( std::string target );
        ~RobotomyRequestForm( void );
        RobotomyRequestForm(const RobotomyRequestForm& cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);

        void formAction() const;

    private :

        std::string _target;
};

#endif