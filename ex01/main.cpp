#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    // try {
    //     Bureaucrat test("bureaucrat", 0);
    //     std::cout << test;
    // }
    // catch (Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl; 
    // }
    // catch (Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl; 
    // }

    // std::cout << std::endl;

    // try {
    //     Bureaucrat bureaucrat1( "bob" , 2);
    //     std::cout << bureaucrat1;
    //     bureaucrat1.incrementGrade();
    //     std::cout << bureaucrat1;
    //     bureaucrat1.incrementGrade();
    // }
    // catch (Bureaucrat::GradeTooHighException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl; 
    // }

    // std::cout << std::endl;

    // try {
    //     Bureaucrat bureaucrat2( "zoro" , 149);
    //     std::cout << bureaucrat2;
    //     bureaucrat2.decrementGrade();
    //     std::cout << bureaucrat2;
    //     bureaucrat2.decrementGrade();
    // }
    // catch (Bureaucrat::GradeTooLowException& e) {
    //     std::cout << "Exception caught: " << e.what() << std::endl; 
    // }


    try {
        std::cout << "--- test copy ---" << std::endl;
        Form form("bob", 2, 5);
        Form form2 = form;
        std::cout << form2;
    }
    catch (Form::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    catch (Form::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
}