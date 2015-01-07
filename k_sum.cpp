/*
The problem:
Given n distinct positive integers, integer k (k <= n) and a number target.
Find k numbers where sum is target. Calculate how many solutions there are?
Example 
Given [1,2,3,4], k=2, target=5. There are 2 solutions:
[1,4] and [2,3], return 2.
*/

//Solution 1: Recursion
   
void helper(vector<int> A,int k, int start,int target, int & ans) {
    if (k < 0 || target < 0) return;
   
    if (k == 0 && target == 0) {
        ans++;
        return;
    }
   
    for(int i = start; i <= A.size()-k; i++)
        helper(A, k-1, i+1, target - A[i], ans);
}

int solutionKSum_Rec(vector<int> A,int k,int target) {
    int ans = 0;
    helper(A, k, 0, target, ans);
    return ans;
}

/*
DP
map[i][j][t] denotes the number of ways to select, 
from first i elements, j elements whose sum equals to target
*/


int solutionKSum_dp(vector<int> A,int k,int target) {
    int n = A.size();
   
    vector<vector<vector<int>>> map(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));
   
    for(int i = 1; i <=n; i++) {
        if (A[i-1] <= target)
        { 
            for(int j = i; j <=n; j++)
               map[j][1][A[i-1]] = 1;
        }
    }
   
    for(int i = 1; i <= n; i++)
      //for(int j = min(i, k); j > 1; j--)
	  for(int j =2;j<= min(i, k); j++)
          for(int p = 1; p <= target; p++)
		  {
              map[i][j][p] = map[i-1][j][p];
              if (p-A[i-1] >=0)
                 map[i][j][p] += map[i-1][j-1][p-A[i-1]];
          }
     
    return map[n][k][target];
}
