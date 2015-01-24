/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. 
If array is sorted in reverse order that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

//brute force, O(n^2)
int inversion_count(vector<int>& nums){
  int count = 0;
  for(int i=0;i<nums.size()-1;++i){
    for(int j=i+1;i<nums.size();++j)
       if(nums[i] > nums[j]) ++count;
  }
  return count;
}

//merge sort, O(nlgn)
int inversion_count(vector<int>& nums){
   vector<int> tmp = nums;
   return mergeSort(nums, tmp, 0, nums.size()-1);
}
int mergeSort(vector<int>& nums, vector<int>& tmp,int left, int right){
  int count = 0;
   if(right > left){
    int middle = left + (right-left)>>1;
    count += mergeSort(nums, tmp, left,middle);
    count += mergeSort(nums, tmp, middle+1,right);
    count += merge(nums,tmp,left,middle+1,right);
  }
  return count;
}
int merge(vector<int>& nums, vector<int> &tmp, int left, int middle, int right){
  int i=left,j=middle,k=left;
  int count = 0;
  while(i<middle && j<=right){
    if(nums[i] <= nums[j]){
      tmp[k++]=nums[i++];
    }else{
      tmp[k++]=nums[j++];
      count += middle-i;
    }
  }
  while(i<middle) tmp[k++] = nums[i++];
  while(j<=right) tmp[k++] = nums[j++];
  for(i=left;i<=right;++i) nums[i] = tmp[i];
  return count;
}








