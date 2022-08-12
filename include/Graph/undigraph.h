#include "../../include/ext_random.h"
#include <algorithm>

#ifndef _UNDIGRAPH_H
#define _UNDIGRAPH_H
namespace cdg {
namespace Graph {
    template <typename val_type = int, const bool is_shuffle = false>
    class Undigraph {
    public:
        typedef val_type valType;
        explicit Undigraph(const int& n);
        Undigraph(const int& n, const valType& vf, const valType& vt);
        void showGraph();
        void randgraph(Rules rules);
        void randgraph(Rules rules, std::initializer_list<long long>);

    private:
        std::vector<std::vector<std::pair<int, valType>>> G;
        std::vector<int> mapping;
        std::vector<std::pair<int, valType>> Empty_Vector;
        int cntEdge = 0, cntNode = 0;
        bool hasValue = false;
        valType valFrom = 0, valTo = 10000; // If hasValue is true, this option will be enabled.
        bool isShuffle = is_shuffle;
        // Part 1: generate rand edge
        void randedge(int V);
        // Part 2:generate functions without arguments
        void emptyGraph();
        void completeGraph();
        void tourGraph();
        void cycleGraph();
        void starGraph();
        void wheelGraph();
        void chainGraph();
        // Part 3:generate functions with arguments
        void pseudoGraph(std::initializer_list<long long> Arguments);
        void cactusGraph(std::initializer_list<long long> Arguments);
        void desertGraph(std::initializer_list<long long> Arguments);
        void bipartiteCompleteGraph(std::initializer_list<long long> Arguments);
        void gridGraph(std::initializer_list<long long> Arguments);
        void normalGraph(Rules rules, std::initializer_list<long long> Arguments);
        void forest(std::initializer_list<long long> Arguments);
    };
}
}
#endif