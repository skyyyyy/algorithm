
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

/*above function doesn't work for below case
int[] a = {1, -1, 3, -2, -4, 2};
法交换出的结果是
-2, -1, -4, 1, 3, 2, 

原有顺序木有保持.
*/

//here is nlog(n) approach
 public void oneZeroSort(int[] a) {
        int negCount = helper(a, 0, a.length - 1);
        for (int i = 0; i < a.length; i ++) {
            if (i < negCount) {
                a[i] = - Math.abs(a[i]);
            } else {
                a[i] = Math.abs(a[i]);
            }
        }
    }

    int helper(int[] a, int l, int r) {
        if (l >= r) return 0;

        int negCount = 0;
        for (int i = l; i <= r; i ++) {
            if (a[i] < 0) negCount ++;
        }

        int negIndex = l;
        int posIndex = l + negCount;
        boolean isSwitch = false;
        while (negIndex < l + negCount && posIndex <= r) {
            if (a[negIndex] > 0 && a[posIndex] < 0) {
                int tmp = a[negIndex];
                a[negIndex] = - a[posIndex];
                a[posIndex] = - tmp;
                posIndex ++;
                negIndex ++;
                isSwitch = true;
            } else {
                if (a[negIndex] < 0) negIndex++;
                if (a[posIndex] > 0) posIndex++;
            }
        }

        if (isSwitch) {
            helper(a, l, negCount - 1);
            helper(a, l + negCount, r);
        }

        return negCount;
    }
