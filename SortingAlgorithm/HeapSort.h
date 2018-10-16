//
// Created by Li Congcong on 2018/10/16.
//

#ifndef SORTINGALGORITHM_HEAPSORT_H
#define SORTINGALGORITHM_HEAPSORT_H

#include "SortingHelper.h"

// 向下调整
template <typename T>
void shiftDown(T arr[], int index, int size) {		// [index, size] 区间内向下调整

    int leftChild, rightChild, largerChild;

    while(2 * index + 1 <= size) {

        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largerChild = index;

        if (arr[leftChild] > arr[largerChild]) {
            largerChild = leftChild;
        }

        if (arr[rightChild] > arr[largerChild] && rightChild <= size) {
            largerChild = rightChild;
        }

        if (largerChild == index) {
            break;
        }
        swap(arr[largerChild], arr[index]);
        index = largerChild;
    }
}

// 将数组调整为堆
template <typename T>
void heapify(T arr[], int size) {	// [0, size)区间内构建最大堆

    int lastNonLeaf = (size - 1 - 1) / 2;
    for (int i = lastNonLeaf; i >= 0; i--) {
        shiftDown(arr, i, size-1);
    }
    return;
}

template <typename T>
void heapSort(T arr[], int size) {

    heapify(arr, size);

    for (int i = 0; i < size - 1; i++) {		// 需要对 size - 1 个元素进行向下调整
        swap(arr[0], arr[size - 1 - i]);		// 将第 i 大的元素放到 size - 1 - i的位置上
        shiftDown(arr, 0, size - 2 - i);		// 对堆顶元素在区间 [0, size - 2 - i]内进行调整
    }

    return;
}
#endif //SORTINGALGORITHM_HEAPSORT_H
