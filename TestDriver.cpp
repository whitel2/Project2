/*********************************************************************************
 * Test Driver for Task 2
 * 
 * Tests the RadixSort method to sort words lexicographically
 *
 * Author - Lauren White
 * Date - 4/3/25
 ********************************************************************************/

#include <iostream>
//#include <iomanip>
#include <string>
#include <vector>

#include "RadixSort.h"

using namespace std;

int main()
{
    vector<int> arr{ 170, 245, 315, 174, 326, 32, 17, 26 };
    RadixSort(arr);

    cout << "Sorted: " << endl;
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}
