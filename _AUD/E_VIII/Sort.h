//
// Created by Medion on 22.05.2025.
//

#pragma once

#include <cinttypes>
#include <utility>
#include <limits>

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
    };

} // hs_aud

