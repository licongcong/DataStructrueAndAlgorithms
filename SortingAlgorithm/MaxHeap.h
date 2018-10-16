//
// Created by Li Congcong on 2018/10/16.
//

#ifndef SORTINGALGORITHM_MAXHEAP_H
#define SORTINGALGORITHM_MAXHEAP_H

template <typename T>
class MaxHeap {
public:
    MaxHeap(int capacity) :m_capacity(capacity) {	// 创建一个空堆
        m_data = new T[m_capacity + 1];	// 从下标为 1 开始存储
        m_count = 0;
    }

    void insert(T item);	// 向堆中插入一个元素
    T get();				// 取出堆顶元素
    T remove();				// 删除堆顶元素

    int capacity() {
        return m_capacity;
    }

    int count() {
        return m_count;
    }

    ~MaxHeap() {
        delete[] m_data;
    }
private:
    void t_shiftUp(int index);	// 将 m_data[index] 向上调整
    void t_shiftDown(int index);	// 将 m_data[index] 向下调整
private:
    T* m_data;		//	堆中数据
    int m_capacity;	//	当前堆容量
    int m_count;	//	当前堆中元素个数
};

template <typename T>
void MaxHeap<T>::t_shiftDown(int index) {

    int leftChild, rightChild, largerChild;

    while(2 * index <= m_count) {
        leftChild = 2 * index;
        rightChild = 2 * index + 1;
        largerChild = index;

        if (m_data[leftChild] > m_data[largerChild]) {	// 判断当前元素是否比其左儿子小
            largerChild = leftChild;
        }

        if (rightChild <= m_count && m_data[rightChild] > m_data[largerChild]) {	// 判断当前元素是否比其右儿子小
            largerChild = rightChild;
        }

        if (largerChild == index) {		// 当前元素比其儿子结点都大时，结束调整
            break;
        }

        swap(m_data[largerChild], m_data[index]);	// 将当前元素与其较大的儿子节点交换位置
        index = largerChild;	// 继续调整位置
    }
    return;
}

template <typename T>
T MaxHeap<T>::remove() {
    assert(m_count > 0);

    T ret = get();
    swap(m_data[m_count], m_data[1]);
    // m_data[1] = m_data[m_count];	// 将堆尾元素放到堆顶中
    -- m_count;	// 调整堆中元素个数

    t_shiftDown(1);	// 调整堆顶元素位置
    return ret;

}

template <typename T>
T MaxHeap<T>::get() {

    assert(m_count >= 1);
    return m_data[1];

}

template <typename T>
void MaxHeap<T>::insert(T item) {
    assert(m_count < m_capacity);

    ++m_count;	// 插入位置
    m_data[m_count] = item;	//插入元素

    t_shiftUp(m_count);	// 向上调整该元素
    return;
}

template <typename T>
void MaxHeap<T>::t_shiftUp(int index) {

    int parent = index / 2;

    while (parent > 0 && m_data[parent] < m_data[index]) {	// 若当前元素的父节点的值小于当前元素，则交换
        swap(m_data[parent], m_data[index]);
        index = parent;
        parent /= 2;
    }
    return;
}
#endif //SORTINGALGORITHM_MAXHEAP_H
