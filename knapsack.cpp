// Returns the maximum value that can be put in a knapsack of capacity W(weight limit)

//time:n^2, space:n^2
int knapsack(const vector<int> &vals, const vector<int> &weights, int weight_limit){
   vector<vector<int>> dp(vals.size()+1, vector<int>(weight_.imit+1,0));
   for(int i=1;i<=vals.size();++i){
     for(int j=1;j<=weight_limit;++j){
       dp[i][j] = d[i-1][j];
       if(weights[i-1] <= j){
         dp[i][j] = max(dp[i][j], vals[i-1]+dp[i-1][j-weights[i-1]]);
       }
     }
   }
   return dp.back().back();
}

//time:n^2, space:n
int knapsack2(const vector<int>& vals, const vector<int>& weights, int weight_limit){
   vector<int> dp(weight_limit+1,0);
   for(int i=1; i<=vals.size();++i){
      for(int j=weight_limit;j>=1;--j){
         if(j>=weights[i-1]){
            dp[j] = max(dp[j], vals[i-1]+dp[j-weights[i-1]]);
         }
      }
   }
   return dp.back();
}
