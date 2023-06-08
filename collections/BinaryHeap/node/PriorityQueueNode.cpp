//
// Created by Piotr Szczypior on 13/05/2023.
//

#include "PriorityQueueNode.h"

PriorityQueueNode::PriorityQueueNode() {
    this->vertex = 0;
    this->property = 0;
}

PriorityQueueNode::PriorityQueueNode(int vertex, int property) {
    this->vertex = vertex;
    this->property = property;
}

bool PriorityQueueNode::operator>(PriorityQueueNode const &node) const {
    return this->property > node.property;
}

bool PriorityQueueNode::operator==(PriorityQueueNode const &node) const {
    return this->vertex == node.vertex;
}

bool PriorityQueueNode::operator<(PriorityQueueNode const &node) const {
    return this->property < node.property;
}

bool PriorityQueueNode::operator<=(PriorityQueueNode const &node) const {
    return this->property <= node.property;
}

bool PriorityQueueNode::operator>=(PriorityQueueNode const &node) const {
    return this->property >= node.property;
}

bool PriorityQueueNode::operator>(const int &value) const {
    return this->property > value;
}

bool PriorityQueueNode::operator<(const int &value) const {
    return this->property < value;
}

bool PriorityQueueNode::operator<=(const int &value) const {
    return this->property <= value;;
}

bool PriorityQueueNode::operator>=(const int &value) const {
    return this->property >= value;;
}

PriorityQueueNode::~PriorityQueueNode() = default;



