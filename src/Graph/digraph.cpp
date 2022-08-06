#include "../../include/Graph/digraph.h"

cdg::Digraph::Digraph(const int& n)
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

cdg::Digraph::Digraph(const int& n, const bool& is_shuffle)
{
    isShuffle = is_shuffle;
    cntNode = n;
    for (int i = 0; i <= n; i++) {
        G.emplace_back(Empty_Vector);
    }
    for (int i = 0; i <= n; i++) {
        mapping.emplace_back(i);
    }
    std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
}

cdg::Digraph::Digraph(const int& n, const bool& is_shuffle, const int& vf, const int& vt)
{
    isShuffle = is_shuffle;
    hasValue = true;
    cntNode = n;
    valfrom = vf;
    valto = vt;
    for (int i = 0; i <= n; i++) {
        G.emplace_back(Empty_Vector);
    }
    for (int i = 0; i <= n; i++) {
        mapping.emplace_back(i);
    }
    std::shuffle(mapping.begin() + 1, mapping.end(), rand_eng);
}
void cdg::Digraph::showGraph()
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

void cdg::Digraph::emptyGraph()
{
}
void cdg::Digraph::completeGraph()
{
    for (int i = 1; i < cntNode; i++) {
        for (int j = i + 1; j <= cntNode; j++) {
            if (hasValue) {
                G[i].push_back(std::make_pair(j, randint(valfrom, valto)));
            } else {
                G[i].push_back(std::make_pair(j, 1));
            }
            cntEdge++;
        }
    }
}
void cdg::Digraph::tourGraph()
{
}
void cdg::Digraph::cycleGraph()
{
    for (int i = 1; i < cntNode; i++) {
        G[i].push_back(std::make_pair(i + 1, randint(valfrom, valto)));
    }
    G[cntNode].push_back(std::make_pair(1, randint(valfrom, valto)));
}
void cdg::Digraph::starGraph()
{
}
void cdg::Digraph::wheelGraph()
{
}
void cdg::Digraph::chainGraph()
{
}
void cdg::Digraph::pseudoGraph()
{
}
void cdg::Digraph::cactusGraph()
{
}
void cdg::Digraph::desertGraph()
{
}
void cdg::Digraph::bipartiteGraph()
{
}
void cdg::Digraph::gridGraph()
{
}

void cdg::Digraph::randgraph(Rules rules)
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
    } else if (rules[0] == "Tree") {
        ;
    } else if (rules[0] == "Pseudo") {
        pseudoGraph();
    } else if (rules[0] == "Cactus") {
        cactusGraph();
    } else if (rules[0] == "Desert") {
        desertGraph();
    } else if (rules[0] == "Bipartite") {
        bipartiteGraph();
    } else if (rules[0] == "Grid") {
        gridGraph();
    } else {
        throw std::invalid_argument("Invalid argument:" + rules[0]);
    }
}
