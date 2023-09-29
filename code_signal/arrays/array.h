#ifndef CODEVAULT_ARRAY_H
#define CODEVAULT_ARRAY_H

#include <string>
#include <vector>

class Array {
public:
    Array() = default;
    ~Array() = default;

    static int first_duplicate(std::vector<int> a);
    static char first_not_repeating_character(const std::string& s);

protected:
private:
};
#endif
