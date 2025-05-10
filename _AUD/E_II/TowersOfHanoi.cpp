//
// Created on 04.04.2025.
//

#include "TowersOfHanoi.h"

namespace hs_aud {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    int TowersOfHanoi::neededMoves(int numberOfRings) {
        if(numberOfRings < 1)
            return 0;
        int lastResult = 0;
        for(int i = 0; i < numberOfRings; i++) {
            lastResult = lastResult * 2 + 1;
        }
        return lastResult;
    }


    void TowersOfHanoi::move_r(int n, int from, int to, int clipboard) {
        if(n != 1) move_r(n-1, from, clipboard, to);
        cout << from << " to " << to << endl;
        if(n != 1) move_r(n-1, clipboard, to, from);
    }










} // hs_aud