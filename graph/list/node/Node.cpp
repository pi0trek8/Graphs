#include "Node.h"

Node::Node() {
    this->vertex = 0;
    this->weight = 0;
}

Node::Node(int end_vertex, int edge_weight) {
    this->vertex = end_vertex;
    this->weight = edge_weight;
}

bool Node::operator==(Node &node) const {
    return this->vertex == node.vertex && this->weight == node.weight;
}

bool Node::operator<(Node &node) const {
    return this->weight < node.weight;
}

bool Node::operator>(const Node &node) const {
    return this->weight > node.weight;
}

bool Node::operator<=(Node &node) const {
    return this->weight <= node.weight;
}

bool Node::operator>=(Node &node) const {
    return this->weight >= node.weight;
}

int Node::operator+(const int &value) const {
    return (this->weight + value);
}

Node::operator int() const {
    return this->vertex;
}

Node::operator int() {
    return this->vertex;
}

int Node::operator+(const int &value) {
    return (this->weight + value);
}

bool Node::operator>(const int &value) const {
    return this->weight > value;
}

bool Node::operator==(int v) const {
    return this->vertex == v;
}

Node& Node::operator=(const Node& other) = default;

Node::~Node() = default;
