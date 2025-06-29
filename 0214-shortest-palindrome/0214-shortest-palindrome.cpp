class Solution {
    public:
    string shortestPalindrome(string s) {
        int n = s.size();

        // Comparing two strings of length n takes O(n) time,
        // whereas comparing two integers (hash values) takes O(1) time.
        // So, convert the string into a numeric hash to enable faster comparisons.

        // Choose a prime number near 26 as the base for hashing (e.g., 29 or 31 is ideal).
        int p = 31, mod = 1e9 + 7;

        int i = 0;
        long long prefix = 0, suffix = 0, pow = 1;
        int long_palin = 0;

        // We want to find the longest palindromic prefix starting from index 0.
        while (i < n) {
            prefix = (prefix * p + (s[i] - 'a' + 1) + mod) % mod;
            suffix = (suffix + (s[i] - 'a' + 1) * pow + mod) % mod;
            pow = (pow * p + mod) % mod;
            // Check if the substring s[0...i] is a palindrome by comparing prefix and suffix hashes.
            if (prefix == suffix) long_palin = i + 1;
            i++;
        }

        // Take the remaining suffix after the longest palindromic prefix.
        // Reverse it and prepend it to the original string to form the shortest palindrome.
        string s1 = s.substr(long_palin);
        reverse(s1.begin(), s1.end());
        return s1 + s;
    }
                                            
};