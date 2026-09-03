class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int temp = 1e9, c=0;
        for(int x: nums1){
            if(x%2!=0){
              c++;
            }
            temp = min(temp, x);
        }
        if(temp%2!=0 || c==0){
         return true;
        }
        return false;
    }
};