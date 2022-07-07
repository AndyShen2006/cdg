#include <iostream>
#include <string>
#include <vector>
#ifndef _BASIC_LIB_H
#define _BASIC_LIB_H
namespace cdg {
// Class Rule
class Rules {
public:
    // Construct functions
    Rules() = default;
    Rules(const Rules& r);
    explicit Rules(const std::string& r);
    //  Basic informations
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
    // Generate functions
    void generate(const Rules& r);
    void generate(const std::string& r);

private:
    std::vector<std::string> rules;
};

// Class Interval（Noting completed）
template <typename T>
class Interval {
public:
    T getStart();
    T getEnd();
    bool getLtype();
    bool getRtype();

private:
    T start, end;
    bool Ltype; // false->( ; true->[
    bool Rtype; // false->) ; true->]
};
}
cdg::Rules makerules();
#endif