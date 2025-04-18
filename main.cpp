// Haris Dedic - Main Program
#include <iostream>
#include "DictionaryReader.h"
#include "WordTransformer.h"
#include "RadixSort.h"

#include <vector>
#include <string>

// from Task-3
bool isSorted(const std::vector<std::string>& words);
std::vector<std::string> removeDuplicates(const std::vector<std::string>& words);

using namespace std;

// helper to print transformation path
void printPath(const vector<string>& path) {
    if (path.empty()) {
        cout << "No transformation path found.\n";
    }
    else {
        cout << "Transformation path (" << path.size() - 1 << " step(s)):\n";
        for (const string& word : path) {
            cout << word << "\n";
        }
    }
}

int main() {
    string filePath;
    cout << "Enter the name of the dictionary text file: ";
    getline(cin, filePath);

    // Step 1: Load dictionary from file
    DictionaryReader reader(filePath);
    vector<string> words = reader.getDictionary();

    if (words.empty()) {
        cout << "Exiting: Dictionary could not be loaded.\n";
        return 1;
    }

    // Step 2: Check if it's sorted; if not, sort it using RadixSort
    if (!isSorted(words)) {
        cout << "Dictionary is not sorted. Sorting using RadixSort...\n";
        RadixSort(words);
    }

    // Step 3: Remove duplicates
    words = removeDuplicates(words);

    // Step 4: Prompt for start and end words
    string startWord, endWord;
    cout << "Enter the start word: ";
    cin >> startWord;
    cout << "Enter the end word: ";
    cin >> endWord;

    // Step 5: Use WordTransformer with cleaned dictionary
    WordTransformer transformer(words);
    vector<string> result = transformer.findTransformPath(startWord, endWord);

    // Step 6: Print transformation path
    printPath(result);

    return 0;
}
