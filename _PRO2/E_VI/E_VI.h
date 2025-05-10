//
// Created on 10.05.2025.
//

#pragma once

#include "../_MAIN.h"


namespace hs_pro_II {

    /** exercise 6.2 a) **********************************************************/
    struct A_I
    {
        std::unique_ptr<struct B_I> P2; // <--- Smart - Pointer - Typ einsetzen
        A_I () { std :: cout << "A created \n" ; }
        ~ A_I () { std :: cout << "A destroyed \n" ; }
    };
    struct B_I
    {
        std ::weak_ptr<struct A_I> P3 ; // <---
        B_I () { std :: cout << "B created \n" ; }
        ~ B_I () { std :: cout << "B destroyed \n" ; }
    };

    /** exercise 6.2 b) **********************************************************/
    struct A_II
    {
        std::unique_ptr<struct B_II> P2;
        std::shared_ptr<struct C_II> P3;
        std::unique_ptr<struct D_II> P4;

        A_II() { std::cout << "A created\n"; }
        ~A_II() { std::cout << "A destroyed\n"; }
    };

    struct B_II
    {
        B_II() { std::cout << "B created\n"; }
        ~B_II() { std::cout << "B destroyed\n"; }
    };

    struct C_II
    {
        C_II() { std::cout << "C created\n"; }
        ~C_II() { std::cout << "C destroyed\n"; }
    };

    struct D_II
    {
        std::weak_ptr<struct A_II> P5;
        std::shared_ptr<struct C_II> P6;

        D_II() { std::cout << "D created\n"; }
        ~D_II() { std::cout << "D destroyed\n"; }
    };
    /****************************************************************************/


    class E_VI {
    private:
        static void* get_return_address();


    public:
        static void recursiveAnalyse(size_t callNumber);
        static void testGraph_II_a();
        static void testGraph_II_b();


    };








} // hs_pro_II

