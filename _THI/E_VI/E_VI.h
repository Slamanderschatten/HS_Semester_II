//
// Created on 12.05.2025.
//

#pragma once

#include "../_MAIN.h"

namespace hs_thi {

    class E_VI {
    private:


    public:

        static bool isGoodSolutionForSOS(size_t n, const int* a, intmax_t b, size_t solutionSize, const size_t* solution);
        static size_t timeOf_isGoodSolutionForSOS(size_t n);
        static bool sos(size_t n, const int* a, intmax_t b);
        static size_t timeOf_sos(size_t n);


    };

} // hs_thi
