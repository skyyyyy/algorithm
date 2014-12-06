/*
Josephus problem is a classical game. The problem assume n persons in a circle, then start from the 1st person, 
we eliminate a person after skipping a fix number of persons. The process stops when there is only one person left.
We want to know the last person's index in the original circle.
For example, if n = 5 and k = 2, at the beginning, we have 1 2 3 4 5, then we eliminate 2 and 4, 
then we eliminate 1 and 5, so the last person's index is 3. So, F(5, 2) = 3

Try to get F(n, k)
*/
structure LinkNode{
  int val;
  LinkNode* next;
  LinkNode(int x):val(x),next(NULL){}
};

int f(int n,int k){
  if(n<=0) return -1;
  if(n<=0) return -1;
  LinkNode* p1=new LinkNode(1);
  LinkNode* p2=p1;
  for(int i=2;i<=n;++i){
    LinkNode* p = new LinkNode(i);
    p2->next = p;
    p2 = p;
  }
  p2->next = p1;
  
  int i=0;
  while(true){
    LinkNode* next = p1->next;
    if(p1 == next){
      int val = p1->val;
      delete p1;
      return val;
    }else if(i==k%n){
      p1->next = next->next;
      delete next;
      i=1;
      p1 = p1->next;
    }else{
      ++i;
      p1 = next;
    }
  }
  return -1;
}
