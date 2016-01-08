/*
跳河问题。给一个0/1数组R代表一条河，0代表水，1代表石头。起始位置R[0]等于1，
初速度为1. 每一步可以选择以当前速度移动，或者当前速度加1再移动。只能停留在石
头上。问最少几步可以跳完整条河流。

给定数组为R=[1,1,1,0,1,1,0,0]，最少3步能过河：
第一步先提速到2，再跳到R[2]；
第二步先提速到3，再跳到R[5]；
第三步保持速度3，跳出数组范围，成功过河。

[1,1,1,0,1,1,1,1,0,0] shoud return 4.
*/

//recursive
int crossRiver(int A[], int n, int speed, int index){
    if(index >= n) return 0;
	else if(A[index] == 0) return n;
	return 1+min(crossRiver(A,n,speed,index+speed), crossRiver(A,n,speed+1,index+speed+1));
}

//DP
int crossRiver(int A[], int n){
  vector<vector<pair<int, int>>> dp(n);
  dp[0].push_back(make_pair(1, 1));
  int res = INT_MAX;
  for (int i = 0; i < n; ++i) {
        if (A[i] == 0) continue;
        vector<pair<int,int>>& dp_i = dp[i];
	for(int j=0;j<dp_i.size();++j){
	      pair<int,int>& pr = dp_i[j];
	      if (i + pr.first >= n){
	        res = min(pr.second, res);
	      } else if (A[i + pr.first] == 1) {
	        dp[i + pr.first].push_back(make_pair(pr.first, pr.second + 1));
	      }
	      if (i + pr.first + 1 >= n) {
	        res = min(pr.second, res);
	      } else if (A[i + pr.first + 1] == 1) {
	        dp[i + pr.first + 1].push_back(make_pair(pr.first + 1, pr.second + 1));
	      }
	}
  }
  return res;
}
