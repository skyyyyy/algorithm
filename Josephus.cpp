/*
Josephus problem is a classical game. The problem assume n persons in a circle, then start from the 1st person, 
we eliminate a person after skipping a fix number of persons. The process stops when there is only one person left.
We want to know the last person's index in the original circle.
For example, if n = 5 and k = 2, at the beginning, we have 1 2 3 4 5, then we eliminate 2 and 4, 
then we eliminate 1 and 5, so the last person's index is 3. So, F(5, 2) = 3

Try to get F(n, k)
*/
