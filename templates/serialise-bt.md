Assuming the **standard BFS (level-order)** approach used in LeetCode 297.

---

# Serialize (Tree → String)

### Logic

* If tree is empty, return empty string.
* Perform level order traversal.
* Store node values.
* For missing children, store `"N"` (null marker).
* Join everything with commas.

### Pseudocode

```text
SERIALIZE(root)

if root == NULL
    return ""

create empty queue
push root into queue

answer = ""

while queue is not empty

    node = queue.front()
    pop queue

    if node == NULL
        append "N," to answer
        continue

    append node.value + "," to answer

    push node.left into queue
    push node.right into queue

return answer
```

---

# Deserialize (String → Tree)

### Logic

* Split string by commas.
* First value is the root.
* Traverse level by level.
* For every node, assign:

  * next value → left child
  * next value → right child
* Skip `"N"` entries.

### Pseudocode

```text
DESERIALIZE(data)

if data is empty
    return NULL

split data by ',' into values

create root from values[0]

create queue
push root into queue

index = 1

while queue is not empty

    node = queue.front()
    pop queue

    // Left child
    if values[index] != "N"
        create left node
        node.left = left node
        push left node into queue

    index++

    // Right child
    if values[index] != "N"
        create right node
        node.right = right node
        push right node into queue

    index++

return root
```

---

## Mental Picture

Example tree

```text
        1
       / \
      2   3
         / \
        4   5
```

### Serialization

Queue evolution:

```text
[1]

Visit 1
Output: 1
Push 2,3

[2,3]

Visit 2
Output: 2
Push N,N

[3,N,N]

Visit 3
Output: 3
Push 4,5

[N,N,4,5]

Visit N
Output: N

Visit N
Output: N

Visit 4
Output: 4
Push N,N

Visit 5
Output: 5
Push N,N
```

Serialized string:

```text
1,2,3,N,N,4,5,N,N,N,N
```

### Deserialization

Read values in order:

```text
Root = 1

Queue = [1]

Take 1
Left = 2
Right = 3

Queue = [2,3]

Take 2
Left = N
Right = N

Queue = [3]

Take 3
Left = 4
Right = 5

Queue = [4,5]

Take 4
Left = N
Right = N

Take 5
Left = N
Right = N
```

The original tree is reconstructed exactly.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`
