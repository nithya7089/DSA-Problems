class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1;
        int mini = 0, maxi = 0;

        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i]);

            if (i == mini) maxi = ans;

            if (nums[i] < maxi - k)
                mini = i + 1;
        }

        return mini < nums.size() ? mini : -1;
    }
};