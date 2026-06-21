#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        if (!words.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);

        words.erase(beginWord);

        int level = 1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return level;

                for (int pos = 0; pos < word.size(); pos++) {

                    char original = word[pos];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        word[pos] = c;

                        if (words.count(word)) {

                            q.push(word);

                            words.erase(word);
                        }
                    }

                    word[pos] = original;
                }
            }

            level++;
        }

        return 0;
    }
};

struct TestCase {
    string beginWord;
    string endWord;
    vector<string> wordList;
    int expected;
};

int main() {

    vector<TestCase> tests = {
        {
            "hit",
            "cog",
            {"hot","dot","dog","lot","log","cog"},
            5
        },
        {
            "hit",
            "cog",
            {"hot","dot","dog","lot","log"},
            0
        },
        {
            "a",
            "c",
            {"a","b","c"},
            2
        },
        {
            "hot",
            "dog",
            {"hot","dog"},
            0
        },
        {
            "red",
            "tax",
            {"ted","tex","red","tax","tad","den","rex","pee"},
            4
        }
    };

    Solution sol;

    int passed = 0;

    for (int i = 0; i < tests.size(); i++) {

        int result = sol.ladderLength(
            tests[i].beginWord,
            tests[i].endWord,
            tests[i].wordList
        );

        bool ok = (result == tests[i].expected);

        cout << "Test " << i + 1 << ": "
             << (ok ? "PASS" : "FAIL")
             << " | Expected = "
             << tests[i].expected
             << " | Got = "
             << result
             << endl;

        if (ok) passed++;
    }

    cout << "\nPassed "
         << passed
         << "/"
         << tests.size()
         << " tests\n";

    return 0;
}