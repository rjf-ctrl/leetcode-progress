### Copy-Pastable Notes

#### LeetCode 752 - Open the Lock

**Pattern:** Implicit Graph + BFS Shortest Path

##### Problem Transformation

```text
Lock Combination -> Node
Rotate Wheel     -> Edge

Minimum Turns
    ->
Shortest Path
    ->
BFS
```

##### Intuition

The graph is never explicitly built.

Each lock state:

```text
0000
0001
1234
9999
```

is a node.

From any state, we can rotate one wheel:

```text
+1
-1
```

creating up to:

```text
4 wheels × 2 directions = 8 neighbors
```

per state.

##### Standard BFS Approach

1. Start from `"0000"`.
2. Store deadends in a hash set.
3. Use a queue for BFS.
4. Use a visited set.
5. Generate all 8 neighboring combinations.
6. Process level by level.
7. Return the level when target is reached.

##### Neighbor Generation

For every wheel:

```cpp
digit -> (digit + 1) % 10
digit -> (digit + 9) % 10
```

Examples:

```text
0 -> 9
9 -> 0
```

```text
1234

2234
0234

1334
1134

1244
1224

1235
1233
```

##### Complexity

```text
States = 10000

Time:  O(10000)
Space: O(10000)
```

---

### Alternative Integer-Based BFS

Instead of storing:

```text
"1234"
```

store:

```text
1234
```

Use:

```cpp
vector<int> dist(10000);
```

where:

```cpp
dist[x]
```

stores the minimum turns required to reach state `x`.

##### Digit Extraction

```cpp
digit = (x / div) % 10;
```

Example:

```text
x = 1234
div = 10

digit = 3
```

##### Generate +1 Rotation

```cpp
v = (x/div + 1) * div + x % div;
```

Example:

```text
1234 -> 1244
```

##### Generate -1 Rotation

```cpp
v = (x/div - 1) * div + x % div;
```

Example:

```text
1234 -> 1224
```

##### Wrap Around

```text
9 -> 0
0 -> 9
```

handled mathematically without string operations.

##### Why Use This?

```text
Integer operations
<
String operations
```

More memory efficient and slightly faster while using the exact same BFS logic.

---

### Errors Made / Lessons Learned

#### 1. Character vs Integer Confusion

Wrong:

```cpp
combo[i] = turnLeft(curr[i]);
```

`curr[i]` is:

```cpp
'0'
```

which is ASCII:

```text
48
```

not digit:

```text
0
```

Result:

```text
'/' , '.', '-' ...
```

were generated instead of valid lock states.

Fix:

```cpp
int digit = curr[i] - '0';

combo[i] = turnLeft(digit) + '0';
```

---

#### 2. Wrong Helper Return Type

Wrong:

```cpp
char turnLeft(...)
```

Returning:

```cpp
9
```

produces:

```text
ASCII 9
```

not:

```text
'9'
```

Better:

```cpp
int turnLeft(...)
int turnRight(...)
```

and convert back using:

```cpp
+'0'
```

---

#### 3. Distance Incremented Before Processing Level

Wrong:

```cpp
turns++;

process level
```

This causes:

```text
0000
```

to appear as:

```text
1 move away from itself
```

Correct:

```cpp
process level
turns++
```

---

#### 4. Checking Target Using Visited Set

Wrong:

```cpp
if(visited.count(target))
```

BFS correctness comes from processing nodes.

Correct:

```cpp
if(curr == target)
```

after popping from queue.

---

#### 5. Forgot to Mark Start Visited

Must do:

```cpp
visited.insert("0000");
```

immediately after pushing.

Otherwise:

```text
0000 -> 1000 -> 0000
```

can revisit start.

---

#### 6. Deadend Start State

Need:

```cpp
if(dead.count("0000"))
    return -1;
```

before BFS.

---

#### 7. BFS Distance Rule

Distance represents:

```text
Levels
```

not:

```text
Nodes processed
```

Always use:

```cpp
int size = q.size();

for(size nodes)
    process level

distance++
```

---

### Key Takeaways

#### Implicit Graph Recognition

If the problem gives:

```text
Grid
Lock
String
Board State
Puzzle State
```

instead of:

```text
Vertices
Edges
Adjacency List
```

then think:

```text
State = Node
Move  = Edge
```

#### Shortest Path Recognition

If the problem asks:

```text
Minimum Turns
Minimum Moves
Minimum Operations
Minimum Transformations
```

then think:

```text
Unweighted Graph
       +
BFS Shortest Path
```

#### Open Lock Pattern

```text
Lock State
    ↓
Graph Node

Rotate Wheel
    ↓
Graph Edge

Minimum Turns
    ↓
BFS
```
```cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    vector<int> dist(10000, 10000);

    for(const auto& s: deadends) {
        dist[stoi(s)] = -1;
    }

    int t = stoi(target);

    dist[t] = 0;
    queue<int> q;
    q.push(t);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == 0) {
            return dist[0];
        }

        // permutations
        int div = 1;
        for(int i = 0; i < 4; ++i) {
            int digit = (x/div) % 10;
            int v;
            // +1
            if(digit < 9) {
                v = (x/div +1 )*div + x%div;
            } 
            else { /* 9 -> 0*/
                v = (x/div - 9)*div + x%div;
            }

            if(dist[v] > dist[x]+1) {
                dist[v] = dist[x]+1;
                q.push(v);
            }
            // -1
            if(digit > 0) {
                v = (x/div - 1)*div + x%div;
            } 
            else { /* 0 -> 9 */
                v = (x/div + 9)*div + x%div;
            }
            if(dist[v] > dist[x]+1) {
                dist[v] = dist[x]+1;
                q.push(v);
            }

            div *= 10;
        }

    }

    return -1;
        
    }
};
```
