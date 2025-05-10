//
// Created on 22.04.2025.
//

#pragma once

#include "../_MAIN.h"

namespace hs_aud {

    class Vector {
    private:
        size_t dimension;
        int *data;

    public:
        explicit Vector(int dim);
        virtual ~Vector();
        void set(size_t i, int val);
        [[nodiscard]] int get(size_t i) const;
        [[nodiscard]] int bin_search(int searchedValue) const;


    };

} // hs_aud
