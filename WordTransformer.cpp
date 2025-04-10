// Haris Dedic - Project 2 - Word Transformer
#include "WordTransformer.h"
#include <iostream>

using namespace std;

// constructor — loads words from DictionaryReader into our own dictionary
WordTransformer::WordTransformer(const DictionaryReader& reader) {
    vector<string> rawDict = reader.getDictionary();
    dictionary.clear();

    // only keep non-empty words
    for (int i = 0; i < rawDict.size(); ++i) {
        if (!rawDict[i].empty()) {
            dictionary.push_back(rawDict[i]);
        }
    }

    // no words? big problem.
    if (dictionary.empty()) {
        cout << "Error: Dictionary is empty.\n";
    }
}

// helper — returns true if two words differ by just 1 character
bool WordTransformer::isOneCharDifferent(const string& a, const string& b) {
    if (a.length() != b.length()) return false;  // lengths gotta match

    int diff = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;  // more than 1 diff? nah
        }
    }
    return diff == 1;
}

// finds index of a word in the dictionary (brute-force style)
int WordTransformer::findIndex(const string& word) {
    for (int i = 0; i < dictionary.size(); ++i) {
        if (dictionary[i] == word) return i;
    }
    return -1;  // not found
}

// EXTRA CREDIT 2 -- NEEDS FIXING !!!
// helper method to identify and print the character change between two words
string WordTransformer::identifyCharacterChange(const string& from, const string& to) {
    for (int i = 0; i < from.length(); ++i) {
        if (from[i] != to[i]) {
            return string(1, from[i]) + " -> " + string(1, to[i]);
        }
    }
    return "";
}

// finds transformation path from start to end
vector<string> WordTransformer::findTransformPath(const string& start, const string& end) {
    vector<string> path;
    vector<string> changes; // vector to store char changes

    // basic sanity checks
    if (start.length() != end.length()) {
        cout << "Error: Start and end words must be the same length.\n";
        return path;
    }

    if (dictionary.empty()) {
        cout << "Error: Dictionary is empty.\n";
        return path;
    }

    // make sure both words are in the dictionary
    int startIndex = findIndex(start);
    int endIndex = findIndex(end);

    if (startIndex == -1) {
        dictionary.push_back(start);  // throw it in if missing
        startIndex = dictionary.size() - 1;
    }
    if (endIndex == -1) {
        dictionary.push_back(end);
        endIndex = dictionary.size() - 1;
    }

    // book-keeping
    vector<bool> visited(dictionary.size(), false);
    vector<int> parent(dictionary.size(), -1);

    vector<int> queue; 
    int frontIndex = 0;

    // start with the first word
    queue.push_back(startIndex);
    visited[startIndex] = true;

    // classic loop
    while (frontIndex < queue.size()) {
        int current = queue[frontIndex++];
        string currentWord = dictionary[current];

        // for debugging or slow runs — show progress
        cout << "Checking word: " << currentWord << endl;

        // check all possible next words
        for (int i = 0; i < dictionary.size(); ++i) {
            if (!visited[i] && isOneCharDifferent(currentWord, dictionary[i])) {
                visited[i] = true;
                parent[i] = current;
                queue.push_back(i);

                // identifying the char change between current word and next word - EC2
                string change = identifyCharacterChange(currentWord, dictionary[i]);
                if (!change.empty()) {
                    changes.push_back(change);
                }

                // found our destination!
                if (i == endIndex) {
                    stack<string> tempStack;
                    int trace = endIndex;

                    // backtrack through parents using a stack
                    while (trace != -1) {
                        tempStack.push(dictionary[trace]);
                        trace = parent[trace];
                    }

                    // build the actual path
                    while (!tempStack.empty()) {
                        path.push_back(tempStack.top());
                        tempStack.pop();
                    }

                    // EXTRA CREDIT 1
                    cout << "\nTransformation path found in " << (path.size() - 1) << " step(s).\n";
                    cout << "Transformation path: ";
                    for (const string& word : path) {
                        cout << word << " ";
                    }
                    cout << endl;

                    // EXTRA CREDIT 2 -- need to update and fix!!!!
                    cout << "Character changes: ";
                    for (const string& change : changes) {
                        cout << change << " ";
                    }
                    cout << endl;

                    return path;
                }
            }
        }
    }

    // if we got here, there's no path
    return path;
}
