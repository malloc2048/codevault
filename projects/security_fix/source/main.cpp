#include <fstream>
#include <iostream>
#include "customer.h"

int main() {
    std::string number_input;
    std::cout << "Enter the number of customer objects you wish to enter: ";

    // read as a string then convert to a number to clear the newline from the input stream
    std::getline(std::cin, number_input);
    auto customer_count = std::strtol(number_input.c_str(), nullptr, 10);

    if (customer_count <= 0)
        return -1;

    std::ofstream customer_data("CustomerData.txt", std::ios::app);
    if (!customer_data.is_open()) {
        std::cout << "cannot open customer data file: CustomerData.txt" << std::endl;
        return -2;
    }

    std::cout << "customer data file opened" << std::endl;
    for (auto count = 0; count < customer_count; count++) {
        Customer customer {};
        std::cout << "first name: ";
        std::getline(std::cin, customer.first_name);

        std::cout << "middle name: ";
        std::getline(std::cin, customer.middle_name);

        std::cout << "last name: ";
        std::getline(std::cin, customer.last_name);

        std::cout << "street address: ";
        std::getline(std::cin, customer.address);

        std::cout << "city: ";
        std::getline(std::cin, customer.city);

        std::cout << "state: ";
        std::getline(std::cin, customer.state);

        std::cout << "postal code: ";
        std::getline(std::cin, customer.zip_code);

        std::cout << "customer ID: ";
        std::getline(std::cin, number_input);
        customer.id = std::strtol(number_input.c_str(), nullptr, 10);

        customer_data << customer.to_string() << std::endl;
    }

    std::cout << "done adding customers to the database" << std::endl;
    customer_data.close();
    return 0;
}
