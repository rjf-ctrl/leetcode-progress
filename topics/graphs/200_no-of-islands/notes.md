# LeetCode 200 - Number of Islands

## Pattern

Treat each land cell ('1') as a graph node.

For every unvisited land cell:

1. Found a new island.
2. Run DFS/BFS.
3. Mark all connected land as visited.
4. Increment island count.

Answer = Number of connected components of land.

Time: O(m*n)
Space: O(m*n) worst case

---

## Version 1: DFS + Visited Array

DFS(row, col):

```
if out of bounds
   or grid[row][col] == '0'
   or visited[row][col]:
    return

visited[row][col] = true

DFS(row+1, col)
DFS(row-1, col)
DFS(row, col+1)
DFS(row, col-1)
```

numIslands():

```
islands = 0

for every cell:

    if grid[i][j] == '1'
       and not visited:

        islands++
        DFS(i, j)
```

---

## Version 2: DFS (Sink Island) [Most Common]

Idea:
Use the grid itself as the visited array.

When visiting land:

```
grid[row][col] = '0'
```

This "sinks" the island.

DFS(row, col):

```
if out of bounds
   or grid[row][col] == '0':
    return

grid[row][col] = '0'

DFS(row+1, col)
DFS(row-1, col)
DFS(row, col+1)
DFS(row, col-1)
```

numIslands():

```
islands = 0

for every cell:

    if grid[i][j] == '1':

        islands++
        DFS(i, j)
```

---

## Version 3: BFS + Visited Array

BFS(startRow, startCol):

```
queue.push(start)

visited[start] = true

while queue not empty:

    (r,c) = queue.front()

    queue.pop()

    for each direction:

        nr = r + dr[k]
        nc = c + dc[k]

        if valid
           and grid[nr][nc] == '1'
           and not visited:

            visited[nr][nc] = true

            queue.push(nr,nc)
```

numIslands():

```
islands = 0

for every cell:

    if grid[i][j] == '1'
       and not visited:

        islands++
        BFS(i,j)
```

---

## Standard Direction Arrays

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

Meaning:

Up    = (-1, 0)
Down  = ( 1, 0)
Left  = ( 0,-1)
Right = ( 0, 1)

---

## Common Mistakes

1. Using:

   grid[x][y] == 1

instead of:

```
grid[x][y] == '1'
```

because grid stores chars.

2. Writing:

   int n = grid.size()

instead of:

```
int n = grid[0].size()
```

3. Checking diagonal neighbors.

Number of Islands uses only:

```
Up, Down, Left, Right
```

4. Accessing:

```
grid[0]
```

before checking:

```
if(grid.empty())
```

---

## Interview One-Liner

Number of Islands = Count connected components in a grid using DFS/BFS.
Each time an unvisited land cell is found, start a traversal and mark the
entire component visited.
