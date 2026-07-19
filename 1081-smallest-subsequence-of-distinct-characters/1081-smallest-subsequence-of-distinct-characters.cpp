class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[27] = {0};
        bitset<27> mp;
        string st;

        for (auto& c : s)
            freq[c & 31]++;

        for (auto& c : s) {
            int x = c & 31;
            freq[x]--;

            if (mp.test(x))
                continue;

            while (st.length() && st.back() > c && freq[st.back() & 31]) {
                mp.reset(st.back() & 31);
                st.pop_back();
            }

            st.push_back(c);
            mp.set(x);
        }

        return st;
    }
};