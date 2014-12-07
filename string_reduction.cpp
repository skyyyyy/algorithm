/*
Problem:  A string that only contains three types of letters :"a", "b", "c". Our goal is to reduce the string. 
If two different letters are adjacent to each other, we can reduce the two letters into another letter. 
The rule is like this: if we encounter "ab" (or "ba"), we reduce to "c";   if we encounter "bc" (or "cb"), 
we reduce to "a";  if we encounter "ca" (or "ac"), we reduce to "b". If two adjacent letters are the same, 
we can't reduce them. We need to find an optimal way to reduce the string as much as possible.

For example, for string "acbb", if we try to reduce "ac"first, we get "bbb". 
But, if we reduce "cb" first, we get "aab" and we can further make "aab" => "ac" => "b". 
The latter approach gives us an optimal reduction.

Solution: Here what really matters is the numbers of letter "a", "b" and "c". 
Let us name them as num_a, num_b and num_c. If two of them are zero, we can't reduce that string. 
Otherwise, we can reduce the string into a string that has a length of 1 or 2.
If num_a, num_b and num_c are all even or odd,  we can reduce to a string with length 2; 
If not, we can reduce to a string with length 1.

Then how to do the reduction? The detail is as follow:

1. if the string has a length of 3 and contains one "a", one "b" and one "c", whatever order of the three letter are in, 
we can only reduce the string into a string with length 2; if the string has a length of 2 and contains two different letters,
we can only reduce the string into a string with length 1. Let us regard these two cases as base cases.

2. for a general case, we have num_a "a" , num_b  "b" and num_c  "c". After every reduction, 
the sum of num_a, num_b and num_c will decrease by 1, since we substitue two letters with one letter.  

3. Then at each round, which two adjacent letters we choose to reduce? We try to find an adjacent pair that contains a letter
which has the highest count. For example, if now, we have 3 "a", 4 "b" and 6 "c" in the string, 
we choose an adjacent pair that contains "c"since num_c = max(num_a, num_b, num_c) .
Can we find such pair? definitely we can. If there are multiple such pairs, choose a random one. 
Then after we reduce this pair, num_c--, max(num_a, num_b, num_c) may decrease by 1, remain unchanged, or increase by 1. 
However, since max(num_a, num_b, num_c) is up-bounded by num_a + num_b + num_c. num_a + num_b + num_c is decreasing 
after every round, then max(num_a, num_b, num_c) will also decrease if we look at a long wrong. Therefore, 
by using our strategy,  max(num_a, num_b, num_c) will eventually decrease to 1, which means we are encounter the base cases
in step 1.

4. Then when the string will be reduced to a length of 1 and when to a length of 2? We observe
that is num_a, num_b and num_c are all even, then after one transformation, they will become all odd; similarly, 
if there are originally all odd, after one transformation, they will become all even. 
Then according to the analysis in step 3), we know at the end, the max(num_a, num_b, num_c) will eventually decrease to 1. 
But, they should still be all odd at that time (since "1" is odd). Therefore, at the very end, 
we will have num_a = 1, num_b = 1 and num_c =1, which will  eventually lead to a string of length 2. 
It is easy to prove that if num_a, num_b and num_c are  not all even or odd, the string will be reduced to length 1.

5. if num_a, num_b and num_c are  not all even or odd, there must be only two cases: a) two of the counters are odd 
and one is even b) two of the counters are even and one is odd.  For example, if num_b is odd, num_a and num_c are both even.
The string actually will eventually be reduced to  "b".

6. if num_a, num_b and num_c are all even or odd, there might be multiple different final forms.
*/



void checkl(deque<char> &d)
{
     deque<char>::iterator it;
     it=d.end()-1;
     while(d.size()>1)
     {
           //cout<<*it<<" it "<<*(it-1)<<"\n";
           if(((*it=='a')&& (*(it-1)=='b'))||((*it=='b')&& (*(it-1)=='a')))
           {                        
               d.pop_back();
               d.pop_back();
               d.push_back('c');
               //cout<<"1";
           }
           else if(((*it=='b')&& (*(it-1)=='c'))||((*it=='c')&& (*(it-1)=='b')))
           {                        
               d.pop_back();
               d.pop_back();
               d.push_back('a');
               //cout<<"2";
           }
           else if(((*it=='c')&& (*(it-1)=='a'))||((*it=='a')&& (*(it-1)=='c')))
           {                        
               d.pop_back();
               d.pop_back();
               d.push_back('b');
               //cout<<"3";
           }          
           else //if(*it==*(it-1))
           {
                return;
                //cout<<"equal";
           }
           --it;
     }
     //for(it=d.begin();it<d.end();it++)
     //cout<<*it<<" lend ";
     //cout<<"\n";
}
 
void checkr(deque<char> &d)
{
     deque<char>::iterator it;
     
     
     it=d.begin();
       
     while(d.size()>1)
     {
           //cout<<*it<<" it "<<*(it+1)<<"\n";
           if(((*it=='a')&& (*(it+1)=='b'))||((*it=='b')&& (*(it+1)=='a')))
           {                        
               d.pop_front();
               d.pop_front();
               d.push_front('c');
               //cout<<"1";
           }
           else if(((*it=='b')&& (*(it+1)=='c'))||((*it=='c')&& (*(it+1)=='b')))
           {                        
               d.pop_front();
               d.pop_front();
               d.push_front('a');
               //cout<<"2";
           }
           else if(((*it=='c')&& (*(it+1)=='a'))||((*it=='a')&& (*(it+1)=='c')))
           {                        
               d.pop_front();
               d.pop_front();
               d.push_front('b');
               //cout<<"3";
           }
           else //if(*it==*(it+1))
           return;
           ++it;
     }
     //for(it=d.begin();it<d.end();it++)
     //cout<<*it<<" rend ";
     //cout<<"\n";
}    
 
int main()
{
    deque<char> d;
    int i,l,r,min;
    string a;
    cin>>a;
    //cout<<d.size()<<"\n";
    min=a.length();
    for(i=0;i<a.length();i++)
    {
          //cout<<"a["<<i<<"]:\n";
          d.push_back(a[i]);
         
          l=i-1;
          while(l>=0)
          {
                     //cout<<l<<"mainl "<<a[l]<<"\n";
                     d.push_back(a[l]);
                     checkl(d);
                     l--;
          }
          r=i+1;
          while(r<a.length())
          {
                     //cout<<r<<" mainr "<<a[r]<<"\n";
                     d.push_front(a[r]);
                     checkr(d);
                     r++;
          }
         // cout<<d.size()<<"\n";
          if(d.size()<min)
          min=d.size();
          d.clear();
    }
    cout<<min;                
   
    system("pause");
    return 0;
}













*/
