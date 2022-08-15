// Tree library: For generating tree data
// This file is a part of cdg library, which provides some useful classes and functions in order to generate data more efficiently.
// Copyright (C) 2022 Andy Shen
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
#include "../ext_random.hpp"
#include "../information.hpp"
#include <algorithm>
#include <vector>
#ifndef _TREE_H
#define _TREE_H
namespace cdg {
namespace Graph {
    template <typename val_type = int, typename randRule = intRand>
    class Tree {
    public:
        typedef val_type valType;
        randRule Rand;
        explicit Tree(const unsigned&& n)
        {
            cntNode = n;
            ufs.init(n);
            for (unsigned i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
            }
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        Tree(const unsigned&& n, const unsigned&& r)
        {
            cntNode = n;
            ufs.init(n);
            for (unsigned i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
            }
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        Tree(const unsigned&& n, const valType&& vf, const valType&& vt)
        {
            cntNode = n;
            ufs.init(n);
            for (unsigned i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
            }
            valFrom = vf;
            valTo = vt;
            hasValue = true;
            for (unsigned i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        Tree(const unsigned&& n, const unsigned&& r, const valType&& vf, const valType&& vt)
        {
            cntNode = n;
            ufs.init(n);
            for (unsigned i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
            }
            valFrom = vf;
            valTo = vt;
            hasValue = true;
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        void showTree(Rules&& rules)
        {
            if (hasValue) {
                if (rules.size() > 1) {
                    throw std::invalid_argument("Too many arguments!");
                }
                if (rules[0] == "Adjacency") {
                    if (hasValue) {
                        throw std::invalid_argument("You cannot print tree with value in adjacency mode!");
                    }
                    for (unsigned i = 1; i < T.size(); i++) {
                        std::cout << i << ' ';
                        for (const auto& it : T[i]) {
                            std::cout << it.first << ' ' << it.second << ' ';
                        }
                        std::cout << std::endl;
                    }
                } else if (rules[0] == "Edge") {
                    for (unsigned i = 1; i < T.size(); i++) {
                        for (const auto& it : T[i]) {
                            if (i > it.first) {
                                std::cout << i << ' ' << it.first << ' ' << it.second << std::endl;
                            }
                        }
                    }
                }
            } else {
                if (rules.size() > 1) {
                    throw std::invalid_argument("Too many arguments!");
                }
                if (rules[0] == "Adjacency") {
                    for (unsigned i = 1; i < T.size(); i++) {
                        std::cout << i << ' ';
                        for (const auto& it : T[i]) {
                            std::cout << it.first << ' ';
                        }
                        std::cout << std::endl;
                    }
                } else if (rules[0] == "Edge") {
                    for (unsigned i = 1; i < T.size(); i++) {
                        for (const auto& it : T[i]) {
                            std::cout << i << ' ' << it.first << std::endl;
                        }
                    }
                }
            }
        }
        void randTree()
        {
            int u = 0, v = 0;
            for (unsigned i = 1; i <= cntNode - 1; i++) {
                do {
                    u = randint(1, cntNode);
                    v = randint(1, cntNode);
                } while (ufs.isSamePar(u, v));
                ufs.unite(u, v);
                valType w = Rand(valFrom, valTo);
                T[u].emplace_back(std::make_pair(v, w));
                T[v].emplace_back(std::make_pair(u, w));
            }
        }
        // TODO 生成特殊树
        void randTree(Rules&& rules, std::initializer_list<int>&& arguments)
        {
        }

    private:
        unsigned cntNode = 0;
        const unsigned& cntEdge = cntNode - 1;
        unsigned root = 1;
        bool hasValue = false;
        valType valFrom, valTo;
        std::vector<std::vector<std::pair<unsigned, valType>>> T;
        const std::vector<std::pair<unsigned, valType>> EmptyVector;
        const std::pair<unsigned, valType> EmptyElement;
        std::vector<int> mapping;
        UFS ufs;
    };
}
}

#endif