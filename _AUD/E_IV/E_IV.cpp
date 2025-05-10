//
// Created on 22.04.2025.
//

#include "E_IV.h"

namespace hs_a {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    void E_IV::fib_i() {
        uintmax_t n = 3;
        uintmax_t vI = 1, vII = 1;
        while(true) {
            n++;
            uintmax_t result = vI + vII;
            vI = vII;
            vII = result;
            cout << n << ": " << result << endl;
        }
    }


    void E_IV::fib_r(uintmax_t last, uintmax_t value, uintmax_t n) {
        cout << n << ": " << value << endl;
        fib_r(value, last + value, n+1);
    }


    void E_IV::fib_iII() {
        uintmax_t vI = 1, vII = 1;
        while(true) {
            uintmax_t result = vI + vII;
            vI = vII;
            vII = result;
            cout << result << endl;
        }
    }


    int E_IV::task15_r(int n) {
        if(n == 1)
            return 1;
        return n * task15_r(n-1) + n;
    }


    int E_IV::task15_i(int n) {
        int result = 0;

        for(int i = 1; i <= n; i++) {
            result = i * result + i;
        }
        return result;
    }







} // hs_a