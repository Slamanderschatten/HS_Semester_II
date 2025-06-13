


#include <stdexcept>

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
#include "E_VII/Tabel.h"
#include "sort/Sort.h"





#define TASK 36
#define SUBTASK 2








int main() {
    using namespace hs_aud;
    using namespace std;

    srand(time(0));


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

#if TASK == 21 // INFIX => POSTFIX and 22 POSTFIX Calculation
    {

#if SUBTASK == 1
        Calculator<double> calculator;

        string calc;
        cout << "set calculation" << endl;
        //cin >> calc;
        //calc = "1.2+2*3-(4+5*1)*2";
        calc = "1+2+5*3+12-(4+5*4/2)*2+4*(6*3+1)+0.1";

        string postfix = calculator.infixToPostfix(calc);
        double result = calculator.calcPostfix(postfix);
        cout << endl << result << endl;
#endif

#if SUBTASK == 2
        Calculator<double> calculator;

        string calc;
        cout << "set calculation" << endl;
        //cin >> calc;
        //calc = "1+2*3-(4+5*1)*2+0.1";
        calc = "1+2+5*3+12-(4+5*4/2)*2+4*(6*3+1)+0.1";
        cout << calculator.calc(calc) << endl;
#endif

    }
#endif

#if TASK == 25 // stack
    {
        int errors = 0;
        int in = 4;
        int out = -1;
        Table<int> table;

        //empty
        if(table.first()) errors++;
        if(table.last()) errors++;
        if(table.next()) errors++;
        if(table.previous()) errors++;
        if(table.erase()) errors++;
        if(table.get(out)) errors++;
        if(table.set(out)) errors++;

        //one node
        table.insert(1);
        if(!table.get(out)) errors++;
        if(out != 1) errors++;
        if(!table.erase()) errors++;
        table.append(2);
        if(!table.get(out)) errors++;
        if(out != 2) errors++;
        if(!table.erase()) errors++;
        table.append(3);

        if(!table.first()) errors++;
        if(!table.last()) errors++;
        if(table.next()) errors++;
        if(table.previous()) errors++;
        if(!table.set(in/*4*/)) errors++;
        if(!table.get(out))  errors++;
        if(out != 4) errors++;
        table.clear();

        // more nodes
        table.append(5);
        table.append(6);
        table.insert(7);
        table.first();
        if(!table.get(out)) errors++;
        if(out != 7) errors++;
        if(!table.erase()) errors++;
        if(!table.get(out)) errors++;
        if(out != 5) errors++;
        if(!table.last()) errors++;
        if(!table.get(out)) errors++;
        if(out != 6) errors++;
        if(!table.previous()) errors++;
        if(!table.get(out)) errors++;
        if(out != 5) errors++;
        if(!table.next()) errors++;
        if(!table.get(out)) errors++;
        if(out != 6) errors++;

        table.clear();
        if(table.get(out)) errors++;




        cout << "errors: " << errors << endl;
    }
#endif

#if TASK == 27 // sort
    {
        const size_t n = 9;
        int a[n]={0, 10, 20, 1, 11, 21, 2,12, 22};

        // insertion-sort
        for(int i : a)
            cout << i << " ";
        cout << " => insertion-sort need ";
        cout << Sort<int>::insertionSort(a, n);
        cout << " steps => ";
        for(int i : a)
            cout << i << " ";
        cout << endl << endl;

        //selection-sort
        int b[n]={0, 10, 20, 1, 11, 21, 2,12, 22};
        for(int i : b)
            cout << i << " ";
        cout << " => selection-sort need ";
        cout << Sort<int>::selectionSort(b, n);
        cout << " steps => ";
        for(int i : b)
            cout << i << " ";
        cout << endl << endl;

        //exchange-sort (bubble-sort)
        int c[n]={0, 10, 20, 1, 11, 21, 2,12, 22};
        for(int i : c)
            cout << i << " ";
        cout << " => exchange-sort need ";
        cout << Sort<int>::exchangeSort(c, n);
        cout << " steps => ";
        for(int i : c)
            cout << i << " ";
        cout << endl << endl;
    }
#endif

#if TASK == 33 // sort
    {
        const size_t n = 9;
        int a[n]={0, 10, 20, 1, 11, 21, 2,12, 22};

        // insertion-sort
        for(int i : a)
            cout << i << " ";
        cout << " => insertion-sort need ";
        cout << Sort<int>::insertionSort(a, n);
        cout << " steps => ";
        for(int i : a)
            cout << i << " ";
        cout << endl << endl;

        //selection-sort
        int b[n]={0, 10, 20, 1, 11, 21, 2,12, 22};
        for(int i : b)
            cout << i << " ";
        cout << " => selection-sort need ";
        cout << Sort<int>::selectionSort(b, n);
        cout << " steps => ";
        for(int i : b)
            cout << i << " ";
        cout << endl << endl;

        //exchange-sort (bubble-sort)
        int c[n]={0, 10, 20, 1, 11, 21, 2,12, 22};
        for(int i : c)
            cout << i << " ";
        cout << " => exchange-sort need ";
        cout << Sort<int>::exchangeSort(c, n);
        cout << " steps => ";
        for(int i : c)
            cout << i << " ";
        cout << endl << endl;

        // quick-sort a
        for(int i : a)
            cout << i << " ";
        cout << " => quick-sort a need ";
        cout << Sort<int>::quickSort<1>(a, 0, n-1);
        cout << " steps => ";
        for(int i : a)
            cout << i << " ";
        cout << endl << endl;

        // quick-sort b
        for(int i : a)
            cout << i << " ";
        cout << " => quick-sort b need ";
        cout << Sort<int>::quickSort<2>(a, 0, n-1);
        cout << " steps => ";
        for(int i : a)
            cout << i << " ";
        cout << endl << endl;

        // quick-sort n
        for(int i : a)
            cout << i << " ";
        cout << " => quick-sort n need ";
        cout << Sort<int>::quickSort<3>(a, 0, n-1);
        cout << " steps => ";
        for(int i : a)
            cout << i << " ";
        cout << endl << endl;
    }
#endif

#if TASK == 35 // quick-sort
    {


        const size_t n = 6000;
        vector<int> a;

        /** 2,1,4,3,6,5,8,7,10,9,12,11,14,13,…… */
        cout << "input: 2,1,4,3,6,5,8,7,10,9,12,11,14,13,……\n\n";


        // insertion-sort
        a.clear();
        for(int i = 1; i <= n/2; i++) {
            a.push_back(2*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(2*i-1);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => insertion-sort need ";
        cout << Sort<int>::insertionSort(a.data(), n);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;

        // quick-sort
        a.clear();
        for(int i = 1; i <= n/2; i++) {
            a.push_back(2*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(2*i-1);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => quick-sort need ";
        cout << Sort<int>::quickSort<1>(a.data(), 0, n-1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;


        /** 5,4,3,2,1,10,9,8,7,6,15,14,13,12,11,20,19,18,17,16,…. */
        cout << "\n\n input: 5,4,3,2,1,10,9,8,7,6,15,14,13,12,11,20,19,18,17,16,….\n\n";

        // insertion-sort
        a.clear();
        for(int i = 1; i <= n/5; i++) {
            a.push_back(5*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-1);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-2);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-3);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-4);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => insertion-sort need ";
        cout << Sort<int>::insertionSort(a.data(), n);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;

        // quick-sort
        a.clear();
        for(int i = 1; i <= n/5; i++) {
            a.push_back(5*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-1);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-2);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-3);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-4);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => quick-sort need ";
        cout << Sort<int>::quickSort<1>(a.data(), 0, n-1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;


        /** k,k-1,k-2,…..1,2k,2k-1,2k-2,….k+1,3k,3k-1,3k-2,….2k+1,…… */
        cout << "\n\n input: k,k-1,k-2,…..1,2k,2k-1,2k-2,….k+1,3k,3k-1,3k-2,….2k+1,……\n\n";
        int k = 10;

        // insertion-sort
        a.clear();
        for(int i = 1; i <= n / k; i++) {
            for(int j = 0; j < k; j++) {
                a.push_back(i*k-j);
                if(i<3)
                    cout << a.back() << " ";
            }
        }
        cout << "\n => insertion-sort need ";
        cout << Sort<int>::insertionSort(a.data(), n);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;

        // quick-sort
        a.clear();
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < k; j++) {
                a.push_back(k-j);
                if(i<3)
                    cout << a.back() << " ";
            }
        }
        cout << "\n => quick-sort need ";
        cout << Sort<int>::quickSort<1>(a.data(), 0, n-1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;

    }
#endif

#if TASK == 36 // merge-sort
    {


        const size_t n = 8;
        vector<int> a;

        /** 2,1,4,3,6,5,8,7,10,9,12,11,14,13,…… */
        cout << "input: 2,1,4,3,6,5,8,7,10,9,12,11,14,13,……\n\n";

        // quick-sort
        a.clear();
        for(int i = 1; i <= n/2; i++) {
            a.push_back(2*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(2*i-1);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => merge-sort need ";
        cout << Sort<int>::mergeSortInPlace(a.data(), 0, a.size() - 1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;


        /** 5,4,3,2,1,10,9,8,7,6,15,14,13,12,11,20,19,18,17,16,…. */
        cout << "\n\n input: 5,4,3,2,1,10,9,8,7,6,15,14,13,12,11,20,19,18,17,16,….\n\n";

        // quick-sort
        a.clear();
        for(int i = 1; i <= n/5; i++) {
            a.push_back(5*i);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-1);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-2);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-3);
            if(i < 10)
                cout << a.back() << " ";
            a.push_back(5*i-4);
            if(i < 10)
                cout << a.back() << " ";
        }
        cout << "\n => merge-sort need ";
        cout << Sort<int>::mergeSortInPlace(a.data(), 0, a.size() - 1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;


        /** k,k-1,k-2,…..1,2k,2k-1,2k-2,….k+1,3k,3k-1,3k-2,….2k+1,…… */
        cout << "\n\n input: k,k-1,k-2,…..1,2k,2k-1,2k-2,….k+1,3k,3k-1,3k-2,….2k+1,……\n\n";
        int k = 4;

        // quick-sort
        a.clear();
        for(int i = 1; i <= n / k; i++) {
            for(int j = 0; j < k; j++) {
                a.push_back(i*k-j);
                if(i<3)
                    cout << a.back() << " ";
            }
        }
        cout << "\n => merge-sort need ";
        cout << Sort<int>::mergeSortInPlace(a.data(), 0, a.size() - 1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;


        /** 1,4,5,7,2,3,8,9 */
        cout << "\n\n input: 1,4,5,7,2,3,8,9\n\n";

        // quick-sort
        a.clear();
        a.push_back(1); cout << a.back() << " ";
        a.push_back(4); cout << a.back() << " ";
        a.push_back(5); cout << a.back() << " ";
        a.push_back(7); cout << a.back() << " ";
        a.push_back(2); cout << a.back() << " ";
        a.push_back(3); cout << a.back() << " ";
        a.push_back(8); cout << a.back() << " ";
        a.push_back(9); cout << a.back() << " ";
        cout << "\n => merge-sort need ";
        cout << Sort<int>::mergeSortInPlace(a.data(), 0, a.size() - 1);
        cout << " steps => \n";
        for(int i = 0; i < 20 && i < n; i++)
            cout << a[i] << " ";
        cout << endl << endl;

    }
#endif






    return 0;
}
