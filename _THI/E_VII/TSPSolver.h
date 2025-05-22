#pragma once
#include "TSPSolutionCandidate.h"
#include "TSPInstance.h"
#include <string>

using namespace std;

class TSPSolver {

public:
    static string getSolution(const string& tsp, long long int& c);
    static bool checkEachSequence(unsigned int **matrix, unsigned int* sequence, unsigned int maxSum, unsigned int level, long long int& c);


private:
    static TSPSolutionCandidate* findSolution(const TSPInstance& tsp,
        unsigned int* solution,
        unsigned int numberOfNodesVisitedInSolution);
};

