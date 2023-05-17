//
// Created by Piotr Szczypior on 13/05/2023.
//

#ifndef GRAPH_ALGORITHMS_PRIORITYQUEUENODE_H
#define GRAPH_ALGORITHMS_PRIORITYQUEUENODE_H


class PriorityQueueNode {
public:
    int vertex;
    int property;

    bool operator>(PriorityQueueNode const &node) const;

    bool operator==(PriorityQueueNode const &node) const;

    bool operator<(PriorityQueueNode const &node) const;

    bool operator<=(PriorityQueueNode const &node) const;

    bool operator>=(PriorityQueueNode const &node) const;


    bool operator>(int const &value) const;

    bool operator==(int const &value) const;

    bool operator<(int const &value) const;

    bool operator<=(int const &value) const;

    bool operator>=(int const &value) const;

    PriorityQueueNode();

    explicit PriorityQueueNode(int vertex, int property);

    virtual ~PriorityQueueNode();
};


#endif //GRAPH_ALGORITHMS_PRIORITYQUEUENODE_H
