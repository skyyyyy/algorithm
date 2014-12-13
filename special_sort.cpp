
/*
Given an array which has n integers. It has both positive and negative integers.Now you need to sort this array in such a way
that,the negative integers should be in the front,and the positive integers should at the back.
Also the relative position should not be changed.
eg. -1 1 3 -2 2 ans: -1 -2 1 3 2.
*/

/*
Most of the answers here are either too complicated or are not O(N) running time and O(1) space complexities. 
Anything that shifts the elements to the right, uses memmove, or has a nested while loop inside a for loop will be O(N^2).

The way to do this is to first loop, count the negative values, then loop again and swap positive values 
with the next available open positive position as you iterate through the values. Code as follows:

*/

void SpecialSort(int* arr, int n)
{
    int negCount = 0;
    for (int i =0; i < n; ++i) {
        if (arr[i] < 0)
            negCount++;
    }

    int negIndex = 0;
    int posIndex = negCount;

    while (posIndex < n && negIndex < negCount) {
        if (arr[negIndex] < 0)
            negIndex++;
        else
            swap(arr[negIndex], arr[posIndex++]);
    }
}
