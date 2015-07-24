/*
give an integer array A, find out if there is a triplet index, i,j and k, which i<j<k and A[i]<A[j]<A[k]
*/
//linear time, without extra space
bool find3Numbers(int A[], int n){
   int first = INT_MAX;
   int second = INT_MAX;
   for(int i=0;i<n;++i){
       if(A[i]<=first) first = A[i];
       else if(A[i]<=second) second = A[i];
       else return true;
   }
   return false;
}
