/*
give an integer array A, find out if there is a triplet index, i,j and k, which i<j<k and A[i]<A[j]<A[k]
*/
//linear time, without extra space
bool find3Numbers(int A[], int n){
   int first = INT_MIN;
   int second = INT_MIN;
   for(int i=0;i<n;++i){
       if(A[i]<=first) first = A[i];
       else if(A[i]<=second) second = A[i];
       else return true;
   }
   return false;
}
