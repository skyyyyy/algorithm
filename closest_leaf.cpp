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
    vector<TreeNode*> ancestor;
    findAncestor(root, target, ancestor);
    for(int i=0;i<ancestor.size();++i){
        min_dist = min(min_dist,i+minDistToLeaf(ancestor[i]));
    }
    return min_dist;
}
bool findAncestor(TreeNode* root, TreeNode* target, vector<TreeNode*> &ancestor){
     if(!root) return false;
     if(root == target){
       ancestor.push_back(root);
       return true;
     }
     if(findAncestor(root->left, target, ancestor) || 
        findAncestor(root->right, target, ancestor)){
         ancestor.push_back(root);
         return true;
     }
     return false;
}
int minDistToLeaf(TreeNode* root){
    if(!root) return INT_MAX;
    int res = 0;
    if(root->left || root->right){
        res = 1 +min(minDistToLeaf(root->left),minDistToLeaf(root->right));          
    } 
    return res;
}








