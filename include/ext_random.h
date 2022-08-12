#include "basic_lib.h"
#include <random>
#include <string>
#ifndef _EXT_RANDOM_H
#define _EXT_RANDOM_H

// Initalize
static std::random_device rand_dev; // NOLINT
static std::mt19937_64 rand_eng(rand_dev()); // NOLINT

// Generate random valuable in interval [start,end]
unsigned int randuint(unsigned int start, unsigned int end);
int randint(int start, int end);
long long randll(long long start, long long end);
unsigned long long randull(unsigned long long start, unsigned long long end);
double randdouble(double start, double end);

// Rand rule
std::string randrule(cdg::Rules rules);
// Generate string, character
char randdigit();
char randlower();
char randupper();
char randsymbol();
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
char randchar(const cdg::Rules& rules);
char randchar(const std::string& rules);
std::string randstring(const unsigned& length, const cdg::Rules& rules);
std::string randstring(const unsigned& length, const std::string& rules);
#endif