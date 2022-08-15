#include "../ext_random.hpp"
#include "../information.hpp"
#include <vector>
#ifndef _TREE_H
#define _TREE_H
namespace cdg {
namespace Graph {
    template <typename val_type, typename randRule>
    class Tree {
    public:
        typedef val_type valType;
        randRule Rand;
        explicit Tree(const int& n)
        {
            cntNode = n;
            ufs.init(n);
            for (int i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
                for (int j = 0; j <= n; j++) {
                    T[i].emplace_back(std::move(EmptyElement));
                }
            }
        }
        Tree(const int& n, const int& r)
        {
            cntNode = n;
            ufs.init(n);
            for (int i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
                for (int j = 0; j <= n; j++) {
                    T[i].emplace_back(std::move(EmptyElement));
                }
            }
            root = r;
        }
        Tree(const int& n, const valType& vf, const valType& vt)
        {
            cntNode = n;
            ufs.init(n);
            for (int i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
                for (int j = 0; j <= n; j++) {
                    T[i].emplace_back(std::move(EmptyElement));
                }
            }
            valFrom = vf;
            valTo = vt;
            hasValue = true;
        }
        Tree(const int& n, const int& r, const valType& vf, const valType& vt)
        {
            cntNode = n;
            ufs.init(n);
            for (int i = 0; i <= n; i++) {
                T.emplace_back(std::move(EmptyVector));
                for (int j = 0; j <= n; j++) {
                    T[i].emplace_back(std::move(EmptyElement));
                }
            }
            root = r;
            valFrom = vf;
            valTo = vt;
            hasValue = true;
        }
        void showTree(Rules& rules)
        {
            if (hasValue) {
                if (rules.size() > 1) {
                    throw std::invalid_argument("Too many arguments!");
                }
                if (rules[0] == "Adjacency") {
                    for (int i = 1; i < T.size(); i++) {
                        std::cout << i << ' ';
                        for (const auto& it : T[i]) {
                            std::cout << it.first << ' ' << it.second << ' ';
                        }
                        std::cout << std::endl;
                    }
                } else if (rules[0] == "Edge") {
                    for (int i = 1; i < T.size(); i++) {
                        for (const auto& it : T[i]) {
                            std::cout << i << ' ' << it.first << ' ' << it.second << std::endl;
                        }
                    }
                }
            } else {
                if (rules.size() > 1) {
                    throw std::invalid_argument("Too many arguments!");
                }
                if (rules[0] == "Adjacency") {
                    for (int i = 1; i < T.size(); i++) {
                        std::cout << i << ' ';
                        for (const auto& it : T[i]) {
                            std::cout << it.first << ' ';
                        }
                        std::cout << std::endl;
                    }
                } else if (rules[0] == "Edge") {
                    for (int i = 1; i < T.size(); i++) {
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
            for (int i = 1; i <= cntNode - 1; i++) {
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

    private:
        int root = 1;
        int cntNode;
        bool hasValue = false;
        valType valFrom, valTo;
        std::vector<std::vector<std::pair<int, valType>>> T;
        const std::vector<std::pair<int, valType>> EmptyVector;
        const std::pair<int, valType> EmptyElement;
        UFS ufs;
    };
}
}

#endif