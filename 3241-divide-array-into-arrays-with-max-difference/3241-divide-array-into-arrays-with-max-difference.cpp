#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        
        vector<int> subarray;
        for (int i = 0; i < n; ++i) {
            if (subarray.empty() || nums[i] - subarray.front() <= k) {
                subarray.push_back(nums[i]);
                if (subarray.size() == 3) {
                    result.push_back(subarray);
                    subarray.clear();
                }
            } else {
                return {};
            }
        }
        
        if (!subarray.empty()) return {};
        
        return result;
    }
};