#include "TSPInstance.h"
#include "TSPSolutionCandidate.h"
#include "CodingHelper.h"
#include "TSPSolver.h"
#include <iostream>


using namespace std;


string TSPSolver::getSolution(const string& tsp) {
    TSPInstance instance(tsp);

    unsigned int nodeSize = instance.getSize();

    unsigned int sequence[nodeSize+1];
    sequence[0] = nodeSize;
    for(size_t i = 0; i < nodeSize; i++)
        sequence[i+1] = i;

    if(checkEachSequence(instance.getMatrix(), sequence, instance.getMaxPathLength(), nodeSize))
        return CodingHelper::encodeList(sequence);
    else
        return ""s;
}


bool TSPSolver::checkEachSequence(unsigned int** matrix, unsigned int *sequence, unsigned int maxSum, unsigned int level)  {
    if(level == 1) {
        long long int sum = 0;
        int i = 1;
        for(; i < sequence[0]; i++) {
            sum += matrix[sequence[i]][sequence[i+1]];
        }
        sum += matrix[sequence[i]][sequence[1]];
        if(sum <= maxSum)
            return true;
    }
    else {
        if (checkEachSequence(matrix, sequence, maxSum, level - 1))
            return true;
        for (int i = 1; i < level; i++) {
            swap(sequence[i], sequence[level]);
            if (checkEachSequence(matrix, sequence, maxSum, level - 1))
                return true;
            swap(sequence[i], sequence[level]);
        }
    }
    return false;
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


