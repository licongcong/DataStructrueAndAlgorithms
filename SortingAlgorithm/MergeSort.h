//
// Created by Li Congcong on 2018/10/15.
//

#ifndef SORTINGALGORITHM_MERGESORT_H
#define SORTINGALGORITHM_MERGESORT_H

#include "SortingHelper.h"


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

// 没有经过任何优化的MergeSort
template <typename T>
void t_merge(T arr[], T temp[], int left, int mid, int right) {

    int leftStart = left;
    int rightStart = mid + 1;
    int tempIndex = left;

    while (leftStart <= mid && rightStart <= right) {	// 同时处理两个数组

        if (arr[leftStart] >= arr[rightStart]) {
            temp[tempIndex] = arr[rightStart];
            rightStart++;
        }
        else {
            temp[tempIndex] = arr[leftStart];
            leftStart++;
        }

        tempIndex++;

    }

    while (leftStart <= mid) {		// 当左侧数组还有剩余元素时
        temp[tempIndex] = arr[leftStart];
        tempIndex++;
        leftStart++;
    }

    while (rightStart <= right) {	// 当右侧数组还有剩余元素时
        temp[tempIndex] = arr[rightStart];
        tempIndex++;
        rightStart++;
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return;
}

template <typename T>
void t_mergeSort(T arr[], T temp[], int left, int right) {

    if (left >= right) return;

    int mid = left + (right - left) / 2;

    t_mergeSort(arr, temp, left, mid);
    t_mergeSort(arr, temp, mid + 1, right);
    t_merge(arr, temp, left, mid, right);

}
template <typename T>
void t_mergeSort1(T arr[], T temp[], int left, int right) {

    if (right - left <= 16) {
        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;

    t_mergeSort1(arr, temp, left, mid);
    t_mergeSort1(arr, temp, mid + 1, right);
    t_merge(arr, temp, left, mid, right);

}

// 增加merge操作时的判断条件
template <typename T>
void t_mergeSort2(T arr[], T temp[], int left, int right) {

    if (left >= right) return;

    int mid = left + (right - left) / 2;
    t_mergeSort2(arr, temp, left, mid);
    t_mergeSort2(arr, temp, mid+1, right);

    if (arr[mid] > arr[mid+1])	// 只有当arr[mid] > arr[mid+1] 时才有必要进行merge，否则已经为有序数组
        t_merge(arr, temp, left, mid, right);
}

template <typename T>
void mergeSort(T arr[], int size) {

    T *temp = new T[size];
    //t_mergeSort(arr, temp, 0, size - 1);
    // t_mergeSort1(arr, temp, 0, size - 1);
    t_mergeSort2(arr, temp, 0, size - 1);
    delete[] temp;
    return;
}

// 自底向上的Merge Sort
template <typename T>
void mergeSortBU(T arr[], int size) {

    T *temp = new T[size];

    int right = size -1;
    for (int seg = 1; seg <= right; seg += seg) { // 对元素进行分组，1, 2, 4, 8...
        for (int start = 0; start <= right; start += seg + seg) { // 每次merge时的起始位置

            int low = start, high = min(right, start + seg + seg - 1);
            int mid = min(right, start + seg - 1);

            int leftStart = low, leftEnd = mid;
            int rightStart = mid + 1, rightEnd = high;

            int tempIndex = leftStart;
            while (leftStart <= leftEnd && rightStart <= rightEnd) {
                if (arr[leftStart] >= arr[rightStart]) {
                    temp[tempIndex] = arr[rightStart];
                    ++ rightStart;
                } else {
                    temp[tempIndex] = arr[leftStart];
                    ++ leftStart;
                }
                ++ tempIndex;
            }

            while (leftStart <= leftEnd) {
                temp[tempIndex++] = arr[leftStart++];
            }

            while (rightStart <= rightEnd) {
                temp[tempIndex++] = arr[rightStart++];
            }
        }
        for (int i=0; i <= right; ++i) {
            arr[i] = temp[i];
        }
    }
    delete [] temp;
}
#endif //SORTINGALGORITHM_MERGESORT_H
