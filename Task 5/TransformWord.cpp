//Lauren White - Project 2

#include "TransformWord.h"
//#include "RadixSort.h"
//#include "RemoveDuplicates.h"

TransformWord::TransformWord(const vector<string>& dictionary) : dictionary(dictionary) {}

//Transform method used to get from one word to another, changing 1 letter at a time
Result TransformWord::OptimalSequence(const string& startWord, const string& targetWord) {
    queue<vector<string>> paths;
    vector<string> visited;

    paths.push({ startWord });
    visited.push_back(startWord);

    while (!paths.empty()) {
        vector<string> currentPath = paths.front();
        paths.pop();

        string currentWord = currentPath.back();

        if (currentWord == targetWord) {
            Result result;
            result.sequence = currentPath;
            result.steps = currentPath.size() - 1;
            return result; // Found path
        }

        // Use the external findTransformations function
        //adjust based on the output of part 4 code
        vector<string> transformations = findTransformations(currentWord, dictionary);

        for (const string& nextWord : transformations) {
            if (!isVisited(nextWord, visited)) {
                vector<string> newPath = currentPath;
                newPath.push_back(nextWord);
                paths.push(newPath);
                visited.push_back(nextWord);
            }
        }
    }

    Result solution;
    solution.steps = 0;
    return solution; // No solution found
}

//Checks if the word has been used before
bool TransformWord::isVisited(const string& word, const vector<string>& visited) {
    for (const string& visitedWord : visited) {
        if (visitedWord == word) {
            return true;
        }
    }
    return false;
}