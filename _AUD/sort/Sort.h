//
// Created by Medion on 22.05.2025.
//

#pragma once

#include <cinttypes>
#include <utility>
#include <limits>
#include <algorithm>
#include <random>

namespace hs_aud {

    template<typename T>
    class Sort {

    public:
        static size_t insertionSort(T* field, size_t n) {
            size_t numberOfComparisons = 0;
            size_t i,j;
            for (i=1; i<n; i++)
            {
                T elem = field[i];
                j=i;
                numberOfComparisons++;
                for(; j > 0 && elem < field[j-1]; j--) {
                    numberOfComparisons++;
                    field[j] = field[j - 1];
                }
                field[j]=elem;
            }
            return numberOfComparisons;
        }


        static size_t selectionSort(T* field, size_t n) {
            size_t numberOfComparisons = 0;
            size_t i, j, iMin;
            for (i=0;i<n-1;i++)
            {
                iMin=i;
                numberOfComparisons++;
                for (j=i+1;j<n;j++) {
                    numberOfComparisons++;
                    if (field[j] < field[iMin])
                        iMin = j;
                }
                swap(field[i],field[iMin]);
            }
            return numberOfComparisons;
        }


        static size_t exchangeSort(T* field, size_t n) {
            size_t numberOfComparisons = 0;
            if(n < 2)
                return numberOfComparisons;
            for(size_t i = 0; i < n-1; i++) {
                for(size_t j = n-2; j < std::numeric_limits<size_t>::max(); j--) {
                    numberOfComparisons++;
                    if(field[j] > field[j+1])
                        swap(field[j], field[j+1]);
                }
            }
            return numberOfComparisons;
        }


        template<int x>
        static size_t quickSort(T*field, size_t from, size_t to) {
            size_t counter = 0;
            size_t sortedElement = partition<x>(field, from, to, counter);
            if(from+1 < sortedElement)
                counter += quickSort<x>(field, from, sortedElement-1);
            if(sortedElement < to-1)
                counter += quickSort<x>(field, sortedElement+1, to);
            return counter;
        }

        template<int x>
        static size_t partition(T* field, size_t from, size_t to, size_t& counter) {
            if constexpr (x == 1)
                std::swap(field[pivot_a(field, from, to)], field[to]);
            if constexpr (x == 2)
                std::swap(field[pivot_b(field, from, to)], field[to]);
            if constexpr (x == 3)
                std::swap(field[pivot_c(field, from, to)], field[to]);
            size_t i=from, j = to-1;
            while(true) {
                if(field[i] < field[to]) {
                    counter++;
                    i++;
                    if(field[j] >= field[to]) {
                        counter++;
                        j--;
                    }
                    else {
                        while(field[i] < field[to]) {
                            counter++;
                            i++;
                        }
                        if(i >= j) {
                            counter++;
                            std::swap(field[i], field[to]);
                            return i; // pivot was highest || more lower values
                        }
                        std::swap(field[i], field[j]);
                        i++;
                        j--;
                    }
                }
                else {
                    while(field[j] >= field[to]) {
                        counter++;
                        if(i >= j) {
                            counter++;
                            std::swap(field[j], field[to]);
                            return j; // pivot was lowest ||
                        }
                        j--;
                    }
                    if(i >= j) {
                        counter++;
                        std::swap(field[i], field[to]);
                        return i; // field was sorted at begin || field was inverted at begin
                    }
                    std::swap(field[i], field[j]);
                    i++;
                    j--;
                }
            }
        }

        static size_t pivot_a(T* field, size_t from, size_t to) {
            return (to - from) / 2 + from;
        }

        static size_t pivot_b(T* field, size_t from, size_t to) {
            return rand() % (to - from) + from;
        }

        static size_t pivot_c(T* field, size_t from, size_t to) {
            return (to - from) / 2 + from;
        }


        /**
         *  i1   4   5   7 kj2   3   8   9
         *   1  i4   5   7 kj2   3   8   9
         *   1   2  i5   7  k4  j3   8   9
         *   1   2   3   4  i7 kj5   8   9
         *   1   2   3   4   5 ik7  j8   9
         * @param field
         * @param from
         * @param center
         * @param to
         */
        static size_t mergeSortInPlace(T* field, size_t from, size_t to) {
            if(to - from < 1)
                return 0;

            auto center = (to - from) / 2 + 1 + from;

            size_t counter = mergeSortInPlace(field, from, center - 1);
            counter += mergeSortInPlace(field, center, to);

            size_t i = from, j = center, k = j;

            while(true) {
                if(field[i] > field[j]) {
                    counter++;
                    std::swap(field[i], field[j]);
                    i++;
                    j++;
                }
                else if(field[k] < field[j]) {
                    counter += 2;
                    std::swap(field[i], field[k]);
                    i++;
                    k++;
                }
                else { //if i <= k && i <= j
                    counter += 2;
                    i++;
                }
                if(i >= k)
                    return counter;
                if(j > to)
                    break;
            }

            if(i < k) {
                while (k <= to) {
                    std::swap(field[i], field[k]);
                    i++;
                    k++;
                }
            }
            return counter;
        }


        static size_t mergeSort(T* field, size_t from, size_t to) {
            if(to - from < 1)
                return 0;

            auto center = static_cast<size_t>(static_cast<double>(to - from)  / 2.0 + 0.5) + from;

            size_t counter = mergeSortInPlace(field, from, center - 1);
            counter += mergeSortInPlace(field, center, to);

        }

    };

} // hs_aud

