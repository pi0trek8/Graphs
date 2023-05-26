#ifndef GRAPH_ALGORITHMS_SORTER_H
#define GRAPH_ALGORITHMS_SORTER_H


template<class T>
class Sorter {
private:
    int partition(T &collection, int left, int right);

    void quick_sort(T &collection, int left, int right);

public:
    void sort(T &collection);
};

template<class T>
int Sorter<T>::partition(T &collection, int left, int right) {
    int pivot = collection[left];
    int l = left, r = right;
    while (true) {
        while (collection[l] < pivot)
            l++;
        while (collection[r] > pivot)
            r--;
        if(l < r) {
            collection.swap(l, r);
            ++l;
            --r;
        } else {
            if(r == right)
                r--;
            return r;
        }
    }
}

template<class T>
void Sorter<T>::quick_sort(T &collection, int left, int right) {
    if (left >= right)
        return;
    auto index = partition(collection, left, right);
    quick_sort(collection, left, index);
    quick_sort(collection, index + 1, right);

}

template<class T>
void Sorter<T>::sort(T &collection) {
    this->quick_sort(collection, 0, collection.get_size() - 1);
}



#endif //GRAPH_ALGORITHMS_SORTER_H
