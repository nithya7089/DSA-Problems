class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        for(int i=nums[0];i<=nums[nums.size()-1];i++){
           int low = lower_bound(nums.begin(),nums.end(),i-k)-nums.begin();
           int high = lower_bound(nums.begin(),nums.end(),i+k+1)-nums.begin();
           ans = max(high-low,ans);
        }
        return ans;
    }
};