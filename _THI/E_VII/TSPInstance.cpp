#include "TSPInstance.h"
#include "CodingHelper.h"
#include <stdexcept>
#include <iostream>

using namespace std;


TSPInstance::TSPInstance(string k) : TSPInstance() {
    // bitte implementieren!
}


TSPInstance::TSPInstance(unsigned int size, unsigned int* adjMatrix, unsigned int pathLen) {
    nodeSize = size;
    maxPathLen = pathLen;
    size_t k = 0;
    adjacencyMatrix = new unsigned int* [nodeSize];
    for (size_t i = 0; i < nodeSize; i++) {
        adjacencyMatrix[i] = new unsigned int[nodeSize];
        for (size_t j = 0; j < nodeSize; j++) {
            adjacencyMatrix[i][j] = adjMatrix[k];
            k++;
        }
    }
}



TSPInstance::TSPInstance() {
    nodeSize = 0;
    adjacencyMatrix = NULL;
    maxPathLen = 0;
}


TSPInstance::~TSPInstance() {
    for (size_t i = 0; i < nodeSize; i++) {
        delete[] adjacencyMatrix[i];
    }
    delete[] adjacencyMatrix;
}




string TSPInstance::getEncoding() const {
    // bitte implementieren!
}



bool TSPInstance::isGoodSolution(const TSPSolutionCandidate& c) const {
    unsigned int sum = 0;
    for (size_t i = 0; i < c.size - 1; i++) {
        sum = sum + getDistance(c.mySolution[i], c.mySolution[i + 1]);
    }
    sum = sum + getDistance(c.mySolution[c.size - 1], c.mySolution[0]);
    return sum <= maxPathLen;
}

unsigned int TSPInstance::getSize() const {
    return nodeSize;
}

unsigned int TSPInstance::getMaxPathLength() const {
    return maxPathLen;
}


unsigned int TSPInstance::getDistance(unsigned int a, unsigned int b) const {
    if (a >= nodeSize || b >= nodeSize)
        throw new runtime_error("At least one node index is out of bounds.");
    return adjacencyMatrix[a][b];
}



