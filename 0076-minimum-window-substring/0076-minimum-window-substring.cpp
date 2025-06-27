class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq;
        for (char c : t)
            targetFreq[c]++;
        
        int requiredChars = targetFreq.size();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minLeft = 0;
        unordered_map<char, int> windowFreq;
        
        int formedChars = 0;
        
        while (right < s.length()) {
            char currentChar = s[right];
            windowFreq[currentChar]++;
            
            if (targetFreq.find(currentChar) != targetFreq.end() && windowFreq[currentChar] == targetFreq[currentChar])
                formedChars++;
            
            while (left <= right && formedChars == requiredChars) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                
                char leftChar = s[left];
                windowFreq[leftChar]--;
                
                if (targetFreq.find(leftChar) != targetFreq.end() && windowFreq[leftChar] < targetFreq[leftChar])
                    formedChars--;
                
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};