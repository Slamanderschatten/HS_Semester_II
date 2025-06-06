//
// Created on 12.05.2025.
//

#include "_MAIN.h"
#include "E_VI/E_VI.h"
#include "E_VII/CodingHelper.h"
#include "E_VII/TSPInstance.h"
#include "E_VII/TSPSolver.h"




#define TASK 6
#define SUBTASK 2



int main() {
    using namespace hs_thi;
    using namespace std;


#if TASK == 6
#if SUBTASK == 1
    {
        string out;

        const size_t n = 20;
        int a[n] = {1,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
        intmax_t b = 6;
        const size_t solutionSize = 2;
        size_t solution[solutionSize] {1,2};
        cout << "is [";
        for(size_t s : solution)
            out.append(to_string(s)).append(",");
        out.pop_back();
        cout << out << "] a good solution for SOS problem list with searched result " << b << ": [";
        out.clear();
        for(size_t e : a)
            out.append(to_string(e)).append(",");
        out.pop_back();
        cout << out  << "] ?" << endl;
        if(E_VI::isGoodSolutionForSOS(n, a, b, solutionSize, solution))
            cout << " => yes ";
        else cout << " => no ";
        cout << "(calculated in lower then " << E_VI::timeOf_isGoodSolutionForSOS(n) +1 << " ticks)" << endl;
    }
#endif

#if SUBTASK == 2
    {
        const size_t n = 20;
        int a[n] = {1,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4};
        intmax_t b = 6;

        cout << "is there a solution for the SOS problem with the target " << b << " for the list [";
        string out;
        for(size_t e : a)
            out.append(to_string(e)).append(",");
        out.pop_back();
        cout << out << "] ?" << endl;

        if(E_VI::sos(n, a, b))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cout << "(calculated in lower then " << E_VI::timeOf_sos(n) +1 << " ticks)" << endl;

    }
#endif
#endif


#if TASK == 7

#if SUBTASK == 1
    {
        unsigned int a[6] = {5, 2, 1, 4, 8, 16};
        string encoded = CodingHelper::encodeList(a);
        cout << "[2, 1, 4, 8, 16] = " << encoded << " = [";
        string aOutS;
        unsigned int* aOut = CodingHelper::decodeList(encoded);
        for(int i = 1; i < aOut[0]+1; i++) {
            aOutS.append(to_string(aOut[i])).append(", ");
        }
        aOutS.pop_back();
        aOutS.pop_back();
        cout << aOutS << "]" << endl;
        delete aOut;


        unsigned int b[5] = {4, 1, 17, 54, 85};
        aOutS.clear();
        encoded = CodingHelper::encodeList(b);
        cout << "[1, 17, 54, 85] = " << encoded << " = [";
        aOut = CodingHelper::decodeList(encoded);
        for(int i = 1; i < aOut[0]+1; i++) {
            aOutS.append(to_string(aOut[i])).append(", ");
        }
        aOutS.pop_back();
        aOutS.pop_back();
        cout << aOutS << "]" << endl;
    }
#endif

#if SUBTASK == 2
    {
        const unsigned int h = numeric_limits<unsigned int>::max();
        auto* tspInstanceArray = new unsigned int[27] {26, 70,
                                                               0, 12, 19, h, 14,
                                                               12, 0, 13, 11, h,
                                                               19, 13, 0, 17, 8,
                                                               h, 11, 17, 0, 9,
                                                               14, h, 8, 9, 0
        };
        TSPInstance instance(CodingHelper::encodeList(tspInstanceArray));
        auto* tspInstanceArrayResult = CodingHelper::decodeList(instance.getEncoding());
        bool error = false;
        for(int i = 0; i < tspInstanceArray[0]+1; i++) {
            if(tspInstanceArray[i] != tspInstanceArrayResult[i]){
                error = true;
                break;
            }
        }
        error = error;
    }
#endif

#if SUBTASK == 3
    {
        const unsigned int h = numeric_limits<unsigned int>::max();
        /*auto* tspInstanceArray = new unsigned int[102] {101, 246,
                                                       h,   29,  20,  21,  16,  31,  100, 12,  4,   31,
                                                       29,  h,   15,  29,  28,  40,  72,  21,  29,  41,
                                                       20,  15,  h,   15,  14,  25,  81,  9,   23,  27,
                                                       21,  29,  15,  h,   4,   12,  92,  12,  25,  13,
                                                       16,  28,  14,  4,   h,   16,  94,  9,   20,  16,
                                                       31,  40,  25,  12,  16,  h,   95,  24,  36,  3,
                                                       100, 72,  81,  92,  94,  95,  h,   90,  101, 99,
                                                       12,  21,  9,   12,  9,   24,  90,  h,   15,  25,
                                                       4,   29,  23,  25,  20,  36,  101, 15,  h,   35,
                                                       31,  41,  27,  13,  16,  3,   99,  25,  35,  h
        };*/
        auto* tspInstanceArray = new unsigned int[102] {101, 246,
                                                        h,   h,  h,  h,  h,  h,  h, h,  h,   1,
                                                        h,   h,  h,  h,  h,  h,  h, h,  1,   h,
                                                        h,   h,  h,  h,  h,  h,  h, 1,  h,   h,
                                                        h,   h,  h,  h,  h,  h,  1, h,  h,   h,
                                                        h,   h,  h,  h,  h,  1,  h, h,  h,   h,
                                                        h,   h,  h,  h,  1,  h,  h, h,  h,   h,
                                                        h,   h,  h,  1,  h,  h,  h, h,  h,   h,
                                                        h,   h,  1,  h,  h,  h,  h, h,  h,   h,
                                                        h,   1,  h,  h,  h,  h,  h, h,  h,   h,
                                                        1,   h,  h,  h,  h,  h,  h, h,  h,   h
        };
        long long int c = 0;
        auto* tspInstanceArrayResult = CodingHelper::decodeList(TSPSolver::getSolution(CodingHelper::encodeList(tspInstanceArray), c));

        for(int i = 0; i < tspInstanceArrayResult[0]+1; i++) {
            cout << tspInstanceArrayResult[i] << " ";
        }
    }
#endif
#endif

}
