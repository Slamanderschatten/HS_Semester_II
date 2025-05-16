//
// Created on 12.05.2025.
//

#include "E_VI.h"

namespace hs_thi {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/

    bool E_VI::isGoodSolutionForSOS(size_t n, const int* a, intmax_t b, size_t solutionSize, const size_t* solution) {
        if(n < solutionSize)
            return false;
        intmax_t sum = 0;
        for(size_t i = 0; i < solutionSize; i++)  {
            sum += a[solution[i]];
        }
        return sum == b;
    }


    size_t E_VI::timeOf_isGoodSolutionForSOS(size_t n) {
        return 4*n + 5;
    }


    bool E_VI::sos(size_t n, const int *a, intmax_t b) {
        if (n == 0 || b < 0)
            return false;
        if (b == 0)
            return true;
        return sos(n - 1, a, b) || sos(n - 1, a, b - a[n-1]);
    }


    size_t E_VI::timeOf_sos(size_t n) {
        return 8*pow(2, n);
    }







} // hs_thi