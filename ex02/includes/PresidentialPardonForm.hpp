#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public AForm {

    public :
        PresidentialPardonForm( std::string target );
        ~PresidentialPardonForm( void );
        PresidentialPardonForm(const PresidentialPardonForm& cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);

        void formAction() const;

    private :

        std::string _target;
};

#endif