#include "TSPSolutionCandidate.h"
#include "CodingHelper.h"
#include <iostream>

using namespace std;


TSPSolutionCandidate::TSPSolutionCandidate(std::string c) {
    unsigned int* a = CodingHelper::decodeList(c);
    size = a[0];
    mySolution = new unsigned int[size];
    for (size_t i = 0; i < size; i++) {
        mySolution[i] = a[i + 1];
    }
}

TSPSolutionCandidate::TSPSolutionCandidate(unsigned int size, unsigned int* sol) {
    this->size = size;
    mySolution = new unsigned int[size];
    for (size_t i = 0; i < size; i++) {
        mySolution[i] = sol[i];
    }
}

TSPSolutionCandidate::~TSPSolutionCandidate() {
    delete[] mySolution;
}



string TSPSolutionCandidate::getEncoding() {
    unsigned int* a = new unsigned int[size + 1];
    a[0] = size;
    for (size_t i = 0; i < size; i++) {
        a[i + 1] = mySolution[i];
    }
    string q = CodingHelper::encodeList(a);
    delete[] a;
    return q;
}

void TSPSolutionCandidate::print() {
    for (size_t i = 0; i < size; i++) {
        cout << mySolution[i] << "  ";
    }
    cout << endl;
}
