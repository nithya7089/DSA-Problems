class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> arr = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string s;
        while (true) {
            sort(arr.rbegin(), arr.rend());
            bool added = false;
            for (auto& [count, ch] : arr) {
                int len = s.size();
                if (count > 0 && (len < 2 || s[len - 1] != ch || s[len - 2] != ch)) {
                    s += ch;
                    count--;  
                    added = true;
                    break;
                }
            }
            if (!added) {
                break;
            }
        }
        return s;
    }
};
