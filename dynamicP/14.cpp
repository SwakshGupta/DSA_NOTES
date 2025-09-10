
/*

 Print Longest Common Subsequence

 1. see the notes and try to build intuition clearly 

Watch striver lecture for more clearity 



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string LCS(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Backtrack to build the LCS string
    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) {
            lcs.push_back(s[i-1]); // part of LCS
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--; // move up
        }
        else {
            j--; // move left
        }
    }

    reverse(lcs.begin(), lcs.end()); // reverse to correct order
    return lcs;
}

int main() {
    string s = "abcde";
    string t = "ace";

    string ans = LCS(s, t);
    cout << "Longest Common Subsequence: " << ans << endl;

    return 0;
}
