//Lauren White - Project 2

#include "RadixSort.h"

//Radix Sort for strings with a max length of 5
void RadixSort(vector<string>& arr) 
{
    int max_chars = 4;
    int position;
    int index;
    int index2 = 0;

    //If the vector is empty, output a warning message and exit the function
    if (arr.empty())
    {
        cout << "Error: Word list is empty." << endl;
        return;
    }

    //Create queues for each character in the alphabet
    vector<queue<string>> queues(27);

    //Sort starting at the least significant character
    for (position = max_chars; position >= 0; position--)
    {
        index2 = 0;

        //Place numbers into respective queues based on the current character
        for (const string& word : arr) 
        {
            //If the current position is longer than the word, push it into the 0 queue
            index = (position < word.size() && isalpha(word[position])) ? (tolower(word[position]) - 'a' + 1) : 0; 
            //Suggested by Copilot to manage words less than 5 letters long
           
            queues[index].push(word);
        }

        //Collect words back from the queues
        for (auto& queue : queues) 
        {
            //While there are words in the queues
            while (!queue.empty()) 
            {
                //Add the words to the vector
                arr[index2++] = queue.front();
                queue.pop();
            }
        }
    }
}
