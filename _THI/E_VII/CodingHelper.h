#pragma once
#include <string>
#include <limits>
#include <vector>

using namespace std;


/*
 * This class contains a number of static functions that can
 * be used to encode a list of natural numbers into one natural
 * number. The class uses strings as data-type to store big
 * natural numbers in binary encoding.
 */
class CodingHelper {


public:


    /*
     * Decodes the given string s into an array of natural numbers.
     * The first element of the array determines the 
     * number of remaining elements in the array.
     * 
     * For example, the method could return an array with the
     * content (3, 17, 4, 2). The first element states that there
     * are 3 content-elements in the array.
     * 
     * The method never returns for example (7, 3, 2), since the
     * first element of the array is 7, but the number of content-elements
     * is 2.
     * 
     * If the given string s is not formatted correctly (e.g. not
     * formatted using the encodeList method) this method returns NULL
     * 
     * This method is the counterpart of the method encode.
     */
    static unsigned int* decodeList(const string& s, int& size);


    /*
     * Encodes the array a in a string, where the method assumes
     * that the size of the array is reflected in the first element
     * (the element with index 0) of the array. (see comment to encode).
     * This method is the counterpart of the method decode.
     * 
     */
    static string encodeList(unsigned int* a, size_t aSize);



    /*
     * Decodes the given string, assuming it is a correct
     * encoding of a binary number with at most 32 Bits.
     * The behaviour ot the method is undefined for other inputs.
     */
    static unsigned int decodeNumber(const string &s);

    /*
     * Returns the binary representation of the given x
     * in a string.
     */
    static string encodeNumber(unsigned int x);

    /*
     * Returns a string consisting of x concatenated '1'.
     */
    static string getUnary(unsigned int x);

    /*
     * Returns the number of '1' that form a prefix
     * of the given string.
     */
    static unsigned int numberOfLeadingOnes(const string& s);


    /*
     * For strings that use only symbols from {0, 1}, where
     * each bit occurs only in a pair of two equal bits, this function
     * replaces each pair of consecutive equal bits with one bit
     * of the same value.
     *
     * Example: The function works on strings of the form 11110011
     * and returns 1101 for that example.
     *
     * The behaviour of the function is not defined on strings
     * that are not of the described form (paired equal consecutive bits).
     */
    static string removeDoubleEncoding(const string &s);

    /*
     * Builds a new string that doubles every character of the 
     * given one. If, for example, s = "101", this method
     * returns "110011".
     */
    static string getDoubleEncoding(const string &s);

    /*
     * Prints the content of the given array to the standard output.
     */
    static void printArray(const unsigned int* arr, size_t size);


//private:
    static string getPrefixCode1(unsigned int x);
    static string getPrefixCode2(unsigned int x);
    static int getLength(unsigned int x);
    static bool containsJust0And1(const string& s);
};

