#include "CodingHelper.h"
#include "TSPInstance.h"
#include <iostream>

using namespace std;


unsigned int* CodingHelper::decodeList(const string& s) {
    if (!containsJust0And1(s)) return NULL;
    size_t strLen = s.size();
    string t = string(s);
    int count = 0;
    while (t.size() > 0) {
        size_t i = t.find("0");
        t = t.substr(i + 1);
        string v = t.substr(0, i);
        unsigned int nSize = decodeNumber(v);
        if (t.size() < i + nSize)
            return NULL;
        t = t.substr(i + nSize);
        count++;
    }
    unsigned int* a = new unsigned int[count + 1];

    a[0] = count;
    int j = 1;
    t = string(s);
    while (t.size() > 0) {
        size_t i = t.find("0");
        t = t.substr(i + 1);
        string v = t.substr(0, i);
        unsigned int nSize = decodeNumber(v);
        t = t.substr(i);
        string w = t.substr(0, nSize);
        unsigned int k = decodeNumber(w);
        a[j] = k;
        j++;
        t = t.substr(nSize);
    }

    return a;
}



unsigned int* CodingHelper::decodeList(const string& s, int& outSize) {
    vector<unsigned int> values;
    /**
     * @brief
     * 0 => size size \n
     * 1 => size \n
     * 2 => value \n
     * 3 => decode value
     */
     outSize = 0;
    short area = 0;
    int sizeSize = 0;
    int size = 0;
    unsigned int value = 0;
    int i = 0;
    int pos = 0;
    for(char c : s) {
        pos++;
        switch(area) {
            case 1: //decode size
                if (i == 0) {
                    area++;
                    i = size;
                } else {
                    size = (size << 1) + (c - '0');
                    i--;
                    break;
                }

            case 2: // decode value
                if (i == 0)
                    area++;
                else {
                    value = (value << 1) + (c - '0');
                    i--;
                    break;
                }

                values.push_back(value);
                area = 0;
                sizeSize = 0;
                size = 0;
                value = 0;
                outSize++;

            case 0: // decode size of size
                if (c == '1')
                    sizeSize++;
                else {
                    area++;
                    i = sizeSize;
                }
                break;

            default:
                break;
        }
    }
    values.push_back(value);
    outSize++;
    auto* a = new unsigned int [outSize];
    memcpy(a, values.data(), outSize * sizeof(unsigned int));
    return a;
}


string CodingHelper::encodeList(const unsigned int* a, size_t aSize) {
    string compressed;
    int mask = numeric_limits<int>::min(); // only the first bit from the high site is 1
    for(size_t i = 0; i<=aSize; i++) {

        unsigned int value = a[i];
        string valueSerialized;
        int valueSize;
        string valueSizeSerialized;
        int valueSizeSize;
        string valueSizeSizeSerialized;

        //serialize value
        int j;
        for(j = sizeof(int) * 8; j > 0; j--){
            if((value & mask) != 0)
                break;
            value <<= 1;
        }
        valueSize = j;
        for(; j > 0; j--) {
            if(value & mask)
                valueSerialized += '1';
            else
                valueSerialized += '0';
            value <<=1;
        }

        //serialize value size
        for(j = sizeof(int) * 8; j > 0; j--){
            if((valueSize & mask) != 0)
                break;
            valueSize <<= 1;
        }
        valueSizeSize = j;
        for(; j > 0; j--) {
            if(valueSize & mask)
                valueSizeSerialized += '1';
            else
                valueSizeSerialized += '0';
            valueSize <<=1;
        }

        //serialize size of the value size
        for(j = 0; j < valueSizeSize; j++) {
            valueSizeSizeSerialized += '1';
        }
        valueSizeSizeSerialized += '0';

        if(i == aSize) {

        }
        compressed.append(valueSizeSizeSerialized).append(valueSizeSerialized).append(valueSerialized);
    }
    return compressed;
}


bool CodingHelper::containsJust0And1(const string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '0' && s[i] != '1')
            return false;
    }
    return true;
}




string CodingHelper::getPrefixCode1(unsigned int x) {
    int len = getLength(x);
    return getUnary(len) + "0" + encodeNumber(x);
}


string CodingHelper::getPrefixCode2(unsigned int x) {
    int len = getLength(x);
    int lenOfLen = getLength(len);
    return getUnary(lenOfLen) + "0" + encodeNumber(len) + encodeNumber(x);
}



int CodingHelper::getLength(unsigned int x) {
    if (x == 0) return 1;
    int count = 0;
    while (x != 0) {
        count++;
        x = x >> 1;
    }
    return count;
}



unsigned int CodingHelper::decodeNumber(const string& s) {
    unsigned int result = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != '0' && c != '1') return -1;
        if (c == '0') {
            result = result * 2;
        } else {
            result = result * 2 + 1;
        }
    }
    return result;
}

string CodingHelper::encodeNumber(unsigned int x) {
    if (x == 0) return string("0");
    string t = "";
    while (x > 0) {
        if (x % 2 == 0) {
            t = '0' + t;
        } else {
            t = '1' + t;
        }
        x = x / 2;
    }
    return t;
}

string CodingHelper::getUnary(unsigned int x) {
    string s = "";
    for (unsigned int i = 0; i < x; i++) {
        s += '1';
    }
    return s;
}





string CodingHelper::removeDoubleEncoding(const string& s) {
    if (s.size() % 2 != 0) return "";
    string t = "";
    for (int i = 0; i < s.size() / 2; i++) {
        t = t + s[i * 2];
    }
    return t;
}


string CodingHelper::getDoubleEncoding(const string& s) {
    string t = "";
    for (int i = 0; i < s.size(); i++) {
        t += s[i];
        t += s[i];
    }
    return t;
}

unsigned int CodingHelper::numberOfLeadingOnes(const string& s) {
    unsigned int i = 0;
    while (i < s.size() && s[i] == '1')
        i++;
    return i;
}


void CodingHelper::printArray(const unsigned int* arr, size_t size) {
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


/*
int main() {
    unsigned int* a = CodingHelper::decodeList("11101011101011011101");
    string s = CodingHelper::encodeList(a);
    cout << s << endl;

    unsigned int* b = new unsigned int[7]{6, 17, 5, 9, 2, 100, 3};
    string sb = CodingHelper::encodeList(b);
    cout << sb << endl;

    unsigned int* c = CodingHelper::decodeList(sb);

    for (int i = 0; i < 7; i++) {
        cout << c[i] << endl;
    }

    unsigned int h = 1000000;

    unsigned int* tspInstanceArray = new unsigned int[28] {27, 
        5, 
        0, 12, 19, h, 14,
        12, 0, 13, 11, h,
        19, 13, 0, 17, 8,
        h, 11, 17, 0, 9,
        14, h, 8, 9, 0,
        70
    };

    string tspInstanceString = CodingHelper::encodeList(tspInstanceArray);
    TSPInstance tspInstance = TSPInstance(tspInstanceString);


    return 0;
}
*/


