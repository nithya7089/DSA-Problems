class Solution {
public:
    int dp[301][301], len;
    vector<int> ball;
    int val(int i, int j, int k) {
        int a = ((i == 0) ? 1 : ball[i - 1]),
            b = ((j == len - 1) ? 1 : ball[j + 1]);
        return (a * b * ball[k]);
    }
    int rec(int i, int j) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        for (int k = i; k <= j; k++) {
            ans = max(ans, rec(i, k - 1) + rec(k + 1, j) + val(i,j,k));
        }
        dp[i][j] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        ball = nums;
        len = nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, nums.size() - 1);
    }
};