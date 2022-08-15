// Digraph library: For generating digraph data
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
#ifndef _DIGRAPH_H
#define _DIGRAPH_H
namespace cdg {
namespace Graph {
    template <typename val_type, typename randRule>
    class Digraph {
    public:
        typedef val_type valType;
        randRule Rand;
        explicit Digraph(const int&& n)
        {
            cntNode = n;
            for (int i = 0; i <= n; i++) {
                G.emplace_back(Empty_Vector);
            }
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        Digraph(const int&& n, const bool&& is_shuffle)
        {
            cntNode = n;
            isShuffle = is_shuffle;
            for (int i = 0; i <= n; i++) {
                G.emplace_back(Empty_Vector);
            }
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        Digraph(const int&& n, const bool&& is_shuffle, const valType&& vf, const valType&& vt)
        {
            hasValue = true;
            cntNode = n;
            valFrom = vf;
            valTo = vt;
            isShuffle = is_shuffle;
            for (int i = 0; i <= n; i++) {
                G.emplace_back(Empty_Vector);
            }
            for (int i = 0; i <= n; i++) {
                mapping.emplace_back(i);
            }
            std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
        }
        void showGraph()
        {
            std::cout << cntNode << ' ' << cntEdge << std::endl;
            unsigned len = G.size();
            if (isShuffle) {
                if (hasValue) {
                    for (unsigned i = 0; i < len; i++) {
                        for (auto it : G[i]) {
                            std::cout << mapping[i] << ' ' << mapping[it.first] << ' ' << it.second << std::endl;
                        }
                    }
                } else {
                    for (unsigned i = 0; i < len; i++) {
                        for (auto it : G[i]) {
                            std::cout << mapping[i] << ' ' << mapping[it.first] << std::endl;
                        }
                    }
                }
            } else {
                if (hasValue) {
                    for (unsigned i = 0; i < len; i++) {
                        for (auto it : G[i]) {
                            std::cout << i << ' ' << it.first << ' ' << it.second << std::endl;
                        }
                    }
                } else {
                    for (unsigned i = 0; i < len; i++) {
                        for (auto it : G[i]) {
                            std::cout << i << ' ' << it.first << std::endl;
                        }
                    }
                }
            }
        }

    private:
        std::vector<std::vector<std::pair<int, valType>>> G;
        std::vector<int> mapping;
        std::vector<std::pair<int, valType>> Empty_Vector;
        int cntEdge = 0, cntNode = 0;
        bool hasValue = false;
        valType valFrom, valTo; // If hasValue is true, this option will be enabled.
        bool isShuffle = false;
        // Part 1: generate rand edge
        void randedge(int V);
        // Part 2:generate functions without arguments
        void emptyGraph() { }
        void completeGraph()
        {
            for (int i = 1; i < cntNode; i++) {
                for (int j = i + 1; j <= cntNode; j++) {
                    if (hasValue) {
                        G[i].push_back(std::make_pair(j, Rand(valFrom, valTo)));
                    } else {
                        G[i].push_back(std::make_pair(j, 1));
                    }
                    cntEdge++;
                }
            }
        }
        void tourGraph()
        {
        }
        void cycleGraph()
        {
            for (int i = 1; i < cntNode; i++) {
                G[i].push_back(std::make_pair(i + 1, Rand(valFrom, valTo)));
                cntEdge++;
            }
            cntEdge++;
            G[cntNode].push_back(std::make_pair(1, Rand(valFrom, valTo)));
        }
        void starGraph()
        {
            for (int i = 2; i <= cntNode; i++) {
                G[1].push_back(std::make_pair(i, Rand(valFrom, valTo)));
                cntEdge++;
            }
        }
        void wheelGraph()
        {
            for (int i = 2; i <= cntNode; i++) {
                G[1].push_back(std::make_pair(i, Rand(valFrom, valTo)));
                cntEdge++;
            }
            for (int i = 2; i < cntNode; i++) {
                G[i].push_back(std::make_pair(i + 1, Rand(valFrom, valTo)));
                cntEdge++;
            }
            cntEdge++;
            G[cntNode].push_back(std::make_pair(2, Rand(valFrom, valTo)));
        }
        void chainGraph()
        {
            for (int i = 1; i < cntNode; i++) {
                G[i].push_back(std::make_pair(i + 1, Rand(valFrom, valTo)));
                cntEdge++;
            }
        }
        // Part 3:generate functions with arguments
        void cactusGraph(std::initializer_list<long long> Arguments);
        void desertGraph(std::initializer_list<long long> Arguments);
        void bipartiteCompleteGraph(std::initializer_list<long long> Arguments);
        void gridGraph(std::initializer_list<long long> Arguments);
        void normalGraph(Rules rules, std::initializer_list<long long> Arguments);

    public:
        void randgraph(Rules&& rules)
        {
            if (rules.size() > 1) {
                throw std::invalid_argument("Too many arguments!");
            }
            if (rules[0] == "Complete") {
                completeGraph();
            } else if (rules[0] == "Empty") {
                emptyGraph();
            } else if (rules[0] == "Tour") {
                tourGraph();
            } else if (rules[0] == "Cycle") {
                cycleGraph();
            } else if (rules[0] == "Star") {
                starGraph();
            } else if (rules[0] == "Wheel") {
                wheelGraph();
            } else if (rules[0] == "Chain") {
                chainGraph();
            } else {
                throw std::invalid_argument("Invalid argument:" + rules[0]);
            }
        }
        void randgraph(const Rules&& rules, std::initializer_list<long long>&& Arguments)
        {
        }
    };
}
}
#endif