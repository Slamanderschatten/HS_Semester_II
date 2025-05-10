//
// Created on 22.04.2025.
//

#include "Vector.h"

namespace hs_aud {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    Vector::Vector(int dim) {
        dimension = dim;
        data = new int[dimension];
    }


    Vector::~Vector() {
        delete[] data;
    }


    void Vector::set(size_t i, int val) {
        if(i < dimension)
            data[i] = val;
        else
            throw out_of_range("asked index not exist");
    }


    int Vector::get(size_t i) const {
        if(i < dimension)
            return data[i];
        else
            throw out_of_range("asked index not exist");
    }


    int Vector::bin_search(int searchedValue) const  {
        if(dimension == 0)
            return -1;

        size_t u = 0, o = dimension-1;
        size_t a;

        if(data[u] == searchedValue)
            return data[u];
        if(data[o] == searchedValue)
            return data[o];


        while(u <= o) {
            a = (o  - u) / 2 + u;
            if(data[a] == searchedValue)
                return data[u];
            else if(data[a] < searchedValue)
                u = a;
            else if(data[a] > searchedValue)
                o = a;
        }
        return -1;
    }








} // hs_aud