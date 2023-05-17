#include "Edge.h"

Edge::Edge(int start, int end, int weight) {
    this->weight = weight;
    this->end = end;
    this->start = start;
}

bool Edge::operator==(const Edge &item) const {
    return (this->start == item.start && this->end == item.end &&
    this->weight == item.weight) || (this->start == item.end &&
    this->end == item.start && this->weight == item.weight);
}

bool Edge::operator!=(const Edge &item) {
    return !this->operator==(item);
}

bool Edge::operator<(const Edge &item) const {
    return this->weight < item.weight;
}

bool Edge::operator<=(const Edge &item) const {
    return this->weight <= item.weight;
}

bool Edge::operator>(const Edge &item) const {
    return this->weight > item.weight;;
}

bool Edge::operator>=(const Edge &item) const {
    return this->weight >= item.weight;;
}

Edge::Edge() = default;
