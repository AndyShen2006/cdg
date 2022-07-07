#include "../../include/Graph/graph.h"

using namespace cdg;

// For Class Edge

Edge::Edge(int f, int t)
{
    from = f, to = t, value = 1;
}

Edge::Edge(int f, int t, int v)
{
    from = f, to = t, value = v;
}

Edge::Edge(int f, int t, long long v)
{
    from = f, to = t, value = v;
}

// For Class Graph

// Construct functions
Graph::Graph(const Graph& g)
{
    countEdge = g.countEdge;
    countNode = g.countNode;
    G = g.G;
}
Graph::Graph(const std::vector<int>*& g)
{
    int size = static_cast<int>(sizeof(&g));
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(std::make_pair(it, 1));
            countEdge++;
        }
    }
}

Graph::Graph(const std::vector<std::vector<int>>& g)
{
    int size = static_cast<int>(g.size());
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(std::make_pair(it, 1));
            countEdge++;
        }
    }
}
Graph::Graph(const std::vector<std::pair<int, int>>*& g)
{
    int size = static_cast<int>(sizeof(&g));
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(it);
            countNode++;
        }
    }
}
Graph::Graph(const std::vector<std::vector<std::pair<int, int>>>& g)
{
    int size = static_cast<int>(g.size());
    countNode = size;
    for (int i = 0; i < size; i++) {
        for (const auto& it : g[i]) {
            G[i].insert(it);
            countNode++;
        }
    }
}

Graph::Graph(const std::map<int, std::set<int>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            G[from.first].insert(std::make_pair(to, 1));
            countEdge++;
        }
    }
}

Graph::Graph(const std::map<int, std::map<int, int>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            // For program safety
            auto p = static_cast<std::pair<int, long long>>(to);
            G[from.first].insert(p);
            countEdge++;
        }
    }
}

Graph::Graph(const std::map<int, std::map<int, long long>>& g)
{
    for (const auto& from : g) {
        countNode++;
        for (auto to : from.second) {
            G[from.first].insert(to);
            countEdge++;
        }
    }
}

// Not finished(No countNode)
Graph::Graph(const Edge*& edges)
{
    int size = static_cast<int>(sizeof(&edges));
    countEdge = size;
    for (int i = 0; i < size; i++) {
        G[edges[i].from].insert(std::make_pair(edges[i].to, edges[i].value));
    }
}

Graph::Graph(const std::vector<Edge>& edges)
{
    for (auto it : edges) {
        G[it.from].insert(std::make_pair(it.to, it.value));
    }
}

// Generate function
void Graph::generate(const Graph& g)
{
    countEdge = g.countEdge;
    countNode = g.countNode;
    G = g.G;
}
// Display function
void Graph::showGraph(Rules rule)
{
    int hasValue = 0; // Unknown(With-value is default)->0; With_value->1; Without_value->2
    for (const auto& it : rule) {
        if (it == "With_value" && hasValue == 0) {
            hasValue = 1;
        } else if (it == "Without_value" && hasValue == 0) {
            hasValue = 2;
        } else {
            throw std::invalid_argument("Invalid rule:" + it);
        }
    }
    if (hasValue == 0 || hasValue == 1) {
        for (const auto& from : G) {
            std::cout << from.first << ' ';
            for (const auto& to : from.second) {
                std::cout << to.first << ' ' << to.second << std::endl;
            }
        }
    } else {
        for (const auto& from : G) {
            std::cout << from.first << ' ';
            for (const auto& to : from.second) {
                std::cout << to.first << std::endl;
            }
        }
    }
}

// Basic information
unsigned Graph::countedge() const
{
    return countEdge;
}
unsigned Graph::countnode() const
{
    return countNode;
}
std::map<int, std::map<int, long long>> Graph::returnG() const
{
    return G;
}
// Change graph methods
void Graph::addedge(Edge e)
{
    G[e.from].insert(std::make_pair(e.to, e.value));
}
void Graph::addedge(int from, int to)
{
    G[from].insert(std::make_pair(to, 1));
}
void Graph::addedge(int from, int to, int value)
{
    G[from].insert(std::make_pair(to, value));
}
