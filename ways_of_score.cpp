An atm can only dispense values of $1, $5, $20, and $50. Return the number 
of unique ways that a $ amount of X can be tendered.
($1, $5) is distinct from ($5, $1)

Input: 4 Output: 1
Input: 6 Output: 3
Input: 100 Output: 954515231698

//combination doens't contain the duplicate results, but permutations do, why?
int countCombination(){
    int k =6;
    vector<int> scores;
    scores.push_back(1);
    scores.push_back(5);
    scores.push_back(10);
    vector<int> combinations(k+1,0);
    combinations[0] = 1;
    for(int i=0;i<scores.size();++i){
        for(int j=scores[i]; j<=k; ++j){
            combinations[j] += combinations[j-scores[i]];
        }
    }
    
    vector<int> permutations(k+1,0);
    permutations[0] = 1;
    for(int i=0;i<=k;++i){
        for(int j=0;j<scores.size();++j){
            if(i>=scores[j]){
                permutations[i] += permutations[i-scores[j]];
            }
        }
    }
    return permutations.back();
}


