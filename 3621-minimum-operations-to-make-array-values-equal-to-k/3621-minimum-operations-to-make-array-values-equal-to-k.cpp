class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> numSet(nums.begin(), nums.end());
        int min = *numSet.begin();
        if (min < k) return -1;
        return numSet.size() + (min == k ? -1 : 0);
    }
};