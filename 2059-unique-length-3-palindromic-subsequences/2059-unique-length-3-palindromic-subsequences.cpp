class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        unordered_map<char, vector<int>> indices;
        
        for (int i = 0; i < s.length(); ++i) {
            indices[s[i]].push_back(i);
        }
        
        for (auto& pair : indices) {
            char ch = pair.first;
            vector<int>& positions = pair.second;
            
            if (positions.size() > 1) {
                unordered_set<char> chars;
                
                for (int i = positions.front() + 1; i < positions.back(); ++i) {
                    chars.insert(s[i]);
                }
                
                count += chars.size();
            }
        }
        
        return count;
    }
};
