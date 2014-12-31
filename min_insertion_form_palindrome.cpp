#ifndef PALINDROME_H
#define PALINDROME_H
/*
Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

Before we go further, let us understand with few examples:
    ab: Number of insertions required is 1. bab
    aa: Number of insertions required is 0. aa
    abcd: Number of insertions required is 3. dcbabcd
    abcda: Number of insertions required is 2. 
	       adcbcda which is same as number of insertions in the substring bcd(Why?).
    abcde: Number of insertions required is 4. edcbabcde
*/

/*
analyse:  f(i,j)= str[i]==str[j]?f(i-1,j-1):min(f(i-1,j),f(i,j-1)+1;
*/

int minInsertion(string str, int s, int e){
	if(s>e) return INT_MAX;
	else if(s==e) return 0;
	else if(e==s+1) return str[s]==str[e]?0:1;
	if(str[s]==str[e]) return minInsertion(str,s+1,e-1);
	else return min(minInsertion(str,s+1,e),minInsertion(str,s,e-1))+1;
}

int minInsertion(string str){
	return minInsertion(str,0,str.length()-1);
}

/*
lots of overlapped subproblem, can use DP
define dp[i][j] as minimum insertion needed to from palindrome for str[i] to str[j],
dp[0][n-1] will be some result;
dp[i][j]:
  1. 0 if i==j
  2. j==i+1 0 if str[i]==str[j] otherwise 1
  3. min(dp[i][j-1],dp[i+1][j])+1
*/

int _minInsertion(string str){
	int n = str.length();
	vector<vector<int>> dp(n,vector<int>(n,n));
	for(int i=n-1;i>=0;--i){
		for(int j=i;j<n;++j){
			if(i==j)dp[i][j]=0;
			else if(j==i+1) dp[i][j]=(str[i]==str[j])?0:1;
			else if(str[i]==str[j]) dp[i][j]=dp[i+1][j-1];
			else dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
		}
	}
	return dp[0][n-1];
}

void test_minInsertion(){
	int res = minInsertion("ab"); //1
	res = minInsertion("aa");//0
	res = minInsertion("abcd");//3
	res = minInsertion("abcda");//2
	res = minInsertion("abcde");//4


	res = _minInsertion("ab"); //1
	res = _minInsertion("aa");//0
	res = _minInsertion("abcd");//3
	res = _minInsertion("abcda");//2
	res = _minInsertion("abcde");//4
}

#endif
