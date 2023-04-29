## CPP05 - Repetition and Exceptions

### ex00: Bureaucrat
Create a program that implements the `Bureaucrat` class, which represents an official with a name and a grade from 1 (highest) to 150 (lowest). The class should have getter methods for both attributes, as well as methods to increment and decrement the grade, which should throw exceptions if the resulting grade is out of bounds. Also, implement an overload of the `<<` operator to print the `Bureaucrat`'s information.

### ex01: Form
Create a program that implements the `Form` class, which represents a document with a name, a signature status, and grades required to sign and execute it. The signature status should be modifiable by a `Bureaucrat` with a grade higher than the required signature grade. The class should have getter methods for all attributes and an overload of the `<<` operator to print the `Form`'s information. The class should also throw exceptions if the signature or execution grade is out of bounds.

### ex02: Execute
Create a program that implements the `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` classes, which represent forms with specific purposes. Each form should have a method to execute its purpose, which should throw an exception if the executing bureaucrat's grade is too low. Also, implement an overload of the `<<` operator to print the form's information.

### ex03: Intern
Create a program that implements the `Intern` class, which has a `makeForm()` function that takes two strings as parameters and returns a pointer to a Form object. The function initializes the target of the form with the second parameter and prints a message. If the form name passed as parameter doesn't exist, an exception is thrown.
