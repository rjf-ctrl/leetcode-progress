### Copy-Pastable Notes

#### LeetCode 127 - Word Ladder

**Pattern:** Implicit Graph + BFS Shortest Path

##### Problem Transformation

```text
Word          -> Node
1-char change -> Edge
Minimum transformations
            -> Shortest Path
            -> BFS
```

##### Intuition

The graph is not explicitly given.

For a word of length `L`:

* Try changing each position.
* For each position try all 26 characters.
* If the generated word exists in the dictionary, it is a valid neighbor.

##### BFS Logic

1. Store all words in an `unordered_set`.
2. If `endWord` is not present, return `0`.
3. Start BFS from `beginWord`.
4. Generate neighbors on the fly.
5. Remove a word from the set when discovered (acts as visited).
6. Perform level-order BFS.
7. Return the level when `endWord` is reached.

##### Neighbor Generation

```cpp
for each position i:
    for each character c from 'a' to 'z':
        replace word[i] with c
        if transformed word exists:
            valid neighbor
```

##### Complexity

```text
Time:  O(N * L * 26)
Space: O(N)
```

---

### Errors Made / Lessons Learned

#### 1. Explicit Graph Construction → TLE

Built:

```cpp
for(i)
    for(j)
        isNeighbour(...)
```

Complexity:

```text
O(N² * L)
```

For `N = 5000`, this becomes too slow.

**Fix:** Generate neighbors on demand (implicit graph).

---

#### 2. Forgot to Size Graph

Wrong:

```cpp
vector<vector<int>> graph;
graph[i].push_back(...)
```

Correct:

```cpp
vector<vector<int>> graph(wordList.size());
```

---

#### 3. Uninitialized begin/end Indices

```cpp
int begin, end;
```

If word not found:

```cpp
begin/end contain garbage
```

Always initialize:

```cpp
int begin = -1;
int end = -1;
```

---

#### 4. Using `vector.find()`

Wrong:

```cpp
wordList.find(beginWord)
```

`vector` has no member `find()`.

Correct:

```cpp
find(wordList.begin(), wordList.end(), beginWord)
```

---

#### 5. Not Marking Visited

Could revisit words:

```text
hit -> hot -> hit
```

Fix:

```cpp
words.erase(nextWord);
```

when first discovered.

---

#### 6. BFS Distance Increment Bug

Wrong:

```cpp
while(...)
{
    dist++;
}
```

or

```cpp
for(each node)
{
    dist++;
}
```

Distance should increase **per level**, not per node.

Correct:

```cpp
while(...)
{
    process one level
    dist++;
}
```

---

#### 7. Returning Wrong Distance

If checking during neighbor generation:

```cpp
if(next == endWord)
```

then return:

```cpp
dist + 1
```

because the neighbor belongs to the next level.

---

#### 8. Self-Neighbour Generation

Generated:

```cpp
hot -> hot
```

Fix:

```cpp
if(test == s) continue;
```

---

#### Key Takeaway

Whenever you see:

```text
Minimum steps
Minimum transformations
Shortest sequence
```

and the states are:

```text
Strings
Grid cells
Board states
Lock combinations
```

Think:

```text
Implicit Graph
      +
BFS Shortest Path
```


