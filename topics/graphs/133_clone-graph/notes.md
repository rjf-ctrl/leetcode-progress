# 133. Clone Graph
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

--- 

## SOLN

IDEA:
Use DFS/BFS + HashMap

HashMap:
original node -> cloned node

Why?
1. Avoid cloning same node twice.
2. Handle cycles.
3. Return already-created clones instantly.

-----------------------------------------
DFS TEMPLATE
-----------------------------------------

unordered_map<Node*, Node*> mp;

Node* dfs(Node* node) {

    if(node == nullptr)
        return nullptr;

    // already cloned
    if(mp.count(node))
        return mp[node];

    // create clone
    Node* copy = new Node(node->val);

    // IMPORTANT:
    // store BEFORE recursion
    mp[node] = copy;

    // clone neighbours
    for(Node* nei : node->neighbors) {
        copy->neighbors.push_back(dfs(nei));
    }

    return copy;
}

Node* cloneGraph(Node* node) {
    return dfs(node);
}

-----------------------------------------
WHY STORE IN HASHMAP BEFORE DFS?
-----------------------------------------

Graph may contain cycles.

1 <----> 2

Without storing first:

dfs(1)
 -> dfs(2)
     -> dfs(1)
         -> dfs(2)
             ...

Infinite recursion.

Store clone immediately:

mp[node] = copy;

Now revisits return instantly.

-----------------------------------------
WHY USE 'new' ?
-----------------------------------------

WRONG:

Node copy=Node(node->val);
return &copy;

'copy' is a local stack variable.

Function ends
↓
copy destroyed
↓
pointer becomes invalid

This is called a DANGLING POINTER.

-----------------------------------------

CORRECT:

Node* copy = new Node(node->val);

'new' allocates memory on the heap.

Stack                     Heap
-----                     ----
copy  ------------->      Node(val)

Function returns
↓
stack variables disappear
↓
heap object still exists
↓
pointer remains valid

-----------------------------------------
COMPLEXITY
-----------------------------------------

Time  : O(V + E)

Space : O(V)

V = nodes
E = edges

Each node cloned once.
Each edge visited once.

-----------------------------------------
INTERVIEW ONE-LINER
-----------------------------------------

Clone each node once using DFS/BFS,
store (original -> clone) in a hashmap,
create clones using 'new',
store clone before recursion,
and recursively connect cloned neighbours.

BFS VERSION

```
class Solution {
public:
    unordered_map <int, Node*> OldtoNew;
    Node* bfs(Node *node){
        if(!node) return NULL;
        if(OldtoNew.find(node->val)!=OldtoNew.end()) return OldtoNew[node->val];

        Node * copy = new Node(node->val);
        OldtoNew[node->val]=copy;

        queue <Node*> q;
        q.push(node);

        while(!q.empty()){
            Node *current=q.front();
            q.pop();

            for(Node *x: current->neighbors){
                if(!OldtoNew.count(x->val)){
                    OldtoNew[x->val] = new Node(x->val);
                    q.push(x);
                }
                OldtoNew[current->val]->neighbors.push_back(OldtoNew[x->val]);
            }
        }

        return copy;
    }

    Node* cloneGraph(Node* node) {
        return bfs(node);
    }
};

```