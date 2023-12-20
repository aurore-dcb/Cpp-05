#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

int main()
{
    std::cout << GRAY << "----- test grade bureaucrat -----" << RESET_COLOR << std::endl;
    try {
        Bureaucrat Worker("worker", 50);
        std::cout << Worker;
        ShrubberyCreationForm form1("people");
        Worker.signForm(form1);
        std::cout << form1;
        Worker.executeForm(form1);
        Bureaucrat CEO("CEO", 25);
        std::cout << CEO;
        CEO.signForm(form1);
        CEO.executeForm(form1);
        RobotomyRequestForm form2("private");
        CEO.signForm(form2);
        std::cout << form2;
        CEO.executeForm(form2);

    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (AForm::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (AForm::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
}