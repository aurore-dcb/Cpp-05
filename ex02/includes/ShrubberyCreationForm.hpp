#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public AForm {

    public :
        ShrubberyCreationForm( std::string target );
        ~ShrubberyCreationForm( void );
        ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& rhs);

        void execute(Bureaucrat const & executor) const;
};

#endif