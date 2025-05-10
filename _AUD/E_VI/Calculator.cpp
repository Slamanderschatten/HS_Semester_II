//
// Created on 06.05.2025.
//

#include "Calculator.h"

namespace hs_a {




    /******************************************************/
    /************* private *******************************/
    /****************************************************/


    template<typename valType>
    void Calculator<valType>::calcTopOfStacks() {
        if(sValues.size() < 2)
            return;
        long long right = sValues.pop();
        long long left = sValues.pop();
        long long result;
        switch (sOperator.pop()) {
            case '+':
                result = left + right;
                break;
            case '-':
                result = left - right;
                break;
            case '*':
                result = left * right;
                break;
            case '/':
                result = left / right;
                break;
        }
        sValues.push(result);
    }






    /******************************************************/
    /************* public ********************************/
    /****************************************************/


    template<typename valType>
    Calculator<valType>::Calculator() {
        calcSymbols.emplace(')', 0);
        calcSymbols.emplace('+', 5);
        calcSymbols.emplace('-', 5);
        calcSymbols.emplace('*', 10);
        calcSymbols.emplace('/', 10);
        calcSymbols.emplace('(', 15);
    }


    template<typename valType>
    valType Calculator<valType>::calc(string calc) {
        sValues.clear();
        sOperator.clear();
        char startOperator = '(';
        sOperator.push(startOperator);
        calc.append(")");

        intmax_t lastPos = -1;
        for(intmax_t i = 0; i < calc.size(); i++) {
            char sym  = calc[i];
            auto priorityIt = calcSymbols.find(sym);
            if(priorityIt != calcSymbols.end()) {

                //take value
                if(i - lastPos > 1) {
                    valType val = stoll(calc.substr(lastPos + 1, i - lastPos - 1));
                    sValues.push(val);
                }
                lastPos = i;

                //push operator or calculate
                if(sym == ')') {
                    while(sOperator.top() != '(') {
                        calcTopOfStacks();
                    }
                    sOperator.pop();
                }
                else if(priorityIt->second > calcSymbols[sOperator.top()] || sOperator.top() == '(') {
                    sOperator.push(sym);
                }
                else {
                    calcTopOfStacks();
                    i--; //prove the actual operator again
                }
            }
        }
        return sValues.pop();
    }







} // hs_a