class Solution {
public:
    int minimumLength(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }
        for(auto ele : mp){
            int freq = ele.second;
            if(freq%2==1){
            ans += freq-1;
            }
            else{
            ans+= freq-2;
            }
        }
        return (n-ans);
    }
};