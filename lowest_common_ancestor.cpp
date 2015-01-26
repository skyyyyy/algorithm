Lowest Common Ancestor in a Binary Tree 
Given a binary tree (not a binary search tree) and two values say n1 and n2, 
write a program to find the least common ancestor.

(Using Single Traversal)
The method 1 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree 
and without extra storage for path arrays.
The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) matches with root, 
then root is LCA (assuming that both keys are present). If root doesn’t match with any of the keys, 
we recur for left and right subtree. The node which has one key present in its left subtree and the other key present in right 
subtree is the LCA. If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

/* Program to find LCA of n1 and n2 using one traversal of Binary Tree */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// This function returns pointer to LCA of two given values n1 and n2.
// This function assumes that n1 and n2 are present in Binary Tree
struct Node *findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}

Time Complexity: Time complexity of the above solution is O(n) as the method does a simple tree traversal in bottom up fashion.
Note that the above method assumes that keys are present in Binary Tree. If one key is present and other is absent, then it returns the present key as LCA (Ideally should have returned NULL).
We can extend this method to handle all cases by passing two boolean variables v1 and v2. v1 is set as true when n1 is present in tree and v2 is set as true if n2 is present in tree.

/* Program to find LCA of n1 and n2 using one traversal of Binary Tree.
   It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <iostream>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int key;
};
 
// Utility function to create a new tree Node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
 
// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found
struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{
    // Base case
    if (root == NULL) return NULL;
 
    // If either n1 or n2 matches with root's key, report the presence
    // by setting v1 or v2 as true and return root (Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA)
    if (root->key == n1)
    {
        v1 = true;
        return root;
    }
    if (root->key == n2)
    {
        v2 = true;
        return root;
    }
 
    // Look for keys in left and right subtrees
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);
 
    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;
 
    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}
 
// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
    // Base Case
    if (root == NULL)
        return false;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->key == k || find(root->left, k) ||  find(root->right, k))
        return true;
 
    // Else return false
    return false;
}
 
// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
Node *findLCA(Node *root, int n1, int n2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;
 
    // Find lca of n1 and n2 using the technique discussed above
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
 
    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
 
    // Else return NULL
    return NULL;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    Node *lca =  findLCA(root, 4, 5);
    if (lca != NULL)
       cout << "LCA(4, 5) = " << lca->key;
    else
       cout << "Keys are not present ";
 
    lca =  findLCA(root, 4, 10);
    if (lca != NULL)
       cout << "\nLCA(4, 10) = " << lca->key;
    else
       cout << "\nKeys are not present ";
 
    return 0;
}


If we are given a BST where every node has parent pointer, then LCA can be easily determined by traversing up using parent 
pointer and printing the first intersecting node.

We can solve this problem using BST properties. We can recursively traverse the BST from root. 
The main idea of the solution is, while traversing from top to bottom, the first node n we encounter with value 
between n1 and n2, i.e., n1 < n < n2 or same as one of the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2). 
So just recursively traverse the BST in, if node's value is greater than both n1 and n2 then our LCA lies in left side of 
the node, if it's is smaller than both n1 and n2, then LCA lies on right side. Otherwise root is LCA 
(assuming that both n1 and n2 are present in BST)

/* Function to find LCA of n1 and n2. The function assumes that both
   n1 and n2 are present in BST */
struct node *lca(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
         // If both n1 and n2 are smaller than root, then LCA lies in left
        if (root->data > n1 && root->data > n2)
           root = root->left;
 
        // If both n1 and n2 are greater than root, then LCA lies in right
        else if (root->data < n1 && root->data < n2)
           root = root->right;
 
        else break;
    }
    return root;
}

//what if there is parent point for each node:
An easy solution:
As we trace the two paths from both nodes up to the root, eventually it will merge into one single path. 
The LCA is the exact first intersection node where both paths merged into a single path. 
An easy solution is to use a hash table which records visited nodes as we trace both paths up to the root. 
Once we reached the first node which is already marked as visited, we immediately return that node as the LCA.
Node *LCA(Node *root, Node *p, Node *q) {
  hash_set<Node *> visited;
  while (p || q) {
    if (p) {
      if (!visited.insert(p).second)
        return p; // insert p failed (p exists in the table)
      p = p->parent;
    }
    if (q) {
      if (!visited.insert(q).second)
        return q; // insert q failed (q exists in the table)
      q = q->parent;
    }
  }
  return NULL;
}
The run time complexity of this approach is O(h), where h is the tree’s height. 
The space complexity is also O(h), since it can mark at most 2h nodes.

The best solution:
A little creativity is needed here. Since we have the parent pointer, 
we could easily get the distance (height) of both nodes from the root. Once we knew both heights, 
we could subtract from one another and get the height’s difference (dh). 
If you observe carefully from the previous solution, the node which is closer to the root is 
always dh steps ahead of the deeper node. We could eliminate the need of marking visited nodes altogether. Why?

The reason is simple, if we advance the deeper node dh steps above, both nodes would be at the same depth. 
Then, we advance both nodes one level at a time. They would then eventually intersect at one node, 
which is the LCA of both nodes. If not, one of the node would eventually reach NULL (root’s parent), 
which we conclude that both nodes are not in the same tree. 
However, that part of code shouldn’t be reached, since the problem statement assumed that both nodes are in the same tree.
int getHeight(Node *p) {
  int height = 0;
  while (p) {
    height++;
    p = p->parent;
  }
  return height;
}
 
// As root->parent is NULL, we don't need to pass root in.
Node *LCA(Node *p, Node *q) {
  int h1 = getHeight(p);
  int h2 = getHeight(q);
  // swap both nodes in case p is deeper than q.
  if (h1 > h2) {
    swap(h1, h2);
    swap(p, q);
  }
  // invariant: h1 <= h2.
  int dh = h2 - h1;
  for (int h = 0; h < dh; h++)
    q = q->parent;
  while (p && q) {
    if (p == q) return p;
    p = p->parent;
    q = q->parent;
  }
  return NULL;  // p and q are not in the same tree
}

