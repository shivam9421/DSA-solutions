class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int j, string& word1, string& word2) {
        // base case
        if (i < 0  )
            return j+1;
        if(j<0)
        return i+1;    
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j]) {
            return dp[i][j] = f(i - 1, j - 1, word1, word2);
        } else {
            int replacewords = 1 + f(i - 1, j - 1, word1, word2);
            int deletewords = 1 + f(i - 1, j, word1, word2);
            int insertwords = 1 + f(i, j - 1, word1, word2);
            return dp[i][j] = min(replacewords, min(deletewords, insertwords));
        }
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 == 0) return n2;
        if (n2 == 0) return n1;
        dp.assign(n1, vector<int>(n2, -1));
        return f(n1 - 1, n2 - 1, word1, word2);
    }
};
#include <iostream>
#include <cassert>

void runTests() {
    Solution sol;
    
    // Case 1: Both empty
    assert(sol.minDistance("", "") == 0);
    
    // Case 2: word1 is empty
    assert(sol.minDistance("", "abc") == 3);
    
    // Case 3: word2 is empty
    assert(sol.minDistance("abc", "") == 3);
    
    // Case 4: Identical strings
    assert(sol.minDistance("hello", "hello") == 0);
    
    std::cout << "All base case tests passed!" << std::endl;
}