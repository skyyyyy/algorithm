/*
Given an array [a1, a2, ..., an, b1, b2, ..., bn], transform it to 
[a1,b1, a2, b2, ..., an, bn].
Requirement: time complexity O(nlogn), space complexity O(logn)
Sol: the base idea is to use quicksort techniques. Suppose the current array
is A, whose size is 2k.
1. Divide A into four segments: A = [A1 A2 B1 B2], where A1.size = B1.size =
k / 2, B1.size = B2.size = k - k / 2;
2. Swap A2 and B1, and we get A = [A1 B1 A2 B2]. In this step, we actually 
need to rotate [A2 B1] to the right by k - k / 2 items. This can be done by 
reversing [A2 B1] first, and then reversing [A2] and [B1] respectively.
3. Recursive on [A1 B1] and [A2 B2] respectively.

Example: A = [1 2 3 4 5 6 7 8 9 10]
A1 = [1 2], A2 = [3 4 5], B1 = [6 7], B2 = [8 9 10]
After 2nd step, A = [1 2 | 6 7 | 3 4 5| 8 9 10]
For the 3rd step, process [1 2 6 7] and [3 4 5 8 9 10] repectively
*/
void special_swap(vector<int> &nums, int start, int end){
	if(end-start<2) return;
	int h = (end-start+1)/2; //half
	int h_h = (end-start+1)/4; //1/2 half
	reverse(nums,start+h_h,start+h_h+h-1);
	reverse(nums,start+h_h,start+h_h+h_h-1);
	reverse(nums,start+h_h+h_h,start+h_h+h-1);
	special_swap(nums,start,start+h_h+h_h-1);
	special_swap(nums,start+h_h+h_h,end);
}


void test_speical_swap(){
	int a[]={1,2,3,4,5,6,7,8,9,0};
	vector<int> nums; 
	nums.assign(a, a+sizeof(a)/sizeof(a[0]));
	special_swap(nums,0, nums.size()-1);
}
