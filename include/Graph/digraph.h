#include "graph.h"

namespace cdg {
class Digraph : Graph {
public:
    Digraph() = default;
    Digraph(const Digraph& g);
    explicit Digraph(const Graph& g);
    explicit Digraph(const std::vector<int>*& g);
    explicit Digraph(const std::vector<std::vector<int>>& g);
    explicit Digraph(const std::vector<std::pair<int, int>>*& g);
    explicit Digraph(const std::vector<std::vector<std::pair<int, int>>>& g);
    explicit Digraph(const std::map<int, std::set<int>>& g);
    explicit Digraph(const std::map<int, std::map<int, int>>& g);
    explicit Digraph(const std::map<int, std::map<int, long long>>& g);
    explicit Digraph(const Edge*& edges);
    explicit Digraph(const std::vector<Edge>& edges);
    void generate(const Graph& g) override;
    void generate(const Digraph& g);
};
}