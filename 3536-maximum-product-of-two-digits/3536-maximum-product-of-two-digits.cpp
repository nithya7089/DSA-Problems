class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        int n1 = s.size();
        int d = s[n1-2] - '0';
        int d1 = s[n1-1] - '0';
        return d * d1;
    }
};