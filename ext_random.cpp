#include "ext_random.h"

// Generate random integer in interval [start,end]
int randint(int start, int end)
{
    std::uniform_int_distribution<signed int> u(start, end);
    return u(rand_eng);
}

unsigned int randuint(unsigned int start, unsigned int end)
{
    std::uniform_int_distribution<unsigned int> u(start, end);
    return u(rand_eng);
}

long long randll(long long start, long long end)
{
    std::uniform_int_distribution<signed long long> u(start, end);
    return u(rand_eng);
}

unsigned long long randull(unsigned long long start, unsigned long long end)
{
    std::uniform_int_distribution<unsigned long long> u(start, end);
    return u(rand_eng);
}

// Rand rule
std::string randrule(Rules rules)
{
    unsigned i = randuint(0, rules.size() - 1);
    return rules[i];
}

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
char randchar(const Rules& rules)
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
        throw std::invalid_argument("Cannot find find rule:" + current_rule);
    }
}
// A Syntax candy
char randchar(const std::string& rules)
{
    Rules r(rules);
    return randchar(r);
}
std::string randstring(const unsigned int& length, const Rules& rules)
{
    std::string temp;
    for (unsigned i = 1; i <= length; i++) {
        temp.push_back(randchar(rules));
    }
    return temp;
}
// A Syntax candy
std::string randstring(const unsigned int& length, const std::string& rules)
{
    Rules r(rules);
    return randstring(length, r);
}