class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        bool seenDigit = false, seenDot = false, seenE = false, digitAfterE = true;

        while (i < n && s[i] == ' ') i++;  
        int start = i;
        while (n > start && s[n - 1] == ' ') n--; 

        for (; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
                if (seenE) digitAfterE = true;
            } else if (c == '+' || c == '-') {
                if (i > start && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            } else if (c == '.') {
                if (seenDot || seenE) return false;
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenE || !seenDigit) return false;
                seenE = true;
                digitAfterE = false;
            } else return false;
        }

        return seenDigit && digitAfterE;
    }
};