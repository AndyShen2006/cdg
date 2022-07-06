#include <iostream>
#include <string>
#include <vector>
#ifndef _BASIC_LIB_H
#define _BASIC_LIB_H
// Class Rule
class Rules {
public:
    // Construct functions
    Rules() = default;
    explicit Rules(const std::string& r);
    // Basic informations
    unsigned int size();
    unsigned int length();
    // Display function
    void showRules();
    // Part of iterator
    typedef std::vector<std::string>::iterator iterator;
    iterator begin();
    iterator end();
    // Reload symbols
    std::string& operator[](std::size_t n);
    std::vector<std::string> operator+(const Rules& rhs);

private:
    std::vector<std::string> rules;
};
#endif