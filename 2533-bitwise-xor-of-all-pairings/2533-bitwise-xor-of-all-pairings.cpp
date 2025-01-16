class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int d = 0;
        for(int i=0;i<nums2.size();i++){
          d^=nums2[i];
        }
        int ans = 0;
        for(int i=0;i<nums1.size();i++){
         ans = ans^(nums1[i]);
        }
        if(nums1.size() % 2 == 0 && nums2.size() % 2 == 0){
          return 0;
        }
        if(nums1.size() % 2 != 0 && nums2.size() % 2 !=0){
          return (ans^d);
        }
        if(nums1.size() % 2 != 0){
        return d;
        }
        return ans;
    }
};