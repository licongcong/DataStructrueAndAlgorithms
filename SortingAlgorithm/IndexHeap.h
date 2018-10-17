//
// Created by Li Congcong on 2018/10/17.
//

#ifndef SORTINGALGORITHM_INDEXHEAP_H
#define SORTINGALGORITHM_INDEXHEAP_H

template <typename T>
class IndexHeap {
public:
    IndexHeap(int capacity): m_capacity(capacity) {
        m_data = new T[capacity + 1];
        m_index = new int[capacity + 1];
        m_count = 0;
    }
    IndexHeap(T arr[], int size) : m_capacity(size) {
        m_data = new T[size + 1];
        m_index = new int[size + 1];
        m_count = size;
        for (int i = 1; i <= size; i++) {
            m_data[i] = arr[i - 1];
            m_index[i] = i;
        }
        heapify();
    }

    void heapify();		// 将数组调整为最大索引堆
    void insert(T item);	// 向最大索引堆中插入一个元素
    T getMax();			// 取出最大索引堆中的最大元素
    T get(int index);	// 查看索引为 index 的元素
    void update(int index, T item);	// 修改索引为 index 的元素的值
    void remove(); 			// 删除堆中最大的元素

    ~IndexHeap() {
        delete[] m_data;
        delete[] m_index;
    }
private:
    void t_shiftDown(int index);		// 将堆中元素向上调整
    void t_shiftUp(int index);		// 将堆中元素向下调整
private:
    T* m_data;
    int* m_index;
    int m_capacity;
    int m_count;
};

template <typename T>
void IndexHeap<T>::heapify() {		// 将数组调整为最大索引堆
    int lastNonLeaf = m_count / 2;

    for (int i = lastNonLeaf; i > 0; i--) {
        t_shiftDown(m_index[i]);
    }
}

template <typename T>
void IndexHeap<T>::insert(T item) {	// 向最大索引堆中插入一个元素
    assert(m_count < m_capacity);

    m_count++;
    m_index[m_count] = m_index[m_count - 1] + 1;
    m_data[m_count] = item;

    t_shiftUp(m_count);
    return;

}

template <typename T>
void IndexHeap<T>:: remove() { // 删除堆中最大的元素
    assert( m_count > 0 );

    swap( indexes[1] , indexes[m_count] );
    m_count--;
    shiftDown(1);

    return;
}

template <typename T>
T IndexHeap<T>::getMax() {			// 取出最大索引堆中的最大元素
    return m_data[m_index[1]];
}

template <typename T>
T IndexHeap<T>::get(int index) {	// 查看索引为 index 的元素
    return m_data[index];
}

template <typename T>
void IndexHeap<T>::t_shiftDown(int index) {		// 将堆中元素向下调整

    int largerChild, leftChild, rightChild;
    while (2 * index <= m_count)
    {
        largerChild = index;
        leftChild = 2 * index;
        rightChild = 2 * index + 1;

        if (m_data[m_index[leftChild]] > m_data[m_index[largerChild]]) {
            largerChild = leftChild;
        }

        if (rightChild <= m_count && m_data[m_index[rightChild]] > m_data[m_index[largerChild]]) {
            largerChild = rightChild;
        }

        if (largerChild == index) {
            break;
        }
        swap(m_index[largerChild], m_index[index]);
        index = largerChild;
    }
    return;
}

template <typename T>
void IndexHeap<T>::t_shiftUp(int index) {		// 将堆中元素向上调整

    int parent = index / 2;

    while (index > 1 && m_data[m_index[parent]] < m_data[m_index[index]]) {
        swap(m_index[parent], m_index[index]);
        index = parent;
        parent = index / 2;
    }
    return;
}
#endif //SORTINGALGORITHM_INDEXHEAP_H
