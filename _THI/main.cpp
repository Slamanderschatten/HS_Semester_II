//
// Created on 12.05.2025.
//

#include "_MAIN.h"
#include "E_VI/E_VI.h"
#include "E_VII/CodingHelper.h"




#define TASK 7
#define SUBTASK 1



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
        unsigned int a[6] = {6, 2, 1, 4, 8, 16};
        string encoded = CodingHelper::encodeList(a, 5);
        cout << "[6, 2, 1, 4, 8, 16] = " << encoded << " = [";
        string aOutS;
        int aOutSize = 5;
        unsigned int* aOut = CodingHelper::decodeList(encoded, aOutSize);
        for(int i = 0; i < aOut[0]; i++) {
            aOutS.append(to_string(aOut[i])).append(", ");
        }
        aOutS.pop_back();
        aOutS.pop_back();
        cout << aOutS << "]" << endl;
        delete aOut;


        unsigned int b[5] = {5, 1, 17, 54, 85};
        aOutS.clear();
        encoded = CodingHelper::encodeList(b, 4);
        cout << "[5, 1, 17, 54, 85] = " << encoded << " = [";
        aOut = CodingHelper::decodeList(encoded, aOutSize);
        for(int i = 0; i < aOut[0]; i++) {
            aOutS.append(to_string(aOut[i])).append(", ");
        }
        aOutS.pop_back();
        aOutS.pop_back();
        cout << aOutS << "]" << endl;
    }
#endif

#if SUBTASK == 2
    {
    }
#endif
#endif

}
