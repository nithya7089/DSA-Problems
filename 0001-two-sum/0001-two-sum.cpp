class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int> m;
       int n = nums.size();
       for(int i=0;i<n;i++){
        if(m.find(target-nums[i])!=m.end()){
          return {i,m[target-nums[i]]};
        }
        m[nums[i]]=i;
       }
       return {};
    }
};