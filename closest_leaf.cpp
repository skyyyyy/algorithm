Given a Binary Tree and a key ‘k’, find distance of the closest leaf from ‘k’.

Examples:

              A
            /    \    
           B       C
                 /   \  
                E     F   
               /       \
              G         H
             / \       /
            I   J     K

Closest leaf to 'H' is 'K', so distance is 1 for 'H'
Closest leaf to 'C' is 'B', so distance is 2 for 'C'
Closest leaf to 'E' is either 'I' or 'J', so distance is 2 for 'E' 
Closest leaf to 'B' is 'B' itself, so distance is 0 for 'B' 

int closestLeaf(TreeNode* root, TreeNode* target){
    int min_dist = INT_MAX;
    minDistToLeaf(root, target,min_dist);
    return min_dist;
}
int minDistToLeaf(TreeNode* root, TreeNode* target, int &min_dist){
    if(!root) return INT_MAX;
    int res = 0;
    if(root->left || root->right) res = 1 +min(minDistToLeaf(root->left, target,min_dist),minDistToLeaf(root->right,target,min_dist));
    /*
    if(!root->left && !root->right) res=0;
    else if(root->left && !root->right) res = 1 + minDistToLeaf(root->left,target,min_dist);
    else if(root->right && !root->left) res = 1 + minDistToLeaf(root->right, target, min_dist);
    else res = 1 +min(minDistToLeaf(root->left, target,min_dist),minDistToLeaf(root->right,target,min_dist));
    */
    if(target == root) min_dist = min(min_dist, res);
    else if(target == root->left || target==root->right) min_dist=min(min_dist,res+1);
    return res;
}
