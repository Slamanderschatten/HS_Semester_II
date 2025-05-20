#pragma once

#include <string>

using namespace std;

class TSPSolutionCandidate {

public:
    unsigned int size;
    unsigned int* mySolution;

    TSPSolutionCandidate(std::string c);
    TSPSolutionCandidate(unsigned int size, unsigned int* sol);
    ~TSPSolutionCandidate();

    string getEncoding();
    void print();
};

