#include "information.hpp"
#include "structure.hpp"
#include <random>
#include <string>
#ifndef _EXT_RANDOM_H
#define _EXT_RANDOM_H
//  Initalize
static std::random_device rand_dev; // NOLINT
static std::mt19937_64 rand_eng(rand_dev()); // NOLINT

// Functions
//  Generate random integer in interval [start,end]
class intRand {
public:
    int operator()(int start, int end)
    {
        std::uniform_int_distribution<signed int> u(start, end);
        return u(rand_eng);
    }
} randint;
class uintRand {
public:
    unsigned int operator()(unsigned int start, unsigned int end)
    {
        std::uniform_int_distribution<unsigned int> u(start, end);
        return u(rand_eng);
    }
} randuint;

class llRand {
public:
    long long operator()(long long start, long long end)
    {
        std::uniform_int_distribution<signed long long> u(start, end);
        return u(rand_eng);
    }
} randll;
class ullRand {
public:
    unsigned long long operator()(unsigned long long start, unsigned long long end)
    {
        std::uniform_int_distribution<unsigned long long> u(start, end);
        return u(rand_eng);
    }
} randull;
class doubleRand {
public:
    double operator()(double start, double end)
    {
        std::uniform_real_distribution<double> u(start, end);
        return u(rand_eng);
    }
} randdouble;

// Rand rule
class ruleRand {
public:
    std::string operator()(cdg::Rules rules)
    {
        unsigned i = randuint(0, rules.size() - 1);
        return rules[i];
    }
} randrule;

// Generate string, character
char randdigit()
{
    std::uniform_int_distribution<char> u('0', '9');
    return u(rand_eng);
}
char randlower()
{
    std::uniform_int_distribution<char> u('a', 'z');
    return u(rand_eng);
}
char randupper()
{
    std::uniform_int_distribution<char> u('A', 'Z');
    return u(rand_eng);
}
char randsymbol()
{
    std::uniform_int_distribution<int> u(0, 31);
    int r = u(rand_eng);
    if (0 <= r && r <= 14) {
        return static_cast<char>(33 + r);
    } else if (15 <= r && r <= 21) {
        return static_cast<char>(43 + r);
    } else if (22 <= r && r <= 27) {
        return static_cast<char>(69 + r);
    } else {
        return static_cast<char>(95 + r);
    }
}
/*
    There are 5 rules:
    Digit:
        Generate number
    Lower:
        Generate lower alphabet
    Upper:
        Generate upper alphabet
    Space:
        Generate space
    Symbol:
        Generate symbol

    What's more, you can use these rules at
    the same time in order to generate multiply
    datas. You are supposed to divide these
    rules by using space. You can write these
    rules in all arrenge

    For example:
        In function randchar:
            "Digit Lower" will generate a character which
            is a number or an lower alphabet.
        In function randstring:
            "Upper Symbol" will generate a string including
            upper alphabets and numbers.
*/
class charRand {
public:
    char operator()(const cdg::Rules& rules)
    {
        std::string current_rule = randrule(rules);
        if (current_rule == "Digit") {
            return randdigit();
        } else if (current_rule == "Lower") {
            return randlower();
        } else if (current_rule == "Upper") {
            return randupper();
        } else if (current_rule == "Space") {
            return ' ';
        } else if (current_rule == "Symbol") {
            return randsymbol();
        } else {
            throw std::invalid_argument("Invalid rule:" + current_rule);
        }
    }
} randchar;
class stringRand {
public:
    std::string operator()(const unsigned int& length, const cdg::Rules& rules)
    {
        std::string temp;
        for (unsigned i = 1; i <= length; i++) {
            temp.push_back(randchar(rules));
        }
        return temp;
    }
} randstring;
#endif