#include "information.hpp"
#include <iostream>
#include <string>
#include <vector>
#ifndef _BASIC_LIB_H
#define _BASIC_LIB_H
namespace cdg {
// Classes
class Rules {
public:
    // Construct functions
    Rules() = default;
    Rules(const Rules& r)
    {
        rules = r.rules;
    };
    explicit Rules(const std::string& r)
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
    //  Basic informations
    unsigned int size() const
    {
        return rules.size();
    };
    unsigned int length() const
    {
        return rules.size();
    };
    // Display function
    void showRules()
    {
        for (const auto& it : rules) {
            std::cout << it << std::endl;
        }
    }
    // Part of iterator
    typedef std::vector<std::string>::iterator iterator;
    iterator begin()
    {
        return rules.begin();
    }
    iterator end()
    {
        return rules.end();
    }
    // Reload symbols
    std::string& operator[](std::size_t n)
    {
        return rules[n];
    };
    std::vector<std::string> operator+(const Rules& rhs)
    {
        std::vector<std::string> temp;
        for (const auto& it : this->rules) {
            temp.emplace_back(it);
        }
        for (const auto& it : rhs.rules) {
            temp.emplace_back(it);
        }
        return temp;
    };
    // Generate functions
    void generate(const Rules& r)
    {
        Rules temp(r);
        rules = temp.rules;
    }
    void generate(const std::string& r)
    {
        Rules temp(r);
        rules = temp.rules;
    }

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
// Union Find Set
class UFS {
public:
    explicit UFS(int n)
    {
        size = n;
        par.emplace_back(0);
        for (int i = 1; i <= n; i++) {
            par.emplace_back(i);
        }
    }
    void init(int n)
    {
        size = n;
        par.emplace_back(0);
        for (int i = 1; i <= n; i++) {
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
    int size;
};
}
// Functions
cdg::Rules make_Rules(const std::string& r)
{
    cdg::Rules tempRule(r);
    return tempRule;
}
#endif