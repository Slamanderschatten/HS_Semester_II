//
// Created on 06.05.2025.
//

#include "Calculator.h"

namespace hs_aud {




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


    template <typename valType>
    string Calculator<valType>::infixToPostfix(std::string s) {
        string postfix;
        Stack<char> stack;
        char startClamp = '(';
        stack.push(startClamp);
        s += ')';

        for(char c : s) {
            if(c <= '9' && c >= '0') {
                postfix += c;
                cout << c;
            } else if(c == ' ') {

            } else if(c == '(') {
                postfix += ' ';
                cout << ' ';
                stack.push(c);
            } else if(c == ')') {
                while(stack.top() != '(') {
                    postfix += ' ';
                    cout << ' ';

                    char last = stack.pop();
                    postfix += last;
                    cout << last;
                }
                stack.pop();
            } else if(calcSymbols.find(c) != calcSymbols.end()) {
                postfix += ' ';
                cout << ' ';
                if(stack.empty()) {
                    stack.push(c);
                }
                if(stack.top() == '(') {
                    stack.push(c);
                } else if(calcSymbols[c] > calcSymbols[stack.top()]) {
                    stack.push(c);
                } else {
                    char last = stack.pop();
                    postfix += last;
                    cout << last;
                    stack.push(c);
                }
            } else {
                throw runtime_error("wrong symbol in math function [" + s + "] : " + c);
            }
        }

        while(!stack.empty()) {
        postfix += ' ';
        cout << ' ';

        char last = stack.pop();
        postfix += last;
        cout << last;
        }


        return postfix;
    }


    template<typename valType>
    valType Calculator<valType>::calcPostfix(string s) {
        Stack<valType> values;
        size_t numberStart = 0;
        string valAsString;
        for(size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c <= '9' && c >= '0') {
                valAsString += c;
            } else if(c == ' ') {
                if(!valAsString.empty()) {
                    valType val = stoll(valAsString);
                    values.push(val);
                    numberStart = i + 1;
                    valAsString.clear();
                }
            } else if(calcSymbols.find(c) != calcSymbols.end()) {
                valType left = values.pop();
                valType right = stoll(s.substr(numberStart + 1, i - numberStart - 1));
                valType result;
                switch(c) {
                    case '+': result = left + right; break;
                    case '-': result = left - right; break;
                    case '*': result = left * right; break;
                    case '/': result = left / right; break;
                    default: break;
                }
                values.push(result);
                numberStart = i+1;
            } else {
                throw runtime_error("wrong symbol in math function [" + s + "] : " + c);
            }
        }
        if(values.empty())
            return 0;
        else
            return values.pop();
    }










} // hs_aud