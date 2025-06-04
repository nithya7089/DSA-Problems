class Solution {
public:
    string answerString(string word, int k) {
        int n = word.length();
        if (k == 1) {
            return word;
        }

        char d = word[0];
        for (int i = 1; i < n; i++) {
            d = max(d, word[i]);
        }

        int extra = n - k + 1;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (word[i] == d) {
                ans = max(ans, word.substr(i, min(n - i, extra)));
            }
        }
        return ans;
    }
};