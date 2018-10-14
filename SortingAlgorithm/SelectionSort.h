//
// Created by Li Congcong on 2018/10/14.
//

#ifndef SORTINGALGORITHM_SELECTIONSORT_H
#define SORTINGALGORITHM_SELECTIONSORT_H

#include "SortingHelper.h"


template <typename T>
void selectionSort(T* arr, int size) {

    int minIndex;
    for (int i=0; i < size-1; i++) {	// 需要　size - 1 次循环
        minIndex = i;

        for (int j=i+1; j < size; j++) {	// 在[i+1, size-1]中，找出最小元素的下标
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {		// 将找到的第 i 小的元素与位置 i 上的元素调换位置
            swap(arr[minIndex], arr[i]);
        }
    }
    return;
}
#endif //SORTINGALGORITHM_SELECTIONSORT_H
