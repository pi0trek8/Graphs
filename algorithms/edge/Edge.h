#ifndef GRAPH_ALGORITHMS_EDGE_H
#define GRAPH_ALGORITHMS_EDGE_H


class Edge {
public:
    int start;
    int end;
    int weight;

    Edge();

    explicit Edge(int start, int anEnd, int weight);

    bool operator==(const Edge &item) const;

    bool operator!=(const Edge &item);

    bool operator<(const Edge &item) const;

    bool operator<=(const Edge &item) const;

    bool operator>(const Edge &item) const;

    bool operator>=(const Edge &item) const;
};


#endif //GRAPH_ALGORITHMS_EDGE_H
