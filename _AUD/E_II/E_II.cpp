//
// Created by Medion on 03.04.2025.
//

#include "E_II.h"

namespace hs_aud {
    int E_II::tIV_r(int n) {
        if(n <= 2)
            return 1;
        else
            return n * tIV_r(n - 1) - tIV_r(n - 2);
    }


    int E_II::tIV_i(int n) {
        int vI = 1;
        int vII = 1;
        int result;

        if(n <= 2)
            return 1;

        for(int i = 3; i <= n; i++) {
            result = i * vII - vI;
            vI = vII;
            vII = result;
        }
        return result;
    }


    int E_II::tV_r(int n) {
        if(n <= 2)
            return 1;
        else
            return n + tV_r(n - 2);
    }


    int E_II::tV_i(int n) {
        int vI = 1;
        int vII = 1;
        int result;

        if(n <= 2)
            return 1;

        for(int i = 3; i <= n; i++) {
            result = i + vI;
            vI = vII;
            vII = result;
        }
        return result;
    }


    int E_II::tVII(int a, int b) {
        int r = -1;
        while(r != 0) {
            if(a < b)
                swap(a, b);
            r = a - b;
            a = b;
            b = r;
        }
        return a;

    }





} // hs_aud