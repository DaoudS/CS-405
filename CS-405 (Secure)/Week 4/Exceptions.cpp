// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Custom exepction fucntion 
struct CustomException : std::exception {
    const char* what() const throw () {
        return "This is a custom exception";
    }
};


bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;
    throw std::invalid_argument("This is a standard exception"); // Throws invalid arugment exception without any surrounding logic
    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    //Added try and catch block as requested in todo. 
    std::cout << "Running Custom Application Logic." << std::endl;

    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Exception" << e.what() << std::endl;
    }


    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    // Throws custom exception methods
    throw CustomException();

    std::cout << "Leaving Custom Application Logic." << std::endl;
}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    // if den is 0, throw an exception
    if (den == 0) {
        throw std::runtime_error("Invalid operation: cannot divide by zero");
    }
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;
    try
    {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception" << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.

    try
    {
        do_custom_application_logic();
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception from  do_custom_application_logic()" << e.what() << std::endl;
    }

    try
    {
        do_division();
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception from do_division()" << e.what() << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu