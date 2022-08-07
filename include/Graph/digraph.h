#include "../../include/ext_random.h"
#include <algorithm>

#ifndef _DIGRAPH_H
#define _DIGRAPH_H
namespace cdg {
class Digraph {
public:
    explicit Digraph(const int& n);
    Digraph(const int& n, const bool& is_shuffle);
    Digraph(const int& n, const bool& is_shuffle, const int& vf, const int& vt);
    void showGraph();
    void randgraph(Rules rules);
    void randgraph(int V, Rules rules);

private:
    std::vector<std::vector<std::pair<int, int>>> G;
    std::vector<int> mapping;
    std::vector<std::pair<int, int>> Empty_Vector;
    int cntEdge = 0, cntNode = 0;
    bool hasValue = false;
    int valfrom = 0, valto = 10000; // If hasValue is true, this option will be enabled.
    bool isShuffle = true;
    // Part 1: generate rand edge
    void randedge(int V);
    // Part 2:generate functions for certain edges
    void emptyGraph();
    void completeGraph();
    void tourGraph();
    void cycleGraph();
    void starGraph();
    void wheelGraph();
    void chainGraph();
    void pseudoGraph();
    void cactusGraph();
    void desertGraph();
    void bipartiteCompleteGraph();
    void gridGraph();
    // Part 3:generate functions for uncertain edges
    void normalGraph(int V, Rules rules);
    void forest(int N, int V);
};
}
#endif