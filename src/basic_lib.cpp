#include "../include/basic_lib.h"

using namespace cdg;
// Construct functions
Rules::Rules(const Rules& r)
{
    rules = r.rules;
}

Rules::Rules(const std::string& r)
{
    std::string tempstr;
    for (auto it : r) {
        if (it == ' ') {
            rules.emplace_back(tempstr);
            tempstr.clear();
            continue;
        } else {
            tempstr.push_back(it);
        }
    }
    // Push last string
    if (!tempstr.empty()) {
        rules.emplace_back(tempstr);
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
        temp.emplace_back(it);
    }
    for (const auto& it : rhs.rules) {
        temp.emplace_back(it);
    }
    return temp;
}

// Generate functions
void Rules::generate(const Rules& r)
{
    Rules temp(r);
    rules = temp.rules;
}

void Rules::generate(const std::string& r)
{
    Rules temp(r);
    rules = temp.rules;
}

// Make functions
Rules make_rules(const std::string& r)
{
    Rules tempRule(r);
    return tempRule;
}
