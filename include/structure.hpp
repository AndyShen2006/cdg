// Structure header: Some data structures for data generation
// This file is a part of cdg library, which provides some useful classes and functions in order to generate data more efficiently.
// Copyright (C) 2022-2023 Andy Shen
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include "information.hpp"
#include <iostream>
#include <string>
#include <vector>
#ifndef _BASIC_LIB_H
#define _BASIC_LIB_H
namespace cdg {
// Classes
namespace Types {
    class Integral {
    };
}
namespace Rules {
    /*
        Let's think about an argument:
        It often includes a Type(Usually String), which denote the type of this argument
        And also includes some specific details(Usually Integer).
    */
    class Argument {
    private:
        std::string Type;
        std::vector<long long> Details;

    public:
        Argument(const std::string& type, const std::initializer_list<long long>& details)
        {
            Type = type;
            Details = details;
        }
        bool operator<(const Argument& rhs) const
        {
            return this->Type == rhs.Type ? throw std::invalid_argument("Multiple Arguments") : this->Type < rhs.Type;
        }
    };
    class Rules {
    public:
    private:
        std::vector<Argument> rules;
    };
}
// class Rules {
// public:
//     // Construct functions
//     Rules() = default;
//     Rules(const Rules& r)
//     {
//         rules = r.rules;
//     };
//     explicit Rules(const std::string& r)
//     {
//         std::string tempstr;
//         for (auto it : r) {
//             if (it == ' ') {
//                 rules.emplace_back(tempstr);
//                 tempstr.clear();
//                 continue;
//             } else {
//                 tempstr.push_back(it);
//             }
//         }
//         // Push last string
//         if (!tempstr.empty()) {
//             rules.emplace_back(tempstr);
//             tempstr.clear();
//         }
//     }
//     //  Basic informations
//     unsigned int size() const
//     {
//         return rules.size();
//     };
//     unsigned int length() const
//     {
//         return rules.size();
//     };
//     // Display function
//     void showRules()
//     {
//         for (const auto& it : rules) {
//             std::cout << it << std::endl;
//         }
//     }
//     // Part of iterator
//     typedef std::vector<std::string>::iterator iterator;
//     iterator begin()
//     {
//         return rules.begin();
//     }
//     iterator end()
//     {
//         return rules.end();
//     }
//     // Reload symbols
//     std::string& operator[](std::size_t n)
//     {
//         return rules[n];
//     };
//     std::vector<std::string> operator+(const Rules& rhs)
//     {
//         std::vector<std::string> temp;
//         for (const auto& it : this->rules) {
//             temp.emplace_back(it);
//         }
//         for (const auto& it : rhs.rules) {
//             temp.emplace_back(it);
//         }
//         return temp;
//     };
//     // Generate functions
//     void generate(const Rules& r)
//     {
//         Rules temp(r);
//         rules = temp.rules;
//     }
//     void generate(const std::string& r)
//     {
//         Rules temp(r);
//         rules = temp.rules;
//     }

// private:
//     std::vector<std::string> rules;
// };
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
// Union Find Set
class UFS {
public:
    UFS() = default;
    explicit UFS(int n)
    {
        size = n;
        par.emplace_back(0);
        for (int i = 1; i <= n; i++) {
            par.emplace_back(i);
        }
    }
    void init(unsigned n)
    {
        size = n;
        par.emplace_back(0);
        for (unsigned i = 1; i <= n; i++) {
            par.emplace_back(i);
        }
    }
    int findpar(int x) // NOLINT
    {
        return par[x] == x ? x : par[x] = findpar(par[x]);
    }
    bool isSamePar(int x, int y)
    {
        return findpar(x) == findpar(y);
    }
    void unite(int x, int y)
    {
        x = findpar(x);
        y = findpar(y);
        par[x] = y;
    }

private:
    std::vector<int> par;
    unsigned size {};
};
}
// Functions
cdg::Rules make_Rules(const std::string& r)
{
    cdg::Rules tempRule(r);
    return tempRule;
}
#endif