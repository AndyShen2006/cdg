#include "../basic_lib.h"
#include "../ext_random.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#ifndef _GRAPH_H
#define _GRAPH_H
namespace cdg {
class Edge {
public:
    Edge() = default;
    explicit Edge(int f, int t);
    explicit Edge(int f, int t, int v);
    explicit Edge(int f, int t, long long v);
    // Display function
    void showEdge();
    // Basic informations
    int from, to;
    long long value;
    // Change edge methods
    void reverse();
};

class Graph {
public:
    // Construct functions
    Graph() = default;
    Graph(const Graph& g);
    explicit Graph(const std::vector<int>*& g);
    explicit Graph(const std::vector<std::vector<int>>& g);
    explicit Graph(const std::vector<std::pair<int, int>>*& g);
    explicit Graph(const std::vector<std::vector<std::pair<int, int>>>& g);
    explicit Graph(const std::map<int, std::set<int>>& g);
    explicit Graph(const std::map<int, std::map<int, int>>& g);
    explicit Graph(const std::map<int, std::map<int, long long>>& g);
    explicit Graph(const Edge*& edges);
    explicit Graph(const std::vector<Edge>& edges);

    // Generate functions
    virtual void generate(const Graph& g);

    virtual void randgraph(int countV, int countE, Rules rules);

    // Display function
    void showGraph(Rules rule);

    // Basic informations
    unsigned countedge() const;
    unsigned countnode() const;
    std::map<int, std::map<int, long long>> returnG() const;

    // Change graph methods
    virtual void addedge(Edge e);
    virtual void addedge(int from, int to);
    virtual void addedge(int from, int to, int value);

protected:
    unsigned countEdge = 0, countNode = 0;
    std::map<int, std::map<int, long long>> G;
    std::vector<Edge> repeatE;
    Rules rules;
};
}

#endif