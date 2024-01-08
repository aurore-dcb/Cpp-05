#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

    public :
        ShrubberyCreationForm( std::string target );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);

        void formAction() const;

    private :

        std::string _target;
};

#endif