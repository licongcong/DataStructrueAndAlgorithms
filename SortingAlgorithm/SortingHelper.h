//
// Created by Li Congcong on 2018/10/14.
//

#ifndef SORTINGALGORITHM_SORTINGHELPER_H
#define SORTINGALGORITHM_SORTINGHELPER_H

#include <iostream>
#include <ctime>
#include <algorithm>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;

using std::time;
using std::max;
using std::min;
using std::swap;
using std::copy;

namespace SortingHelper {
    template <typename T>
    T* generateRandomSequence(int size, int rangeL, int rangeR) {
        assert(size > 0);
        T* arr = new T[size];

        assert(rangeL <= rangeR);
        srand((unsigned int)time(nullptr));

        for (int i=0; i < size; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL ;
        }

        return arr;
    }

    template <typename T>
    T* generateOrderedSequence(int size) {
        assert(size > 0);
        T* arr = new T[size];

        for (int i=0; i < size; i++) {
            arr[i] = i;
        }

        return arr;

    }

    template <typename T>
    T* generateNearlyOrderedSequence(int size, int pairs) {
        assert( size > 0 && pairs <= size);

        T* arr = new T[size];
        for (int i=0; i < size; i++) {
            arr[i] = i;
        }

        srand((unsigned int) time(nullptr));
        int swapX, swapY;
        for (int i=0; i < pairs; i++) {
            swapX = rand() % size;
            swapY = rand() % size;
            swap(arr[swapX], arr[swapY]);
        }

        return arr;
    }

    template <typename T>
    T* generateOppositeSequence(int size) {
        assert(size > 0);

        T* arr = new T[size];

        for (int i=0; i < size; i++) {
            arr[i] = size - i - 1;
        }
        return arr;
    }

    template <typename T>
    bool isSorted(T* arr, int size) {
        for (int i=0; i < size - 1; i++) {
            if (arr[i] > arr[i+1]) {
                cout << "Not Sorted!!!" << endl;
                return false;
            }
        }
        cout << "Sorted!!!" << endl;
        return true;
    }

    template <typename T>
    T* copyArray(T* arr, int size) {
        assert(size > 0);

        T* result = new T[size];
        copy(arr, arr+size, result);

        return result;
    }

    template <typename T>
    void printArr(T* arr, int size) {
        for (int i=0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

#endif //SORTINGALGORITHM_SORTINGHELPER_H
