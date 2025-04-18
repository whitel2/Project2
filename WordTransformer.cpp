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

// NEW constructor: accepts a pre-cleaned dictionary vector
WordTransformer::WordTransformer(const vector<string>& cleanedDictionary) {
    dictionary.clear();

    for (const string& word : cleanedDictionary) {
        if (!word.empty()) {
            dictionary.push_back(word);
        }
    }

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

// EXTRA CREDIT 2
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
        dictionary.push_back(start);
        startIndex = dictionary.size() - 1;
    }
    if (endIndex == -1) {
        dictionary.push_back(end);
        endIndex = dictionary.size() - 1;
    }

    // BFS setup
    vector<bool> visited(dictionary.size(), false);
    vector<int> parent(dictionary.size(), -1);
    vector<int> queue;
    int frontIndex = 0;

    queue.push_back(startIndex);
    visited[startIndex] = true;

    while (frontIndex < queue.size()) {
        int current = queue[frontIndex++];
        string currentWord = dictionary[current];

        for (int i = 0; i < dictionary.size(); ++i) {
            if (!visited[i] && isOneCharDifferent(currentWord, dictionary[i])) {
                visited[i] = true;
                parent[i] = current;
                queue.push_back(i);

                if (i == endIndex) {
                    // Backtrack path
                    stack<string> tempStack;
                    int trace = endIndex;
                    while (trace != -1) {
                        tempStack.push(dictionary[trace]);
                        trace = parent[trace];
                    }

                    // Build path
                    while (!tempStack.empty()) {
                        path.push_back(tempStack.top());
                        tempStack.pop();
                    }

                    // Output
                    cout << "\nTransformation path found in " << (path.size() - 1) << " step(s).\n";
                    cout << "Transformation path: ";
                    for (const string& word : path) {
                        cout << word << " ";
                    }
                    cout << endl;

                    // Compute character changes
                    cout << "Character changes: ";
                    for (size_t j = 0; j + 1 < path.size(); ++j) {
                        cout << identifyCharacterChange(path[j], path[j + 1]) << " ";
                    }
                    cout << endl;

                    return path;
                }
            }
        }
    }

    // No path found
    return path;
}

