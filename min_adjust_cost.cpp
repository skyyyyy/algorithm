/*
Given an integer array, adjust each integers so that the difference of every adjcent integers are not greater than a given number target.

If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]| 

Note
You can assume each number in the array is a positive integer and not greater than 100

Example
Given [1,4,2,3] and target=1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal. Return 2.
*/
int myAdjust(vector<int> A, int target) { 

	int n = A.size(); 
	vector<vector<int>> dp(n,vector<int>(101,0));
	for(int i = 0; i < n; ++i) { 
		for(int j = 1; j <= 100; ++j) { 
			if(i == 0) { 
				dp[i][j] = abs(A[i] - j); 
			} else { 
				dp[i][j] = INT_MAX; // Some Max Value 
				for(int m = 1; m <= 100; ++m) { 
					if(abs(m - j) > target)	continue; 
					int diff = abs(A[i] - j) + dp[i - 1][m]; 
					dp[i][j] = min(dp[i][j], diff); 
				} 
			} 
		} 
	} 

	int minCost = dp[n - 1][1]; 
	for(int i = 2; i <= 100; ++i) { 
		minCost = min(minCost, dp[n - 1][i]); 
	} 
	return minCost; 
} 
