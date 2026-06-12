--------------------------------------------------
1. LONGEST PALINDROMIC SUBSEQUENCE (LC 516)
--------------------------------------------------

State:
dp[i][j]
= length of longest palindromic subsequence in s[i...j]

Recurrence:

if(s[i] == s[j])
    dp[i][j] = 2 + dp[i+1][j-1];
else
    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);

Base:

dp[i][i] = 1;

Fill Order:

for(i = n-1; i >= 0; i--)
    for(j = i+1; j < n; j++)

Answer:

dp[0][n-1]

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
2. MINIMUM INSERTIONS TO MAKE PALINDROME (LC 1312)
--------------------------------------------------

Key Formula:

answer = n - LPS

where

LPS = Longest Palindromic Subsequence

Reason:

Characters not part of the LPS must be inserted around.

Alternative DP:

State:

dp[i][j]
= minimum insertions needed to make s[i...j] palindrome

Recurrence:

if(s[i] == s[j])
    dp[i][j] = dp[i+1][j-1];
else
    dp[i][j] =
        1 +
        min(dp[i+1][j],
            dp[i][j-1]);

Base:

dp[i][i] = 0;

Answer:

dp[0][n-1]

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
3. MINIMUM DELETIONS TO MAKE PALINDROME
--------------------------------------------------

Key Formula:

answer = n - LPS

Reason:

Delete all characters not in the longest palindromic subsequence.

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
4. LONGEST PALINDROMIC SUBSTRING (LC 5)
--------------------------------------------------

IMPORTANT:

Substring ≠ Subsequence

Substring must be contiguous.

State:

dp[i][j]
= true if s[i...j] is a palindrome

Recurrence:

if(s[i] == s[j])
{
    if(j - i <= 2)
        dp[i][j] = true;
    else
        dp[i][j] = dp[i+1][j-1];
}

Track:

maxLen
startIndex

Answer:

s.substr(startIndex, maxLen)

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
5. COUNT PALINDROMIC SUBSTRINGS (LC 647)
--------------------------------------------------

State:

dp[i][j]
= true if s[i...j] is palindrome

Recurrence:

s[i] == s[j]
&&
(
    j-i <= 2
    ||
    dp[i+1][j-1]
)

Whenever dp[i][j] becomes true:

count++;

Answer:

count

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
6. PALINDROME PARTITIONING II (LC 132)
--------------------------------------------------

Step 1:

Precompute

isPal[i][j]

using palindrome DP.

State:

dp[i]
= minimum cuts needed for suffix starting at i

Recurrence:

dp[i] =
min(
    1 + dp[j+1]
)
for every palindrome s[i...j]

Base:

dp[n] = -1

Answer:

dp[0]

Complexity:

Time  : O(n²)
Space : O(n²)

--------------------------------------------------
7. LPS VIA LCS TRICK
--------------------------------------------------

For:

LC 516
LC 1312
Minimum Deletions

Create:

string rev = s;
reverse(rev.begin(), rev.end());

Compute:

LCS(s, rev)

Result:

LCS(s, rev) = LPS(s)

Then:

LC 516:
answer = LPS

LC 1312:
answer = n - LPS

Min Deletions:
answer = n - LPS

--------------------------------------------------
COMMON FILL ORDER FOR PALINDROME DP
--------------------------------------------------

Whenever state is:

dp[i][j]

and recurrence uses:

dp[i+1][j]
dp[i][j-1]
dp[i+1][j-1]

Use:

for(i = n-1; i >= 0; i--)
{
    for(j = i+1; j < n; j++)
    {
        ...
    }
}

Reason:

Smaller substrings are solved first.

--------------------------------------------------
QUICK IDENTIFICATION GUIDE
--------------------------------------------------

Question asks...

"Longest Palindromic Subsequence"
→ LPS DP

"Minimum Insertions"
→ n - LPS

"Minimum Deletions"
→ n - LPS

"Longest Palindromic Substring"
→ Palindrome DP / Expand Around Center

"Count Palindromic Substrings"
→ Palindrome DP / Expand Around Center

"Minimum Cuts for Palindrome Partitioning"
→ isPal[][] + DP

If you see:
    i+1, j-1

Think:
    Palindrome DP

If you see:
    reverse(s)

Think:
    LPS via LCS