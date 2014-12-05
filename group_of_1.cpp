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
       if(r>0 && m[r-1][c]=='1' && g.find((r-1)*cols+c) == g.end() ){ g.insert((r-1)*cols+c); q.push((r-1)*cols+c);}
       if(r<rows-1 && m[r+1][c]=='1' && g.find((r+1)*cols+c) == g.end()){ g.insert((r+1)*cols+c);q.push((r+1)*cols+c);}
       if(c>0 && m[r][c-1]=='1' && g.find(r*cols+c-1) == g.end()){ g.insert(r*cols+c-1); q.push(r*cols+c-1);}
       if(c<cols-1 && m[r][c+1]=='1' && g.find(r*cols+c+1) == g.end()){g.insert(r*cols+c+1); q.push(r*cols+c+1);}
     }
     for(unordered_set<int>::iterator it=g.begin(); it!=g.end(); ++it)  h.erase(*it);
     
     ++num_group;
  }
  return num_group;
}


//solution 2: use dfs, change '1' to '2' for visisted node, if not allowed to change the value of the element, can resotre it 
//after find the number

int group_of_1_2(vector<vector<char>> &m){
  if(m.empty() || m[0].empty()) return 0;
  int rows=m.size();
  int cols =m[0].size();
  int num_group = 0;
  for(int i=0;i<rows;++i){
    for(int j=0;j<cols;++j){
      if(m[i][j] == '1'){
        group_of_1_dfs(m,i,j);
		    ++num_group;
      }
    }
  }
  return num_group;
}

void group_of_1_dfs(vector<vector<char>> &m, int i,int j){
    m[i][j] = '2';
	if(i>0 && m[i-1][j]=='1') group_of_1_dfs(m,i-1,j);
	if(i<m.size()-1 && m[i+1][j]=='1') group_of_1_dfs(m,i+1,j);
	if(j>0 && m[i][j-1]=='1') group_of_1_dfs(m,i,j-1);
	if(j<m[0].size()-1 && m[i][j+1]=='1') group_of_1_dfs(m,i,j+1);
}



