//Lauren White - Project 2
#ifndef DICTIONARYREADER_H
#define DICTIONARYREADER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DictionaryReader 
{
public:
    DictionaryReader(const string& filePath);
    vector<string> getDictionary() const;

private:
    vector<string> dictionary;
    bool readFile(const string& filePath);
};

#endif