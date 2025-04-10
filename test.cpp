// Haris Dedic - Project 2
#include <iostream>
#include "DictionaryReader.h"
#include "WordTransformer.h"

using namespace std;

void printPath(const vector<string>& path) {
    if (path.empty()) {
        cout << "No transformation path found.\n";
    }
    else {
        cout << "Transformation path:\n";
        for (const string& word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
}

int main() {
    string filePath;
    cout << "Enter the path to your dictionary text file (e.g., dictionary.txt): ";
    getline(cin, filePath);

    // Load dictionary
    DictionaryReader reader(filePath);
    vector<string> dict = reader.getDictionary();

    if (dict.empty()) {
        cout << "Exiting: Dictionary could not be loaded.\n";
        return 1;
    }

    // Prompt for start and end words
    string startWord, endWord;
    cout << "Enter the start word: ";
    cin >> startWord;
    cout << "Enter the end word: ";
    cin >> endWord;

    // Create transformer and get path
    WordTransformer transformer(reader);
    vector<string> result = transformer.findTransformPath(startWord, endWord);

    // Print result
    printPath(result);

    return 0;
}
