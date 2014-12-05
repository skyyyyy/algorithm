/*
Find the Number of Groups of "1" in a Matrix
Problem: Given a matrix, each cell of the matrix is either "1" or "0". Consider that all the adjacent "1" form a group,
find out how many such groups are in the matrix.  By"adjacent",  we mean a cell's left, right, up and down. 
The diagonal is not considered as "adjacent". For example, if we have a matrix as follow:

1 0 0 1
1 1 0 1
0 1 1 1
1 0 0 0

then the output will be 2. There are two groups of "1" here.
*/

int group_of_1(const vector<vector<char>> &m){
  if(m.empty() || m[0].empty()) return 0;
  int rows=m.size();
  int cols =m[0].size();
  int num_group = 0;
  unordered_set<int> h;
  for(int i=0;i<rows;++i){
    for(int j=0;j<cols;++j){
      if(m[i][j] == '1'){
        h.insert(i*cols+j);
      }
    }
  }
  while(!h.empty()){
     int val=*h.begin();
     unordered_set<int> g;
     g.insert(val);
     queue<int> q;
     q.push(val);
     while(!q.empty()){
       int k = q.front();
       q.pop();
       int r = k/cols;
       int c = k%col;
       if(r>0 && g.find((r-1)*cols+c) == g.end() ){ g.insert((r-1)*cols+c); q.push((r-1)*cols+c);}
       if(r<rows-1 && g.find((r+1)*cols+c) == g.end()){ g.insert((r+1)*cols+c);q.push((r+1)*cols+c);}
       if(c>0 && g.find(r*cols+c-1)) == g.end()){ g.insert(r*cols+c-1); q.push(r*cols+c-1);}
       if(c<cols-1 && g.find(r*cols+c+1) == g.end()){g.insert(r*cols+c+1); q.push(r*cols+c+1);}
     }
     for(unordered_set::iterator it=g.begin(); it!=g.end(); ++it)  h.erase(*it);
     
     ++num_group;
  }
  return num_group;
}
