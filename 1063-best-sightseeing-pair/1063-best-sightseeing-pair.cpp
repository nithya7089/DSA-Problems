class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size();
        int maxi = arr[0];
        int ans = 0;
        for(int i=1;i<n;i++){
          ans = max(ans,arr[i] - i + maxi);
           maxi = max(maxi,arr[i]+i);
        }
        return ans;
    }
};