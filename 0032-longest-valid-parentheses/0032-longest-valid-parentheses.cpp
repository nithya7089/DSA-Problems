class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        vector<int> dp(n, 0);
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (i - dp[i - 1] - 2 >= 0)
                        dp[i] += dp[i - dp[i - 1] - 2];
                }
                ans = max(ans, dp[i]);
            }
        }

        return ans;
    }
};
