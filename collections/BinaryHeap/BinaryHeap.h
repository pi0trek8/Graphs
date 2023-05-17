//
// Created by Piotr Szczypior on 07.03.2023.
//

#ifndef LIST_BINARYHEAP_H
#define LIST_BINARYHEAP_H

#include <iostream>
#include <algorithm>
#include "../Array.h"

using namespace std;

template<class T>
class BinaryHeap {
private:
    Array<T> _heap;

    void heapify_down(int index);

    void heapify_up(int index);

    void print(std::string prefix, int index, bool isLeft);

public:
    BinaryHeap();

    void push(T value);

    void pop();

    bool find(T value);

    void print();

    void set(T t, T new_t);

    T get_top();

    bool isEmpty();

    std::string get_name();

    ~BinaryHeap();

    void clear();
};

template<class T>
void BinaryHeap<T>::set(T t, T new_t) {
    for (int i = 0; i < _heap.get_size(); i++) {
        if (_heap[i] == t) {
            _heap[i] = new_t;

            if (i == 0) {
                heapify_down(i);
                return;
            }
            T parent = _heap[(i - 1) / 2];
            if (_heap[i] < parent) {
                heapify_up(i);
            } else {
                heapify_down(i);
            }
            return;
        }
    }
}

template<class T>
void BinaryHeap<T>::clear() {
    this->_heap.clear();
}

template<class T>
T BinaryHeap<T>::get_top() {
    return _heap.get(0);
}

template<class T>
bool BinaryHeap<T>::isEmpty() {
    return _heap.get_size() == 0;
}

template<class T>
void BinaryHeap<T>::heapify_down(int index) {
    // assigning indexes based on the input
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    // assuming that the current node is the largest
    int largest = index;

    // check if the right child is larger than the current node
    if (right_child_index < _heap.get_size() && _heap.get(right_child_index) > _heap.get(largest)) {
        largest = right_child_index;
    }

    // check if the left child is larger than the current node (or the right child, if it was larger)
    if (left_child_index < _heap.get_size() && _heap.get(left_child_index) > _heap.get(largest)) {
        largest = left_child_index;
    }

    // if given index was not largest. Swap values and heapify down once more.
    if (largest != index) {
        _heap.swap(index, largest);
        heapify_down(largest);
    }
}

template<class T>
void BinaryHeap<T>::heapify_up(int index) {
    // calculate index of parent
    int parent_index = (index - 1) / 2;

    // check if index is larger than 0 and if value of index position is grater than value of parent's position.
    if (index && _heap.get(index) > _heap.get(parent_index)) {
        // swap values and heapify up
        _heap.swap(parent_index, index);
        heapify_up(parent_index);
    }
}

template<class T>
void BinaryHeap<T>::pop() {
    // check if array has been initialized (could be omitted because implemented array
    // already have this type of removing safe check but if this case was met without code below
    // it would print "array is empty" not "heap is empty"
    if (_heap.get_size() == 0) {
        cout << "Heap is empty" << endl;
        return;
    }
    // swap values
    _heap.swap(0, _heap.get_size() - 1);
    // remove last (after swap so in fact root) element
    _heap.pop_back();
    // repair
    heapify_down(0);
}

template<class T>
void BinaryHeap<T>::push(T value) {
    // add new value to array
    _heap.push_back(value);
    // check whether everything sticks to maximum heap characteristics
    heapify_up(_heap.get_size() - 1);
}

template<class T>
void BinaryHeap<T>::print() {
    // invoke print helper
    print("", 0, false);
}

template<class T>
void BinaryHeap<T>::print(std::string prefix, int index, bool isLeft) {
    if (index < _heap.get_size()) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__");
        cout << _heap.get(index).property << endl;

        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 1, true);
        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 2, false);

    }
}

template<class T>
std::string BinaryHeap<T>::get_name() {
    // utils method in order to distinguish
    // structure object without reflection in C++
    return "Binary_Heap";
}

template<class T>
bool BinaryHeap<T>::find(T value) {
    // searching heap in order to find value
    // based on DRY principle the code would
    // be the same as in the array
    // because the solution is to simply iterate
    // throughout array
    return _heap.find(value);
}

template<class T>
BinaryHeap<T>::~BinaryHeap() = default;

template<class T>
BinaryHeap<T>::BinaryHeap() = default;


#endif //LIST_BINARYHEAP_H
