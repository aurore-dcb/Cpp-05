#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << GRAY << "----- test grade bureaucrat -----" << RESET_COLOR << std::endl;
    try {
        Bureaucrat test("bureaucrat", 0);
        std::cout << test;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }

    std::cout << std::endl;

    try {
        std::cout << GRAY << "--- test copy ---" << RESET_COLOR << std::endl;
        Form form("warning", 100, 5);
        Form form2 = form;
        std::cout << GRAY << "form" << RESET_COLOR << std::endl;
        std::cout << form;
        std::cout << GRAY << "form2" << RESET_COLOR << std::endl;
        std::cout << form2;

        Bureaucrat Worker("Worker", 26);
        std::cout << GRAY << std::endl << "----- Worker signs form2 -----" << RESET_COLOR << std::endl;
        Worker.signForm(form2);
        std::cout << GRAY << "form" << RESET_COLOR << std::endl;
        std::cout << form;
        std::cout << GRAY << "form2" << RESET_COLOR << std::endl;
        std::cout << form2;
        
        std::cout << GRAY << std::endl << "----- Worker signs form -----" << RESET_COLOR << std::endl;
        Worker.signForm(form);
        std::cout << GRAY << "form" << RESET_COLOR << std::endl;
        std::cout << form;
        std::cout << GRAY << "form2" << RESET_COLOR << std::endl;
        std::cout << form2;

        std::cout << GRAY << "Both forms have been signed." << RESET_COLOR << std::endl << std::endl;

        /* New Bureaucrat and new form */
        std::cout << GRAY << std::endl << "----- New Bureaucrat and new form -----" << RESET_COLOR << std::endl;
        Bureaucrat Manager("Manager", 2);
        Form newForm("crisis", 25, 5);
        std::cout << newForm;

        std::cout << GRAY << "Worker try to sign crisis form" << RESET_COLOR << std::endl;
        Worker.signForm(newForm);
        std::cout << GRAY << "Manager try to sign crisis form" << RESET_COLOR << std::endl;
        Manager.signForm(newForm);

        std::cout << std::endl;

        std::cout << Worker;
        std::cout << "... Worker got an augmentation ..." << std::endl;
        Worker.incrementGrade();
        std::cout << Worker;
        std::cout << GRAY << "Worker try to sign crisis form AGAIN" << RESET_COLOR << std::endl;
        Worker.signForm(newForm);
        std::cout << GRAY << "Worker now has a pretty high grade to sign the crisis form " << RESET_COLOR << std::endl;
        std::cout << newForm;
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
}