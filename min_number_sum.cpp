/*
Find the Minimum Set of Numbers That Sum to at least K

Problem: Given an array of integers, find a smallest subset (with minimum numbers of integers) 
that sum to at least K. For example, a[] = {2,-5,7,8,12, 4} and K = 13, then one of the minimum set can be {8, 12}.
*/

/*
the question is to find the minumber number of the subset
solution 1: sort in increasing order and caculate the sum from the end towards begin, once get the sum is at least K, find the number
            this takes O(nlgn)
solution 2: use partition 
    we introduce a selection based algorithm which on average costs O(n) but costs O(n^2) in the worst case. 
    The approach is similar to kth order-statistics. Randomly choose a pivot from the current array 
    and partition the array into, two parts p1 and p2: p1 contains integers which are smaller than the pivot; 
    p2 contains integers which are larger than or equal to the pivot.
    Check if pivot + sum(p2) == K, if so, we already find the answer; 
          if pivot + sum(p2) > K
               1)if sum(p2) <= K, we also find the answer; 
               2)if sum(p2) > K, we need to do further partition, but we just need to further partition p2;  
          if pivot + sum(p2) < K,  we need to do further partition, but we need to partition p1 instead 
              and the target value K is updated as K - pivot - sum(p2).
*/

int min_number_sum(vector<int>& nums, int k){
  return min_number_sum(nums,0, nums.size()-1,k);
}

int min_number_sum(vector<int> &nums, int start, int end, int k){
    int found = 0;
    while(start < end){
      int s = start;
      int e = end;
      int pivot = nums[s];
      while(s < e){
        while(s < e && nums[e]>=pivot) --e;
        if(s < e) swap(nums[s], nums[e]);
        while(s < e && nums[s]<pivot) ++s;
        if(s < e) swap(nums[s], nums[e]);
      }
      
      int sum = 0;
      for(int i=s;i<=end;++i) sum += nums[i];
      
      if(sum == k ) return end-s+1+found;
      else if(sum > k){
        if(sum-nums[s] <= k) return end-s+found;
        else{
          start = s+1;
        }
      }else{
         found += end-s+1;
         end = s-1;
         k -= sum;
      }
    }
    return -1;
}








