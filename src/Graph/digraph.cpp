#include "../../include/Graph/digraph.h"

using namespace cdg;

Digraph::Digraph(const Digraph& g)
    : Graph(g)
{
    countEdge = g.countEdge;
    countNode = g.countNode;
    G = g.G;
}

Digraph::Digraph(const Graph& g)
{
}

Digraph::Digraph(const std::vector<int>*& g)
{
    int size = static_cast<int>(sizeof(&g));
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(std::make_pair(it, 1));
            G[it].insert(std::make_pair(i, 1));
            countEdge++;
        }
    }
}

Digraph::Digraph(const std::vector<std::vector<int>>& g)
{
    int size = static_cast<int>(g.size());
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(std::make_pair(it, 1));
            G[it].insert(std::make_pair(i, 1));
            countEdge++;
        }
    }
}
Digraph::Digraph(const std::vector<std::pair<int, int>>*& g)
{
    int size = static_cast<int>(sizeof(&g));
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(it);
            G[it.first].insert(std::make_pair(i, it.second));
            countNode++;
        }
    }
}
Digraph::Digraph(const std::vector<std::vector<std::pair<int, int>>>& g)
{
    int size = static_cast<int>(g.size());
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(it);
            G[it.first].insert(std::make_pair(i, it.second));
            countNode++;
        }
    }
}

Digraph::Digraph(const std::map<int, std::set<int>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            G[from.first].insert(std::make_pair(to, 1));
            G[to].insert(std::make_pair(from.first, 1));
            countEdge++;
        }
    }
}

Digraph::Digraph(const std::map<int, std::map<int, int>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            // For program safety
            auto p = static_cast<std::pair<int, long long>>(to);
            G[from.first].insert(p);
            G[p.first].insert(std::make_pair(from.first, p.second));
            countEdge++;
        }
    }
}

Digraph::Digraph(const std::map<int, std::map<int, long long>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            G[from.first].insert(to);
            G[to.first].insert(std::make_pair(from.first, to.second));
            countEdge++;
        }
    }
}

// Not finished(No countNode)
Digraph::Digraph(const Edge*& edges)
{
    int size = static_cast<int>(sizeof(&edges));
    countEdge = size;
    for (int i = 0; i < size; i++) {
        G[edges[i].from].insert(std::make_pair(edges[i].to, edges[i].value));
    }
}

Digraph::Digraph(const std::vector<Edge>& edges)
{
    for (auto it : edges) {
        G[it.from].insert(std::make_pair(it.to, it.value));
    }
}

// Generate function
void Digraph::generate(const Digraph& g)
{
    countEdge = g.countedge();
    countNode = g.countnode();
    G = g.returnG();
}

void Digraph::generate(const Graph& g)
{
    generate(Digraph(g));
}
