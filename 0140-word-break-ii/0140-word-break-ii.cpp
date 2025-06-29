class Solution {
public:
    vector<string> temp, ans;
    map<string, int> words;
    string word[21][21];
    int n;
    string add(vector<string>& vec) {
        string a = "";
        for (int i = 0; i < vec.size(); i++) {
            a += vec[i];
            if (i != vec.size() - 1)
                a += " ";
        }
        return a;
    }
    void rec(int i) {
        if (i == n) {
            ans.push_back(add(temp));
            return;
        }
        for (int j = i; j < n; j++) {
            if (words.count(word[i][j])) {
                temp.push_back(word[i][j]);
                rec(j + 1);
                temp.pop_back();
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                word[i][j] = s.substr(i, j - i + 1);
            }
        }
        for (int i = 0; i < wordDict.size(); i++) {
            words[wordDict[i]] = 1;
        }
        rec(0);
        return ans;
    }
};