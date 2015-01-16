In computer science and mathematics, the Josephus Problem (or Josephus permutation) is a theoretical problem. 
Following is the problem statement:

There are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle 
and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped 
and the next person is executed. The elimination proceeds around the circle 
(which is becoming smaller and smaller as the executed people are removed),
until only the last person remains, who is given freedom. Given the total number of persons n 
and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. 
The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. Firstly, the person at position 2 is killed, 
then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed.
So the person at position 3 survives.
If n = 7 and k = 3, then the safe position is 4. The persons at positions 3, 6, 2, 7, 5, 1 are killed in order, 
and person at position 4 survives.

The problem has following recursive structure.

  josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
  josephus(1, k) = 1
After the first person (kth from begining) is killed, n-1 persons are left.
So we call josephus(n – 1, k) to get the position with n-1 persons. But the position returned by josephus(n – 1, k) 
will consider the position starting from k%n + 1. So, we must make adjustments to the position returned by josephus(n – 1, k).

Following is simple recursive implementation of the Josephus problem. 
The implementation simply follows the recursive structure mentioned above.

#include <stdio.h>
 
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position 
       k%n + 1 as position 1 */
    return (josephus(n - 1, k) + k-1) % n + 1;
}
 
// Driver Program to test above function
int main()
{
  int n = 14;
  int k = 2;
  printf("The chosen place is %d", josephus(n, k));
  return 0;
}
Output:

  The chosen place is 13
Time Complexity: O(n)

The problem can also be solved in O(kLogn) time complexity which is a better solution for large n and small k. 
We will cover that solution in a separate post.
