//Lauren White - Project 2

#ifndef TRANSFORMWORD_H
#define TRANSFORMWORD_H

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

//Stores the result as a sequence of words and the number of steps
struct Result 
{
    vector<string> sequence;
    int steps;
};

class TransformWord
{
public:
    //Default constructor
    TransformWord(const vector<string>& dictionary) : dictionary(dictionary) {};
    Result OptimalSequence(const string& startWord, const string& targetWord);

private:
    vector<string> dictionary;
    bool isVisited(const string& word, const  vector<string>& visited);

};
#endif