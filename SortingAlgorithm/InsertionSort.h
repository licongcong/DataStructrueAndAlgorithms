//
// Created by Li Congcong on 2018/10/14.
//

#ifndef SORTINGALGORITHM_INSERTIONSORT_H
#define SORTINGALGORITHM_INSERTIONSORT_H

#include "SortingHelper.h"

template <typename T>
void insertionSort(T arr[], int size) {

    T temp;
    int index;

    for (int i=0; i < size-1; i++) {
        index = i + 1;
        temp = arr[index];		// 取出下标为 i+1 的元素

        while (temp < arr[index - 1] && index > 0) {	// 查找合适的位置
            arr[index] = arr[index-1];
            index--;
        }
        arr[index] = temp;
    }
    return;
}
#endif //SORTINGALGORITHM_INSERTIONSORT_H
