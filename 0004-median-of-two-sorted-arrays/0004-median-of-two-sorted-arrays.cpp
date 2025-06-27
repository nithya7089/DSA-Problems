#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> ans;
       int a = nums1.size();
       int b = nums2.size();
       for (int i = 0; i < a; i++) {
            int n = nums1[i];
            ans.push_back(n);
       }
       for (int i = 0; i < b; i++) {
            int n = nums2[i];
            ans.push_back(n);
       }
       
       sort(ans.begin(), ans.end());  
       int size = ans.size();
       if (size % 2 == 0) {
           int mid1 = size / 2 - 1;
           int mid2 = size / 2;
           return (ans[mid1] + ans[mid2]) / 2.0; 
       } else {
           int mid = size / 2;
           return ans[mid];  
       }
    }
};