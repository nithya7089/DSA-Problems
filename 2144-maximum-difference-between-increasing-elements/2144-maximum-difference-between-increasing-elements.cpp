class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int pre = nums[0];
        int ans = -1;
        for(int i=1;i<nums.size();i++){
          ans = max(ans,nums[i]-pre);
          pre = min(pre,nums[i]);
        }
        if(ans == 0){
          return -1;
        }
        return ans;
    }
};