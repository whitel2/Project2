//Lauren White - Project 2

#include "RadixSort.h"
//Edit for strings/chars and add comments


void RadixSort(vector<int>& arr)
{
if (arr.empty()) return;

int max_num = *max_element(arr.begin(), arr.end());
int max_digits = static_cast<int>(log10(max_num) + 1);

vector<queue<int>> queues(10);

for (int digit = 0; digit < max_digits; digit++)
{
    //Place numbers into respective queues based on the current digit
    for (int num : arr)
    {
        int dig_val = (num / static_cast<int>(pow(10, digit))) % 10;
        queues[dig_val].push(num);
    }

    //Collect numbers back from the queues
    int index = 0;
    for (auto& queue : queues)
    {
        while (!queue.empty())
        {
            arr[index++] = queue.front();
            queue.pop();
        }
    }
}
}
