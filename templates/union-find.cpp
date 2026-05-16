#include <iostream>
#include <vector>
using namespace std;

class DSU {  //DISJOINT SET UNION
private:
    vector<int> parent;
    vector<int> rank;

public:

    DSU(int n) {

        parent.resize(n);
        rank.resize(n, 0);

        // each node is its own parent initially
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int find(int x) {

        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    // Union by rank
    void unite(int a, int b) {

        int pa = find(a);
        int pb = find(b);

        // already connected
        if (pa == pb)
            return;

        // smaller rank attaches to larger rank
        if (rank[pa] < rank[pb]) {
            parent[pa] = pb;
        }
        else if (rank[pb] < rank[pa]) {
            parent[pb] = pa;
        }
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {

    DSU dsu(10);

    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(4, 5);

    cout << "1 and 3 connected? ";
    cout << dsu.connected(1, 3) << endl;

    cout << "1 and 5 connected? ";
    cout << dsu.connected(1, 5) << endl;

    dsu.unite(3, 5);

    cout << "After union(3,5):" << endl;

    cout << "1 and 5 connected? ";
    cout << dsu.connected(1, 5) << endl;

    return 0;
}