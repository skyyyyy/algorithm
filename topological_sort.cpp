/*
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A-->B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
Note
You can assume that there is at least one topological order in the graph.
Example
For graph as follow: 

0->1->4
0->2->4
0->2->5
0->3->4
0->3->5

The topological order can be:

[0, 1, 2, 3, 4, 5]

or

[0, 2, 3, 1, 5, 4]

or

....



Challenge
Can you do it in both BFS and DFS?
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
    
*/
typedef DirectedGraphNode gnode;
/*
bfs
*/
 
/*
dfs
*/
/**
 * @param graph: A list of Directed graph node
 * @return: Any topological order for the given graph.
 */
vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
    // write your code here
    unordered_set<gnode*> visited;
    stack<gnode*> s;
    for(int i=0;i<graph.size();++i){
         dfs(graph[i], visited, s);
    }
    vector<gnode*> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

void dfs(gnode* node, unordered_map<gnode*> &visited, stack<gnode*> &s){
     if(visisted.find(node)!=visited.end()) return;
     for(int i=0;i<node->neighbors.size();++i){
       dfs(node->neighbors[i], visited, s);
     }
     visited.insert(node);
     s.push(node);
}







