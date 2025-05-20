#pragma once
#include "TSPSolutionCandidate.h"
#include "TSPInstance.h"
#include <string>

using namespace std;

class TSPSolver {

public:
    static string getSolution(const string& tsp);


private:
    static TSPSolutionCandidate* findSolution(const TSPInstance& tsp,
        unsigned int* solution,
        unsigned int numberOfNodesVisitedInSolution);
};

