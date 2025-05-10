//
// Created on 07.04.2025.
//

#include "E_III.h"

namespace hs_aud {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    double E_III::tVIII_r(unsigned int n) {
        if(n == 0)
            return 0;

        return 1.0 / n + tVIII_r(n - 1);
    }


    double E_III::tVIII_i(unsigned int n) {
        double sum = 1;
        for(int i = 2; i <= n; i++) {
            sum += 1.0/i;
        }
        return sum;
    }


    double E_III::piRecursive(const unsigned int n, const unsigned int i) {

        if(i == n)
            return 1;
        else
            return 1 + (i / (i * 2.0 + 1.0)) * piRecursive(n, i+1);
    }






} // hs_aud