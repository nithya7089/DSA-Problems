class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = 0;
        int d = 0;
        for(int i=0;i<n;i++){
          int b = (arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1]);
          if(d == b){
            ans = max(ans,arr[i][0]*arr[i][1]);
          }
          else if(d<b){
            d = b;
            ans = arr[i][0]*arr[i][1];
          }
        }
        return ans;
    }
};