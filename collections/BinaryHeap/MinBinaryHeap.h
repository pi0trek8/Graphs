//
// Created by Piotr Szczypior on 18/05/2023.
//

#ifndef GRAPH_ALGORITHMS_MINBINARYHEAP_H
#define GRAPH_ALGORITHMS_MINBINARYHEAP_H

#include "../Array.h"

template<class T>
class MinBinaryHeap {
private:
    Array<T> _heap;

    void heapify_down(int index);

    void heapify_up(int index);

    void print(std::string prefix, int index, bool isLeft);

public:
    MinBinaryHeap();

    void push(T value);

    void pop();

    bool find(T value);

    void print();

    void set(T t, T new_t);

    T get_top();

    bool isEmpty();

    ~MinBinaryHeap();

    void clear();
};

template<class T>
void MinBinaryHeap<T>::set(T t, T new_t) {
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
void MinBinaryHeap<T>::clear() {
    this->_heap.clear();
}

template<class T>
T MinBinaryHeap<T>::get_top() {
    return _heap.get(0);
}

template<class T>
bool MinBinaryHeap<T>::isEmpty() {
    return _heap.get_size() == 0;
}

template<class T>
void MinBinaryHeap<T>::heapify_down(int index) {
    // assigning indexes based on the input
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;

    // assuming that the current node is the largest
    int smallest = index;

    // check if the right child is larger than the current node
    if (right_child_index < _heap.get_size() && _heap.get(right_child_index) < _heap.get(smallest)) {
        smallest = right_child_index;
    }

    // check if the left child is larger than the current node (or the right child, if it was larger)
    if (left_child_index < _heap.get_size() && _heap.get(left_child_index) < _heap.get(smallest)) {
        smallest = left_child_index;
    }

    // if given index was not largest. Swap values and heapify down once more.
    if (smallest != index) {
        _heap.swap(index, smallest);
        heapify_down(smallest);
    }
}

template<class T>
void MinBinaryHeap<T>::heapify_up(int index) {
    // calculate index of parent
    int parent_index = (index - 1) / 2;

    // check if index is larger than 0 and if value of index position is grater than value of parent's position.
    if (index && _heap.get(index) < _heap.get(parent_index)) {
        // swap values and heapify up
        _heap.swap(parent_index, index);
        heapify_up(parent_index);
    }
}

template<class T>
void MinBinaryHeap<T>::pop() {
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
void MinBinaryHeap<T>::push(T value) {
    // add new value to array
    _heap.push_back(value);
    // check whether everything sticks to maximum heap characteristics
    heapify_up(_heap.get_size() - 1);
}

template<class T>
void MinBinaryHeap<T>::print() {
    // invoke print helper
    print("", 0, false);
}

template<class T>
void MinBinaryHeap<T>::print(std::string prefix, int index, bool isLeft) {
    if (index < _heap.get_size()) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "|__");
        cout << _heap.get(index).vertex << " " << _heap.get(index).property << endl;

        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 1, true);
        print(prefix + (isLeft ? "|   " : "    "), 2 * index + 2, false);

    }
}

template<class T>
bool MinBinaryHeap<T>::find(T value) {
    // searching heap in order to find value
    // based on DRY principle the code would
    // be the same as in the array
    // because the solution is to simply iterate
    // throughout array
    return _heap.find(value);
}

template<class T>
MinBinaryHeap<T>::~MinBinaryHeap() = default;

template<class T>
MinBinaryHeap<T>::MinBinaryHeap() = default;



#endif //GRAPH_ALGORITHMS_MINBINARYHEAP_H
