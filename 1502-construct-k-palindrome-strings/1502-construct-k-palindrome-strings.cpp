class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        int d = 0;
        for (auto& it : m) {
            if (it.second % 2 != 0) d++;
        }
        return d <= k;
    }
};