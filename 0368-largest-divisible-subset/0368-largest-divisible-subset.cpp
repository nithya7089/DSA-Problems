class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1); 
        vector<int> parent(n, -1); 
        int max_index = 0; 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[max_index]) {
                max_index = i;
            }
        }
        vector<int> result;
        int current = max_index;
        while (current != -1) {
            result.push_back(nums[current]);
            current = parent[current];
        }

        return result;
    }
};