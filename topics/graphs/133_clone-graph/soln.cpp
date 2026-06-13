#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
=========================================
LC 133 - Clone Graph
=========================================

Implement:

class Solution {
public:
    Node* cloneGraph(Node* node);
};

=========================================
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
    }

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map <int, Node*> OldtoNew;
    Node* dfs(Node *node){
        if(!node) return NULL;
        if(OldtoNew.find(node->val)!=OldtoNew.end()) return OldtoNew[node->val];

        Node * copy = new Node(node->val);
        OldtoNew[node->val]=copy;

        for(Node *x: node->neighbors){
            copy->neighbors.push_back(dfs(x));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};

bool areGraphsEqual(Node* a, Node* b) {

    if (!a && !b) return true;
    if (!a || !b) return false;

    unordered_map<Node*, Node*> mp;
    queue<pair<Node*, Node*>> q;

    q.push({a, b});
    mp[a] = b;

    while (!q.empty()) {

        auto [u, v] = q.front();
        q.pop();

        if (u == v)
            return false; // must be deep copy

        if (u->val != v->val)
            return false;

        if (u->neighbors.size() != v->neighbors.size())
            return false;

        for (size_t i = 0; i < u->neighbors.size(); i++) {

            Node* nu = u->neighbors[i];
            Node* nv = v->neighbors[i];

            if (!mp.count(nu)) {
                mp[nu] = nv;
                q.push({nu, nv});
            }
            else {
                if (mp[nu] != nv)
                    return false;
            }
        }
    }

    return true;
}

void runTest(string testName, Node* input) {

    Solution sol;

    Node* clone = sol.cloneGraph(input);

    bool pass = areGraphsEqual(input, clone);

    cout << testName << ": "
         << (pass ? "PASS" : "FAIL")
         << '\n';
}

int main() {

    /*
        Test 1

        1 --- 2
        |     |
        4 --- 3
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    runTest("Square Graph", n1);

    /*
        Test 2

        1
    */

    Node* single = new Node(1);

    runTest("Single Node", single);

    /*
        Test 3

        Empty Graph
    */

    runTest("Empty Graph", nullptr);

    /*
        Test 4

        1 <-> 2
    */

    Node* a = new Node(1);
    Node* b = new Node(2);

    a->neighbors = {b};
    b->neighbors = {a};

    runTest("Two Node Cycle", a);

    /*
        Test 5

        Self Loop

        1
        ^
        |
        ----
    */

    Node* self = new Node(1);
    self->neighbors = {self};

    runTest("Self Loop", self);

    return 0;
}