给 1 输出 1
  给 2 输出 11,12,21,22（4个数）
  给 3 输出 111,112,113,121,122,123,132,133,211,212,213,221,222,223,231,232,
233,311,312,313,321,322,323,331,332,333 (27个数)

void combination(int n, vector<int> &partial, vector<vector<int> > &res){
    if(partial.size()==n){
        res.push_back(partial);
    }else{
        for(int i=1;i<=n;++i){
            partial.push_back(i);
            combination(n, partial, res);
            partial.pop_back();
        }
    }
}
vector<vector<int> > combination(int n){
    vector<vector<int> > res;
    vector<int> partial;
    combination(n, partial, res);
    return res;
}
