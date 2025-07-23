class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int t = 0;
        string h = (x > y) ? "ab" : "ba";
        string l = (x > y) ? "ba" : "ab";
        int hs = max(x, y), ls = min(x, y);
        auto a = f(s, h, hs);
        t += a.first;
        auto b = f(a.second, l, ls);
        t += b.first;
        return t;
    }

private:
    pair<int, string> f(const string& s, const string& p, int v) {
        string r;
        int c = 0;
        for (char ch : s) {
            if (!r.empty() && r.back() == p[0] && ch == p[1]) {
                r.pop_back();
                c += v;
            } else {
                r.push_back(ch);
            }
        }
        return {c, r};
    }
};
