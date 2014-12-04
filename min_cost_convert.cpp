/*
Given an array A of positive integers. Convert it to a sorted array with minimum cost. The only valid operation are:
1) Decrement with cost = 1
2) Delete an element completely from the array with cost = value of element
 
For example:
Consider the array 4,3,5,6 . We can sort it by decrementing 4 and thus sorted array will be 3, 3, 5, 6.
Minimum cost is 1 for sorting in this case.
Consider the array 10,3,11,12. We can sort it by deleting 3 and thus sorted array will be 10, 11, 12.
Minimum cost is 3 for this case.
*/
/*
Solution: Here I give a O(N^2) solution by using DP. The key data structure we need is 
**dp[i] which records the minimum cost to covert a subarray a[0, i] into sorted array and the last element of 
the sorted array should be a[i].**  
For the example array a[] = {5,4,7,3}, dp[0] = 0, dp[1] = 1 (since we need to decrease "5" by 1), dp[2] = 1, dp[3] = 7. 
After we had filled up dp[], we need one more data structure: aggr[]. aggr[i] = a[0] + a[1] + ... + a[i]. 
Then the minmum cost to convert the whole array cost_min = min{dp[i] + aggr[N-1] - aggr[i]}. Here  "aggr[N-1] - aggr[i]" 
means the cost that we  delete all the elements with a subscript larger than i.

Then the key is to calculate dp[i]. There are several observations here:
1. if a[i] >=  a[j] (j<i),  we can construct a sorted array ended at a[i] by deleting a[j+1], a[j+2], ... , a[i-1] 
and then append a[i]. The cost of the resulting sorted array is dp[j] + the cost of deleting a[j+1], a[j+2], ... , a[i-1]. 
2. if a[i] < a[j], to have a[i] as the last element, we need to decrease a[j] by a[j] - a[i]. Moreover,  
we may not stop at a[j] and we need to keep look backward until we found a a[m] such that a[m] <= a[i], 
then the cost of the resulting sorted array is dp[m+1] + ∑(a[k] - a[i]) where m<k<j. 
3. To compute dp[i], we need to look at all the j such that  j<i, depending on a[j] and a[i], 
we need to calculate the cost based on step 1 or 2. Then the minmum cost we encounter is the value of dp[i].
*/

int min_cost_convert(const vector<int> &nums){
  if(nums.size() < 2) return 0;
  vector<int> agg(nums.size());
  agg[0] = nums[0];
  for(int i=1;i<nums.size();++i){
    agg[i] = agg[i-1]+nums[i]; 
  }
  
  vector<int> dp(nums.size(),0);
  for(int i=1;i<nums.size();++i){
      dp[i] = INT_MAX;
      for(int j=i-1;j>=0;--j){
          int cost_i=0;
          if(nums[j]<=nums[i]){
              cost_i = dp[j]+ agg[i-1]-agg[j];
          }else{
              cost_i = agg[i-1] - agg[j];
              while(nums[j]>nums[i]){
                  cost_i += nums[j]-nums[i];
                  --j;
              }
              cost_i += dp[j+1];
          }
          dp[i] = min(dp[i], cost_i);
      }
  }
  
  int min_cost = INT_MAX;
  for(int i=0;i<nums.size();++i) min_cost = min(min_cost, dp[i]+agg[nums.size()-1]-agg[i]);
  
  return min_cost;
}
















