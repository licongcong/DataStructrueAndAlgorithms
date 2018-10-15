//
// Created by Li Congcong on 2018/10/15.
//

#ifndef SORTINGALGORITHM_QUICKSORT_H
#define SORTINGALGORITHM_QUICKSORT_H

#include "SortingHelper.h"

// 插入排序算法，在元素较少使使用插入排序算法可以提高算法性能
template <typename T>
void insertionSort(T arr[], int left, int right) {
    int index;
    T temp;

    for (int i = left + 1; i <= right; i++) {
        index = i;
        temp = arr[i];		// 当前要处理的元素
        while (index > left && temp < arr[index - 1]) {	// 查找合适的位置
            arr[index] = arr[index - 1];
            index--;
        }

        arr[index] = temp;
    }
    return;
}

// 没有经过任何优化的分割过程
template <typename T>
void partition(T arr[], int left, int right) {
    if (left >= right)
        return;

    T qivot = arr[left];  // 基准

    int start = left + 1, end = right;
    while (start < end) {
        while (arr[start] < qivot && start < end) { //start < end 保证不会越界
            start++;
        }
        while (arr[end] >= qivot && start < end) {
            end--;
        }
        swap(arr[start], arr[end]);
    }

    if (arr[start] < qivot) {    //start == end时，处理qvivot，保证 start 指向 qivot 的最终位置上
        swap(arr[left], arr[start]);
    }
    else {
        swap(arr[left], arr[start - 1]);
        start--;
    }

    partition(arr, left, start - 1);
    partition(arr, start + 1, right);
}

// 快速排序算法优化：
// 随机选择一个元素作为基准，解决树不均衡的问题
// 元素较少时，使用插入排序算法
template <typename T>
void partition1(T arr[], int left, int right) {
    if (right - left <= 16){        // 当元素个数较少时，使用插入排序算法
        insertionSort(arr, left, right);
        return;
    }
    srand((unsigned int)time(nullptr));
    int index = rand() % (right - left + 1) + left;		// [left, right]随机选择一个元素
    swap(arr[index], arr[left]);

    T qivot = arr[left];  // 基准

    int start = left + 1, end = right;
    while (start < end) {
        while (arr[start] < qivot && start < end) { //start < end 保证不会越界
            start++;
        }
        while (arr[end] >= qivot && start < end) {
            end--;
        }
        swap(arr[start], arr[end]);
    }

    if (arr[start] < qivot) {    //start == end时，处理qvivot
        swap(arr[left], arr[start]);
    }
    else {
        swap(arr[left], arr[start - 1]);
        start--;
    }

    partition1(arr, left, start - 1);
    partition1(arr, start + 1, right);
}

// 三路快速排序算法
template <typename T>
void quickSort3Ways(T arr[], int left, int right) {
    if (right - left <= 16) {
        insertionSort(arr, left, right);
        return;
    }

    srand((unsigned int)time(nullptr));
    int index = rand() % (right - left + 1) + left;		// [left, right]随机选择一个元素
    swap(arr[index], arr[left]);

    T qivot = arr[left];
    int lessTial = left;
    int curr = left + 1;
    int greaterHead = right + 1;
    while (curr < greaterHead) {
        if (arr[curr] > qivot) {
            swap(arr[curr], arr[greaterHead - 1]);
            greaterHead--;
        }
        else if (arr[curr] < qivot) {
            swap(arr[curr], arr[lessTial + 1]);
            lessTial++;
            curr++;
        }
        else {
            curr++;
        }
    }
    swap(arr[left], arr[lessTial]);

    quickSort3Ways(arr, left, lessTial - 1);
    quickSort3Ways(arr, greaterHead, right);
}



template <typename T>
void quickSort(T arr[], int size) {
    partition(arr, 0, size - 1);    // 没有以过任何优化
    // quickSort3Ways(arr, 0, size - 1);    //三路快速排序
    // partition1(arr, 0, size - 1);    //使用插入排序算法和随机选择基准元素优化
}
#endif //SORTINGALGORITHM_QUICKSORT_H
