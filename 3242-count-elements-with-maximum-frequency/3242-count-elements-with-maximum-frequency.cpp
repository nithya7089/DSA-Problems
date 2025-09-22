class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
         mp[nums[i]]++;
        }
        int ans = 0;
        int maxi = 0;
        for(auto it=mp.begin();it!=mp.end();it++){
         if(maxi<it->second){
          maxi = it->second;
         }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
          if(maxi == it->second){
           ans += maxi;
          }
        }
        return ans;
    }
};