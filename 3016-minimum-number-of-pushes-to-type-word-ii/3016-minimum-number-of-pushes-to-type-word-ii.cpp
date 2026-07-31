class Solution {
public:
    static bool compareChars(const char a, const char b, const unordered_map<char, int>& freq) {
        return freq.at(a) > freq.at(b);
    }

    int minimumPushes(string& word) {
        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }

        vector<char> sortedChars;
        for (const auto& entry : freq) {
            sortedChars.push_back(entry.first);
        }
        sort(sortedChars.begin(), sortedChars.end(), [&](char a, char b) {
            return compareChars(a, b, freq);
        });

        int keyPresses = 0;
        int keyPosition = 1;
        int keyNumber = 2;

        for (char ch : sortedChars) {
            keyPresses += freq.at(ch) * keyPosition;
            if (keyNumber < 9) {
                keyNumber += 1;
            } else {
                keyNumber = 2;
                keyPosition += 1;
            }
        }

        return keyPresses;
    }
};