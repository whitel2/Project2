/*********************************************************************************
 * Test Driver for Task 2
 * 
 * Tests the RadixSort method to sort words lexicographically
 *
 * Author - Lauren White
 * Date - 4/3/25
 ********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "RadixSort.h"

using namespace std;

int main()
{
    vector<string> words = { "apple", "banana", "pear", "peach", "berry", "apple" };
    RadixSort(words);

    cout << "Sorted: " << endl;
    for (string word : words)
    {
        cout << word << endl;
    }

    return 0;
}
