#include "TSPInstance.h"
#include "TSPSolutionCandidate.h"
#include "CodingHelper.h"
#include "TSPSolver.h"
#include <iostream>


using namespace std;


string TSPSolver::getSolution(const string& tsp) {
    TSPInstance instance(tsp);

    unsigned int nodeSize = instance.getSize();
    unsigned int maxPath = instance.getMaxPathLength();
    unsigned int** matrix = instance.getMatrix();

    unsigned int sequence[nodeSize+1];
    for(size_t i = 0; i < nodeSize; i++)
        sequence[i+1] = i;

    size_t sum = 0;
    for(int i = 2; i <= nodeSize; i++) {
        sum += matrix[sequence[i-1]][sequence[i]];
        if(sum > maxPath)
            break;
    }
    if(sum <= maxPath)
        return CodingHelper::encodeList(sequence);

    for (int i = 0; i < nodeSize - 1; ++i) {
        for (int j = 0; j < nodeSize - 1; ++j) {
            std::swap(sequence[j], sequence[j + 1]);

            sequence[0] = sequence[nodeSize];
        }
    }
}




/*
int main() {
    unsigned int distances[100] = {
        0,   29,  20,  21,  16,  31,  100, 12,  4,   31,
        29,  0,   15,  29,  28,  40,  72,  21,  29,  41,
        20,  15,  0,   15,  14,  25,  81,  9,   23,  27,
        21,  29,  15,  0,   4,   12,  92,  12,  25,  13,
        16,  28,  14,  4,   0,   16,  94,  9,   20,  16,
        31,  40,  25,  12,  16,  0,   95,  24,  36,  3,
        100, 72,  81,  92,  94,  95,  0,   90,  101, 99,
        12,  21,  9,   12,  9,   24,  90,  0,   15,  25,
        4,   29,  23,  25,  20,  36,  101, 15,  0,   35,
        31,  41,  27,  13,  16,  3,   99,  25,  35,  0
    };
    TSPInstance tsp = TSPInstance(10, distances, 246);
    string s = tsp.getEncoding();
    s = TSPSolver::getSolution(s);
    cout << s << endl;
}
*/


