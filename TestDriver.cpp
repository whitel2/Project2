/*********************************************************************************
 * Test Driver for Task 1
 *
 * Tests the DictionaryReader class to read in the dictionary
 *
 * Author - Lauren White
 * Date - 4/5/25
 ********************************************************************************/

#include <iostream>
#include <string>
#include "DictionaryReader.h"

using namespace std;

int main() 
{
    string filename;

    //Get the dictionary file name to read in
    cout << "Enter the dictionary file name: ";
    getline(cin, filename);

    DictionaryReader dictionary(filename);
    vector<string> words = dictionary.getDictionary();

    //If there are no words in the dictionary vector, output an error message and exit the function
    if (words.empty()) 
    {
        cout << "Error: Dictionary file is empty." << endl;
        return 1;
    }

    //Output the words from the dictionary
    cout << "Words from the dictionary file:" << endl;
    for (const string& word : words) 
    {
        cout << word << endl;
    }

    /*
    //Visual Studios would not output the entire list, so I had CoPilot write a test to make sure the first 50 words were correctly processed
    cout << "First 50 words from " << filename << ":" << std::endl;

    size_t count = 0; // Counter for the number of words printed
    for (const string& word : words) {
        cout << word << endl;
        count++;

        if (count >= 50) { // Check if we've printed 50 words
            break; // Exit the loop
        }
    }*/

    return 0;
}