// Haris Dedic - Task-3
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// checks if the list is sorted, because we need it sorted before deduplication
bool isSorted(const vector<string>& words) {
    for (size_t i = 1; i < words.size(); ++i) {
        if (words[i] < words[i - 1]) {
            return false;
        }
    }
    return true;
}

// removes duplicates from a sorted list, assumes input is already sorted
vector<string> removeDuplicates(const vector<string>& words) {
    if (words.empty()) return {}; // nothing to do if list is empty

    vector<string> uniqueWords;
    uniqueWords.push_back(words[0]); // always keep the first word

    for (size_t i = 1; i < words.size(); ++i) {
        if (words[i] != words[i - 1]) { // only add unique words
            uniqueWords.push_back(words[i]);
        }
    }
    return uniqueWords;
}

// reads words from a file, expecting them to be one word per line
vector<string> readWordsFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "error opening file!" << endl;
        return {};
    }

    vector<string> words;
    string word;
    while (getline(inputFile, word)) { // read one word per line
        words.push_back(word);
    }
    inputFile.close();
    return words;
}

// prints words, one per line
void printWords(const vector<string>& words) {
    for (const auto& w : words) {
        cout << w << "\n";
    }
}

int main() {
    string filename;
    cout << "enter the name of the text file: ";
    cin >> filename;

    vector<string> words = readWordsFromFile(filename);
    if (words.empty()) return 1; // exit if file is empty or error occurred

    if (!isSorted(words)) {
        cerr << "error: the input list is not sorted!" << endl;
        return 1;
    }

    printWords(removeDuplicates(words)); // deduplicate and print
    return 0;
}