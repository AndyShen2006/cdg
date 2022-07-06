#include "basic_lib.h"

// Construct functions
Rules::Rules(const std::string& r)
{
    std::string tempstr;
    for (auto it : r) {
        if (it == ' ') {
            rules.push_back(tempstr);
            tempstr.clear();
            continue;
        } else {
            tempstr.push_back(it);
        }
    }
    // Push last string
    if (!tempstr.empty()) {
        rules.push_back(tempstr);
        tempstr.clear();
    }
}

// Basic informations
unsigned int Rules::size()
{
    return rules.size();
}
unsigned int Rules::length()
{
    return rules.size();
}

// Display function
void Rules::showRules()
{
    for (const auto& it : rules) {
        std::cout << it << std::endl;
    }
}

// Part of iterator
Rules::iterator Rules::begin()
{
    return rules.begin();
}
Rules::iterator Rules::end()
{
    return rules.end();
}

// Reload symbols
std::string& Rules::operator[](std::size_t n)
{
    return rules[n];
}
std::vector<std::string> Rules::operator+(const Rules& rhs)
{
    std::vector<std::string> temp;
    for (const auto& it : this->rules) {
        temp.push_back(it);
    }
    for (const auto& it : rhs.rules) {
        temp.push_back(it);
    }
    return temp;
}

Rules make_rules(const std::string& r)
{
    Rules tempRule(r);
    return tempRule;
}
