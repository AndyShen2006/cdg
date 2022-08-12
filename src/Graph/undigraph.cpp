#include "../../include/Graph/undigraph.h"
template <typename val_type, const bool is_shuffle>
cdg::Graph::Undigraph<val_type, is_shuffle>::Undigraph(const int& n)
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

template <typename val_type, const bool is_shuffle>
cdg::Graph::Undigraph<val_type, is_shuffle>::Undigraph(const int& n, const valType& vf, const valType& vt)
{
    hasValue = true;
    cntNode = n;
    valFrom = vf;
    valTo = vt;
    for (int i = 0; i <= n; i++) {
        G.emplace_back(Empty_Vector);
    }
    for (int i = 0; i <= n; i++) {
        mapping.emplace_back(i);
    }
    std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::showGraph()
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

template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::emptyGraph()
{
    // An empty Graph needn't have edges
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::completeGraph()
{
    for (int i = 1; i < cntNode; i++) {
        for (int j = i + 1; j <= cntNode; j++) {
            if (hasValue) {
                G[i].push_back(std::make_pair(j, randint(valFrom, valTo)));
            } else {
                G[i].push_back(std::make_pair(j, 1));
            }
            cntEdge++;
        }
    }
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::tourGraph()
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::cycleGraph()
{
    for (int i = 1; i < cntNode; i++) {
        G[i].push_back(std::make_pair(i + 1, randint(valFrom, valTo)));
        cntEdge++;
    }
    cntEdge++;
    G[cntNode].push_back(std::make_pair(1, randint(valFrom, valTo)));
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::starGraph()
{
    for (int i = 2; i <= cntNode; i++) {
        G[1].push_back(std::make_pair(i, randint(valFrom, valTo)));
        cntEdge++;
    }
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::wheelGraph()
{
    for (int i = 2; i <= cntNode; i++) {
        G[1].push_back(std::make_pair(i, randint(valFrom, valTo)));
        cntEdge++;
    }
    for (int i = 2; i < cntNode; i++) {
        G[i].push_back(std::make_pair(i + 1, randint(valFrom, valTo)));
        cntEdge++;
    }
    cntEdge++;
    G[cntNode].push_back(std::make_pair(2, randint(valFrom, valTo)));
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::chainGraph()
{
    for (int i = 1; i < cntNode; i++) {
        G[i].push_back(std::make_pair(i + 1, randint(valFrom, valTo)));
        cntEdge++;
    }
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::randgraph(Rules rules)
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
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::pseudoGraph(std::initializer_list<long long> Arguments)
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::cactusGraph(std::initializer_list<long long> Arguments)
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::desertGraph(std::initializer_list<long long> Arguments)
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::bipartiteCompleteGraph(std::initializer_list<long long> Arguments)
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::gridGraph(std::initializer_list<long long> Arguments)
{
}
template <typename val_type, const bool is_shuffle>
void cdg::Graph::Undigraph<val_type, is_shuffle>::randgraph(cdg::Rules rules, std::initializer_list<long long> Arguments)
{
}
