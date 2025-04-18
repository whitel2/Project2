//Haris Dedic - Project 2 - Word Transformer
#pragma once
#ifndef WORD_TRANSFORMER_H
#define WORD_TRANSFORMER_H

#include "DictionaryReader.h"
#include <string>
#include <vector>
#include <stack>

using namespace std;

class WordTransformer {
public:
	WordTransformer(const DictionaryReader& reader);
	// NEW constructor: initialize with cleaned dictionary
	WordTransformer(const vector<string>& cleanedDictionary);


	vector<string> findTransformPath(const string& startWord, const string& endWord);

private:
	vector<string> dictionary;

	bool isOneCharDifferent(const string& a, const string& b);
	int findIndex(const string& word/*, const vector<string>& vec*/);
	string identifyCharacterChange(const string& from, const string& to);
};

#endif // WORD_TRANSFORMER_H