//
// Created on 10.05.2025.
//

#include "E_VI.h"

namespace hs_pro_II {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/

    void* E_VI::get_return_address() {
        return __builtin_return_address(0);
    }






    /******************************************************/
    /************* public ********************************/
    /****************************************************/

    void E_VI::recursiveAnalyse(size_t callNumber) {
        //char filler[100];
        cout << "Call number: " << callNumber << ", on stack address: " << &callNumber << endl;
        recursiveAnalyse(++callNumber);
    }


    void E_VI::testGraph_II_a() {
        std ::shared_ptr<A_I> P1 {std :: make_shared<A_I>() }; // <---
        P1->P2 = std :: make_unique<B_I>() ; // <---
        P1->P2->P3 = P1 ;
    }


    void E_VI::testGraph_II_b() {
        std::shared_ptr<A_II> P1 { std::make_unique<A_II>() };

        // aus A:
        P1->P2 = std::make_unique<B_II>();
        P1->P3 = std::make_shared<C_II>();
        P1->P4 = std::make_unique<D_II>();

        // aus D:
        P1->P4->P5 = P1;
        P1->P4->P6 = P1->P3;
    }







} // hs_pro_II