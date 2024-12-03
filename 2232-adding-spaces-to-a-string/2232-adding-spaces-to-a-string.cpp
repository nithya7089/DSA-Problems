class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int j = 0;
        string d;
        for (int i = 0; i < s.length(); i++) {
            if (j < spaces.size() && i  == spaces[j]) {
                ans += d;
                ans += " ";
                j++;
                d = "";
            }
            d += s[i];
        }
        if (!d.empty()) {
            ans += d;
        }
        return ans;
    }
};
