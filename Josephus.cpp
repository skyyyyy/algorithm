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


//index starts from 1
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


時間O(n)，空間O(1)
設f(n)爲初始有n人時最後一個自殺的人的編號，那麼有如下遞推式：
1
f(n) = (f(n-1) + m) mod n
以n=5, m=3爲例，一開始有這麼5個人：
1
0 1 2 3 4
第一輪報數後2號死亡，圈子裏剩下來的人的編號是這些：
1
3 4 0 1
這裏把3號寫在最前面了，因爲輪到3開始報數。如果我們有辦法知道n=4時的答案，即初始圈子爲：
1
0 1 2 3
時的答案，那麼可以把n=4的初始圈子的所有數x變換成(x+3) mod 5，得到：
1
3 4 0 1
這個恰好就是n=5時第一輪結束後的圈子狀態，也就是說我們可以根據n=4的答案推出n=5時的答案。
手工演算一下就能發現n=z時的圈子第一輪結束後(即m-1號自殺後)的圈子狀態，可以由n=z-1的初始圈子施以變換x -> (x+m) mod z得到。
於是我們可以從n=1開始(此時的答案是0)，推出n=2的答案，再推出n=3，直到計算到所要求的n。
下面是C語言實現：

//index starts from 0
int f(int n, int m)
{
  int s = 0;
  for (int i = 2; i <= n; i++)
    s = (s + m) % i;
  return s;
}


時間O(log n)，空間O(log n)
換一個遞推思路，考慮報數過程又回到第0個人時會發生什麼。這時有floor(n/m)*m個人都已經報過數了，並且死了floor(n/m)人。之後一輪的報數會數過m個人，又會回到第0個人。
我們以n=8, m=3爲例看看會發生什麼。一開始：
0 1 2 3 4 5 6 7
floor(n/3)*3個人都報過數後：
0 1 x 3 4 x 6 7  (A)
即2號和5號死亡，接下來輪到6號開始報數。因爲還剩下6個人，我們設法做一個變換把編號都轉換到0~5：

2 3 x 4 5 x 0 1  (B)
            ___
(B)的答案等於規模縮小後的情況n'=6時最後一個人的編號s。然後根據s算出圈子狀態(A)的最後一個人的編號。
如果s在最後一個x後面(帶下劃線)，即s < n%m，那麼s2 = s-n%m+n；否則s2 = s-n%m+(s-n%m)/(m-1)；
注意如果n < m，那麼報數回到第一個人時還沒死過人。因爲子問題的規模沒有減小，所以上述方法不適用。
需要用之前時間複雜度O(n)的方法遞推。下面是C語言實現：

int rec(int n, int m)
{
  if (n == 1) return 0;
  if (n < m) return (rec(n - 1, m) + m) % n;
  int s = rec(n - n / m, m) - n % m;
  return s < 0 ? s + n : s + s / (m-1);
}
n每次變爲n * (m-1) / m，即以一個常數因子衰減到剛好小於m，然後換用線性複雜度的遞推算法，總的時間複雜度爲O(m + log_{m/(m-1)}{n/m})，如果把m看作常數的話就是O(log n)。程序中在子問題計算後還需要做一些處理，無法尾遞歸，所以空間複雜度也等於這個。
參考：
Time Improvement on Josephus Problem (2002) by Fatih Gelgi
http://stackoverflow.com/questions/4845260/josephus-for-large-n-facebook-hacker-cup
時間O(log n)，空間O(1)
三年前我還看到過一段更巧妙的代碼，具體寫法不可考了，當時盯着式子思考了好久呢。其等價的形式長這樣：

int kth(int n, int m, int k)
{
  if (m == 1) return n-1;
  for (k = k*m+m-1; k >= n; k = k-n+(k-n)/(m-1));
  return k;
}
這個函數解決了第二種問法的一個擴展問題，即第k個(從0數起)自殺的人的編號。如果取k = n-1那麼就得到了最後一個自殺的人的編號。
這個算法的思想是第k*m+m-1次報數的人就是第k個自殺的人，追蹤他之前每次報數的時刻來確定他的編號。
考慮n=5, m=3, k=5，一共有15次報數(每報m次數死一個人，一共有k+1個人要死，所以需要(k+1)*m次報數)，每一次報數的人的編號如下：

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
0 1 2 3 4 0 1 3 4 1  3  1  3  3  3
報到2、5、8、11、14的人自殺。
設第p次(從0數起)報數的人是y，令p = m*a+b (0 <= b < m)。
經過前p次報數，一共死了floor(p/m) = a人，圈子裏還剩下n-a人。
如果y本次報數後沒有自殺，那麼他下次報數是在圈子裏其他n-a人都報數之後，
也就是第q = p+n-a = n+(m-1)*a+b次報數。
這是後繼的計算式，逆用即可計算前驅。
由y本次報數後還存活知b < m-1，故a = floor((q-n)/(m-1))，
p = q-(n-a) = q-n+floor((q-n)/(m-1))。
我們要求第k個自殺的人，他是第k*m-1次報數後自殺的，用計算前驅的方式求出這個人之前一次報數是在什麼時候，不斷地重複這一過程，
直到知道他是第k' (0 <= k' < n)次報數的人，那麼k'就是這個人的編號。
