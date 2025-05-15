//
// Created on 06.05.2025.
//

#pragma once

#include "../_MAIN.h"
#include "Stack.h"

namespace hs_aud {

    template<typename valType>
    class Calculator {
    private:
        unordered_map<char, uint8_t> calcSymbols;
        Stack<long long> sValues;
        Stack<char> sOperator;


        void calcTopOfStacks();

    public:

        Calculator();
        valType calc(string s);
        string infixToPostfix(string s);
        valType calcPostfix(string s);


    };

} // hs_aud
