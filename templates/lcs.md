# LONGEST COMMON SUBSEQUENCE (LCS) GUIDE

BASE PROBLEM
------------

Given strings:

s1
s2

Find the length of the longest subsequence common to both.

Example:

s1 = "abcde"
s2 = "ace"

Answer = 3 ("ace")

Leetcode:
1143 - Longest Common Subsequence

HOW TO RECOGNIZE LCS PROBLEMS

Keywords:

- Subsequence
- Common subsequence
- Match characters
- Delete characters
- Insert/Delete to convert strings
- Palindromic subsequence
- Distinct subsequences

If there are TWO strings and choices involve:
- match
- skip left
- skip right

Think LCS.

**STATE DEFINITION**

dp[i][j]

Meaning:

Answer using:

s1[0...i-1]
s2[0...j-1]

## STANDARD RECURRENCE

if(s1[i-1] == s2[j-1])

    dp[i][j] =
        1 + dp[i-1][j-1]

else

    dp[i][j] =
        max(dp[i-1][j],
            dp[i][j-1])

## STANDARD TABULATION TEMPLATE
```
int lcs(string s1, string s2){

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(
        n+1,
        vector<int>(m+1, 0)
    );

    for(int i=1; i<=n; i++){

        for(int j=1; j<=m; j++){

            if(s1[i-1] == s2[j-1]){

                dp[i][j] =
                    1 + dp[i-1][j-1];

            }

            else{

                dp[i][j] =
                    max(dp[i-1][j],
                        dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}
```
Time:
O(n*m)

Space:
O(n*m)

**SPACE OPTIMIZED TEMPLATE**
```
vector<int> prev(m+1,0);

for(int i=1;i<=n;i++){

    vector<int> curr(m+1,0);

    for(int j=1;j<=m;j++){

        if(s1[i-1]==s2[j-1]){

            curr[j] =
                1 + prev[j-1];

        }

        else{

            curr[j] =
                max(prev[j],
                    curr[j-1]);
        }
    }

    prev = curr;
}

return prev[m];
```
Space:
O(m)

## PRINTING THE LCS

After filling dp:
```
i=n
j=m

while(i>0 && j>0){

    if(s1[i-1]==s2[j-1]){

        answer += s1[i-1];

        i--;
        j--;
    }

    else if(dp[i-1][j] > dp[i][j-1]){

        i--;
    }

    else{

        j--;
    }
}

reverse(answer.begin(),
        answer.end());
```

LCS PATTERN CHEAT SHEET

CHARACTERS MATCH

Take them.

Move diagonally.

1 + dp[i-1][j-1]

----------------------------------------

CHARACTERS DON'T MATCH

Skip one character.

max(
    dp[i-1][j],
    dp[i][j-1]
)

IMPORTANT VARIATIONS

1. LONGEST COMMON SUBSEQUENCE

LC 1143

Answer:

dp[n][m]

----------------------------------------

2. LONGEST COMMON SUBSTRING

Characters must be continuous.

if(match)

    dp[i][j] =
        1 + dp[i-1][j-1]

else

    dp[i][j] = 0

Take maximum over all cells.

LC 718 (similar)

----------------------------------------

3. LONGEST PALINDROMIC SUBSEQUENCE

LC 516

LPS(s)

=

LCS(
    s,
    reverse(s)
)

----------------------------------------

4. MINIMUM INSERTIONS TO MAKE PALINDROME

Answer:

n - LPS

=

n - LCS(
        s,
        reverse(s)
    )

LC 1312

----------------------------------------

5. DELETE OPERATION FOR TWO STRINGS

LC 583

Answer:

(n-LCS)
+
(m-LCS)

----------------------------------------

6. MINIMUM INSERTIONS/DELETIONS
TO CONVERT STRING A TO B

Insertions:

m-LCS

Deletions:

n-LCS

----------------------------------------

7. SHORTEST COMMON SUPERSEQUENCE

Length:

n + m - LCS

LC 1092

----------------------------------------

8. DISTINCT SUBSEQUENCES

LC 115

Different DP.

Count ways.

Not standard LCS recurrence.

INTERVIEW RECOGNITION RULE

Two strings?

↓

Need longest common pattern?

↓

Characters match?
Take diagonal.

Characters don't match?
Skip one string.

↓

Think LCS.

MUST DO PROBLEMS

1143 Longest Common Subsequence
516  Longest Palindromic Subsequence
583  Delete Operation for Two Strings
712  Minimum ASCII Delete Sum
1092 Shortest Common Supersequence
1312 Minimum Insertions to Palindrome
115  Distinct Subsequences