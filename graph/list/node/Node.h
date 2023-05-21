
#ifndef GRAPH_ALGORITHMS_NODE_H
#define GRAPH_ALGORITHMS_NODE_H


class Node {
public:
    int vertex;
    int weight;

    Node();

    explicit Node(int end_vertex, int edge_weight);

    ~Node();

    int operator+(int const &value) const;

    int operator+(int const &value);

    Node& operator=(const Node& other);

    explicit operator int() const;

    explicit operator int();

    bool operator==(Node &node) const;

    bool operator==(int v) const;

    bool operator<(Node &node) const;

    bool operator>(const Node &node) const;

    bool operator>(const int &value) const;

    bool operator<=(Node &node) const;

    bool operator>=(Node &node) const;
};


#endif //GRAPH_ALGORITHMS_NODE_H
