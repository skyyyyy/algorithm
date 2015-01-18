现在有一个数N，（0 < N < 10,000)，找到一个最小的正整数S：
满足
1）S的所有数字只有0或者1。
2）S能被N整除。

比如：
输入 25， 输出 100
输入 30， 输出 1110
输入 99， 输出 111111111111111111

思路：
例如n=7 取{1，10，100，1000，10000，100000} 他们对7的余数{1，3，2，6，4，5}，
只要从这个集合里面找出前几个数字相加可以等于7就可以了，
那几个余数对应的原来的数相加，就是符合要求的最小的数。比如说7是1+6对应原来的数字1+1000=1001。
再比如n=30，取{1，10，100，1000，10000，100000} 他们对7的余数{1，10，10，10，10，10}，
只要从这个集合里面找出前几个数字相加可以等于30就可以了，
那几个余数对应的原来的数相加，就是符合要求的最小的数。比如说30是10+10+10对应原来的数字10+100+1000=1110。


int zero_one_multiple(int k){
    vector<vector<int> > reminder;
    for(int i=1;; i *= 10){
        if(i%k==0) return i;
        vector<int> r_i;
        r_i.push_back(i);
        r_i.push_back(i%k);
        reminder.push_back(r_i);
        int size=reminder.size();
        for(int j=0;j<size-1;++j){
            vector<int> r = reminder[j];
            int sum = i%k+r.back();
            if(sum == k){
                int res = 0;
                for(int m=0;m<r.size()-1;++m){
                    res += r[m];
                }
                res += i;
                return res;
            }
            r.pop_back();
            r.push_back(i);
            r.push_back(sum);
            reminder.push_back(r);
        }
    }
}

