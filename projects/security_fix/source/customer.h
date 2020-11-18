#ifndef PORTFOLIO_CUSTOMER_H
#define PORTFOLIO_CUSTOMER_H

#include <string>
#include <sstream>

struct Customer {
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip_code;
    int id;

    std::string to_string() const {
        std::stringstream ss;
        ss << id << delimiter << first_name << delimiter << middle_name << delimiter << last_name << delimiter
            << address << delimiter << city << delimiter << state << delimiter << zip_code;
        return ss.str();
    }

    decltype(std::string()) delimiter {","};
};
#endif
