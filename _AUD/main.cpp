


#include "_MAIN.h"
#include "E_I/Collatz.h"
#include "E_II/E_II.h"
#include "E_II/TowersOfHanoi.h"
#include "E_III/E_III.h"
#include "E_IV/E_IV.h"
#include "E_IV/Vector.h"
#include "E_V/E_V.h"
#include "E_VI/Stack.h"
#include "E_VI/Calculator.h"
#include "E_VI/Calculator.cpp"





#define TASK 21
#define SUBTASK 1








int main() {
    using namespace hs_a;
    using namespace std;


#if TASK == 1
    {
        Collatz::calc(27);
        cout << endl << endl;
        Collatz::calc(37);
        cout << endl << endl;
        Collatz::calc(42);
        cout << endl << endl;
    }
#endif

#if TASK == 4
    {
        //recursive
        cout << E_II::tIV_r(1);
        cout << endl;
        cout << E_II::tIV_r(2);
        cout << endl;
        cout << E_II::tIV_r(3);
        cout << endl;
        cout << E_II::tIV_r(4);
        cout << endl;
        cout << E_II::tIV_r(5);
        cout << endl << endl << endl;

        //iterative
        cout << E_II::tIV_i(1);
        cout << endl;
        cout << E_II::tIV_i(2);
        cout << endl;
        cout << E_II::tIV_i(3);
        cout << endl;
        cout << E_II::tIV_i(4);
        cout << endl;
        cout << E_II::tIV_i(5);
        cout << endl << endl << endl;


    }
#endif

#if TASK == 5
    {
        //recursive
        cout << E_II::tV_r(1);
        cout << endl;
        cout << E_II::tV_r(2);
        cout << endl;
        cout << E_II::tV_r(3);
        cout << endl;
        cout << E_II::tV_r(4);
        cout << endl;
        cout << E_II::tV_r(5);
        cout << endl << endl << endl;

        //iterative
        cout << E_II::tV_i(1);
        cout << endl;
        cout << E_II::tV_i(2);
        cout << endl;
        cout << E_II::tV_i(3);
        cout << endl;
        cout << E_II::tV_i(4);
        cout << endl;
        cout << E_II::tV_i(5);
        cout << endl << endl << endl;
    }
#endif

#if TASK == 6 //number of moves for towers of hanoi
    {
        TowersOfHanoi::move_r(4, 1, 3, 2);
        cout << endl << endl;

        cout << 1 << " => " << TowersOfHanoi::neededMoves(1);
        cout << endl;
        cout << 2 << " => " << TowersOfHanoi::neededMoves(2);
        cout << endl;
        cout << 3 << " => " << TowersOfHanoi::neededMoves(3);
        cout << endl;
        cout << 4 << " => " << TowersOfHanoi::neededMoves(4);
        cout << endl;
        cout << 5 << " => " << TowersOfHanoi::neededMoves(5);
        cout << endl << endl << endl;
    }
#endif

#if TASK == 7 //greatest common divisor
    {
        cout << E_II::tVII(9,15);
        cout << endl;
        cout << E_II::tVII(16,28);
        cout << endl;
        cout << E_II::tVII(119,544);
        cout << endl << endl << endl;
    }
#endif

#if TASK == 8 // Sum(1/n)...
    {
        cout << E_III::tVIII_r(1);
        cout << endl;
        cout << E_III::tVIII_r(3);
        cout << endl;
        cout << E_III::tVIII_r(5);
        cout << endl << endl << endl;
        cout << E_III::tVIII_i(1);
        cout << endl;
        cout << E_III::tVIII_i(3);
        cout << endl;
        cout << E_III::tVIII_i(5);
        cout << endl << endl << endl;
    }
#endif

#if TASK == 9 // PI
    {
        cout << 2 * E_III::piRecursive(200);
        cout << endl << endl << endl;
    }
#endif

#if TASK == 13 // fibonacci
    {
#if SUBTASK == 1
        E_IV::fib_i();
        /*
         * 1 sec = 50 000
         * 10 sec = 600 000
         * 1 min = 4 000 000
         * Zeitkomplexität = n
         * Speicherkomplexität = 1
         */
#endif
#if SUBTASK == 2
        E_IV::fib_r(0,1,1);
        /*
         * 1 sec = 50 000
         * 10 sec = 40 000 -> Segmentation fault
         * 1 min = 40 000 -> Segmentation fault
         * Zeitkomplexität = n
         * Speicherkomplexität = n
         */
#endif
#if SUBTASK == 3
        /*
         * 1 sec =
         * 10 sec =
         * 1 min = 4 000 000
         * Zeitkomplexität = n
         * Speicherkomplexität = 1
         */
        E_IV::fib_iII();
#endif
    }
#endif

#if TASK == 14 // bin search
    {
        Vector v(100);
        for(int i = 0; i < 100; i++) {
            v.set(i, i);
        }

        cout << "search value 20: " << v.bin_search(20);
    }
    /*
     * log2(2^k -1)
     * log2(n)
     */
#endif

#if TASK == 15 //
    {
        cout << E_IV::task15_r(1) << " ";
        cout << E_IV::task15_r(2) << " ";
        cout << E_IV::task15_r(3) << " ";
        cout << E_IV::task15_r(4) << " ";
        cout << E_IV::task15_r(5) << " ";
        cout << E_IV::task15_r(6) << " ";
        cout << E_IV::task15_r(7) << " ";
        cout << E_IV::task15_r(8) << " ";
        cout << E_IV::task15_r(9) << " ";
        cout << E_IV::task15_r(10) << endl;
        cout << E_IV::task15_i(1) << " ";
        cout << E_IV::task15_i(2) << " ";
        cout << E_IV::task15_i(3) << " ";
        cout << E_IV::task15_i(4) << " ";
        cout << E_IV::task15_i(5) << " ";
        cout << E_IV::task15_i(6) << " ";
        cout << E_IV::task15_i(7) << " ";
        cout << E_IV::task15_i(8) << " ";
        cout << E_IV::task15_i(9) << " ";
        cout << E_IV::task15_i(10) << endl;
    }
    /*
     * c) n^n
     * d) n
     * e) n
     */
#endif

#if TASK == 19 // fakultaet
    {
        cout << E_V::task19(1) << " ";
        cout << E_V::task19(2) << " ";
        cout << E_V::task19(3) << " ";
        cout << E_V::task19(4) << " ";
        cout << E_V::task19(5) << " ";
        cout << E_V::task19(6) << " ";
        cout << E_V::task19(7) << " ";
        cout << E_V::task19(8) << " ";
        cout << E_V::task19(9) << " ";
        cout << endl;
    }
#endif

#if TASK == 20 // stack
    {
        Stack<int> stack;
        int i1 = 1;
        int i2 = 2;
        stack.push(i1);
        stack.push(i2);
        cout << stack.top() << endl;
        cout << stack.pop() << endl;
        cout << stack.top() << endl;
        cout << stack.size() << endl;
        cout << stack.empty() << endl;
        cout << stack.pop() << endl;
        cout << stack.empty() << endl;
        cout << endl;
    }
#endif

#if TASK == 21 // INFIX => POSTFIX
    {
#if SUBTASK == 2
        unordered_map<char, uint8_t> calcSymbols;
        calcSymbols.emplace('(', 0);
        calcSymbols.emplace(')', 0);
        calcSymbols.emplace('*', 1);
        calcSymbols.emplace('/', 1);
        calcSymbols.emplace('+', 2);
        calcSymbols.emplace('-', 2);
        Stack<char> sOperator;
        char startOperator = '(';
        sOperator.push(startOperator);
        Stack<long long> sValues;
        string calc;
        cout << "set calculation" << endl;
        //cin >> calc;
        calc = "1+2*3-(4+5*1)*2";
        calc.append(")");

        long long lastPos = -1;
        for(size_t i = 0; i < calc.size(); i++) {
            char sym  = calc[i];
            auto priorityIt = calcSymbols.find(sym);
            if(priorityIt != calcSymbols.end()) {

                //take value
                if(i - lastPos > 1) {
                    long long val = stoll(calc.substr(lastPos + 1, i - lastPos - 1));
                    sValues.push(val);
                }
                lastPos = i;

                if(sOperator.top() == '(') {
                    sOperator.push(sym);
                }
                else if(sym == ')') {
                    while(sOperator.top() != '(') {
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
                    sOperator.pop();
                }
                else if(priorityIt->second < calcSymbols[sOperator.top()]) {
                    sOperator.push(sym);
                }
                else {
                    long long right = sValues.pop();
                    long long left = sValues.pop();
                    long long result = 0;
                    switch(sOperator.pop()) {
                        case '+': result = left + right; break;
                        case '-': result = left - right; break;
                        case '*': result = left * right; break;
                        case '/': result = left / right; break;
                    }
                    sValues.push(result);
                    if(priorityIt->second >= calcSymbols[sOperator.top()]) {
                        right = sValues.pop();
                        left = sValues.pop();
                        switch(sOperator.pop()) {
                            case '+': result = left + right; break;
                            case '-': result = left - right; break;
                            case '*': result = left * right; break;
                            case '/': result = left / right; break;
                        }
                        sValues.push(result);
                    }
                    sOperator.push(sym);
                }
            }
        }
#endif

#if SUBTASK == 1
        Calculator<long long int> calculator;

        string calc;
        cout << "set calculation" << endl;
        //cin >> calc;
        //calc = "1+2*3-(4+5*1)*2";
        calc = "1+2+5*3+12-(4+5*4/2)*2+4*(6*3+1)";
        cout << calculator.calc(calc) << endl;
#endif


    }
#endif






    return 0;
}
