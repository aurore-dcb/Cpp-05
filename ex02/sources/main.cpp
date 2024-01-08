#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
    std::cout << GRAY << std::endl << "----- test grade bureaucrat -----" << std::endl << RESET_COLOR << std::endl;
    try {
        Bureaucrat Worker("worker", 200);
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    /* ----------------------------------------- */
    std::cout << GRAY << std::endl << "----- test execute form without sign -----" << std::endl << RESET_COLOR << std::endl;
    try {
        Bureaucrat Worker("worker", 50);
        std::cout << Worker;
        ShrubberyCreationForm form1("home");
        std::cout << form1;
        Worker.executeForm(form1);
        Worker.signForm(form1);
        Worker.executeForm(form1);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
    /* ----------------------------------------- */
    std::cout << GRAY << std::endl << "----- test grade too low to execute -----" << std::endl << RESET_COLOR << std::endl;
    try {
        Bureaucrat employee("employee", 80);
        RobotomyRequestForm robotForm("important");
        std::cout << employee;
        std::cout << robotForm;
        employee.signForm(robotForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    /* ----------------------------------------- */
    std::cout << GRAY << std::endl << "----- test grade too low to sign/execute -----" << std::endl << RESET_COLOR << std::endl;
    try {
        Bureaucrat employee("employee", 80);
        ShrubberyCreationForm shrubberyForm("everyone");
        RobotomyRequestForm robotForm("important");
        std::cout << employee;
        std::cout << robotForm;
        employee.signForm(shrubberyForm);
        employee.signForm(robotForm);

        std::cout << std::endl;
        Bureaucrat chef("chef", 50);
        std::cout << chef;
        chef.signForm(robotForm);
        chef.executeForm(robotForm);

        std::cout << std::endl;
        Bureaucrat boss("boss", 6);
        std::cout << boss;
        std::cout << robotForm;
        boss.executeForm(robotForm);

        std::cout << std::endl;
        PresidentialPardonForm presidentialForm("bigboss");
        std::cout << presidentialForm;
        boss.signForm(presidentialForm);
        boss.executeForm(presidentialForm);
        std::cout << "Boss got an augmentation." << std::endl;
        boss.incrementGrade();
        boss.executeForm(presidentialForm);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}