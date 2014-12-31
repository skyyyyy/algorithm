/*
给定一个数字数组 ,其中每个元素是从末端数小于原数组中该元素的个数。求原数组。
原数组中元素是 从1到n。Example:
Count array 3, 0, 1, 0
原数组:4, 1, 3, 2
idea: length of count array is 4, we should have 1,2,3,4
how to get the order?starting from first item in count array:
first count is 3, so first number in original array is 4th number; remove 4 from original array we get 1,2,3
second count is 0, so second number in original array is first number, which is 1; remove 1, we get 2,3
third count is 1, so third number in original array is second number which is 3; remove 3, we get 2
fourth number is 0, so fourth number in original array is first number which is 2; finally we get 4,1,3,2
*/
/*
solution 1:
1)build an original array in increasing order
2)iterate count array, use value in count array as index in original array to get the corresponding value
3)put that value to result in current index, in the mean time, remove that value from original array
time complexity: O(n^2) since erase takes o(n) time.
space complexity: O(n)
*/
vector<int> findOriginalArray(vector<int> &counts){
	int n = counts.size();
	vector<int> arr(n);
	vector<int> res(n);
	for(int i=1;i<=n;++i) arr[i-1]=i;
	for(int i=0;i<n;++i){
		res[i] = arr[counts[i]];
		arr.erase(arr.begin()+counts[i]);
	}
	return res;
}

/*
solution 2: construct a segment tree so we can erase the element from array in log(n) time
so the entire time complexity becomes O(nlogn)
*/
struct StNode{
	int start, end;
	int cover;
	StNode* left, *right;
	StNode(int s,int e):start(s),end(e),left(NULL),right(NULL){}
};

StNode* constructSt(int s, int e){
	StNode* node = new StNode(s,e);
	if(s==e){
		node->cover = 1;
	}else{
		int m = s+(e-s)/2;
		node->left = constructSt(s,m);
		node->right = constructSt(m+1,e);
		node->cover = node->left->cover+node->right->cover;
	}
	return node;
}
int query(StNode* node, int k){
	if(node->start == node->end) return node->start;
	else{
		if(node->left->cover>=k) return query(node->left,k);
		else return query(node->right,k-node->left->cover);
	}
}

void del(StNode* node, int num){
	if(node && node->start<=num && node->end>=num){
		node->cover--;
		del(node->left,num);
		del(node->right,num);
	}
}

vector<int> _findOriginalArray(vector<int> &counts){
	int n = counts.size();
	vector<int> res(n);
	StNode* root = constructSt(1,n);
	for(int i=0;i<n;++i){
		res[i]=query(root,counts[i]+1);
		del(root,res[i]);
	}
	return res;
}

void test_countarray(){
	//int a[]={3, 0, 1, 0}; //4,1,3,2
	int a[]={2,3,1,0,1,0}; //3,5,2,1,6,4
	vector<int> A;
	A.assign(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> res= findOriginalArray(A);
	res = _findOriginalArray(A);
}
