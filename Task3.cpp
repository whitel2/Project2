#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// check if words are sorted
// !!todo - fix this function
bool isSorted(const vector<string>& words) {
	for (size_t i = 1; i < words.size(); i++) {
		if (words[i] < words[i - 1]) {
			return false; // not sorted
		}
	}
	return true; // all good
}

// remove duplicates 
vector<string> removeDuplicates(const vector<string>& words) {
	if (!isSorted(words)) {
		cerr << "Error: The input list is not sorted!" << endl;
		return {}; // nope
	}

	vector<string> uniqueWords;
	if (words.empty()) return uniqueWords; // nothing to do here

	uniqueWords.push_back(words[0]); // first word stays
	for (size_t i = 1; i < words.size(); i++) {
		if (words[i] != words[i - 1]) { // only keep new words
			uniqueWords.push_back(words[i]);
		}
	}

	return uniqueWords;
}

vector<string> readWords(const string& filename) {
	ifstream file(filename);
	vector<string> words;
	string line, word;

	// error on unable to open?

	while (getline(file, line)) { // read words
		stringstream ss(line);
		while (getline(ss, word, ',')) { // they list will be separated by commas?
			words.push_back(word);
		}
	}

	return words;
}

void printWords(const vector<string>& words) {
	for (const string& word : words) {
		cout << word << endl;
	}
}

int main() {
	string filename;

	cout << "Enter the filename: ";
	cin >> filename; 

	vector<string> words = readWords(filename);

	if (words.empty()) { return 1; }

	vector<string> uniqueWords = removeDuplicates(words);

	if (!uniqueWords.empty()) { printWords(uniqueWords); } // magic

	return 0;
}