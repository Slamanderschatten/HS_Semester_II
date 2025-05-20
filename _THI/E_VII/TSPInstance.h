#pragma once

#include "TSPSolutionCandidate.h"
#include <string>
#include "CodingHelper.h"
#include <cmath>

using namespace std;

/*
 * This class represents one instance of the traveling salesperson problem (TSP).
 */
class TSPInstance {

private:
    unsigned int nodeSize;           // number of nodes of the graph
    unsigned int** adjacencyMatrix;  // distance between nodes
    unsigned int maxPathLen;         // maximal length of a roundtrip through all nodes

public: 
    /*
     * Initializes a TSP-instance with the values that are
     * encoded in the given string. The string has to encode
     * a list of integers. Each integer has to be encoded in
     * a self delimiting form as prefix-code. The thus encoded
     * integers have to be given in the following order:
     * m, d(1,1), ..., d(1,m), d(2, 1), ..., d(2, m), ..., d(m, 1), ..., d(m, m), b
     * where m is the number of nodes of the graph, d(i,j) is the
     * distance between node i and j and b is the maximal 
     * allowed length of the round-trip.
     */
    explicit TSPInstance(const string& k);

    /*
     * Initializes a TSP-instance, where
     * size is the number of nodes in the graph,
     * adjMatrix encodes the adjancency-matrix of dimension size x size,
     *           where indices 0, ..., size - 1 endode the first line of the matrix
     *           indices size, ..., 2*size -1 deocde the second line and so on.
     * pathLen is the maximal allowed length for a round-trip.
     */
    TSPInstance(unsigned int size, unsigned int* adjMatrix, unsigned int pathLen);


    ~TSPInstance();

    /*
     * Returns a string-representation for this TSP-instance. The format of that
     * representation is the same as used in the constructor TSPInstance(string).
     */
    string getEncoding() const;

    /*
     * Returns true if and only if the given solution candidate is
     * syntactically correct and of correct size for this TSP-instance
     * and if the solution it encodes is correct for this TSP-instance.
     */
    bool isGoodSolution(const TSPSolutionCandidate& c) const;

    /*
     * Returns the number of nodes in this TSP-instance.
     */
    unsigned int getSize() const;

    /*
     * Returns the distance between the two given nodes.
     */
    unsigned int getDistance(unsigned int a, unsigned int b) const;

    /*
     * Returns the maximum length of an allowed round-trip for this
     * TSP-instance.
     */
    unsigned int getMaxPathLength() const;


private:
    TSPInstance();  // constructs an empty instance
};

